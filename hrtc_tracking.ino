#define TINY_GSM_MODEM_SIM800                     // Define the modem type
#include <TinyGPS++.h>
#include <HardwareSerial.h>
#include <Wire.h>
#include <TinyGsmClient.h>

const char server[] = "api.thingspeak.com";       // The server address to connect to
const char resource[] = "/update";                // The resource path for updating data on ThingSpeak
const int port = 80;                              // The server port number (HTTP)
const char apn[] = "bsnlnet";                     // GPRS APN (Access Point Name)
const char gprsUser[] = "";                       // GPRS User (empty if not required)
const char gprsPass[] = "";                       // GPRS Password (empty if not required)
const char simPIN[] = "";                         // SIM card PIN (empty if not required)
String apiKeyValue = "JZ61RQ0GNHJSSPB4";          // API key for ThingSpeak

#define MODEM_RST 5                               // Pin for modem reset
#define MODEM_PWKEY 4                             // Pin for modem power key
#define MODEM_POWER_ON 23                         // Pin for modem power on
#define MODEM_TX 27                               // Pin for modem TX
#define MODEM_RX 26                               // Pin for modem RX
#define I2C_SDA 21                                // Pin for I2C SDA
#define I2C_SCL 22                                // Pin for I2C SCL

#define SerialMon Serial                          // Serial for debugging (Serial Monitor)
#define SerialAT Serial1                          // Serial for AT commands to modem

#define TINY_GSM_RX_BUFFER 1024                   // Define the RX buffer size for the modem

TinyGPSPlus gps;                                  // GPS object
HardwareSerial gpsSerial(2);                      // Serial2 for GPS

TinyGsm modem(SerialAT);                          // Create TinyGsm modem object
TinyGsmClient client(modem);                      // Create TinyGsm client object for internet connection

TwoWire I2CPower = TwoWire(0);                    // Create TwoWire object for I2C communication

#define uS_TO_S_FACTOR 1000000UL                  // Conversion factor for microseconds to seconds
#define TIME_TO_SLEEP 3600                        // Time ESP32 will go to sleep (in seconds)

#define IP5306_ADDR 0x75                          // I2C address for IP5306
#define IP5306_REG_SYS_CTL0 0x00                  // Register address for IP5306 system control

// Function to set power boost keep on for IP5306
bool setPowerBoostKeepOn(int en) {
  I2CPower.beginTransmission(IP5306_ADDR);
  I2CPower.write(IP5306_REG_SYS_CTL0);
  if (en) {
    I2CPower.write(0x37);                         // Set bit1: 1 to enable, 0 to disable boost keep on
  } else {
    I2CPower.write(0x35);                         // 0x37 is the default register value
  }
  return I2CPower.endTransmission() == 0;
}

void setup() {
  SerialMon.begin(115200);                        // Start serial monitor at baud rate 115200
  I2CPower.begin(I2C_SDA, I2C_SCL, 400000);       // Start I2C communication
  bool isOk = setPowerBoostKeepOn(1);             // Set power boost keep on for IP5306
  SerialMon.println(String("IP5306 KeepOn ") + (isOk ? "OK" : "FAIL"));  // Print status of IP5306 keep on

  pinMode(MODEM_PWKEY, OUTPUT);                   // Set modem power key pin as output
  pinMode(MODEM_RST, OUTPUT);                     // Set modem reset pin as output
  pinMode(MODEM_POWER_ON, OUTPUT);                // Set modem power on pin as output
  digitalWrite(MODEM_PWKEY, LOW);                 // Set modem power key pin low
  digitalWrite(MODEM_RST, HIGH);                  // Set modem reset pin high
  digitalWrite(MODEM_POWER_ON, HIGH);             // Set modem power on pin high

  SerialAT.begin(115200, SERIAL_8N1, MODEM_RX, MODEM_TX);  // Start serial for AT commands
  gpsSerial.begin(9600, SERIAL_8N1, 18, 19);      // Start serial for GPS (TX: 18, RX: 19)

  delay(3000);                                    // Wait for the modem to initialize

  SerialMon.println("Initializing modem...");     // Print initializing message
  modem.restart();                                // Restart the modem
  if (strlen(simPIN) && modem.getSimStatus() != 3) {  // Unlock SIM card if required
    modem.simUnlock(simPIN);
  }
}

void loop() {
  // Read data from the GPS module
  while (gpsSerial.available() > 0) {
    gps.encode(gpsSerial.read());
  }

  if (gps.location.isUpdated()) {
    float latitude = gps.location.lat();          // Get the latest latitude
    float longitude = gps.location.lng();         // Get the latest longitude

    SerialMon.print("Latitude: ");
    SerialMon.println(latitude, 6);
    SerialMon.print("Longitude: ");
    SerialMon.println(longitude, 6);

    // Connect to the internet via GPRS
    SerialMon.print("Connecting to APN: ");
    SerialMon.print(apn);
    if (!modem.gprsConnect(apn, gprsUser, gprsPass)) {
      SerialMon.println(" fail");
    } else {
      SerialMon.println(" OK");
      SerialMon.print("Connecting to ");
      SerialMon.print(server);
      if (!client.connect(server, port)) {
        SerialMon.println(" fail");
      } else {
        SerialMon.println(" OK");

        // Prepare and send HTTP POST request with GPS data
        SerialMon.println("Performing HTTP POST request...");
        String httpRequestData = "api_key=" + apiKeyValue 
                                 + "&field1=" + String(latitude, 6) 
                                 + "&field2=" + String(longitude, 6);

        client.print(String("POST ") + resource + " HTTP/1.1\r\n");
        client.print(String("Host: ") + server + "\r\n");
        client.println("Connection: close");
        client.println("Content-Type: application/x-www-form-urlencoded");
        client.print("Content-Length: ");
        client.println(httpRequestData.length());
        client.println();
        client.println(httpRequestData);

        // Wait for the server response and print it to the serial monitor
        unsigned long timeout = millis();
        while (client.connected() && millis() - timeout < 10000L) {
          while (client.available()) {
            char c = client.read();
            SerialMon.print(c);
            timeout = millis();
          }
        }
        SerialMon.println();

        client.stop();                           // Close the client connection
        SerialMon.println(F("Server disconnected"));
        modem.gprsDisconnect();                  // Disconnect from GPRS
        SerialMon.println(F("GPRS disconnected"));
      }
    }
  }

  delay(3000);                                  // Wait for 30 seconds before repeating the loop
}


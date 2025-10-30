# 🚌 Real-Time Bus Tracking System

A comprehensive IoT-based real-time bus tracking solution that combines GPS, GSM, and cloud technologies to provide live location tracking for public transportation. Built with ESP32, Flutter, and modern web technologies.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Flutter](https://img.shields.io/badge/Flutter-02569B?logo=flutter&logoColor=white)](https://flutter.dev)
[![ESP32](https://img.shields.io/badge/ESP32-000000?logo=espressif&logoColor=white)](https://www.espressif.com/)

---

## 📑 Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Workflow](#Workflow)
- [Hardware Components](#hardware-components)
- [Software Stack](#software-stack)
- [Installation](#installation)
  - [Hardware Setup](#hardware-setup)
  - [Software Setup](#software-setup)
- [Configuration](#configuration)
- [Complete Code Implementation](#complete-code-implementation)
  - [ESP32 Firmware - Combined Version](#esp32-firmware---combined-version)
  - [Database Schema](#database-schema)
  - [Flutter App Structure](#flutter-app-structure)
- [Usage](#usage)
- [API Documentation](#api-documentation)
- [Project Structure](#project-structure)
- [Challenges & Solutions](#challenges--solutions)
- [Future Enhancements](#future-enhancements)
- [Contributing](#contributing)
- [License](#license)
- [Acknowledgments](#acknowledgments)
- [Contact](#contact)

---

## 🎯 Overview

The **Real-Time Bus Tracking System** is designed to modernize public transportation by providing live tracking updates of buses directly to passengers' mobile phones. This project specifically targets the Himachal Road Transport Corporation (H.R.T.C.) buses but can be adapted for any public transport system.

### Key Objectives

- ✅ Provide real-time bus location tracking
- ✅ Reduce passenger waiting time uncertainty
- ✅ Improve public transportation efficiency
- ✅ Offer cost-effective hardware solutions
- ✅ Enable scalable cloud-based data management
- ✅ Create user-friendly mobile applications

**Project Period:** August 2024 - December 2024  
**Institution:** Jawaharlal Nehru Govt. Engg. College, Sundernagar (HP)

---

## ✨ Features

### For Passengers
- 📍 **Real-time location tracking** on interactive maps
- ⏱️ **Estimated arrival times** at bus stops
- 🗺️ **Route visualization** with OpenStreetMap
- 📱 **Cross-platform mobile app** (Android/iOS)
- 🔔 **Push notifications** for bus updates
- 👤 **User authentication** and profile management

### For Administrators
- 📊 **Fleet management dashboard**
- 📈 **Historical data analytics**
- 🚨 **Real-time alerts** for delays/breakdowns
- 🛣️ **Route optimization insights**
- 👥 **Driver management system**
- 📉 **Performance monitoring**

### Technical Features
- 🌐 **GPRS-based data transmission**
- 🛰️ **GPS coordinate tracking**
- ☁️ **Cloud database storage** (Supabase)
- 🔄 **Real-time data synchronization**
- 🔋 **Power-efficient hardware design**
- 🔐 **Secure API communications**

---

## 🏗️ Workflow 
   ![Real-time-bus-tracking-system](Workflow.png)
### Data Flow
1. **GPS Module** continuously captures latitude/longitude coordinates
2. **ESP32 Microcontroller** processes GPS data and formats it as JSON
3. **SIM800H GSM Module** transmits data via GPRS to the cloud
4. **Supabase Database** stores location data with timestamps
5. **Flutter Mobile App** fetches data and displays on OpenStreetMap
6. **Users** view real-time bus locations on their smartphones

---

## 🔧 Hardware Components

| Component | Model | Purpose | Specifications |
|-----------|-------|---------|----------------|
| **Microcontroller** | LilyGO T-Call SIM800H (ESP32 WROVER) | Data processing & GSM communication | Dual-core 240MHz, 520KB SRAM, Wi-Fi/BLE |
| **GPS Module** | Neo-6M | Location tracking | 50-channel, 2.5m accuracy, -162 dBm sensitivity |
| **Power Supply** | Rechargeable Li-ion Battery | Continuous operation | 5V regulated output |
| **Antenna** | GPS Ceramic Antenna | Signal reception | External antenna support |
| **Enclosure** | Weather-resistant casing | Component protection | IP65 rated (optional) |

### Hardware Features
- **ESP32 WROVER**: Dual-core processor with integrated Wi-Fi and Bluetooth
- **SIM800H GSM Module**: Quad-band 850/900/1800/1900 MHz support
- **Neo-6M GPS**: High sensitivity with external antenna capability
- **Power Management**: Low power consumption with deep sleep modes

---

## 💻 Software Stack

### Backend
- **Database**: [Supabase](https://supabase.com/) - PostgreSQL-based BaaS
- **IoT Platform**: [ThingSpeak](https://thingspeak.com/) - Data visualization
- **Programming**: Arduino C/C++ for ESP32 firmware

### Frontend
- **Framework**: [Flutter](https://flutter.dev/) 3.x - Cross-platform mobile app
- **State Management**: flutter_bloc 8.1.6
- **Maps**: flutter_map 7.0.2 with OpenStreetMap
- **Database Client**: supabase_flutter 2.8.1

### Development Tools
- **IDE**: Arduino IDE 2.x, Visual Studio Code
- **Version Control**: Git & GitHub
- **API Testing**: Postman

### Key Dependencies
```yaml
dependencies:
  flutter_bloc: ^8.1.6        # State management
  supabase_flutter: ^2.8.1    # Backend integration
  flutter_map: ^7.0.2         # Map rendering
  latlong2: ^0.9.1            # GPS calculations
  geolocator: ^13.0.2         # Device location
  equatable: ^2.0.6           # Value equality
```

---

## 📥 Installation

### Hardware Setup

#### Required Components
- LilyGO T-Call SIM800H (ESP32 WROVER) × 1
- Neo-6M GPS Module × 1
- SIM card with GPRS data plan
- 5V Rechargeable Battery
- Jumper wires
- Weather-resistant enclosure (optional)

#### Wiring Diagram
```
ESP32 T-Call          Neo-6M GPS
─────────────         ──────────
GPIO 18 (TX2) ───────► RX
GPIO 19 (RX2) ◄─────── TX
3.3V          ───────► VCC
GND           ───────► GND
```

#### Circuit Connections

| ESP32 Pin | Neo-6M Pin | Description |
|-----------|------------|-------------|
| GPIO 18   | RX         | Serial TX to GPS |
| GPIO 19   | TX         | Serial RX from GPS |
| 3.3V      | VCC        | Power supply |
| GND       | GND        | Ground |

**Note**: The SIM800H module is integrated into the LilyGO T-Call board.

#### Assembly Steps

1. **Mount GPS Module**: Secure the Neo-6M GPS module with clear sky visibility
2. **Connect Wiring**: Follow the wiring diagram above
3. **Insert SIM Card**: Place an active SIM card with GPRS enabled into the SIM800H slot
4. **Power Connection**: Connect the rechargeable battery to the power input
5. **Enclosure**: Place components in weather-resistant housing (if outdoor use)
6. **Antenna Positioning**: Ensure GPS antenna has unobstructed view of the sky

### Software Setup

#### Prerequisites
- Arduino IDE 2.0 or higher
- Flutter SDK 3.0 or higher
- Git installed
- Supabase account
- ThingSpeak account (for visualization)

#### 1. Clone Repository
```bash
git clone https://github.com/yourusername/real-time-bus-tracking.git
cd real-time-bus-tracking
```

#### 2. ESP32 Firmware Setup
```bash
cd firmware
```

**Install Required Arduino Libraries:**
- TinyGSM
- TinyGPSPlus
- HardwareSerial
- Wire

**Via Arduino IDE:**
1. Open `Sketch > Include Library > Manage Libraries`
2. Search and install: `TinyGSM`, `TinyGPS-Plus`

#### 3. Mobile App Setup
```bash
cd mobile_app
flutter pub get
```

#### 4. Database Setup

**Supabase Schema:**
```sql
-- Create tables (see complete schema below)
CREATE TABLE drivers (
  id BIGINT PRIMARY KEY GENERATED ALWAYS AS IDENTITY,
  name TEXT NOT NULL,
  contact_number TEXT,
  license_number TEXT UNIQUE
);

CREATE TABLE buses (
  id BIGINT PRIMARY KEY GENERATED ALWAYS AS IDENTITY,
  bus_number TEXT NOT NULL UNIQUE,
  route TEXT NOT NULL,
  capacity INTEGER,
  driver_id INTEGER REFERENCES drivers(id),
  status TEXT CHECK (status IN ('active', 'maintenance', 'inactive'))
);

CREATE TABLE locations (
  id BIGINT PRIMARY KEY GENERATED ALWAYS AS IDENTITY,
  bus_id INTEGER REFERENCES buses(id),
  latitude DECIMAL(10, 8) NOT NULL,
  longitude DECIMAL(11, 8) NOT NULL,
  timestamp TIMESTAMPTZ DEFAULT NOW(),
  previous_stop TEXT,
  next_stop TEXT
);
```

Run this schema in your Supabase SQL editor.

---

## ⚙️ Configuration

### ESP32 Configuration

Edit the configuration in the Arduino sketch:
```cpp
// Network Configuration
const char apn[] = "your-apn";           // Your GPRS APN (e.g., "bsnlnet")
const char gprsUser[] = "";              // GPRS username (if required)
const char gprsPass[] = "";              // GPRS password (if required)

// Supabase Configuration
const char server[] = "your-project.supabase.co";
const char resource[] = "/rest/v1/coordinates";
String apiKeyValue = "your-supabase-anon-key";

// ThingSpeak Configuration (optional)
const char thingSpeakServer[] = "api.thingspeak.com";
String thingSpeakAPIKey = "your-thingspeak-api-key";
```

### Mobile App Configuration

Create `lib/config/constants.dart`:
```dart
class AppConstants {
  static const String supabaseUrl = 'https://your-project.supabase.co';
  static const String supabaseAnonKey = 'your-supabase-anon-key';
  
  // OpenStreetMap Configuration
  static const String osmTileUrl = 'https://tile.openstreetmap.org/{z}/{x}/{y}.png';
  
  // App Configuration
  static const int dataRefreshInterval = 3000; // milliseconds
  static const double defaultZoom = 13.0;
}
```

---


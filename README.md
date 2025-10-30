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
│   (Flutter)     │
└─────────────────┘

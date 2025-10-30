# 🚌 Real-Time Bus Tracking System

> An **IoT-based smart transportation project** using **ESP32, GSM, GPS, and Flutter** to monitor public bus locations in real-time and enhance commuter convenience.

![Project Banner](assets/banner.png)

---

## 📑 Table of Contents

1. [Introduction](#introduction)
2. [Objectives](#objectives)
3. [Block Diagram & Working](#block-diagram--working)
4. [Hardware Components](#hardware-components)
5. [Software Tools](#software-tools)
6. [System Implementation](#system-implementation)
7. [Mobile Application Features](#mobile-application-features)
8. [Advantages](#advantages)
9. [Applications](#applications)
10. [Challenges & Future Scope](#challenges--future-scope)
11. [Conclusion](#conclusion)
12. [Author & Credits](#author--credits)

---

## 🧠 Introduction

The **Real-Time Bus Tracking System** is designed to provide live location updates of public buses using **GPS and GSM** modules integrated with an **ESP32 microcontroller**.  
The system transmits bus coordinates to a **Supabase cloud database** and displays the data on a **Flutter-based mobile app** using **OpenStreetMap** for visualization.  

This project aims to enhance the **efficiency, safety, and reliability** of public transportation by allowing commuters to monitor bus positions, arrival times, and routes in real-time.

---

## 🎯 Objectives

- Track bus locations in real-time using GPS and GSM.
- Display live data on a user-friendly Flutter mobile app.
- Enable cloud-based data logging using Supabase and ThingSpeak.
- Improve commuter convenience and reduce uncertainty.
- Support smart city and intelligent transport initiatives.

---

## ⚙️ Block Diagram & Working

```mermaid
graph LR
A[GPS Module (Neo-6M)] -->|Latitude, Longitude| B[ESP32 (LilyGO T-Call SIM800H)]
B -->|GPRS Data| C[Supabase Cloud Database]
C -->|REST API| D[Flutter Mobile Application]
D -->|Visualization| E[OpenStreetMap API]

# IoT-Based Multilayer Security System

A security system combining multiple sensing layers and IoT connectivity to detect, alert, and report intrusion events in real time.

## Table of Contents

1. [Overview](#overview)  
2. [Features](#features)  
3. [System Architecture](#system-architecture)  
4. [Repository Structure](#repository-structure)  
5. [Hardware Components](#hardware-components)  
6. [Software & Libraries](#software--libraries)  
7. [Wiring & Connections](#wiring--connections)  
8. [Setup & Usage](#setup--usage)  
9. [Operation Flow](#operation-flow)  
10. [Enhancements & Future Work](#enhancements--future-work)  
11. [License](#license)  
12. [Authors & Acknowledgements](#authors--acknowledgements)

---

## Overview

This project implements a **multilayer security system** using IoT. It integrates sensors (e.g. laser beam interruption, motion detection) with a microcontroller to trigger local alarms and send alerts over the network. The system is suitable for home or small-scale premises security.

---

## Features

- Dual-layer sensing: laser beam + motion detection  
- Real-time alerts via IoT (cloud or server)  
- Local alarm (buzzer / LED)  
- Modular design so you can add more sensors or features  
- Remote monitoring capability  

---

## System Architecture

Below is a schematic conceptualization of how the system is structured:

                      ┌────────────────────────────────────────────┐
                      │           Cloud / IoT Platform              │
                      │ (e.g., Blynk, ThingSpeak, Adafruit IO)      │
                      │ - Receives data from system                 │
                      │ - Displays real-time status & alerts        │
                      └────────────────────────────────────────────┘
                                         ▲
                                         │ Wi-Fi / Internet
                                         ▼
               ┌────────────────────────────────────────────────────────┐
               │       Microcontroller (ESP32 / ESP8266 / Arduino)      │
               │ - Central control and processing unit                  │
               │ - Reads data from sensors                              │
               │ - Controls local alerts (buzzer, LEDs)                 │
               │ - Sends event data to IoT platform                     │
               └────────────────────────────────────────────────────────┘
                           ▲                              ▲
                           │                              │
          ┌────────────────┘                              └────────────────┐
          │                                                                 │
    ┌─────────────────────────────┐                             ┌──────────────────────────────┐
    │   Layer 1: Laser Detection  │                             │  Layer 2: Motion Detection   │
    │   - Laser & LDR / Photodiode│                             │  - PIR Sensor monitors area  │
    │   - Detects interruption of │                             │  - Detects movement/humans   │
    │     laser beam (perimeter)  │                             │    in monitored zone         │
    └─────────────────────────────┘                             └──────────────────────────────┘
          │                                                                 │
          ▼                                                                 ▼
       ┌────────────────────────────────────────────────────────────────────────┐
       │           Local Alert & Control Layer                                  │
       │ - Buzzer / Siren: audible alert when breach detected                   │
       │ - LED Indicators: visual signal (armed, triggered, safe)               │
       │ - Optional LCD/OLED: display system status                             │
       └────────────────────────────────────────────────────────────────────────┘
                                         │
                                         ▼
                       ┌────────────────────────────────────────────┐
                       │           Power Supply Layer               │
                       │ - Provides regulated 5V/3.3V DC power      │
                       │ - Supports battery backup or USB adapter   │
                       └────────────────────────────────────────────┘

### Description of Layers

1. **Sensor Layer**  
   - **Laser / optical sensor** monitors a light beam; if interrupted, it's a potential breach.  
   - **PIR / motion sensor** captures motion in the protected zone, adding redundancy.

2. **Control & Processing Layer**  
   - The **microcontroller** (e.g. ESP32 or Arduino + WiFi) continuously reads sensor signals.  
   - On detecting a breach (beam break or motion), it executes local actions and network communication.

3. **Alert / Actuation Layer**  
   - A **buzzer / siren** is sounded locally.  
   - LEDs or displays show status or breach signals.  
   - Optionally, a user interface or status display can be included.

4. **IoT / Communication Layer**  
   - The microcontroller sends data (alerts, logs) to a remote **cloud / server / dashboard** over WiFi.  
   - Users can monitor status or receive notifications remotely.

5. **Power Layer**  
   - Provides stable power (5 V, 3.3 V, etc.) to all modules.  
   - A battery backup or UPS can help in case of power cuts.

---

## Repository Structure


---

## Hardware Components

You will need (approximate):

| Component                     | Purpose                                  |
|-------------------------------|------------------------------------------|
| Microcontroller board (ESP32, ESP8266, or Arduino + WiFi) | Core unit to read sensors and send data |
| Laser emitter + photodiode / LDR / light sensor | For beam-break detection             |
| PIR motion sensor             | Detects human movement                   |
| Buzzer / siren                 | Produces audible alarm                    |
| LEDs (status indicators)      | Visual signals (armed, triggered)         |
| Resistors, wires, breadboard / PCB | Interconnect components             |
| Power supply (adapter / battery) | Power the system                      |
| Optional: transistor / driver | To drive high-current buzzer if needed     |

---

## Software & Libraries

In your `.ino` sketch, you’ll need the following:

- **WiFi library**:  
  - For ESP32: `#include <WiFi.h>`  
  - For ESP8266: `#include <ESP8266WiFi.h>`  
- Sensor libraries (if any) depending on the modules used  
- Network / communication library (e.g. MQTT client, HTTP client)  
- Standard Arduino core libraries (GPIO, delay, etc.)

Make sure you have installed the board support package in the Arduino IDE for your microcontroller (ESP32, ESP8266, etc.).

---

## Wiring & Connections

Here’s a general wiring guideline:

1. **Laser / optical sensor**  
   - Laser emitter: Vcc + GND  
   - Photodiode / light sensor: to analog/digital input of microcontroller (with pull-up/pull-down resistor as needed)

2. **PIR Motion Sensor**  
   - Vcc and GND  
   - Output to a digital input pin on the microcontroller

3. **Buzzer / Siren**  
   - Connect via a digital output pin  
   - Use a transistor / MOSFET if the current exceeds what the microcontroller pin can supply  
   - Include a diode if needed for inductive loads

4. **LED Indicators**  
   - Each LED with its series resistor to indicate system states (armed, triggered, etc.)

5. **Power Supply**  
   - Ensure common ground  
   - Provide stable voltage for microcontroller and sensors  
   - Add decoupling capacitors if needed

---

## Setup & Usage

1. Clone the repository:  
   ```bash
   git clone https://github.com/anirbanbose06-cpu/IOT-Based-Multilayer-Security-System.git

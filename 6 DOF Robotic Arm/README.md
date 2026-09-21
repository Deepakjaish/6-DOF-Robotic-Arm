# 🦾 6 DOF Robotic Arm with Bluetooth Control

<p align="center">
  <img src="Images/arm_main.jpg" alt="6 DOF Robotic Arm" width="600"/>
</p>
---

## 🚧 Current Project Status

> **This project is actively in progress.** Core functionality is working and the arm is operational. The following upgrades are pending and will be implemented shortly:

| Item | Status | Notes |
|---|---|---|
| Arduino Uno R3 | ✅ Installed | Main controller running |
| MG996R #1 — Shoulder joint | ✅ Installed | Link 1 rotation working |
| MG996R #2 — Shoulder joint | ✅ Installed | Link 2 rotation working |
| MG996R #3 — Base joint | ⏳ Pending | Not yet available — will be installed soon |
| 3× SG90 servos | ✅ Installed | Elbow, wrist, gripper working |
| HC-05 Bluetooth | ✅ Installed | Wireless control working |
| External battery/power supply | ⏳ Pending | Currently running on mobile charger (5V 2A) — dedicated external battery supply will be added |
| Full 6 DOF operation | ⏳ Pending | Will be complete once MG996R #2 and external power are installed |

> ⭐ **Star this repo to follow progress updates**

---

## 📌 Overview

A fully functional **6 Degree-of-Freedom robotic arm** designed from scratch in SolidWorks and built physically using 3D printed PLA parts, servo motors, and M3 hardware. The arm is controlled wirelessly from an Android smartphone via a Bluetooth HC-05 module and Arduino Uno.

This project covers the complete engineering cycle:
- **Mechanical design** in SolidWorks with full assembly
- **3D printing** and physical fabrication
- **Electronics wiring** with proper power management
- **Embedded C programming** for Bluetooth serial control

---

## ✨ Features

- 🔄 6 independent joint control — base, shoulder, elbow, wrist roll, wrist pitch, gripper
- ⚙️ Gear-driven gripper mechanism — designed from scratch in SolidWorks
- 📱 Wireless Android control via HC-05 Bluetooth module
- 🖥️ SolidWorks CAD with full assembly and mates
- 🖨️ Fully 3D printed PLA structure — STL files included
- 🔌 Safe dual power supply — servos on 5V 2A charger, Arduino on USB

---

## 🔧 Bill of Materials

| Component | Quantity | Purpose | Approx Cost (₹) |
|---|---|---|---|
| Arduino Uno R3 | 1 | Main microcontroller | ₹264 |
| MG996R servo motor | 2 ✅ + 1 ⏳ | Shoulder (installed) + Base (pending) | ₹680 |
| SG90 micro servo | 3 | Elbow, wrist, gripper — all installed | ₹255 |
| HC-05 Bluetooth module | 1 | Wireless smartphone control | ₹150 |
| Mobile charger 5V 2A | 1 | Current power supply — external battery pending | ₹0 (existing) |
| Mini breadboard | 1 | HC-05 voltage divider circuit | ₹30 |
| 1kΩ resistor | 1 | Voltage divider for HC-05 RX | ₹2 |
| 2kΩ resistor | 1 | Voltage divider for HC-05 RX | ₹2 |
| M3 screws assorted | 1 set | Structural assembly | ₹100 |
| M3 lock nuts + washers | 1 set | Pivot joints | ₹50 |
| Jumper wires | 1 pack | Wiring connections | ₹40 |
| PLA filament (printed) | ~280g | Arm structure and gripper | ₹2,248 |
| **Total** | | | **~₹3,821** |

---

## 🦿 Degrees of Freedom

| DOF | Joint | Servo | Arduino Pin | Range | Status |
|---|---|---|---|---|---|
| 1 | Base rotation | MG996R | Pin 9 | 0° – 180° | ✅ Working |
| 2 | Shoulder | MG996R | Pin 10 | 0° – 180° | ⏳ Servo pending |
| 3 | Elbow | SG90 | Pin 11 | 0° – 180° | ✅ Working |
| 4 | Wrist roll | SG90 | Pin 6 | 0° – 180° | ✅ Working |
| 5 | Gripper open/close | SG90 | Pin 5 | 5° – 80° | ✅ Working |

---

## 🔌 Wiring Diagram

<p align="center">
  <img width="2720" height="3600" alt="2mg996r_3sg90_wiring_diagram" src="https://github.com/user-attachments/assets/26cd0939-523f-4c15-a9d9-f674c94000c3" />

</p>

### Key Wiring Rules
- ⚠️ **Never power servos from Arduino 5V pin** — use the dedicated 5V 2A charger
- ⚠️ **Common GND is critical** — connect charger GND to Arduino GND pin
- ⚠️ **HC-05 RX needs voltage divider** — Arduino TX is 5V, HC-05 RX accepts 3.3V only
- ✅ HC-05 VCC connects to Arduino **3.3V pin** — not 5V

### Pin Summary
```
Arduino Pin 9   →  MG996R #1 signal  (base)
Arduino Pin 10  →  MG996R #2 signal  (shoulder)
Arduino Pin 11  →  SG90 #1 signal    (elbow)
Arduino Pin 6   →  SG90 #2 signal    (wrist)
Arduino Pin 5   →  SG90 #3 signal    (gripper)
Arduino Pin 0   →  HC-05 TX
Arduino Pin 1   →  HC-05 RX (via voltage divider)
Arduino 3.3V    →  HC-05 VCC
Arduino GND     →  HC-05 GND + charger GND (common)
Charger +5V     →  All servo red wires
Charger GND     →  All servo brown/black wires
```

---

## 💻 Software Setup

### Requirements
- Arduino IDE 2.x — [Download here](https://www.arduino.cc/en/software)
- Servo library — built into Arduino IDE (no install needed)
- SoftwareSerial library — built into Arduino IDE (no install needed)

### Upload Steps
```
1. Open Arduino IDE
2. Open Code/arm_bluetooth.ino
3. Select Tools → Board → Arduino Uno
4. Select Tools → Port → your COM port
5. Click Upload button
6. Wait for "Done uploading"
```

### Bluetooth App Setup
```
1. Download "Bluetooth Serial Controller" on Android — free on Play Store
2. Enable Bluetooth on phone → pair with HC-05
   Default password: 1234
3. Open app → connect to HC-05
4. Map buttons to these commands:
   Button A → send 'A'  (base left)
   Button B → send 'B'  (base right)
   Button C → send 'C'  (shoulder up)
   Button D → send 'D'  (shoulder down)
   Button E → send 'E'  (elbow up)
   Button F → send 'F'  (elbow down)
   Button G → send 'G'  (wrist up)
   Button H → send 'H'  (wrist down)
   Button I → send 'I'  (gripper close)
   Button J → send 'J'  (gripper open)
```

---

## 🖨️ CAD Design and 3D Printing

### SolidWorks Design
- Designed in **SolidWorks 2026 SP2.1**
- Full assembly with mates — fully defined, zero errors
- Gear-driven gripper with LimitAngle mate (5° to 80°) and GearMate
- All parts fully constrained before sending to print

<p align="center">
  <img width="337" height="245" alt="Screenshot 2026-07-25 191840" src="https://github.com/user-attachments/assets/832a6c54-67a0-4601-b0d0-f71658de05b5" />
</p>

### Print Settings (give to print shop)
```
Material:       PLA
Layer height:   0.2mm  (0.15mm for gears)
Infill:         40%    (60% for gears only)
Walls:          4 perimeters minimum
Supports:       Yes — tree supports where needed
Bed adhesion:   Brim 5mm
Print speed:    40-50mm/s maximum
```

### Printed Parts List
```
gripper_base_link.stl     × 1
gear_1.stl                × 2  (left and right)
gripper_link_1.stl        × 2  (left and right fingers)
gripper_link_2.stl        × 2  (left and right connectors)
[remaining arm parts]
```

---

## 🔨 Physical Assembly Order

```
Step 1  →  Assemble gripper — test open/close by hand
Step 2  →  Mount gripper to wrist servo
Step 3  →  Build wrist assembly and attach to forearm
Step 4  →  Build forearm and attach to elbow servo
Step 5  →  Build upper arm and attach to shoulder servo
Step 6  →  Mount to base with base rotation servo
Step 7  →  Wire all servos and HC-05 per wiring diagram
Step 8  →  Upload code
Step 9  →  Test each joint one by one before full operation
```

---

## 📐 Mathematics Behind the Arm

This project introduced me to the core robotics mathematics:

| Concept | Application |
|---|---|
| **Trigonometry** | Joint angle calculations, atan2 for position |
| **Forward Kinematics** | Given joint angles → find gripper position |
| **Inverse Kinematics** | Given target position → find joint angles |
| **Denavit-Hartenberg Parameters** | Systematic arm description method |
| **PWM signals** | 1ms–2ms pulse = 0°–180° servo control |
| **Gear ratio** | Gripper force and travel calculation |

---

## 🧠 Skills Demonstrated

```
Hardware:     Arduino Uno, MG996R, SG90, HC-05, servo drivers
Software:     Embedded C, Arduino IDE, SolidWorks 2026
Protocols:    UART (Bluetooth serial), PWM (servo control)
CAD:          Part design, assembly, mates, constraint definition
Fabrication:  3D printing, M3 hardware assembly, PLA prototyping
Concepts:     GPIO, PWM, kinematics, gear mechanisms, robotics
```

---

## 📁 Repository Structure

```
6DOF-Robotic-Arm-Bluetooth/
├── CAD/
│   ├── gripper_base_link.SLDPRT
│   ├── gripper_link_1.SLDPRT
│   ├── gripper_link_2.SLDPRT
│   ├── gear_1.SLDPRT
│   ├── assembly_screenshot.png
│   └── STL/
│       ├── gripper_base_link.stl
│       ├── gear_1_left.stl
│       ├── gear_1_right.stl
│       ├── gripper_link_1_left.stl
│       ├── gripper_link_1_right.stl
│       ├── gripper_link_2_left.stl
│       └── gripper_link_2_right.stl
├── Code/
│   └── arm_bluetooth.ino
├── Images/
│   ├── arm_main.jpg
│   ├── arm_side.jpg
│   ├── gripper_close.jpg
│   └── wiring_setup.jpg
├── Wiring/
│   └── wiring_diagram.png
└── README.md
```

---

## 🚀 Upcoming and Future Improvements

### Pending Hardware (Coming Soon)
- [ ] Install MG996R #2 servo on shoulder joint — ordered, arriving soon
- [ ] Replace mobile charger with dedicated external battery supply (LM2596 buck converter + 9V battery) for full portability
- [ ] Test full 6 DOF operation with all joints active simultaneously

### Future Upgrades
- [ ] Add PCA9685 servo driver for cleaner wiring with all 6 DOF active
- [ ] Implement inverse kinematics in Arduino code
- [ ] Add position feedback with potentiometers for closed-loop control
- [ ] Build custom Android app with joystick control
- [ ] Upgrade to STM32 for faster processing
- [ ] Add computer vision for autonomous pick and place

---

## 👤 About

**[Deepak Jaish]**
3rd Year Automation & Robotics Engineering Student
[University School of Automation & Engineering], Delhi

[![LinkedIn][(https://img.shields.io/badge/LinkedIn-Connect-blue?style=flat-square&logo=linkedin)](YOUR_LINKEDIN_URL)](https://www.linkedin.com/in/deepak-jaish-a46a1b376/)
[![GitHub][(https://img.shields.io/badge/GitHub-Follow-black?style=flat-square&logo=github)](YOUR_GITHUB_URL)](https://github.com/)

---

## 📄 License

This project is open source under the MIT License.
Feel free to use, modify, and build upon it.

---

<p align="center">
  Built with ❤️ as part of my embedded systems and robotics learning journey
</p>

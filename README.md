# 🚀 Design and Implementation of a Microcontroller-Based Speed Control System for a DC Motor Using a Three-Phase AC Supply  

![Hardware](https://img.shields.io/badge/Hardware-Electronics-blue?style=for-the-badge&logo=hackaday) 
![Software](https://img.shields.io/badge/Software-Tools-green?style=for-the-badge&logo=github) 
![Microcontroller](https://img.shields.io/badge/STM32-MCU-lightgrey?style=for-the-badge&logo=arm) 
![MATLAB](https://img.shields.io/badge/MATLAB-Simulation-orange?style=for-the-badge&logo=mathworks) 

---

## 📖 Project Overview  
This project focuses on the **design and implementation of a microcontroller-based system** to control the speed of a **DC motor** powered by a **three-phase AC supply**.  
The work involves:  
- Conversion of three-phase AC into a variable DC supply  
- Speed control strategies using microcontroller  
- Measurement and monitoring of motor speed  
- Closed-loop feedback implementation  

---

## 📝 Problem Statements  
The project is divided into three main problem areas:  

1. **Problem 1:**  
   [View Document](https://docs.google.com/document/d/1jismQVmJ2xTGl6kcEOOyZwChlzPkZLgF/edit?usp=sharing&ouid=112146480935061970223&rtpof=true&sd=true)  

2. **Problem 2:**  
   [View Document](https://docs.google.com/document/d/1Ge7Az897FzeVD9xJ1EdhM5dMWKOpNZCw/edit?usp=sharing&ouid=112146480935061970223&rtpof=true&sd=true)  

3. **Problem 3:**  
   [View Document](https://docs.google.com/document/d/1f6BGSJ3D3NMmxlI-MNt4v6Lp3DVv5Vy_/edit?usp=sharing&ouid=112146480935061970223&rtpof=true&sd=true)  

---

## ⚙️ Methods and Analysis  

### 1️⃣ Methods of Speed Control of a DC Motor  

| Method | Advantages | Disadvantages |
|--------|------------|---------------|
| **Armature Voltage Control** | Wide speed range below rated, efficient, smooth control | Needs controlled DC supply, limited above rated |
| **Field Flux Control** | Simple, allows above-rated speed, low field power | Reduced torque at weak field, limited range |
| **Armature Resistance Control** | Simple, low cost | Inefficient, heat losses, poor regulation |

---

### 2️⃣ Methods of Conversion of Three-Phase AC to Variable DC  

| Method | Advantages | Disadvantages |
|--------|------------|---------------|
| **Phase-Controlled Rectifier** | High power capacity, cost-effective | Harmonics, poor power factor, ripple |
| **Rectifier + DC-DC Chopper** | Smooth DC, efficient, accurate | Complex, costly, fast switching needed |
| **PWM Controlled Systems** | Precise, efficient, low distortion | Expensive, requires DSP/microcontroller |

---

### 3️⃣ Measurement of DC Motor Speed Using Microcontroller  

- **Optical Encoder:** High accuracy, digital pulse counting  
- **Hall Effect Sensor:** Reliable, compact, magnetic pulse detection  
- **Tachometer:** Direct measurement, analog → ADC input  
- **Back EMF Estimation:** Simple, low cost but less accurate  

**Pros of Microcontroller-Based Measurement:**  
✅ Real-time monitoring  
✅ Easy display integration  
✅ Enables closed-loop feedback  

**Cons:**  
❌ Requires calibration  
❌ Noise sensitive  
❌ Extra hardware sensors needed  

---

## 🛠️ Hardware  

| 🔢 S. No. | 🔧 Component / Equipment | 📐 Specification | 🛒 Source |
|-----------|--------------------------|------------------|-----------|
| 1 | Vero Board | Standard | Co-operative Market |
| 2 | Screw Connectors | 2-pin / 3-pin | Co-operative Market |
| 3 | Diodes | 3A | Co-operative Market |
| 4 | Resistors | 1% Tolerance | Co-operative Market |
| 5 | Load Resistance | 8.2 Ω, 10W | Co-operative Market |
| 6 | Inductor | 6.8 mH | Co-operative Market |
| 7 | Pin Male Headers | Standard | Co-operative Market |
| 8 | Transformer | 220V → 12-12V, 1A | Co-operative Market |
| 9 | Thyristors | BT151, C106 | Co-operative Market |
| 10 | ARM Controller | STM32F401 | Co-operative Market |
| 11 | Programmer | ST-LINK V2 (for STM32) | Co-operative Market |
| 12 | Capacitors | 330µF, 1000µF, 470µF | Co-operative Market |
| 13 | MOSFET Module | Standard | Co-operative Market |

---

## 💻 Software  

| 🔢 S. No. | 🖥️ Software | 🌐 Source |
|-----------|-------------|-----------|
| 1 | Multisim | National Instruments (NI) |
| 2 | Arduino IDE | [Arduino Official Website](https://www.arduino.cc/en/software) |
| 3 | MATLAB | University Campus License / Student Access |

---

## 📊 Results & Observations
- Motor speed vs. voltage characteristics
- Control response (rise time, overshoot, settling time)
- Efficiency analysis
- Comparative study of control methods

---

## 🔮 Future Work
- Multi-motor support
- Fuzzy logic / AI-based controllers
- Wireless monitoring & IoT integration
- Improved thermal management

---

## 🙏 Acknowledgements  

- **Project Instructor:** Dr. Javed  
- **Team Lead:** Muhammad Taha  
- **Collaborators:** Farzam Shaikh, Ali Nasir, Maaz Adil  
- **Institution:** NED University, Electrical Engineering Department  

---

## ✍️ Author  

**Muhammad Taha**  
- 🌐 Portfolio: [thetahaansari.github.io/mappe](https://thetahaansari.github.io/mappe/)  
- 💼 LinkedIn: [linkedin.com/in/muhammad-taha-b93716299](https://www.linkedin.com/in/muhammad-taha-b93716299/)  
- 🔗 GitHub: [github.com/Muhammad-Taha-Ansari](https://github.com/Muhammad-Taha-Ansari)  

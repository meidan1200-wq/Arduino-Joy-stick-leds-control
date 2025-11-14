# 🕹️ Arduino Joystick 6-LED Direction Indicator

An interactive Arduino project where a **joystick controls six LEDs** — each LED lights up depending on which **direction the joystick is moved** 🎮💡

You can move the joystick **upwards, backwards, and diagonally (corners)** — and each direction activates a specific LED.  

This version also includes **push‑button functionality**:\
➡️ **Pressing the joystick button lights up *all* six LEDs at once.**

---

## 🧠 How It Works

The joystick module sends analog signals (X and Y axes) to the Arduino.  
Depending on the direction, the Arduino turns on one of **six LEDs**:

| Joystick Direction | LED Activated |
|--------------------|----------------|
| ⬆️ Forward         | Top LED 🔺      |
| ⬇️ Backward        | Bottom LED 🔻   |
| ↗️ Forward-Right   | Top-Right LED    |
| ↖️ Forward-Left    | Top-Left LED     |
| ↘️ Backward-Right  | Bottom-Right LED |
| ↙️ Backward-Left   | Bottom-Left LED  |

When the joystick is centered, **all LEDs are off**.

---

## ⚙️ Hardware Setup

### 🔩 Components
- Arduino Uno (or compatible board)
- 1 Joystick module 🕹️
- 6 LEDs (any color)
- 6 Resistors (220Ω–330Ω)
- Breadboard + Jumper wires

### 🔌 Circuit
- Connect the joystick’s **VRx** to **A0** and **VRy** to **A1** on the Arduino.
- Each LED connects to a digital output pin (e.g., pins **2–7**).  
- Use resistors in series with LEDs to limit current.

![Circuit Diagram](https://github.com/meidan1200-wq/Arduino-Joy-stick-leds-control/blob/main/ref_circuit/circuit.png?raw=true) 

💡 **Tip:** Ensure all GND connections (joystick and LEDs) share a common ground with the Arduino.

---

## 💻 Running the Project

### 🧰 Option 1 – Using Arduino IDE
1. Open the folder:  
   `ArduinoVersion/Joystick6LED/Joystick6LED.ino`
2. Select your board (e.g., Arduino Uno) and correct COM port.
3. Click **Upload** (➡️) to flash the program.
4. Move the joystick — LEDs will light up based on direction!

### ⚡ Option 2 – Using PlatformIO (VS Code)
1. Open the folder `Joystick6LED/` in **VS Code** with PlatformIO.
2. Connect your board via USB.
3. Build and upload the code:  
   - 🧱 **Build:** Click ✔️  
   - 🚀 **Upload:** Click →  
4. The joystick now controls all six LEDs interactively.

---

## 🕹️ Demo
Move the joystick to see different LED responses:
- ⬆️ → Forward LED lights up  
- ⬇️ → Backward LED lights up  
- ↗️ / ↖️ / ↘️ / ↙️ → Corner LEDs light up
-   🔘 Button Press → **All LEDs ON**\  
- 🔘 Center → All LEDs off  

Try smooth diagonal movements for combined LED effects 🔄

---

## 📘 License
This project is open-source and free for personal and educational use.

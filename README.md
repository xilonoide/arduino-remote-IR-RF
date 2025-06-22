# 🎛️ Arduino Remote IR & RF

![Arduino](https://img.shields.io/badge/Platform-Arduino-blue)
![License](https://img.shields.io/badge/License-MIT-green)
![Nano](https://img.shields.io/badge/Board-Nano-orange)

---

## 📖 Description

**arduino-remote-IR-RF** is a project to turn an **Arduino Nano** into a universal remote control using **infrared (IR)** and **433 MHz radio frequency (RF)** signals.

This device can:

- 📡 Read signals from existing IR and RF remote controls.  
- 📤 Transmit those signals to control compatible devices.  
- ⚙️ Configure custom devices.  
- 🎭 Create and combine **"scenes"**, groups of commands for multiple devices.

---

## 🎯 Key Features

- **IR & RF signal capture:** Detect and learn real remote control signals.  
- **IR & RF signal emission:** Reproduce those signals to control devices.  
- **Custom scenes:**  
  Each scene has two functions:  
  - 🔆 Turn ON  
  - 🌙 Turn OFF  
  
  Scenes can group commands for multiple devices, such as air conditioning, TV, lights, etc.

---

## 🛠️ Requirements

- Arduino Nano  
- IR receiver module  
- IR emitter  
- 433 MHz RF module (transceiver or transmitter + receiver)  
- Arduino libraries for IR and RF (`IRremote`, `RC-Switch`)

---

## 🚀 Installation & Usage

1. Connect the Arduino Nano and the IR and RF modules according to the project schematic.  
2. Upload the firmware to the Arduino using the Arduino IDE.  
3. Use the serial monitor to capture signals from your current remotes.  
4. Define custom devices and scenes.  
5. Send commands from the Arduino to control your devices.

---

## ❤️ Contributions

Contributions are welcome!  
Feel free to open issues for suggestions or bug reports, and send pull requests.

---

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file.

---

## 📬 Contact

If you have questions or want to collaborate, contact me via GitHub or email.

---

Thank you for using **arduino-remote-IR-RF**!  
Make your Arduino an all-in-one universal remote! 🚀✨

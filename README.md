# 🌡️ Temperature Converter - C++ Console Application

A simple and structured **console-based Temperature Converter** built using C++.

This project focuses on applying **clean code practices, input validation, and modular design** while handling real-world unit conversions.

---

## 🚀 Features

- 🔄 Convert between:
  - Celsius ↔ Fahrenheit  
  - Celsius ↔ Kelvin  
  - Fahrenheit ↔ Kelvin  
- 🔢 User-friendly input system  
- ✅ Strong input validation  
- 🔁 Continuous conversion loop  
- 🎯 Clean formatted output using `iomanip`  

---

## 🧠 Core Concepts Applied

- **Enums (`enum`)** for representing temperature types safely  
- **Structs (`struct`)** to group conversion data  
- **Modular function design** (clear separation of concerns)  
- **Input validation techniques** using:
  - `cin.clear()`
  - `cin.ignore()`  
- **Switch-case logic** for handling multiple conversion paths  

---

## ⚙️ How It Works

1. User selects the temperature unit to convert **from**
2. User selects the unit to convert **to**
3. User enters a numeric value
4. Program performs the conversion and displays the result
5. User can repeat or exit

---

## 🛠️ How to Run

### Compile:
```bash
g++ -std=c++11 Tempuratue-Changer.cpp -o converter
./converter

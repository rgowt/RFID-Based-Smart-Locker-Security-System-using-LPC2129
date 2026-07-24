# RFID Based Smart Locker Security System using LPC2129

## 📌 Project Overview

This project is an **RFID-based Smart Locker Security System** developed using the **LPC2129 (ARM7)** microcontroller. The system provides **two-level authentication** by combining an RFID card and a 4×4 keypad password.

If an unauthorized person attempts to access the locker by entering the wrong password three times, the system locks itself, activates a buzzer, and sends an SMS alert through a GSM module.

---

## 🚀 Features

- RFID Card Authentication
- 4×4 Matrix Keypad Password Verification
- 16x2 LCD Display for User Interface
- DC Motor Control for Locker Door
- GSM SMS Alert for Unauthorized Access
- Buzzer Alarm after 3 Wrong Password Attempts
- Two-Level Security (RFID + Password)

---

## 🛠 Hardware Components

- LPC2129 ARM7 Microcontroller
- RFID Reader (UART)
- RFID Card/Tag
- 4×4 Matrix Keypad
- 16×2 LCD Display
- GSM Module (SIM800/SIM900)
- DC Motor
- Motor Driver
- Buzzer
- Power Supply

---

## 💻 Software Used

- Keil µVision
- Embedded C
- Flash Magic (for programming)
- LPC21xx Library

---

## 📂 Project Structure

```
Project
│
├── main.c              # Main application
├── rfid.c              # UART0 RFID functions
├── keypad.c            # Keypad scanning
├── lcd_display.c       # LCD driver
├── GSM.c               # GSM SMS functions
├── delay.c             # Timer delay
│
├── lcd_display.h
├── keypad.h
├── rfid.h
├── GSM.h
├── delay.h
│
└── README.md
```

---

## 🔄 System Flow

```
Start
   │
   ▼
Initialize LCD
Initialize UART0 (RFID)
Initialize UART1 (GSM)
   │
   ▼
Scan RFID Card
   │
   ├── Invalid Card
   │      │
   │      ▼
   │   Display "Invalid Card"
   │
   └── Valid Card
          │
          ▼
    Enter Password
          │
     ┌────┴─────┐
     │          │
Correct      Wrong
     │          │
     ▼          ▼
Motor ON   Increase Count
                │
                ▼
      Wrong Attempts = 3 ?
             │
      ┌──────┴──────┐
      │             │
     No            Yes
      │             │
      ▼             ▼
Retry        System Locked
                  │
                  ▼
           GSM SMS Alert
                  │
                  ▼
              End
```

---

## 🔐 Working Principle

1. System waits for an RFID card.
2. The RFID tag is compared with the stored ID.
3. If the RFID card is valid, the user is asked to enter a 4-digit password.
4. If the password is correct:
   - LCD displays success.
   - DC motor is activated to unlock the locker.
5. If the password is incorrect:
   - Attempt counter increases.
6. After three wrong attempts:
   - System is locked.
   - GSM module sends an SMS alert.
   - Buzzer can be activated.

---

## 📱 GSM Alert Message

```
UNAUTHORISED PERSON ACCESS YOUR LOCKER
```

---

## 📟 LCD Messages

```
SCAN RFID CARD...

VALID CARD.....

ENTER PASS

PASSWORD CORRECT

PASSWORD INCORRECT

YOUR SYSTEM IS
LOCKED....

INVALID CARD.....
```

---

## ⚙ Pin Configuration

### LCD

| LCD | LPC2129 |
|------|----------|
| D0-D7 | P0.10 - P0.17 |
| RS | P0.18 |
| EN | P0.19 |

### RFID

| Device | LPC2129 |
|---------|----------|
| TX/RX | UART0 |

### GSM

| Device | LPC2129 |
|---------|----------|
| TX/RX | UART1 |

### Motor

| Pin | Function |
|------|----------|
| P0.6 | Motor Input 1 |
| P0.7 | Motor Input 2 |

### Buzzer

| Pin | Function |
|------|----------|
| P0.21 | Buzzer |

### Keypad

Rows:
- P1.27
- P1.28
- P1.29
- P1.30

Columns:
- P1.23
- P1.24
- P1.25
- P1.26

---

## 🔧 Technologies Used

- Embedded C
- LPC2129 ARM7
- UART Communication
- Timer Programming
- LCD Interfacing
- Keypad Interfacing
- RFID Communication
- GSM AT Commands

---

## 📚 Learning Outcomes

- ARM7 LPC2129 Programming
- UART0 & UART1 Communication
- RFID Integration
- GSM SMS Communication
- LCD Interfacing
- Matrix Keypad Scanning
- Embedded C Programming
- Timer Delay Implementation

---

## 👨‍💻 Author

**Gowtham**

Embedded Systems Enthusiast

---

## 📄 License

This project is open-source and available for educational purposes.

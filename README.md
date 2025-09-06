# RISC-V Assembler

This project implements an **Assembler** and a **Simulator** for the **4-bit K2 Microprocessor** in C.  
It demonstrates fundamental concepts of **computer architecture**, **assembly translation**, and **processor simulation**.

---

## 📖 Overview
The project consists of:
- **Assembler** → Converts K2 ISA assembly (`.asm`) files into machine code (`.bin`).
- **Simulator** → Loads and executes machine code on a modeled K2 processor.
- **Example Program** → Fibonacci sequence generator written in K2 assembly.
- **Makefile** → For easy compilation and execution.

---

## ⚙️ Features
- Supports the following instruction set:
  - `RA = RA + RB` → Add registers and store result in RA
  - `RB = RA + RB` → Add registers and store result in RB
  - `RA = RA - RB` → Subtract RB from RA
  - `RB = RA - RB` → Subtract RB from RA
  - `RO = RA` → Move RA into output register
  - `RA = imm` → Load immediate value into RA
  - `RB = imm` → Load immediate value into RB
  - `Jump carry imm` → Jump if carry flag set
  - `Jump imm` → Unconditional jump

---

## 🖥️ Architecture
The **K2 Microprocessor** is a simple **4-bit microprocessor** supporting:
- Two general-purpose registers (`RA`, `RB`)
- One output register (`RO`)
- Basic arithmetic, data transfer, and control flow instructions.

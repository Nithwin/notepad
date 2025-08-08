# 📝 Nithwin's Notepad

A minimal yet elegant Notepad clone built with **C++**, **Qt Framework**, and **CMake**. Designed for simplicity and speed, this application allows users to write, edit, and manage text files with a beautiful and clean user interface — just like Windows Notepad, but with a personal touch.

![Screenshot](https://github.com/user-attachments/assets/0c3aa71f-267a-4104-a0e6-17f0348827c9)

---

## 🚀 Features

- 🖊️ Clean and distraction-free text editor
- 💾 Save and open `.txt` files
- 🪟 Custom window styling using Qt stylesheets
- 🖥️ Maximized window by default for better focus
- 🧠 Automatically updates window title based on file
- 📂 Navigation support for multiple file actions

---

## 🔧 Tech Stack

- **Language**: C++
- **GUI Framework**: Qt (Widgets)
- **Build System**: CMake

---

## 🛠️ How to Build & Run

### 🔄 Prerequisites

Make sure the following are installed:

- Qt (5 or 6)
- CMake (>= 3.15)
- C++ Compiler (G++, Clang, MSVC, etc.)

### 📦 Build Instructions

```bash
# Clone the repository
git clone https://github.com/yourusername/notepad-app.git
cd notepad-app

# Create build directory
mkdir build && cd build

# Generate build files using CMake
cmake ..

# Build the app
cmake --build .

# Run the application
./NithwinNotepad

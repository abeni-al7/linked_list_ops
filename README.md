# Linked List Manager with File Persistence

A C++ implementation of a linked list with file storage capabilities, featuring comprehensive operations and robust error handling.

## 📑 Table of Contents
- [Introduction](#-introduction)
- [Features](#-features)
- [Prerequisites](#-prerequisites)
- [Usage](#-usage)
- [Example Usage](#-example-usage)
- [File Format](#-file-format)

## 🌟 Introduction

This console-based application provides complete linked list management with:
- **File persistence** using `linked_list_data.txt`
- **10 core operations** with intuitive menu interface
- **Error-resistant design** with input validation
- **Real-time visualization** of list structure
- Automatic state preservation between sessions

Built using C-style structs and standard file handling (`fstream`), following C compatibility constraints.

## 🚀 Features

### Core Operations
- **Insertion**  
  ↳ Beginning ∙ End ∙ Specific Position  
- **Deletion**  
  ↳ By Value ∙ By Position  
- **Search & Update**  
  ↳ Value Existence Check ∙ Value Modification  
- **List Management**  
  ↳ Full Reversal ∙ Node Counting ∙ Visual Display

### Enhanced Features
- 🛡️ Robust input validation
- 📂 Automatic file synchronization
- 📊 Visual list representation with node arrows
- 🔄 Undo-safe operations (through file persistence)
- 📍 Position-aware error messages
- 💾 Zero-configuration data management

## 🛠️ Prerequisites

- C++ Compiler (GCC/MinGW/Clang)
```bash
# Linux
sudo apt install g++

# Windows (MinGW)
https://sourceforge.net/projects/mingw/
```

## 📖 Usage

# Compilation
```bash
g++ linked_list.cpp -o linkedlist.exe
```
# Execution
```bash
# Linux/macOS
./linkedlist.exe

# Windows
linkedlist.exe
```
# Data File
- Auto-created at first run as linked_list_data.txt
- Format: Space-separated integer values
- Location: Same directory as executable

## 🔍 Example Usage
# Scenario 1: New List Creation
```plaintext
========================================
▶ INITIALIZATION
========================================
🆕 Creating new linked list
🔢 Enter number of initial items: 3
🔢 Item 1: 5
🔢 Item 2: 12
🔢 Item 3: 8
✅ Created list with 3 items

========================================
▶ CURRENT LINKED LIST
========================================
[5] → [12] → [8] → NULL
```
# Scenario 2: Existing List Modification
```plaintext
========================================
▶ MAIN MENU
========================================
🔢 Enter your choice (1-11): 1
🔢 Enter value to insert: 10
✅ Added 10 at beginning

========================================
▶ CURRENT LINKED LIST
========================================
[10] → [5] → [12] → [8] → NULL

========================================
▶ MAIN MENU
========================================
🔢 Enter your choice (1-11): 5
🔢 Enter position to delete: 2
✅ Deleted node at position 2

========================================
▶ CURRENT LINKED LIST
========================================
[10] → [5] → [8] → NULL
```
## 📄 File Format
linked_list_data.txt contents after above operations:
```text
10 5 8
```


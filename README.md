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
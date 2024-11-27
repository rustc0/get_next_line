# Get Next Line

**Get Next Line** (GNL) is a project designed to implement a function that reads a line ending with a newline character (`\n`) 
from a file descriptor, without knowing the file size beforehand. This function is an essential utility for handling input in a variety of real-world programming scenarios. The goal is to create a reliable, efficient, and reusable implementation.

## Table of Contents

- [Features](#features)  
- [Understanding the Function](#understanding-the-function)  

---

## Features

- **Handles multiple file descriptors:** Simultaneously reads from multiple files.  
- **Dynamic Buffer Management:** Supports varying buffer sizes for optimal performance.  
- **Error Handling:** Ensures stability when encountering edge cases or invalid inputs.  
- **Portability:** Compatible with both Linux and macOS.  

---

## Understanding the Function

**`get_next_line(int fd)`** works by:
1. Reading from the file descriptor in chunks of size `BUFFER_SIZE`.
2. Storing leftover data between function calls in a static variable.
3. Splitting the content into lines based on the newline character (`\n`).
4. Returning each line dynamically allocated as a null-terminated string.

---

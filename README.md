### 🛒 Order Management System  

This is a simple **Order Management System** implemented in **C++**, which allows users to place, complete, and view pending orders. It uses **a circular queue** for efficient order management, ensuring FIFO (First-In, First-Out) processing.  

---

## 📌 Features  
✔️ **Place an Order** – Users can add an order with an order ID, item name, and quantity.  
✔️ **Complete an Order** – The oldest order is processed and removed from the queue.  
✔️ **View Pending Orders** – Displays all the orders currently in the queue.  
✔️ **Predefined Item List** – Users can choose from a list of available items.  

---

## 🔧 Data Structure Used  

### **Circular Queue (Array-Based Implementation)**  
The core data structure in this project is a **circular queue**, implemented using a fixed-size array. It efficiently manages orders using two pointers:  
- _**front**_ – Tracks the first element in the queue.  
- _**rear**_ – Tracks the next available position for a new order.  

#### **Why Circular Queue?**  
🔹 **Prevents Wasted Space:** A normal queue implementation would lead to unused spaces as elements are dequeued. A circular queue ensures space is reused efficiently.  
🔹 **Fast Operations:** Both `enqueue` (adding an order) and `dequeue` (processing an order) work in **O(1)** time complexity.  

#### **Circular Queue Implementation Details**  
- **Enqueue Operation:**  
  - Checks if the queue is full.  
  - Adds the order at _**rear**_ and updates _**rear**_ in a circular manner using _(rear + 1) % MAX_SIZE_.  
- **Dequeue Operation:**  
  - Checks if the queue is empty.  
  - Removes the order from `front` and updates _**front**_ in a circular manner using _(front + 1) % MAX_SIZE_.  
- **Display Operation:**  
  - Iterates from `front` to `rear` and prints each order's details.  

---

## 🎯 Future Enhancements  
- ✅ Increase the queue size dynamically using **linked list implementation** instead of a fixed-size array.  
- ✅ Implement a **priority queue** for handling urgent orders.  
- ✅ Add a **file-based order log** for tracking processed orders.  

---

## 📜 License  
This project is open-source under the **MIT License**.  

---

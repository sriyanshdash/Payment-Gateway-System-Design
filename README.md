# Payment-Gateway-System-Design
A mock backend system design with CLI-based API simulation (/pay, /refund, /status) and architectural documentation.

# 💳 System Design Mock Project: Payment Gateway Backend

## 🔍 Overview
This is a mock system design and CLI simulation of a Payment Gateway backend (like Razorpay or PayPal), built for educational and interview preparation purposes. The project includes system design documentation, CLI simulation in C++, API reference, and guidance for architectural diagrams.

---

## 🧱 Project Components

| Component               | Description                             |
|-------------------------|-----------------------------------------|
| ✅ CLI Simulation        | Simulates /pay, /status, and /refund    |
| ✅ System Design PDF     | High-level architecture and specs       |
| ✅ API Documentation     | Markdown-based REST API docs            |
| ✅ Architecture Diagram  | Visual overview of system components    |

---

## 🧪 How to Run the CLI Simulation

### 🔧 Compile
```bash
g++ main.cpp transaction.cpp -o gateway
./gateway
```

### 💡 Operations
- `/pay` → Create a new payment transaction
- `/status` → Check transaction status
- `/refund` → Refund an existing transaction

All transactions are stored in `transactions.txt`.

---

## 📘 API Reference

For detailed request/response format, see [`API_DOCUMENTATION.md`](./API_DOCUMENTATION.md)

---

## 📄 System Design Document

For architectural overview and component responsibilities, see [`System_Design_Payment_Gateway.pdf`](./System_Design_Payment_Gateway.pdf)

---

## 🌍 License

MIT License


# 📘 Payment Gateway API Documentation

This document defines the simulated REST API endpoints used in the Payment Gateway System Design Mock Project.

---

## 🔐 Authentication
- All endpoints require a valid `userToken` or `merchantId`.
- In the CLI simulation, these are entered as plain text (no auth logic).

---

## 🚀 API Endpoints

### ✅ POST /pay
Initiates a payment transaction.

- **Input (JSON/CLI equivalent):**
```json
{
  "userToken": "USER123TOKEN",
  "merchantId": "MRC987",
  "amount": 450.50
}
```

- **Response:**
```json
{
  "transactionId": "TX382901",
  "status": "SUCCESS"
}
```

---

### 📊 GET /status/:transactionId
Checks the status of a given transaction.

- **Input:**
```
/status/TX382901
```

- **Response:**
```json
{
  "transactionId": "TX382901",
  "status": "SUCCESS"
}
```

---

### 🔁 POST /refund
Refunds an existing successful transaction.

- **Input (JSON/CLI):**
```json
{
  "transactionId": "TX382901"
}
```

- **Response:**
```json
{
  "transactionId": "TX382901",
  "status": "REFUNDED"
}
```

---

## 📦 Status Codes

| Code     | Meaning               |
|----------|------------------------|
| SUCCESS  | Payment completed      |
| REFUNDED | Refund successful      |
| PENDING  | Awaiting confirmation  |
| FAILED   | Transaction error      |

---

## 🛡️ Security Notes (Mock CLI Version)
- In the full design, use:
  - Token-based authentication
  - API key validation for merchants
  - HTTPS communication
  - Rate limiting via gateway

---

## 🧪 CLI Simulation Notes
- User input replaces API body
- `transactions.txt` acts as backend DB
- Status changes are simulated, not networked

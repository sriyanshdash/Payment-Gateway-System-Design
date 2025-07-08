#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "transactions.h"

std::vector<Transaction> transactions;

// Load from file
void loadTransactions() {
    std::ifstream file("transactions.txt");
    if (!file) return;
    std::string line;
    while (getline(file, line)) {
        Transaction tx;
        tx.deserialize(line);
        transactions.push_back(tx);
    }
    file.close();
}

// Save to file
void saveTransactions() {
    std::ofstream file("transactions.txt");
    for (auto& tx : transactions) {
        file << tx.serialize() << "\n";
    }
    file.close();
}

// Generate random transaction ID
std::string generateId() {
    std::stringstream ss;
    ss << "TX" << std::rand() % 1000000;
    return ss.str();
}

// Simulate /pay
void pay() {
    std::string token, merchant;
    double amount;
    std::cin.ignore();
    std::cout << "Enter user token: ";
    getline(std::cin, token);
    std::cout << "Enter merchant ID: ";
    getline(std::cin, merchant);
    std::cout << "Enter amount: ₹";
    std::cin >> amount;

    std::string tid = generateId();
    Transaction tx(tid, token, merchant, amount, "SUCCESS");

    transactions.push_back(tx);
    saveTransactions();

    std::cout << "✅ Payment Successful. Transaction ID: " << tid << "\n";
}

// Simulate /status
void checkStatus() {
    std::string tid;
    std::cin.ignore();
    std::cout << "Enter Transaction ID: ";
    getline(std::cin, tid);

    for (auto& tx : transactions) {
        if (tx.getId() == tid) {
            std::cout << "📊 Status: " << tx.getStatus() << "\n";
            return;
        }
    }
    std::cout << "❌ Transaction not found.\n";
}

// Simulate /refund
void refund() {
    std::string tid;
    std::cin.ignore();
    std::cout << "Enter Transaction ID to refund: ";
    getline(std::cin, tid);

    for (auto& tx : transactions) {
        if (tx.getId() == tid) {
            tx.setStatus("REFUNDED");
            saveTransactions();
            std::cout << "✅ Refunded transaction " << tid << "\n";
            return;
        }
    }
    std::cout << "❌ Transaction not found.\n";
}

int main() {
    std::srand(std::time(0));
    loadTransactions();

    int choice;
    while (true) {
        std::cout << "\n=== 💳 Payment Gateway CLI ===\n";
        std::cout << "1. Pay (/pay)\n";
        std::cout << "2. Check Status (/status)\n";
        std::cout << "3. Refund (/refund)\n";
        std::cout << "4. Exit\n";
        std::cout << "Choose: ";
        std::cin >> choice;

        switch (choice) {
            case 1: pay(); break;
            case 2: checkStatus(); break;
            case 3: refund(); break;
            case 4: std::cout << "👋 Exiting...\n"; return 0;
            default: std::cout << "❌ Invalid option!\n";
        }
    }
}

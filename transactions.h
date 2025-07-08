#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction {
private:
    std::string id;
    std::string userToken;
    std::string merchantId;
    double amount;
    std::string status;

public:
    Transaction();
    Transaction(std::string tid, std::string token, std::string merchant, double amt, std::string stat);

    std::string getId() const;
    std::string getStatus() const;
    void setStatus(const std::string& newStatus);

    std::string serialize() const;
    void deserialize(const std::string& line);
};

#endif

#include "transactions.h"
#include <sstream>

Transaction::Transaction() {
    id = "";
    userToken = "";
    merchantId = "";
    amount = 0.0;
    status = "PENDING";
}

Transaction::Transaction(std::string tid, std::string token, std::string merchant, double amt, std::string stat) {
    id = tid;
    userToken = token;
    merchantId = merchant;
    amount = amt;
    status = stat;
}

std::string Transaction::getId() const {
    return id;
}

std::string Transaction::getStatus() const {
    return status;
}

void Transaction::setStatus(const std::string& newStatus) {
    status = newStatus;
}

std::string Transaction::serialize() const {
    return id + "," + userToken + "," + merchantId + "," + std::to_string(amount) + "," + status;
}

void Transaction::deserialize(const std::string& line) {
    std::istringstream iss(line);
    std::string token;

    getline(iss, id, ',');
    getline(iss, userToken, ',');
    getline(iss, merchantId, ',');
    getline(iss, token, ',');
    amount = std::stod(token);
    getline(iss, status, ',');
}

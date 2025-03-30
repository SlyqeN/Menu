#include "Client.h"

#include <iostream>

Client::Client(const std::string& login, const std::string& password) {
    this->login = login;
    this->password = password;
}

bool Client::addDeposit(const Deposit& deposit) {
    if (depositCount < 10) {
        deposits[depositCount++] = deposit;
        return true;
    }
    return false;
}

bool Client::operator==(const Client& other) const {
    return login == other.login;
}

bool Client::operator<(const Client& other) const {
    return login < other.login;
}

const Deposit* Client::getDeposits() const { 
    return deposits; 
}

int Client::getDepositCount() const { 
    return depositCount; 
}

std::ostream& operator<<(std::ostream& os, const Client& client) {
    os << "Клиент: " << client.login << "\nВклады: " << client.depositCount;
    return os;
}

std::istream& operator>>(std::istream& is, Client& client) {
    std::cout << "Введите логин: ";
    is >> client.login;
    std::cout << "Введите пароль: ";
    is >> client.password;
    return is;
}

void Client::displayInfo() const {
    std::cout << *this << "\n";
}
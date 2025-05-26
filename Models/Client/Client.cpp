#include "Client.h"
#include <iostream>
using namespace std;

Client::Client(const string& login, const string& password) {
    this->login = login;
    this->password = password;
}

bool Client::addDeposit(const Deposit& deposit) {
    if (deposits.getSize() < 10) {
        deposits.push_back(deposit);
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
    return deposits.data();
}

int Client::getDepositCount() const {
    return deposits.getSize();
}

ostream& operator<<(ostream& os, const Client& client) {
    os << "Клиент: " << client.login << endl << "Вклады: " << client.deposits.getSize();
    return os;
}

istream& operator>>(istream& is, Client& client) {
    cout << "Введите логин: ";
    is >> client.login;
    cout << "Введите пароль: ";
    is >> client.password;
    return is;
}

void Client::displayInfo() const {
    cout << *this << endl;
}
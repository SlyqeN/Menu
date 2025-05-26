#include "AuthManager.h"
#include <algorithm>
using namespace std;

AuthManager::AuthManager(MyVector<Client>& c, int mc, MyVector<Employee>& e, int me)
    : clients(c), maxClients(mc), employees(e), maxEmployees(me) {}

bool AuthManager::registerClient(const std::string& login, const std::string& password) {
    if (clients.getSize() >= maxClients) return false;
    for (int i = 0; i < clients.getSize(); ++i) {
        if (clients[i].getLogin() == login) return false;
    }
    clients.push_back(Client(login, password));
    return true;
}

bool AuthManager::registerEmployee(const std::string& login, const std::string& password, const std::string& position) {
    if (employees.getSize() >= maxEmployees) return false;
    for (int i = 0; i < employees.getSize(); ++i) {
        if (employees[i].getLogin() == login) return false;
    }
    employees.push_back(Employee(login, password, position));
    return true;
}

int AuthManager::authenticate(const std::string& login, const std::string& password) const {
    for (int i = 0; i < clients.getSize(); ++i) {
        if (clients[i].getLogin() == login && clients[i].getPassword() == password) return 1;
    }
    for (int i = 0; i < employees.getSize(); ++i) {
        if (employees[i].getLogin() == login && employees[i].getPassword() == password) return 2;
    }
    return 0;
}

bool AuthManager::removeClient(const std::string& login) {
    for (int i = 0; i < clients.getSize(); ++i) {
        if (clients[i].getLogin() == login) {
            clients.erase(i);
            return true;
        }
    }
    return false;
}

void AuthManager::sortClients() {
    std::sort(clients.data(), clients.data() + clients.getSize(), [](const Client& a, const Client& b) {
        return a < b;
    });
}

Client* AuthManager::getClients() const {
    return clients.data();
}

int AuthManager::getClientCount() const {
    return clients.getSize();
}

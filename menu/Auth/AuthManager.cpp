#include "AuthManager.h"
#include <algorithm>

AuthManager::AuthManager(Client* c, int& cn, int mc, Employee* e, int& en, int me) 
    : clients(c), clientCount(cn), maxClients(mc), 
      employees(e), employeeCount(en), maxEmployees(me) {}

bool AuthManager::registerClient(const std::string& login, const std::string& password) {
    if (clientCount >= maxClients) return false;
    for (int i = 0; i < clientCount; ++i) {
        if (clients[i].getLogin() == login) return false;
    }
    clients[clientCount++] = Client(login, password);
    return true;
}

bool AuthManager::registerEmployee(const std::string& login, const std::string& password, const std::string& position) {
    if (employeeCount >= maxEmployees) return false;
    for (int i = 0; i < employeeCount; ++i) {
        if (employees[i].getLogin() == login) return false;
    }
    employees[employeeCount++] = Employee(login, password, position);
    return true;
}

int AuthManager::authenticate(const std::string& login, const std::string& password) const {
    for (int i = 0; i < clientCount; ++i) {
        if (clients[i].getLogin() == login && clients[i].getPassword() == password) return 1;
    }
    for (int i = 0; i < employeeCount; ++i) {
        if (employees[i].getLogin() == login && employees[i].getPassword() == password) return 2;
    }
    return 0;
}

bool AuthManager::removeClient(const std::string& login) {
    for (int i = 0; i < clientCount; ++i) {
        if (clients[i].getLogin() == login) {
            for (int j = i; j < clientCount - 1; ++j) clients[j] = clients[j + 1];
            clientCount--;
            return true;
        }
    }
    return false;
}

void AuthManager::sortClients() {
    std::sort(clients, clients + clientCount, [](const Client& a, const Client& b) {
        return a < b;
    });
}

Client* AuthManager::getClients() const { 
    return clients; 
}

int AuthManager::getClientCount() const { 
    return clientCount; 
}
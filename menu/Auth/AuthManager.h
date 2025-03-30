#ifndef AUTHMANAGER_H
#define AUTHMANAGER_H

#include "../../Models/Client/Client.h"
#include "../../Models//Employee/Employee.h"

class AuthManager {
    private:
        Client* clients;
        Employee* employees;
        int& clientCount;
        int& employeeCount;
        int maxClients;
        int maxEmployees;
    
    public:
        AuthManager(Client* c, int& cn, int mc, Employee* e, int& en, int me);
        
        bool registerClient(const std::string& login, const std::string& password);
        bool registerEmployee(const std::string& login, const std::string& password, const std::string& position);
        int authenticate(const std::string& login, const std::string& password) const;
        
        bool removeClient(const std::string& login);
        void sortClients();
        
        Client* getClients() const;
        int getClientCount() const;
    };
#endif
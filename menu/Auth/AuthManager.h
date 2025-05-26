#ifndef AUTHMANAGER_H
#define AUTHMANAGER_H

#include "../../Models/Client/Client.h"
#include "../../Models/Employee/Employee.h"
#include "../../menu/MyVector.h"
using namespace std;

class AuthManager {
private:
    MyVector<Client>& clients;
    MyVector<Employee>& employees;
    int maxClients;
    int maxEmployees;

public:
    AuthManager(MyVector<Client>& c, int mc, MyVector<Employee>& e, int me);

    bool registerClient(const std::string& login, const std::string& password);
    bool registerEmployee(const std::string& login, const std::string& password, const std::string& position);
    int authenticate(const std::string& login, const std::string& password) const;

    bool removeClient(const std::string& login);
    void sortClients();

    Client* getClients() const;
    int getClientCount() const;
};

#endif

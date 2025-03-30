#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "../Deposit/Deposit.h"
#include <string>

#include "../Client/Client.h"
#include "../Person.h"

class Employee : public Person {
    private:
        std::string position;
    
    public:
        Employee() = default;
        Employee(const std::string& login, const std::string& password, const std::string& position);
        
        bool operator==(const Employee& other) const;
        bool operator<(const Employee& other) const;
        void viewClientDeposits(const Client& client) const;
        
        friend std::ostream& operator<<(std::ostream& os, const Employee& emp);
        friend std::istream& operator>>(std::istream& is, Employee& emp);
        void displayInfo() const override;
    };

#endif
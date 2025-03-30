#ifndef CLIENT_H
#define CLIENT_H

#include "../Person.h"
#include "../Deposit/Deposit.h"

class Client : public Person {
    private:
        Deposit deposits[10];
        int depositCount = 0;
    
    public:
        Client() = default;
        Client(const std::string& login, const std::string& password);
        
        bool addDeposit(const Deposit& deposit);
        bool operator==(const Client& other) const;
        bool operator<(const Client& other) const;
        const Deposit* getDeposits() const;
        int getDepositCount() const;
        
        friend std::ostream& operator<<(std::ostream& os, const Client& client);
        friend std::istream& operator>>(std::istream& is, Client& client);
        void displayInfo() const override;
    };
    #endif
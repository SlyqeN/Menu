#ifndef CLIENT_H
#define CLIENT_H

#include "../Person.h"
#include "../Deposit/Deposit.h"
#include "../../menu/MyVector.h"
#include "../../menu/AbstractDepositContainer.h"
using namespace std;

class Client : public Person, public AbstractDepositContainer {
    private:
        MyVector<Deposit> deposits;
    
    public:
        Client() = default;
        Client(const std::string& login, const std::string& password);
        
        bool addDeposit(const Deposit& deposit) override;
        bool operator==(const Client& other) const;
        bool operator<(const Client& other) const;
        const Deposit* getDeposits() const override;
        int getDepositCount() const override;
        
        friend std::ostream& operator<<(std::ostream& os, const Client& client);
        friend std::istream& operator>>(std::istream& is, Client& client);
        void displayInfo() const override;
    };
    #endif
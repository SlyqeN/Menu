#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <iostream>
#include <string>

class Deposit {
    private:
        std::string name;
        double amount;
        double interestRate;
    
    public:
        Deposit() = default;
        Deposit(const std::string& name, double amount, double rate);
        
        friend std::ostream& operator<<(std::ostream& os, const Deposit& dep);
        friend std::istream& operator>>(std::istream& is, Deposit& dep);
        
        std::string getName() const;
        double getAmount() const;
        double getInterestRate() const;
    };

#endif
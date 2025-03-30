#include "Deposit.h"
#include <iostream>


Deposit::Deposit(const std::string& name, double amount, double rate) 
    : name(name), amount(amount), interestRate(rate) {}

std::ostream& operator<<(std::ostream& os, const Deposit& dep) {
    os << "Вклад: " << dep.name 
       << "\nСумма: " << dep.amount 
       << "\nПроцент: " << dep.interestRate << "%";
    return os;
}

std::istream& operator>>(std::istream& is, Deposit& dep) {
    std::cout << "Название вклада: ";
    is >> dep.name;
    std::cout << "Сумма: ";
    is >> dep.amount;
    std::cout << "Процентная ставка (%): ";
    is >> dep.interestRate;
    return is;
}

std::string Deposit::getName() const { 
    return name; 
}

double Deposit::getAmount() const { 
    return amount; 
}

double Deposit::getInterestRate() const { 
    return interestRate; 
}
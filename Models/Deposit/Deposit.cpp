#include "Deposit.h"
#include <iostream>
#include <exception>
#include "../../menu/MyException.h"
using namespace std;


Deposit::Deposit(const string& name, double amount, double rate) 
    : name(name), amount(amount), interestRate(rate) {}

ostream& operator<<(ostream& os, const Deposit& dep) {
    os << "Вклад: " << dep.name 
       << endl << "Сумма: " << dep.amount 
       << endl << "Процент: " << dep.interestRate << "%";
    return os;
}

istream& operator>>(istream& is, Deposit& dep) {
    cout << "Название вклада: ";
    is >> dep.name;
    cout << "Сумма: ";
    is >> dep.amount;
    if(is.fail() || dep.amount < 0) throw MyException("Сумма должна быть положительной!");
    cout << "Процентная ставка (%): ";
    is >> dep.interestRate;
    if(is.fail() || dep.interestRate < 0 || dep.interestRate > 100) throw MyException("Процент некорректен!");
    return is;
}

string Deposit::getName() const { 
    return name; 
}

double Deposit::getAmount() const { 
    return amount; 
}

double Deposit::getInterestRate() const { 
    return interestRate; 
}
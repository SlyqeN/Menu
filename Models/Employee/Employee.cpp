#include "Employee.h"
#include <iostream>

Employee::Employee(const std::string& login, const std::string& password, const std::string& position) {
    this->login = login;
    this->password = password;
    this->position = position;
}

bool Employee::operator==(const Employee& other) const {
    return login == other.login;
}

bool Employee::operator<(const Employee& other) const {
    return login < other.login;
}

void Employee::viewClientDeposits(const Client& client) const {
    if (client.getDepositCount() == 0) {
        std::cout << "У клиента нет вкладов.\n";
        return;
    }
    
    std::cout << "Вклады клиента " << client.getLogin() << ":\n";
    for (int i = 0; i < client.getDepositCount(); ++i) {
        std::cout << "🔹 " << client.getDeposits()[i] << "\n";
    }
}

std::ostream& operator<<(std::ostream& os, const Employee& emp) {
    os << "Сотрудник: " << emp.login << "\nДолжность: " << emp.position;
    return os;
}

std::istream& operator>>(std::istream& is, Employee& emp) {
    std::cout << "Введите логин: ";
    is >> emp.login;
    std::cout << "Введите пароль: ";
    is >> emp.password;
    std::cout << "Введите должность: ";
    is >> emp.position;
    return is;
}

void Employee::displayInfo() const {
    std::cout << *this << "\n";
}
#include "Employee.h"
#include <iostream>
using namespace std;

Employee::Employee(const string& login, const string& password, const string& position) {
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
        cout << "У клиента нет вкладов." << endl;
        return;
    }
    
    cout << "Вклады клиента " << client.getLogin() << ":" << endl;
    const Deposit* deposits = client.getDeposits();
    for (int i = 0; i < client.getDepositCount(); ++i) {
        cout << "🔹 " << deposits[i] << endl;
    }
}

ostream& operator<<(ostream& os, const Employee& emp) {
    os << "Сотрудник: " << emp.login << endl << "Должность: " << emp.position;
    return os;
}

istream& operator>>(istream& is, Employee& emp) {
    cout << "Введите логин: ";
    is >> emp.login;
    cout << "Введите пароль: ";
    is >> emp.password;
    cout << "Введите должность: ";
    is >> emp.position;
    return is;
}

void Employee::displayInfo() const {
    cout << *this << endl;
}
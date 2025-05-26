#include <iostream>
#include <exception>
#include "Models/Client/Client.h"
#include "Models/Employee/Employee.h"
#include "menu/Auth/AuthManager.h"
#include "menu/CMenu.h"
#include "menu/MyVector.h"
#include "menu/MyException.h"
using namespace std;

int main() {
    try {
        MyVector<Client> clients;
        MyVector<Employee> employees;
        employees.push_back(Employee("admin", "admin123", "Администратор"));
        AuthManager auth(clients, 100, employees, 10);
        string currentUserLogin;
        CMenu mainMenu;
        mainMenu.addItem(CMenuItem("Регистрация клиента", [&]() {
            try {
                Client newClient;
                cin >> newClient;
                if (auth.registerClient(newClient.getLogin(), newClient.getPassword())) {
                    cout << "Регистрация успешна!" << endl;
                } else {
                    cout << "Ошибка: Логин занят или достигнут лимит клиентов!" << endl;
                }
            } catch(const MyException& ex) {
                cout << ex.what() << endl;
                cin.clear(); cin.ignore(10000, '\n');
            } catch(const exception& ex) {
                cout << ex.what() << endl;
                cin.clear(); cin.ignore(10000, '\n');
            }
        }));
        mainMenu.addItem(CMenuItem("Войти", [&]() {
            try {
                string login, password;
                cout << "Логин: ";
                cin >> login;
                cout << "Пароль: ";
                cin >> password;
                int role = auth.authenticate(login, password);
                currentUserLogin = login;
                if (role == 0) {
                    cout << "Ошибка: Неверный логин или пароль!" << endl;
                    return;
                }
                CMenu userMenu;
                if (role == 1) {
                    userMenu.addItem(CMenuItem("Оформить вклад", [&]() {
                        try {
                            Deposit deposit;
                            cin >> deposit;
                            for (int i = 0; i < clients.getSize(); ++i) {
                                if (clients[i].getLogin() == currentUserLogin) {
                                    if (clients[i].addDeposit(deposit)) {
                                        cout << "Вклад успешно добавлен!" << endl;
                                    } else {
                                        cout << "Ошибка: Превышен лимит вкладов!" << endl;
                                    }
                                    break;
                                }
                            }
                        } catch(const MyException& ex) {
                            cout << ex.what() << endl;
                            cin.clear(); cin.ignore(10000, '\n');
                        } catch(const exception& ex) {
                            cout << ex.what() << endl;
                            cin.clear(); cin.ignore(10000, '\n');
                        }
                    }));
                    userMenu.addItem(CMenuItem("Мой профиль", [&]() {
                        for (int i = 0; i < clients.getSize(); ++i) {
                            if (clients[i].getLogin() == currentUserLogin) {
                                clients[i].displayInfo();
                                const Deposit* deposits = clients[i].getDeposits();
                                for (int j = 0; j < clients[i].getDepositCount(); ++j) {
                                    cout << "🔹 " << deposits[j] << endl;
                                }
                                break;
                            }
                        }
                    }));
                } else if (role == 2) {
                    userMenu.addItem(CMenuItem("Список клиентов", [&]() {
                        if (clients.getSize() == 0) {
                            cout << endl;
                            cout << "Список клиентов пуст." << endl;
                            return;
                        }
                        cout << endl;
                        cout << "Список клиентов (" << clients.getSize() << "):" << endl;
                        for (int i = 0; i < clients.getSize(); ++i) {
                            cout << i + 1 << ". " << clients[i].getLogin() << endl;
                        }
                    }));
                    userMenu.addItem(CMenuItem("Удалить клиента", [&]() {
                        string targetLogin;
                        cout << "Введите логин клиента: ";
                        cin >> targetLogin;
                        if (auth.removeClient(targetLogin)) {
                            cout << "Клиент " << targetLogin << " удалён!" << endl;
                        } else {
                            cout << endl;
                            cout << "Ошибка: Клиент не найден!" << endl;
                        }
                    }));
                    userMenu.addItem(CMenuItem("Сортировать клиентов", [&]() {
                        auth.sortClients();
                        cout << "Клиенты отсортированы по логину." << endl;
                        for (int i = 0; i < clients.getSize(); ++i) {
                            cout << "  " << i + 1 << ". " << clients[i].getLogin() << endl;
                        }
                    }));
                    userMenu.addItem(CMenuItem("Просмотр вкладов", [&]() {
                        try {
                            if (clients.getSize() == 0) {
                                cout << endl;
                                cout << "Нет клиентов для просмотра." << endl;
                                return;
                            }
                            cout << "Выберите клиента (1-" << clients.getSize() << "): ";
                            int choice;
                            cin >> choice;
                            if (cin.fail()) throw MyException("Ошибка: введено не число!");
                            if (choice < 1 || choice > clients.getSize()) throw MyException("Ошибка: Неверный выбор!");
                            employees[0].viewClientDeposits(clients[choice - 1]);
                        } catch(const MyException& ex) {
                            cout << ex.what() << endl;
                            cin.clear(); cin.ignore(10000, '\n');
                        } catch(const exception& ex) {
                            cout << ex.what() << endl;
                            cin.clear(); cin.ignore(10000, '\n');
                        }
                    }));
                }
                userMenu.run();
            } catch(const MyException& ex) {
                cout << ex.what() << endl;
                cin.clear(); cin.ignore(10000, '\n');
            } catch(const exception& ex) {
                cout << ex.what() << endl;
                cin.clear(); cin.ignore(10000, '\n');
            }
        }));
        mainMenu.addItem(CMenuItem("Демонстрация вектора (весь диапазон)", []() {
            try {
                MyVector<string> vec;
                cout << endl << "Добавление строк в вектор" << endl;
                vec.push_back("Один");
                vec.push_back("Два");
                vec.push_back("Три");
                cout << "Размер после добавления: " << vec.getSize() << endl;
                cout << endl << "Итерация по диапазону:" << endl;
                for (auto it:vec) {
                    cout << "  * " << it << endl;
                }
                cout << endl << "Удаляем элемент с индексом 1" << endl;
                vec.erase(1);
                cout << "После удаления:" << endl;
                for (auto it:vec) {
                    cout << "  * " << it << endl;
                }
                cout << endl << "Добавим элементы вновь" << endl;
                vec.push_back("Четыре");
                vec.push_back("Пять");
                cout << "Итоговое содержимое:" << endl;
                for (auto it:vec) {
                    cout << "  * " << it << endl;
                }
                cout << "Общий размер: " << vec.getSize() << endl;
            } catch(const MyException& ex) {
                cout << ex.what() << endl;
            } catch(const exception& ex) {
                cout << ex.what() << endl;
            }
        }));
        mainMenu.run();
    } catch(const MyException& ex) {
        cout << ex.what() << endl;
    } catch(const exception& ex) {
        cout << ex.what() << endl;
    }
}

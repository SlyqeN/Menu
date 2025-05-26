#include "CMenu.h"
#include <iostream>
#include <limits>
using namespace std;

void CMenu::addItem(const CMenuItem& item) {
    items.push_back(item);
}

void CMenu::run() const {
    while (true) {
        cout << endl << "====== Главное меню ======" << endl;

        int i = 1;
        for (auto it = items.begin(); it != items.end(); ++it) {
            cout << i++ << ". " << it->getTitle() << endl;
        }

        cout << "0. Выход" << endl << "Выберите пункт: ";

        int choice;
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка ввода! Попробуйте снова." << endl;
            continue;
        }

        if (choice == 0) break;

        if (choice < 1 || choice > items.getSize()) {
            cout << "Неверный пункт! Попробуйте снова." << endl;
            continue;
        }

        items[choice - 1].execute();
    }
}

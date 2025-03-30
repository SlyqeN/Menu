#include "CMenu.h"
#include <iostream>
#include <limits>

void CMenu::addItem(const CMenuItem& item) {
    if (itemCount < MAX_MENU_ITEMS) {
        items[itemCount] = item;
        itemCount++;
    } else {
        std::cerr << "Меню переполнено!\n";
    }
}

void CMenu::run() const {
    while (true) {
        std::cout << "\n--- Меню ---\n";
        for (int i = 0; i < itemCount; ++i) {
            std::cout << (i + 1) << ". " << items[i].getTitle() << "\n";
        }
        std::cout << "0. Выход\nВыберите пункт: ";

        int choice;
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка ввода!\n";
            continue;
        }

        if (choice == 0) break;
        if (choice < 1 || choice > itemCount) {
            std::cout << "Неверный пункт!\n";
            continue;
        }

        items[choice - 1].execute();
    }
}
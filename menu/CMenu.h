#ifndef CMENU_H
#define CMENU_H

#include "CMenuItem.h"

constexpr int MAX_MENU_ITEMS = 10;

class CMenu {
private:
    CMenuItem items[MAX_MENU_ITEMS];
    int itemCount = 0;

public:
    void addItem(const CMenuItem& item);
    void run() const;
};

#endif
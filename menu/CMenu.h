#ifndef CMENU_H
#define CMENU_H

#include "CMenuItem.h"
#include "MyVector.h"

class CMenu {
private:
    MyVector<CMenuItem> items;

public:
    void addItem(const CMenuItem& item);
    void run() const;
};

#endif

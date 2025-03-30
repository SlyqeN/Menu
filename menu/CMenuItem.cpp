#include "CMenuItem.h"

CMenuItem::CMenuItem(const std::string& title, std::function<void()> action) 
    : title(title), action(action) {}

void CMenuItem::execute() const {
    if (action) action();
}

const std::string& CMenuItem::getTitle() const {
    return title;
}
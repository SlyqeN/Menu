#ifndef CMENUITEM_H
#define CMENUITEM_H

#include <functional>
#include <string>

class CMenuItem {
private:
    std::string title;
    std::function<void()> action;

public:
    CMenuItem() = default;
    CMenuItem(const std::string& title, std::function<void()> action);
    void execute() const;
    const std::string& getTitle() const;
};

#endif
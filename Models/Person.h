#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

class Person {
    protected:
        std::string login;
        std::string password;
    
    public:
        virtual ~Person() = default;
        virtual void displayInfo() const = 0;
        const std::string& getLogin() const { return login; }
        const std::string& getPassword() const { return password; }
    };
#endif
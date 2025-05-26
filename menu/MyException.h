#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include <exception>
#include <string>
class MyException : public std::exception {
public:
    MyException(const char* error) : m_error(error) {}
    MyException(const std::string& error) : m_error(error) {}
    const char* what() const noexcept override { return m_error.c_str(); }
private:
    std::string m_error;
};
#endif 
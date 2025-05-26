#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
#include <exception>
#include "MyException.h"
using namespace std;

template <class T>
class MyVector {
    T* arr;
    int sz;
    int cap;
    void resize(int newCap) {
        T* tmp = new T[newCap];
        for (int i = 0; i < sz; ++i)
            tmp[i] = arr[i];
        delete[] arr;
        arr = tmp;
        cap = newCap;
    }
public:
    MyVector() : arr(nullptr), sz(0), cap(0) {}
    MyVector(int n, const T& val = T()) : sz(n), cap(n) {
        arr = new T[cap];
        for (int i = 0; i < sz; ++i) arr[i] = val;
    }
    ~MyVector() { delete[] arr; }
    void push_back(const T& val) {
        if (sz >= cap) resize(cap == 0 ? 1 : cap * 2);
        arr[sz++] = val;
    }
    void erase(int idx) {
        if (idx < 0 || idx >= sz) return;
        for (int i = idx; i < sz - 1; ++i)
            arr[i] = arr[i + 1];
        --sz;
    }
    int getSize() const { return sz; }
    T& operator[](int idx) { if(idx<0||idx>=sz) throw MyException("Индекс вне диапазона"); return arr[idx]; }
    const T& operator[](int idx) const { if(idx<0||idx>=sz) throw MyException("Индекс вне диапазона"); return arr[idx]; }
    T* begin() { return arr; }
    T* end() { return arr + sz; }
    const T* begin() const { return arr; }
    const T* end() const { return arr + sz; }
    T* data() { return arr; }
    const T* data() const { return arr; }
};

#endif // MYVECTOR_H 

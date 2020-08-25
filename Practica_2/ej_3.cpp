/*
date: 24-08-2020
File: ej_3.cpp
Author : Facundo Martin Cabrera
Email: cabre94@hotmail.com facundo.cabrera@ib.edu.ar
GitHub: https://github.com/cabre94
GitLab: https://gitlab.com/cabre94
Description:
*/

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <sstream>
#include <cstdlib>

#define MAX_SIZE 10000


template <class T>
class Stack{
    T *v;
    int max_size, top;
public:
    class Underflow {};
    class Overflow {};
    class Bad_size {};
    
    Stack(int size);
    ~Stack();

    void push(T);
    T pop();
};

template<class T>
Stack<T>::Stack(int size){
    if(size > MAX_SIZE)
        throw Bad_size{};
    max_size = size;
    top = 0;
    v = new T[size];
}

template<class T>
Stack<T>::~Stack(){
    delete [] v;
}

template<class T>
void Stack<T>::push(T t){
    if(top == max_size)
        throw Overflow{};
    v[top++] = t;
}

template<class T>
T Stack<T>::pop(){
    if(top == 0)
        throw Underflow{};
    return v[--top];
}



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

template <class T>
class Stack{
    T *v;
    int max_size, top;
public:
    class Underflow {};
    class Overflow {};
    
    Stack(int size);
    ~Stack();

    void push(T);
    T pop();


}
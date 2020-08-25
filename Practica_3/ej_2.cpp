/*
date: 25-08-2020
File: ej_2.cpp
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

unsigned long long int fibonacci(bool reset = false){
    static unsigned long long int f1 = 1, f2 = 1;
    if(reset){
        f1 = 1;
        f2 = 1;        
    }else{
        unsigned long long int aux = f2 + f1;
        f1 = f2;
        f2 = aux;
    }
    return f2;
}

int main(int argc, const char** argv) {

    for(int i=2; i<100; i++){
        std::cout << "Iteracion " << i << "-esima: " << fibonacci() << std::endl;
        if(i == 50)
            fibonacci(true);
    }
    return 0;
}
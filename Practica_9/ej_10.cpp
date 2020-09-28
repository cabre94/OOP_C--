/*
date: 27-09-2020
File: ej_10.cpp
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

template<class T>
class Vector{
private:
    T *v;
    int sz;
public:
    Vector() : v(nullptr), sz(0) {}	            //Default constructor
    Vector(int sz_) : v(new T[sz_]), sz(sz_) {}
    ~Vector();

    Vector(const Vector &);	//Copy constructor
    Vector(Vector &&);	    //Move constructor

    Vector &operator=(const Vector &);	//Copy assignment
    Vector &operator=(Vector &&);	    // Move assignment

    T& operator[](int i){return v[i];}

    // void set(T t, int i);
    int getSize(){return sz;}
    
    template <class U> friend std::ostream& operator<<(std::ostream &out, Vector<U> &vec);

private:
    void swap(Vector<T> &other);
};


template<class T>
Vector<T>::~Vector(){
    delete [] v;
}

template<class T>
Vector<T>::Vector(const Vector<T> &vec) : v(new T[vec.sz]), sz(vec.sz){
    std::cout << "Copy constructor" << std::endl;
    for(int i=0; i < sz; i++)
        v[i] = vec.v[i];
}

template<class T>
Vector<T>::Vector(Vector &&vec) : v(nullptr), sz(vec.sz){
    std::cout << "Move Constructor" << std::endl;
    this->swap(vec);
    // return *this;
}

template<class T>
Vector<T> &Vector<T>::operator=(const Vector &vec){
    std::cout << "Copy Assigment" << std::endl;
    T *aux = new T[vec.sz];
    for(int i=0; i < vec.sz; i++)
        aux[i] = vec.v[i];
    delete [] v;
    v = aux;
    sz = vec.sz;
    return *this;
}

template<class T>
Vector<T> &Vector<T>::operator=(Vector &&vec){
    std::cout << "Move assignment" << std::endl;
    this->swap(vec);
    sz = vec.sz;        // Me queda la duda si me falta hacer vec.v = nullptr, porque
    return *this;              // no estoy seguro si antes del swap this->v tiene nullptr o kk (o si da igual)
}

template<class T>
void Vector<T>::swap(Vector<T> &other){
    using std::swap;
    swap(v, other.v);
}

// template<class T>
// void Vector<T>::set(T t, int i){
//     v[i] = t;
// }


template <class T>
std::ostream& operator<<(std::ostream &out, Vector<T> &vec){
    for(int i=0; i < vec.sz-1; i++)
        out << vec[i] << " - ";
    out << vec[vec.sz-1];
    return out;
}




int main(int argc, const char** argv){

    Vector<int> vec(10);

    for(int i=0; i < vec.getSize(); i++)
        vec[i] = i*2;
    
    std::cout << vec << std::endl;

    Vector<int> vec2 = vec;                     // Copy constructor
    std::cout << vec2 << std::endl;

    Vector<int> vec3 = std::move(vec);          // Move Constructor
    std::cout << vec3 << std::endl;

    Vector<int> vec4;
    vec4 = vec2;            // Copy assigment

    vec4 = std::move(vec3); // Move assigment

    std::cout << true << std::endl;
    


    return 0;
}
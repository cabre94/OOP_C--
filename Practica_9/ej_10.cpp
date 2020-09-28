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

#define N 8*sizeof(uint64_t)

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

    T& operator[](int i) const {return v[i];}

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


///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////


template<>
class Vector<bool>{
private:
    uint64_t *v;
    int bits;       // Cantidad de bits
    int sz;         // Cantidad de elementos de v
public:
    Vector() : v(nullptr), bits(0), sz(0) {}
    Vector(int bits_);
    ~Vector();

    Vector(const Vector &);	//Copy constructor
    Vector(Vector &&);	    //Move constructor

    Vector &operator=(const Vector &);	//Copy assignment
    Vector &operator=(Vector &&);	    // Move assignment

    friend std::ostream& operator<<(std::ostream &out, Vector<bool> &vec);

    void set(int bit, bool value=true);
    int getSize(){return bits;}     // No retorna realmente size, pero es lo que el usuario esperaria

private:

};

// template<>
Vector<bool>::Vector(int bits_) : v(new uint64_t[1+bits_/N]), bits(bits_), sz(1+bits_/N){
    // for (int i = 0; i < bits; i++) {
    //     v[i/(sz*N)] &= 0 << (i%(sz*N));
    // }
}

Vector<bool>::~Vector(){
    delete [] v;
}

Vector<bool>::Vector(const Vector<bool> &vec) : v(new uint64_t[vec.sz]), bits(vec.bits), sz(vec.sz){
    std::cout << "Vector<bool> Copy constructor" << std::endl;

    for(int i=0; i < vec.bits; i++)
        set(i, vec.v[i/(sz*N)] >> (i%(sz*N)));
}

void Vector<bool>::set(int i, bool value){
    if(value)
        v[i/(sz*N)] |= 1 << (i % (sz*N));
    else
        v[i/(sz*N)] &= (1 << (i % (sz*N)));
}




std::ostream& operator<<(std::ostream &out, Vector<bool> &vec){
    for(int i=0; i < vec.bits; i++){
        out << ( vec.v[i/(vec.sz*N)] >> (i%(vec.sz*N)) ) % 2;
    }
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

    

    //////////////////////////////////////////////////////////
    srand(time(NULL));
    // srand(14);

    Vector<bool> vec_b(10);

    std::cout << vec_b << std::endl;
    std::cout << vec_b.getSize() << std::endl;

    for(int i=0; i<vec_b.getSize(); i++)
        // vec_b.set(i, rand() % 2);
        vec_b.set(i, 1);
    
    std::cout << vec_b << std::endl;



    return 0;
}
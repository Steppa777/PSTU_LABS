#pragma once
#include <iostream> 
#include <string>
using namespace std;

template <class T>
class Plenty {
    
public:
Plenty(int s, T k);
Plenty(const Plenty<T>& a);
~Plenty();
Plenty& operator=(const Plenty<T>& a);
T& operator[](int index);
int operator()();

friend Plenty& operator+(Plenty& x, Plenty& y);
friend ostream& operator<< <>(ostream& out, const Plenty<T>& a);
friend istream& operator>> <>(istream& in, Plenty<T>& a);

private:
int size;
T* data;
};

template <class T>
Plenty<T>::Plenty(int s, T k) {
size = s;
data = new T[size];
for (int i = 0; i < size; i++)
data[i] = k;
}

template <class T>
Plenty<T>::Plenty(const Plenty& a) {
size = a.size;
data = new T[size];
for (int i = 0; i < size; i++)
data[i] = a.data[i];
}

template <class T>
Plenty<T>::~Plenty() {
delete[]data;
data = 0;
}

template <class T>
Plenty<T>& Plenty<T>::operator=(const Plenty<T>& a) {
if (this == &a)return *this;
size = a.size;
if (data != 0) delete[]data;
data = new T[size];
for (int i = 0; i < size; i++)
data[i] = a.data[i];
return *this;
}


template <class T>
T& Plenty<T>::operator[](int index) {
if (index < size) return data[index];
else cout << "\nОшибка! index>size";
}

template <class T>
Plenty<T> Plenty<T>::operator - (const T k) {
Plenty<T> temp(size, k);
for (int i = 0; i < size; ++i)
temp.data[i] = data[i] - k;
return temp;
}

template <class T>
int Plenty<T>::operator ()() {
return size;
}

template <class T>
ostream& operator<< <>(ostream& out, const Plenty<T>& a) {
for (int i = 0; i < a.size; ++i)
out << a.data[i] << " ";
return out;
}

template <class T>
istream& operator>> <>(istream& in, Plenty<T>& a) {
for (int i = 0; i < a.size; ++i)
in >> a.data[i];
return in;
}


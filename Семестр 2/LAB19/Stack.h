#pragma once
#include <iostream>
using namespace std;

template <class T>
class node {
public: T data;
node<T>* next;
};

template <class T>

class Stack {
private:
node<T>* top;
public:
Stack() {
top = NULL;
}
bool isEmpty() {
if (top == NULL)
return false;
else
return true;
}
T Top() {
if (top)
return top->data;
else
cout << "Стек пустой" << endl;
}

void push(const T& val) {
if (top == NULL) {
top = new node<T>;
top->next = NULL;
top->data = val;
}
else {
node<T>* temp = new node<T>;
temp->data = val;
temp->next = top;
top = temp;
}
}
	
void pop() {
if (top == NULL) {
cout << "Стек пустой" << endl;
return;
}
else {
cout << top->data << ": Удален" << endl;
node<T>* temp = top;
top = top->next;
delete temp;
}
}


void print() {
node<T>* temp = top;
while (temp != NULL) {
cout << temp->data << " ";
temp = temp->next;
}
cout << endl;
}
};

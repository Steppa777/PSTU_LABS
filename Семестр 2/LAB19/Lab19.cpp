#include "Stack.h"
#include <iostream>
using namespace std;

int main()  {
Stack<int> s;
bool flag = true;
while (flag) {
cout << "Введите 1 - Ввести элемент" << endl;
cout << "Введите 2 - Удалить последний введенный элемент" << endl;
cout << "Введите 3 - Вывод Стека" << endl;
cout << "Введите 0 - Выход из программы" << endl;
cout << "Выбор: ";
int V;
cin >> V;

switch (V) {
case(1): int n; 
cout << "Вводите элемент: "; cin >> n; s.push(n); break;
case(2): s.pop(); break;
case(3): s.print(); break;
case(0): return 0;
default: cout << "Такой операции не существует! Cделайте выбор снова " << endl; break;
}
cout << "======================================================="<< endl;
}
    return 0;
}

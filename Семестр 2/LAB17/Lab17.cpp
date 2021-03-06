#include <iostream>
#include<string>
#include <ctime>
#include <math.h>
using namespace std;
struct info {
string FIO;
string PASS;
string NUMER;

void Show() {
cout << "=========================================="<< endl;
cout << "Имя    : " << FIO << endl;
cout << "Телефон: " << NUMER << endl;
cout << "Паспорт: " << PASS << endl;
}
void Random() {
string names[] = { "Stepan", "Veniamin","Vladimir","Sergei", "Petr", "Ilya","Mark", "Egor" };
string secnames[] = { "Ivanov","Keller", "Kuznetsov", "Gegin", "Popov", "Vesnin", "Cheshkin", "Nekrasov" };
string thirdnames[] = { "Sergeyevich","Nikitin","Pavlovich","Aleksandrovich", "Nikolaevich", "Ivanovich" };
FIO = names[1+ rand() % 8] + " " + secnames[1+rand() % 7] + " " + thirdnames[1 + rand() % 5];
string phone;
for (int i = 0; i < 10; i++) {
phone.push_back(rand() % 10 + 48);
}
NUMER = phone;
string pas;
for (int i = 0; i < 10; i++) {
pas.push_back(rand() % 10 + 48);
}
PASS = pas;
}
};

int get(string str) {
int value = 0;
int j = 1;
for (auto i : str) {
value += i * j;
j++;
}
return value;
}

int hash_t(string str, int size) {
double f;
return int(size * modf(get(str) *  0.87987654321, &f));
}

void make_table(int n, int size, info* st2) {
int* table = new int[size];
int hashn = size;
for (int i = 0; i < size; i++) {
table[i] = -1;
}
int collisions = 0;
for (int k = 0; k < n; k++) {
int num;
int hash = hash_t(st2[k].PASS, hashn);
if (table[hash] == -1) {
table[hash] = k;
}
else {
num = hash;
while (num < size && table[num] != -1) {
collisions++;
num++;
}
if (num >= size)  {
size *= 2;
int* table2 = new int[size];
for (int i = 0; i < size / 2; i++) {
table2[i] = table[i];
}
for (int i = size / 2; i < size; i++) {
table2[i] = -1;
}
delete[]table;
table = table2;
}
if (table[num] == -1) {
table[num] = k;
}
}
}
cout << "=========================================="<< endl;
cout << "Число колизий: " << collisions << endl;
cout << "=========================================="<< endl;
cout << "Введите ключ для поиска(паспорт): ";
string key;
cin.ignore();
getline(cin, key);
int hashkey = hash_t(key, hashn);
if (st2[table[hashkey]].PASS == key) {
cout << "Элемент найден: " << endl;
st2[table[hashkey]].Show();
}
else {
while (st2[table[hashkey]].PASS != key && hashkey < size) {
hashkey++;
}
if (st2[table[hashkey]].PASS == key) {
cout << "Элемент найден: " << endl;
st2[table[hashkey]].Show();
}
else
cout << "Такой элемент не найден";
}

bool p = 0;
cout << "=========================================="<< endl;
cout << "Хотите удалить элемент? " << endl;
cout << "Введите 0: Нет "<< endl;
cout << "Введите 1: Да "<< endl;
cin >> p;
if (p) {
info* st = new info[n - 1];
for (int i = 0; i < table[hashkey]; i++) {
st[i] = st2[i];
}
for (int i = table[hashkey]; i < n - 1; i++) {
st[i] = st2[i + 1];
}
delete[]st2;
cout << "После удаления: " << endl;
for (int i = 0; i < n - 1; i++) {
st[i].Show();
}
cout << "=========================================="<< endl;
}
}

int main() {
int n, size;
string key;
cout << "Введите количество элементов: ";
cin >> n;
cout << "Введите размер таблицы: ";
cin >> size;
info* st = new info[n];
int* table = new int[size];
for (int i = 0; i < n; i++) {
st[i].Random();
st[i].Show();
}
make_table(n, size, st);
}

#pragma once
#include "TRIAD.h"
class TIME:
public TRIAD {
public:
TIME(void);
public:
~TIME(void); 
TIME(int,int,int);
TIME(const TIME&);

void hour(int);
void min(int);
void sec(int);
   
TIME operator++(int); 
TIME operator+(int);

TIME& operator=(const TIME&);

friend istream& operator>>(istream& in, TIME& l);
friend ostream& operator<<(ostream& out, const TIME& l);
};

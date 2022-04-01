#ifndef INVMENU_H
#define INVMENU_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

extern BookData book[20];

char title[51], isbn[14], author[31], publisher[31], date[11];
int qty;
double wholesale, retail;

//function prototypes
void invMenu();

void lookUpBook();
void addBook();
void editBook();
void deleteBook();

#endif
#ifndef INVMENU_H
#define INVMENU_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//global arrays
extern char title[20][51], isbn[20][14], author[20][31], publisher[20][31], date[20][11];
extern int qty[20];
extern double wholesale[20], retail[20];

//function prototypes
void invMenu();

void lookUpBook();
void addBook();
void editBook();
void deleteBook();

#endif
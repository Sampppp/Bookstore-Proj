#ifndef INVMENU_H
#define INVMENU_H

#include <iostream>
#include <iomanip>
#include <string>
#include "BookData.h"
using namespace std;

extern InvBook book[20];

void invMenu();		//function prototypes

void lookUpBook();
void addBook();
void editBook();
void deleteBook();

#endif
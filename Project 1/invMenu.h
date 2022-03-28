#ifndef INVMENU_H
#define INVMENU_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
//global arrays
extern string title[], isbn[], author[], publisher[], date[];
extern int qty[];
extern double wholesale[], retail[];
//function prototypes
void invMenu();

void lookUpBook();
void addBook();
void editBook();
void deleteBook();

#endif
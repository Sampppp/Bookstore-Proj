#ifndef BOOKINFO_H
#define BOOKINFO_H

#include <iostream>
#include <string>
using namespace std;

//global functions
extern char title[20][51], isbn[20][14], author[20][31], publisher[20][31], date[20][11];
extern int qty[20];
extern double wholesale[20], retail[20];

//function prototypes
void bookInfo(char[], char[], char[], char[], char[], int, double, double);

#endif

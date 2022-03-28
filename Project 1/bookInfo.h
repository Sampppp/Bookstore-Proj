#ifndef BOOKINFO_H
#define BOOKINFO_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
//global arrays
extern char title[][], isbn[][], author[][], publisher[][], date[][];
extern int qty[];
extern double wholesale[], retail[];
//function prototypes
void bookInfo(int);

#endif

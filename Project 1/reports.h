#ifndef REPORTS_H
#define REPORTS_H

#include <iostream>
#include <iomanip>
#include <string>
#include "BookData.h"
using namespace std;

extern InvBook book[20];

//function prototypes
void reports();

void repListing();
void repWholesale();
void repRetail();
void repQty();
void repCost();
void repAge();

#endif
#ifndef BOOKDATA_H
#define BOOKDATA_H

#include <iomanip>
#include <string>
#include <cctype>
using namespace std;



extern BookData book[20];

void setTitle(char*, int);
void setISBN(char*, int);
void setAuthor(char*, int);
void setPublisher(char*, int);
void setDate(char*, int);
void setQty(int, int);
void setWholesale(double, int);
void setRetail(double, int);
int isEmpty(int);
void removeBook(int);

#endif

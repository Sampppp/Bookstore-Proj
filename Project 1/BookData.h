#ifndef BOOKDATA_H
#define BOOKDATA_H

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

//class that stores book data
class BookData {
private:
	char title[51], isbn[14], author[31], publisher[31];
public:
	BookData(); //constructor

	void setTitle(char*);
	void setISBN(char*);
	void setAuthor(char*);
	void setPublisher(char*);

	char* getTitle();
	char* getISBN();
	char* getAuthor();
	char* getPublisher();

	bool bookMatch(char*);
};

class InvBook : public BookData {
private:
	char date[11];
	int qty;
	double wholesale, retail;
public:
	InvBook(); //constructor

	void setDate(char*);
	void setQty(int);
	void setWholesale(double);
	void setRetail(double);
	char* getDate();
	int getQty();
	double getWholesale();
	double getRetail();

	bool isEmpty();
	void removeBook();
};

extern BookData book[20];
#endif

#ifndef BOOKDATA_H
#define BOOKDATA_H

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

class BookData {		//BookData class
private:
	char title[51], isbn[14], author[31], publisher[31];
	friend class InvBook;
public:
	BookData();		//constructor

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

class InvBook : public BookData {		//InvBook class
private:
	char date[11];
	int qty;
	double wholesale, retail;
public:
	InvBook();		//constructor

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

class SoldBook : public InvBook {		//SoldBook class
private:
	static double taxRate;
	int qtySold, bookIndex;
	double subtotal, tax, total;
public:
	SoldBook();		//constructor

	void setQtySold(int);
	void setBookIndex(int);
	void setSubtotal(double);
	void setTax();
	void setTotal();

	int getQtySold();
	int getBookIndex();
	double getSubtotal();
	double getTax();
	double getTotal();
	
};

extern InvBook book[20];
#endif

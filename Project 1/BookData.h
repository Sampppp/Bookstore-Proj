#ifndef BOOKDATA_H
#define BOOKDATA_H

#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

class BookData {
private:
	char title[51], isbn[14], author[31], publisher[31], date[11];
	int qty;
	double wholesale, retail;
public:
	BookData(); //constructor

	void setTitle(char*);
	void setISBN(char*);
	void setAuthor(char*);
	void setPublisher(char*);
	void setDate(char*);
	void setQty(int);
	void setWholesale(double);
	void setRetail(double);

	char* getTitle();
	char* getISBN();
	char* getAuthor();
	char* getPublisher();
	char* getDate();
	int getQty();
	double getWholesale();
	double getRetail();

	int isEmpty();
	void removeBook();
};

extern BookData book[20];

#endif

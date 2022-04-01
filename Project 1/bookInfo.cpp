/******************************************************************
** Program: Chapter 10, Programming Project 6
** Course: CS226 CRN 36331
** Professor: Ping-Wei Tsai
** Student: Samson Pak
** Due Date: 03/28/22
******************************************************************/
#include "bookInfo.h"
#include "BookData.h"

void bookInfo(int i) {

	//Displays book information template
	cout << endl << endl
		<< "           Serendipity Booksellers" << endl
		<< "              Book Information" << endl << endl
		<< "          ISBN: " << book[i].isbn << endl
		<< "          Title: " << book[i].title << endl
		<< "          Author: " << book[i].author << endl
		<< "          Publisher: " << book[i].publisher << endl
		<< "          Date Added: " << book[i].date << endl
		<< "          Quantity-On-Hand: " << book[i].qty << endl
		<< "          Wholesale Cost: $" << book[i].wholesale << endl
		<< "          Retail Price: $" << book[i].retail << endl;
}
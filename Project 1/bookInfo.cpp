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
		<< "          ISBN: " << book[i].getISBN() << endl
		<< "          Title: " << book[i].getTitle() << endl
		<< "          Author: " << book[i].getAuthor() << endl
		<< "          Publisher: " << book[i].getPublisher() << endl
		<< "          Date Added: " << book[i].getDate() << endl
		<< "          Quantity-On-Hand: " << book[i].getQty() << endl
		<< "          Wholesale Cost: $" << book[i].getWholesale() << endl
		<< "          Retail Price: $" << book[i].getRetail() << endl;
}
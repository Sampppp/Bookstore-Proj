/******************************************************************
** Program: Chapter 8, Programming Project 4
** Course: CS226 CRN 36331
** Professor: Ping-Wei Tsai
** Student: Samson Pak
** Due Date: 02/28/22
******************************************************************/
#include "bookInfo.h"

void bookInfo(char isbn[14], char title[51], char author[31], char publisher[31], char date[11], int qty, double wholesale, double retail) {

	//Displays book information template
	cout << endl << endl
		<< "           Serendipity Booksellers" << endl
		<< "              Book Information" << endl << endl
		<< "          ISBN: " << isbn << endl
		<< "          Title: " << title << endl
		<< "          Author: " << author << endl
		<< "          Publisher: " << publisher << endl
		<< "          Date Added: " << date << endl
		<< "          Quantity-On-Hand: " << qty << endl
		<< "          Wholesale Cost: $" << wholesale << endl
		<< "          Retail Price: $" << retail << endl;
}

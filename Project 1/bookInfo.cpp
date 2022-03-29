/******************************************************************
** Program: Chapter 10, Programming Project 6
** Course: CS226 CRN 36331
** Professor: Ping-Wei Tsai
** Student: Samson Pak
** Due Date: 03/28/22
******************************************************************/
#include "bookInfo.h"

void bookInfo(int i) {

	//Displays book information template
	cout << endl << endl
		<< "           Serendipity Booksellers" << endl
		<< "              Book Information" << endl << endl
		<< "          ISBN: " << isbn[i] << endl
		<< "          Title: " << title[i] << endl
		<< "          Author: " << author[i] << endl
		<< "          Publisher: " << publisher[i] << endl
		<< "          Date Added: " << date[i] << endl
		<< "          Quantity-On-Hand: " << qty[i] << endl
		<< "          Wholesale Cost: $" << wholesale[i] << endl
		<< "          Retail Price: $" << retail[i] << endl;
}

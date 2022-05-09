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
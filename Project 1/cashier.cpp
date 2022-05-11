#include "cashier.h"
#include "bookInfo.h"
#include "strUpper.h"
#include "BookData.h"

void cashier() {

	//input variables
	char input, choice;
	char tempTitle[51], tempISBN[14];
	int quantity1 = 0;
	int totalQty;
	
	int bookSelect[20], purchaseQty;
	

	int totalBooks = 0;

	//Cashier input menu
	cout << endl << endl
		<< "Serendupity Booksellers" << endl
		<< "Cashier Menu" << endl << endl;
	cout << "How many Titles do you plan to buy?: ";
	cin >> totalQty;

	SoldBook* sold;

	try {
		//Dynamically allocated array
		sold = new SoldBook[totalQty];
	}
	catch (exception msg){
		cout << "An error has occured..." << endl << endl;
		exit(0);
	}
	cout << endl << endl
		<< "Enter book data below" << endl;

	for (int i = 0; i < totalQty; i++) {
		cout << "Title: ";
		cin.ignore();
		cin.getline(tempTitle, 14);
		strUpper(tempTitle);

		for (int a = 0; a < 20; a++) {
			if (book[a].bookMatch(tempTitle) == true) {
				sold[i].setBookIndex(a);
				break;
			}
			else if (a == 19) {
				cout << endl << "There are no books that match the title" << endl;
				return;
			}
		}
		bookInfo(sold[i].getBookIndex());

		if (book[sold[i].getBookIndex()].getQty() == 0) {
			cout << endl << endl << "This book is out of stock";
			return;
		}

		do {
			cout << endl << "How many of this book would you like to purchase?: ";
			cin >> purchaseQty;
			if (purchaseQty > book[sold[i].getBookIndex()].getQty()) {
				cout << endl << endl << "Please enter a valid amount";
			}
		} while (purchaseQty > book[i].getQty());

		book[sold[i].getBookIndex()].setQty(book[sold[i].getBookIndex()].getQty() - purchaseQty);

		sold[i].setQtySold(purchaseQty);
		sold[i].setSubtotal(book[sold[i].getBookIndex()].getRetail());
		sold[i].setTax();
		sold[i].setTotal();
	}


	//receipt 
	cout << endl << endl << endl
		<< "Serendipity Book Sellers" << endl << endl
		<< "Date: " << "<date>" << endl << endl
		<< "Qty             ISBN             Title                 Price                   Total" << endl
		<< "_____________________________________________________________________________________________" << endl;
	
	double subtotalTotal = 0, taxTotal = 0, totalTotal = 0;

	for (int i = 0; i < totalQty; i++) {
		cout << sold[i].getQtySold() << "               " 
			<< book[sold[i].getBookIndex()].getISBN() << "             " 
			<< book[sold[i].getBookIndex()].getTitle() << "                 "
			<< "$ " << fixed << setprecision(2) << showpoint << book[sold[i].getBookIndex()].getRetail() << "                   $ "
			<< fixed << setprecision(2) << showpoint << sold[i].getSubtotal() << endl;

		subtotalTotal += sold[i].getSubtotal();
		taxTotal += sold[i].getTax(); 
		totalTotal += sold[i].getTotal();
	}

	cout << endl << endl
		<< "          Subtotal $ " << fixed << setprecision(2) << showpoint << subtotalTotal << endl
		<< "               Tax $ " << fixed << setprecision(2) << showpoint << taxTotal << endl
		<< "             Total $ " << fixed << setprecision(2) << showpoint << totalTotal << endl << endl
		<< "Thank You For Shopping at Serendipity!";
}
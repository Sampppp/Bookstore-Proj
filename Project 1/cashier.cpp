/******************************************************************
** Program: Chapter 14, Programming Project 10
** Course: CS226 CRN 36331
** Professor: Ping-Wei Tsai
** Student: Samson Pak
** Due Date: 04/25/22
******************************************************************/
#include "cashier.h"
#include "bookInfo.h"
#include "strUpper.h"
#include "BookData.h"

void cashier() {
	//cost variables
	const double TAX_RATE = 0.6;
	double subtotal = 0, total, tax;
	//input variables
	char input, choice;
	char title1[51], isbn1[14];
	int quantity1 = 0;
	//loop variable
	int i, o = -1;
	int bookSelect[20], purchaseQty[20];

	//Cashier input menu
	cout << endl << endl
		<< "Serendupity Booksellers" << endl
		<< "Cashier Menu" << endl << endl;
	//repeats if user wants to purchase another book
	do {
		//variable increments to count how many different books are bing purchased and used as a variable for the array spot for the quantity of each type of book being bought
		o++;
		//resets variable for the array spot for which selects a book
		i = 0;
		
		//searches the system for a matching ISBN
		for (i = 0; i <= 20; i++) {
			//user input
			cout << "ISBN: ";
			cin.ignore();
			cin.getline(isbn1, 14);
			//converts to uppercase
			strUpper(isbn1);
			//if the ISBN is not matched with any in the system, error will be displayed and function will return
			
			if (strstr(book[i].getISBN(), isbn1)) {
				cout << endl << "          Possible match found: " << book[i].getTitle() << endl << endl;
				do {
					cout << "          Is this a correct match?(y/n) ";
					cin >> choice;
					if (choice != 'y' && choice != 'n')
						cout << endl << endl << "          Please enter a valid character!";
				} while (choice != 'y' && choice != 'n');
				//saves which array space the book being purchased is in
				if (choice == 'y') {
					bookSelect[o] = i;
					break;
				}
				else
					return;
			}
			if (i == 20) {
				cout << endl << "ISBN is not recognized by the system";
				return;
			}
		}
		//displays the selected book's info
		bookInfo(bookSelect[o]);
		//checks if the book is in stock
		if (book[bookSelect[o]].getQty() == 0) {
			cout << endl << endl << "This book is out of stock";
			return;
		}
		//asks for a valid amount of books being purchased
		do {
			cout << endl << "How many of this book would you like to purchase?: ";
			cin >> purchaseQty[o];
			if (purchaseQty[o] > book[bookSelect[o]].getQty() || purchaseQty[o] <= 0)
				cout << endl << endl << "Please enter a valid amount";
		} while (purchaseQty[o] > book[bookSelect[o]].getQty() || purchaseQty[o] <= 0);

		//edits the available stock of the book being purchased;
		book[bookSelect[o]].setQty(book[bookSelect[o]].getQty() - purchaseQty[o]);

		//calculates the subtotal of the book(s) being purchased
		subtotal += book[bookSelect[o]].getWholesale() * purchaseQty[o];

		//prompts user if they want to add more books to their purchase
		do {
			cout << endl << "Would you like to purchase another title? (y/n): ";
			cin >> input;
			if (input != 'y' && input != 'n')
				cout << endl << "Please enter a valid response";
		} while (input != 'y' && input != 'n');

	} while (input == 'y');

	//calculates the cost of the purchase
	tax = subtotal * TAX_RATE;
	total = subtotal + tax;

	//receipt 
	cout << endl << endl << endl
		<< "Serendipity Book Sellers" << endl << endl
		<< "Date: " << "<date>" << endl << endl
		<< "Qty             ISBN             Title                 Price                   Total" << endl
		<< "_____________________________________________________________________________________________" << endl;
	//repeats the book information for the book(s) being purchased
	for (int p = 0; p <= o; p++) {
		cout << purchaseQty[p] << "               " 
			<< book[bookSelect[p]].getISBN() << "             " 
			<< book[bookSelect[p]].getTitle() << "                 " 
			<< "$ " << fixed << setprecision(2) << showpoint << book[bookSelect[p]].getWholesale() << "                   $ " 
			<< fixed << setprecision(2) << showpoint << (purchaseQty[p] * book[bookSelect[p]].getWholesale()) << endl;
	}
	cout << endl << endl
		<< "          Subtotal $ " << fixed << setprecision(2) << showpoint << subtotal << endl
		<< "               Tax $ " << fixed << setprecision(2) << showpoint << tax << endl
		<< "             Total $ " << fixed << setprecision(2) << showpoint << total << endl << endl
		<< "Thank You For Shopping at Serendipity!";
}
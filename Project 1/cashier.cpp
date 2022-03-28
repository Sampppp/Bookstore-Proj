/******************************************************************
** Program: Chapter 8, Programming Project 4
** Course: CS226 CRN 36331
** Professor: Ping-Wei Tsai
** Student: Samson Pak
** Due Date: 02/28/22
******************************************************************/
#include "cashier.h"
#include "bookInfo.h"

void cashier() {
	//cost variables
	const double TAX_RATE = 0.6;
	double subtotal = 0, total, tax;

	//input variables
	char input;
	string date1 = "1/1/1", isbn1;
	string title1;
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
		
		//user input
		cout << "ISBN: ";
		cin >> isbn1;

		//searches the system for a matching ISBN
		for (i = 0; i <= 20; i++) {
			//if the ISBN is not matched with any in the system, error will be displayed and function will return
			if (i == 20) {
				cout << endl << "ISBN is not recognized by the system";
				return;
			}
			//compares inputed ISBN with system's data to find a match
			if (isbn[i] == isbn1) {
				//saves which array space the book being purchased is in
				bookSelect[o] = i;
				//sets loop variable to stop the loop
				i = 21;
			}
		}
		//displays the selected book's info
		bookInfo(bookSelect[o]);
		//checks if the book is in stock
		if (qty[bookSelect[o]] == 0) {
			cout << endl << endl << "This book is out of stock";
			return;
		}
		//asks for a valid amount of books being purchased
		do {
			cout << endl << "How many of this book would you like to purchase?: ";
			cin >> purchaseQty[o];
			if (purchaseQty[o] > qty[bookSelect[o]] || purchaseQty[o] <= 0)
				cout << endl << endl << "Please enter a valid amount";
		} while (purchaseQty[o] > qty[bookSelect[o]] || purchaseQty[o] <= 0);

		//edits the available stock of the book being purchased;
		qty[bookSelect[o]] -= purchaseQty[o];

		//calculates the subtotal of the book(s) being purchased
		subtotal += wholesale[bookSelect[o]] * purchaseQty[o];

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
		<< "Date: " << date1 << endl << endl
		<< "Qty             ISBN             Title                 Price                   Total" << endl
		<< "_____________________________________________________________________________________________" << endl;
	//repeats the book information for the book(s) being purchased
	for (int p = 0; p <= o; p++) {
		cout << purchaseQty[p] << "               " << isbn[bookSelect[p]] << "             " << title[bookSelect[p]] << "                 " << "$ " << fixed << setprecision(2) << showpoint << wholesale[bookSelect[p]] << "                   $ " << fixed << setprecision(2) << showpoint << (purchaseQty[p] * wholesale[bookSelect[p]]) << endl;
	}
	cout << endl << endl
		<< "          Subtotal $ " << fixed << setprecision(2) << showpoint << subtotal << endl
		<< "               Tax $ " << fixed << setprecision(2) << showpoint << tax << endl
		<< "             Total $ " << fixed << setprecision(2) << showpoint << total << endl << endl
		<< "Thank You For Shopping at Serendipity!";
}
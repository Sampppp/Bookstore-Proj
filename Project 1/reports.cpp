/******************************************************************
** Program: Chapter 8, Programming Project 4
** Course: CS226 CRN 36331
** Professor: Ping-Wei Tsai
** Student: Samson Pak
** Due Date: 02/28/22
******************************************************************/
#include "reports.h"
#include "bookInfo.h"

void reports() {
	int choice;
	do {
		//displays menu
		cout << endl << endl
			<< "           Serendipity Booksellers" << endl
			<< "                   Reports" << endl << endl
			<< "          1. Inverntory Listing" << endl
			<< "          2. Inverntory Wholesale Value" << endl
			<< "          3. Inverntory Retail Value" << endl
			<< "          4. Listing by Quantity" << endl
			<< "          5. Listing by Cost" << endl
			<< "          6. Listing by Age" << endl
			<< "          7. Return to Main Menu" << endl;
		//repeats the enter prompt if an invalid input was made
		do {
			cout << endl << "          Enter Your Choice: ";
			cin >> choice;
			switch (choice) {
			case 1:
				repListing();
				break;
			case 2:
				repWholesale();
				break;
			case 3:
				repRetail();
				break;
			case 4:
				repQty();
				break;
			case 5:
				repCost();
				break;
			case 6:
				repAge();
				break;
			case 7:
				return;
				break;
			default:
				cout << endl << "          Please enter a number in the range 1 - 7" << endl;
			}
		} while (choice > 7 || choice < 1);
	} while (choice != 7);
}

//funtions
void repListing() {
	//variable to count the empty spots in the system;
	int empty = 0, choice;

	cout << endl << endl
		<< "           Serendipity Booksellers" << endl
		<< "               Listing Report" << endl << endl;
	//displays all the book info in the system
	for (int i = 0; i < 20; i++) {
		if (title[i] != "")
			bookInfo(i);
		else
			empty++;
	}
	//displays the number of books listed and prompts the user to exit back to the menu
	cout << endl << "          There are " << 20 - empty << "books in the sytem" << endl
		<< "          1. Return to Menu";
	do {
		cout << endl << endl << "          Enter Your Choice: ";
		cin >> choice;
		if (choice != 1)
			cout << endl << "          Please enter 1 to exit" << endl;
	} while (choice != 1);
	return;
}

void repWholesale() {
	int total = 0, choice;
	cout << endl << endl
		<< "           Serendipity Booksellers" << endl
		<< "              Wholesale Report" << endl << endl;
	for (int i = 0; i < 20; i++) {
		if (title[i] != "") {
			bookInfo(i);
			total += wholesale[i] * qty[i];
		}
	}
	//displays the value of books listed and prompts the user to exit back to the menu
	cout << endl << "          The wholesale value of the inventory is $" << total << endl
		<< "          1. Return to Menu";
	do {
		cout << endl << endl << "          Enter Your Choice: ";
		cin >> choice;
		if (choice != 1)
			cout << endl << "          Please enter 1 to exit" << endl;
	} while (choice != 1);
	return;
}

void repRetail() {
	int total = 0, choice;
	cout << endl << endl
		<< "           Serendipity Booksellers" << endl
		<< "                Retail Report" << endl << endl;
	for (int i = 0; i < 20; i++) {
		if (title[i] != "") {
			bookInfo(i);
			total += retail[i] * qty[i];
		}
	}
	//displays the value of books listed and prompts the user to exit back to the menu
	cout << endl << "          The retail value of the inventory is $" << total << endl
		<< "          1. Return to Menu";
	do {
		cout << endl << endl << "          Enter Your Choice: ";
		cin >> choice;
		if (choice != 1)
			cout << endl << "          Please enter 1 to exit" << endl;
	} while (choice != 1);
	return;
}

void repQty() {
	int arr[20];
	int *ptr[20];

	for (int i = 0; i < 20; i++) {
		arr[i] = qty[i];
		ptr[i] = &arr[i];
	}
	
	//selection sort the array
	int i, j, max;

	for (i = 0; i < 19; i++) {
		max = i;
		for (j = i + 1; j < 20; j++) {
			if (arr[j] > arr[max])
				max = j;
		}
		//swaps the values
		int temp = arr[max];
		arr[max] = arr[i];
		arr[i] = temp;
	}
	
	//printing the sorted array
	for (int i = 0; i < 20; i++) {
		if(title[i] != "")
			bookInfo(*ptr[i]);
	}
}

void repCost() {

}

void repAge() {

}


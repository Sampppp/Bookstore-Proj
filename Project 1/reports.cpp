/******************************************************************
** Program: Chapter 14, Programming Project 10
** Course: CS226 CRN 36331
** Professor: Ping-Wei Tsai
** Student: Samson Pak
** Due Date: 04/25/22
******************************************************************/
#include "reports.h"
#include "bookInfo.h"
#include "BookData.h"
#include "Menus.h"

void reports() {
	int choice;
	do {
		//displays menu
		cout << menu.getShopHeader() << menu.getRepMenu();
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

	cout << menu.getShopHeader()
		<< "               Listing Report" << endl << endl;
	//displays all the book info in the system
	for (int i = 0; i < 20; i++) {
		if (book[i].isEmpty() == false)
			bookInfo(i);
		else
			empty++;
	}
	//displays the number of books listed and prompts the user to exit back to the menu
	cout << endl << "          There are " << 20 - empty << " books in the sytem" << endl
		<< "          Press any key and enter to return to menu: ";
	cin >> choice;
	return;
}

void repWholesale() {
	int total = 0, choice;
	cout << menu.getShopHeader()
		<< "              Wholesale Report" << endl << endl;
	for (int i = 0; i < 20; i++) {
		if (book[i].isEmpty() == false) {
			bookInfo(i);
			total += book[i].getWholesale() * book[i].getQty();
		}
	}
	//displays the value of books listed and prompts the user to exit back to the menu
	cout << endl << "          The wholesale value of the inventory is $" << total << endl
		<< "          Press any key and enter to return to menu: ";
	cin >> choice;
	return;
}

void repRetail() {
	int total = 0, choice;
	cout << menu.getShopHeader()
		<< "                Retail Report" << endl << endl;
	for (int i = 0; i < 20; i++) {
		if (book[i].isEmpty() == false) {
			bookInfo(i);
			total += book[i].getRetail() * book[i].getQty();
		}
	}
	//displays the value of books listed and prompts the user to exit back to the menu
	cout << endl << "          The retail value of the inventory is $" << total << endl
		<< "          Press any key and enter to return to menu: ";
	cin >> choice;
	return;
}

void repQty() {
	int arr1[20], arr2[20];
	//initializes the array
	for (int i = 0; i < 20; i++) {
		arr1[i] = i;
		arr2[i] = book[i].getQty();
	}
	//selection sort the array
	int i, j, max;
	for (i = 0; i < 19; i++) {
		max = i;
		for (j = i + 1; j < 20; j++) {
			if (arr2[j] > arr2[max])
				max = j;
		}
		//swaps the values
		int temp = arr1[max];
		arr1[max] = arr1[i];
		arr1[i] = temp;

		temp = arr2[max];
		arr2[max] = arr2[i];
		arr2[i] = temp;
	}

	//prints books in order
	for (int i = 0; i < 20; i++) {
		if (book[i].isEmpty() == false)
			bookInfo(arr1[i]);
	}
	int choice;
	cout << endl << "          The book have been sorted by quantity in decending order" << endl
		<< "          Press any key and enter to return to menu: ";
	cin >> choice;
	return;
}

void repCost() {
	int arr1[20];
	double arr2[20];
	//initializes the array
	for (int i = 0; i < 20; i++) {
		arr1[i] = i;
		arr2[i] = book[i].getWholesale();
	}
	//selection sort the array
	int i, j, max;
	for (i = 0; i < 19; i++) {
		max = i;
		for (j = i + 1; j < 20; j++) {
			if (arr2[j] > arr2[max])
				max = j;
		}
		//swaps the values
		int temp1 = arr1[max];
		arr1[max] = arr1[i];
		arr1[i] = temp1;

		double temp2 = arr2[max];
		arr2[max] = arr2[i];
		arr2[i] = temp2;
	}

	//prints books in order
	for (int i = 0; i < 20; i++) {
		if (book[i].isEmpty() == false)
			bookInfo(arr1[i]);
	}
	int choice;
	cout << endl << "          The book have been sorted by cost in decending order" << endl
		<< "          Press any key and enter to return to menu: ";
	cin >> choice;
	return;
}

void repAge() {
	 int arr1[20];
	char *arr2[20];
	//initializes the array
	for (int i = 0; i < 20; i++) {
		arr1[i] = i;
		arr2[i] = book[i].getDate();
	}
	//selection sort the array
	int i, j, max;
	for (i = 0; i < 19; i++) {
		max = i;
		for (j = i + 1; j < 20; j++) {
			if (arr2[j] < arr2[max])
				max = j;
		}
		//swaps the values
		int temp1 = arr1[max];
		arr1[max] = arr1[i];
		arr1[i] = temp1;

		char *temp2 = arr2[max];
		arr2[max] = arr2[i];
		arr2[i] = temp2;
	}

	//prints books in order
	for (int i = 0; i < 20; i++) {
		if (book[i].isEmpty() == false)
			bookInfo(arr1[i]);
	}
	int choice;
	cout << endl << "          The book have been sorted by date from oldest to newest" << endl
		<< "          Press any key and enter to return to menu: ";
	cin >> choice;
	return;
}
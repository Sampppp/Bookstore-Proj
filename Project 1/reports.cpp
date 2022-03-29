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
		if (strcmp(title[i], "") == 0)
			bookInfo(i);
		else
			empty++;
	}
	//displays the number of books listed and prompts the user to exit back to the menu
	cout << endl << "          There are " << 20 - empty << " books in the sytem" << endl
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
		if (strcmp(title[i], "") == 0) {
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
		if (strcmp(title[i], "") == 0) {
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
	int arr1[20], arr2[20];
	//initializes the array
	for (int i = 0; i < 20; i++) {
		arr1[i] = i;
		arr2[i] = qty[i];
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
		if (strcmp(title[i], "") == 0)
			bookInfo(arr1[i]);
	}
	int choice;
	cout << endl << "          The book have been sorted by quantity in decending order" << endl
		<< "          1. Return to Menu";
	do {
		cout << endl << endl << "          Enter Your Choice: ";
		cin >> choice;
		if (choice != 1)
			cout << endl << "          Please enter 1 to exit" << endl;
	} while (choice != 1);
	return;
}

void repCost() {
	int arr1[20];
	double arr2[20];
	//initializes the array
	for (int i = 0; i < 20; i++) {
		arr1[i] = i;
		arr2[i] = wholesale[i];
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
		if (strcmp(title[i], "") == 0)
			bookInfo(arr1[i]);
	}
	int choice;
	cout << endl << "          The book have been sorted by cost in decending order" << endl
		<< "          1. Return to Menu";
	do {
		cout << endl << endl << "          Enter Your Choice: ";
		cin >> choice;
		if (choice != 1)
			cout << endl << "          Please enter 1 to exit" << endl;
	} while (choice != 1);
	return;
}

void repAge() {
	 int arr1[20];
	char *arr2[20];
	//initializes the array
	for (int i = 0; i < 20; i++) {
		arr1[i] = i;
		arr2[i] = date[i];
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
		if (strcmp(title[i], "") == 0)
			bookInfo(arr1[i]);
	}
	int choice;
	cout << endl << "          The book have been sorted by date from oldest to newest" << endl
		<< "          1. Return to Menu";
	do {
		cout << endl << endl << "          Enter Your Choice: ";
		cin >> choice;
		if (choice != 1)
			cout << endl << "          Please enter 1 to exit" << endl;
	} while (choice != 1);
	return;
}
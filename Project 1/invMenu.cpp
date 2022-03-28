/******************************************************************
** Program: Chapter 8, Programming Project 4
** Course: CS226 CRN 36331
** Professor: Ping-Wei Tsai
** Student: Samson Pak
** Due Date: 02/28/22
******************************************************************/
#include "invMenu.h"
#include "bookInfo.h"
#include "strUpper.h"

void invMenu() {
	int choice;
	do {
		//displays menu
		cout << endl << endl
			<< "           Serendipity Booksellers" << endl
			<< "             Inventory Database" << endl << endl
			<< "          1. Look Up a Book" << endl
			<< "          2. Add a Book" << endl
			<< "          3. Edit a Book's Record" << endl
			<< "          4. Delete a Book" << endl
			<< "          5. Return to the Main Menu" << endl;
		//repeats the enter prompt if an invalid input was made
		do {
			cout << endl << "          Enter Your Choice: ";
			cin >> choice;
			switch (choice) {
			case 1:
				lookUpBook();
				break;
			case 2:
				addBook();
				break;
			case 3:
				editBook();
				break;
			case 4:
				deleteBook();
				break;
			case 5:
				return;
				break;
			default:
				cout << endl << "          Please enter a number in the range 1 - 5" << endl;
			}
		} while (choice > 5 || choice < 1);
	} while (choice != 5);
}
//inventory functions
void lookUpBook() {
	string temp;
	//asks for title of book
	cout << endl << endl
		<< "           Serendipity Booksellers" << endl
		<< "              Book Information" << endl << endl
		<< "          Title: ";
	cin.ignore();
	getline(cin, temp);
	//finds if the entered title is valid
	for (int i = 0; i < 20; i++) {
		if (title[i] == temp) {
			bookInfo(i);
			return;
		}
	}
	cout << endl << "          There are no books that match that title." << endl;
}

void addBook() {
	//looks for an availible space in the array
	for (int i = 0; i < 20; i++) {
		if (title[i] == "") {
			//asks for information input
			cout << endl << endl
				<< "           Serendipity Booksellers" << endl
				<< "                   Add Book" << endl << endl
				<< "          ISBN: ";
			cin >> isbn[i];
			cout << "          Title: ";
			cin.ignore();
			getline(cin, title[i]);
			cout << "          Author: ";
			cin.ignore();
			getline(cin, author[i]);
			cout << "          Publisher: ";
			cin.ignore();
			getline(cin, publisher[i]);
			cout << "          Date Added: ";
			cin >> date[i];
			cout << "          Quantity-On-Hand: ";
			cin >> qty[i];
			cout << "          Wholesale Cost: $";
			cin >> wholesale[i];
			cout << "          Retail Price: $";
			cin >> retail[i];
			return;
		}
	}
	cout << endl << "          No more books may be added to the inventory." << endl;
}

void editBook() {
	string temp;
	int choice;
	//asks for title of book
	cout << endl << endl
		<< "           Serendipity Booksellers" << endl
		<< "                  Edit Book" << endl << endl
		<< "          Title: ";
	cin.ignore();
	getline(cin, temp);
	//finds if the entered title is valid
	for (int i = 0; i < 20; i++) {
		if (title[i] == temp) {
			//displays book info
			bookInfo(i);
			//asks for which information to be edited
			do {
				cout << endl << endl << "          What informatio would you like to edit?" << endl << endl
					<< "          1. ISBN" << endl
					<< "          2. Title" << endl
					<< "          3. Author" << endl
					<< "          4. Publisher" << endl
					<< "          5. Date added" << endl
					<< "          6. Quantity-On-Hand" << endl
					<< "          7. Wholesale price" << endl
					<< "          8. Retail price" << endl
					<< "          9. Return to Inventory Menu" << endl;
				do {
					cout << endl << "          Enter Your Choice: ";
					cin >> choice;
					switch (choice) {
					case 1:
						cout << "          ISBN: ";
						cin.ignore();
						getline(cin, isbn[i]);
						break;
					case 2:
						cout << "          Title: ";
						cin.ignore();
						getline(cin, title[i]);
						break;
					case 3:
						cout << "          Author: ";
						cin.ignore();
						getline(cin, author[i]);
					case 4:
						cout << "          Publisher: ";
						cin.ignore();
						getline(cin, publisher[i]);
						break;
					case 5:
						cout << "          Date Added: ";
						cin >> date[i];
						break;
					case 6:
						cout << "          Quantity-On-Hand: ";
						cin >> qty[i];
						break;
					case 7:
						cout << "          Wholesale Cost: $";
						cin >> wholesale[i];
						break;
					case 8:
						cout << "          Retail Price: $";
						cin >> retail[i];
						break;
					case 9:
						return;
						break;
					default:
						cout << endl << "          Please enter a number in the range 1 - 9" << endl;
					}
				} while (choice > 9 || choice < 1);
			} while (choice != 9);
			return;
		}
	}
	cout << endl << "          There are no books that match that title." << endl;
}

void deleteBook() {
	char choice;
	string temp;
	//asks for title of book
	cout << endl << endl
		<< "           Serendipity Booksellers" << endl
		<< "                  Delete Book" << endl << endl
		<< "          Title: ";
	cin.ignore();
	getline(cin, temp);
	//finds if the entered title is valid
	for (int i = 0; i < 20; i++) {
		if (title[i] == temp) {
			//displays book info
			bookInfo(i);
			//confirms deletion
			cout << endl << "          Are you sure you want to delete this book's information? (y/n): ";
			cin >> choice;
			if (choice == 'y') {
				isbn[i] = "";
				title[i] = "";
			}
			else
				cout << endl << "          Canceled book deletion.";
			return;
		}
	}
	cout << endl << "          There are no books that match that title." << endl;
}
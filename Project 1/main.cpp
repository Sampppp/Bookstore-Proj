/******************************************************************
** Program: Chapter 10, Programming Project 6
** Course: CS226 CRN 36331
** Professor: Ping-Wei Tsai
** Student: Samson Pak
** Due Date: 03/28/22
******************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "bookInfo.h"
#include "cashier.h"
#include "invMenu.h"
#include "reports.h"
#include "strUpper.h" 
#include "BookData.h"
using namespace std;

fstream invFile;

//structure
BookData book[20];

int main() {
	//opens the inventory file
	invFile.open("inventory.dat", ios::in);
	//creates the inventory file if it does not exist
	if (invFile.fail()) {
		invFile.open("inventory.dat", ios::in);
		invFile.close();
		invFile.clear();
		cout << "New file has been created, you must add books to the inventory!";
	}
	//copies the data in the inventory file to the book struct
	else {
		for (int i = 0; i < 20; i++) {
			//loops until all 20 books are copied or the end of the file is reached
			if (invFile.eof())
				break;

			invFile.seekg(i * sizeof(book), ios::beg);
			invFile.read(reinterpret_cast<char*>(&book), sizeof(book));
			book[i];
		}
		//closes file
		invFile.close();
		invFile.clear();
	}
	//main menu
	int choice;
	do {
		//displays menu
		cout << endl << endl
			<< "           Serendipity Booksellers" << endl
			<< "                   Main Menu" << endl << endl
			<< "          1. Cashier Module" << endl
			<< "          2. Inventory Database Module" << endl
			<< "          3. Report Module" << endl
			<< "          4. Exit" << endl;
		//repeats the enter prompt if an invalid input was made
		do {
			cout << endl << "          Enter Your Choice: ";
			cin >> choice;
			switch (choice) {
			case 1:
				cashier();
				break;
			case 2:
				invMenu();
				break;
			case 3:
				reports();
				break;
			case 4:
				//opens the inventory file to input any new or changed data from the book struct
				invFile.open("inventory.dat", ios::out);
				//copies the data for all the 20 books into inventory file
				for (int i = 0; i < 20; i++) {
					invFile.seekp(i * sizeof(book), ios::beg);
					invFile.write(reinterpret_cast<char*>(&book), sizeof(book));
				}
				//closes file
				invFile.close();
				invFile.clear();

				exit(0);
				break;
			default:
				cout << endl << "          Please enter a number in the range 1 - 4" << endl;
				break;
			}
		} while (choice > 5 || choice < 1);
	} while (choice != 4);
	return 0;
}


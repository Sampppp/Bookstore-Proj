/******************************************************************
** Program: Chapter 16, Programming Project 12
** Course: CS226 CRN 36331
** Professor: Ping-Wei Tsai
** Student: Samson Pak
** Due Date: 05/9/22
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
#include "Menus.h"
using namespace std;

//class
InvBook book[20];
Menus menu;

fstream invFile;

int main() {
	try {		//opens the inventory file
		invFile.open("inventory.dat", ios::in);
		if (invFile.fail()) {
			invFile.close();	//closes file
			invFile.clear();
			throw "Inventory File Missing!";		//throws exeption
		}

		else {		//copies the data in the inventory file to the book struct
			for (int i = 0; i < 20; i++) {		//loops until all 20 books are copied or the end of the file is reached
				if (invFile.eof())
					break;

				invFile.seekg(i * sizeof(book), ios::beg);
				invFile.read(reinterpret_cast<char*>(&book), sizeof(book));
				book[i];
			}

			invFile.close();	//closes file
			invFile.clear();
		}
	}
	catch (char* msg) {		//catches exeption
		cout << msg;

		/*
		invFile.open("inventory.dat", ios::in); //creates new file
		invFile.close();
		invFile.clear();
		cout << "New file has been created, you must add books to the inventory!";
		*/
		exit(0);
	}
	
	

	
	//main menu
	int choice;
	do {
		//displays menu
		cout << menu.getShopHeader() << menu.getMainMenu();
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


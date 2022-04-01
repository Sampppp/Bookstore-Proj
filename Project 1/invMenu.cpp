/******************************************************************
** Program: Chapter 10, Programming Project 6
** Course: CS226 CRN 36331
** Professor: Ping-Wei Tsai
** Student: Samson Pak
** Due Date: 03/28/22
******************************************************************/
#include "invMenu.h"
#include "bookInfo.h"
#include "strUpper.h"
#include "BookData.h"

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
	char temp[51];
	char choice;
	//asks for title of book
	cout << endl << endl
		<< "           Serendipity Booksellers" << endl
		<< "              Book Information" << endl << endl;
		
	//finds if the entered title is valid
	for (int i = 0; i < 20; i++) {
		//asks user for a title
		cout << "          Title: ";
		cin.ignore();
		cin.getline(temp, 51);
		//converts to uppercase
		strUpper(temp);
		//matches the entere d title with the system
		if (strstr(book[i].title, temp)) {
			cout << endl << "          Possible match found: " << book[i].title << endl << endl;
			do {
				cout << "          Is this a correct match?(y/n) ";
				cin >> choice;
				if (choice != 'y' && choice != 'n')
					cout << endl << endl << "          Please enter a valid character!";
			} while (choice != 'y' && choice != 'n');
			//displays book's information if match is found
			if (choice == 'y')
				bookInfo(i);
			return;
		}
		//if a match is not found, user will be asked to ender a title
	}
	//displays if no match could be found
	cout << endl << "          There are no books that match that title." << endl;
}

void addBook() {
	//looks for an availible space in the array
	for (int i = 0; i < 20; i++) {
		if (isEmpty(i) == 1) {
			//asks for information input
			cout << endl << endl
				<< "           Serendipity Booksellers" << endl
				<< "                   Add Book" << endl << endl;
			//isbn
			cin.ignore();
			cout << "          ISBN: ";
			cin.getline(isbn, 14);
			setISBN(isbn, i);
			
			//title
			cout << "          Title: ";
			cin.getline(title, 51);
			setTitle(title, i);
		
			//author
			cout << "          Author: ";
			cin.getline(author, 31);
			setAuthor(author, i);

			//publisher
			cout << "          Publisher: ";
			cin.getline(publisher, 31);
			setPublisher(publisher, i);
			
			//date
			cout << "          Date Added: ";
			cin.getline(date, 11);
			setDate(date, i);

			//quantity
			cout << "          Quantity-On-Hand: ";
			cin >> qty;
			setQty(qty, i);

			//wholesale
			cout << "          Wholesale Cost: $";
			cin >> wholesale;
			setWholesale(wholesale, i);

			//retail
			cout << "          Retail Price: $";
			cin >> retail;
			setRetail(retail, i);

			cout << endl << endl << "          Book has been entered";
			return;
		}
	}
	cout << endl << "          No more books may be added to the inventory." << endl;
}

void editBook() {
	char temp[51];
	char choice1;
	int choice2;
	//asks for title of book
	cout << endl << endl
		<< "           Serendipity Booksellers" << endl
		<< "                  Edit Book" << endl << endl;
	//finds if the entered title is valid
	for (int i = 0; i < 20; i++) {
		//asks user for a title
		cout << "          Title: ";
		cin.ignore();
		cin.getline(temp, 51);
		//converts to uppercase
		strUpper(temp);
		//matches the entered title with the system
		if (strstr(book[i].title, temp)) {
			cout << endl << "          Possible match found: " << book[i].title << endl << endl;
			do {
				cout << "          Is this a correct match?(y/n) ";
				cin >> choice1;
				if (choice1 != 'y' && choice1 != 'n')
					cout << endl << endl << "          Please enter a valid character!";
			} while (choice1 != 'y' && choice1 != 'n');
			//displays book's information if match is found
			if (choice1 == 'y')
				bookInfo(i);
			else
				return;

			//asks for which information to be edited
			do {
				cout << endl << endl << "          What information would you like to edit?" << endl << endl
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
					cin >> choice2;
					switch (choice2) {
					case 1:
						cout << "          ISBN: ";
						cin.ignore();
						cin.getline(isbn, 14);
						setISBN(isbn, i);
						break;
					case 2:
						cout << "          Title: ";
						cin.ignore();
						cin.getline(title, 14);
						setISBN(title, i);
						break;
					case 3:
						cout << "          Author: ";
						cin.ignore();
						cin.getline(author, 14);
						setISBN(author, i);
					case 4:
						cout << "          Publisher: ";
						cin.ignore();
						cin.getline(publisher, 14);
						setISBN(publisher, i);
						break;
					case 5:
						cout << "          Date added: ";
						cin.ignore();
						cin.getline(date, 14);
						setISBN(date, i);
						break;
					case 6:
						cout << "          Quantity-On-Hand: ";
						cin >> qty;
						setQty(qty, i);
						break;
					case 7:
						cout << "          Wholesale Cost: $";
						cin >> wholesale;
						setQty(wholesale, i);						break;
					case 8:
						cout << "          Retail Price: $";
						cin >> retail;
						setQty(retail, i);						break;
					case 9:
						return;
						break;
					default:
						cout << endl << "          Please enter a number in the range 1 - 9" << endl;
					}
				} while (choice2 > 9 || choice2 < 1);
			} while (choice2 != 9);
			return;
			cout << endl << "          There are no books that match that title." << endl;
		}
		//if a match is not found, user will be asked to ender a title
	}
}

void deleteBook() {
	char temp[51];
	char choice;
	//asks for title of book
	cout << endl << endl
		<< "           Serendipity Booksellers" << endl
		<< "                  Delete Book" << endl << endl;
	//finds if the entered title is valid
	for (int i = 0; i < 20; i++) {
		//asks user for a title
		cout << "          Title: ";
		cin.ignore();
		cin.getline(temp, 51);
		//converts to uppercase
		strUpper(temp);
		//matches the entered title with the system
		if (strstr(book[i].title, temp)) {
			cout << endl << "          Possible match found: " << book[i].title << endl << endl;
			do {
				cout << "          Is this a correct match?(y/n) ";
				cin >> choice;
				if (choice != 'y' && choice != 'n')
					cout << endl << endl << "          Please enter a valid character!";
			} while (choice != 'y' && choice != 'n');
			//displays book's information if match is found
			if (choice == 'y')
				bookInfo(i);
			else
				return;
			//confirms deletion
			do {
				cout << endl << "          Are you sure you want to delete this book's information? (y/n): ";
				cin >> choice;
				if (choice != 'y' && choice != 'n')
					cout << endl << endl << "          Please enter a valid character!";
			} while (choice != 'y' && choice != 'n');
			
			if (choice == 'y') {
				removeBook(i);
			}
			else
				cout << endl << "          Canceled book deletion.";
			return;
		}
	}
	cout << endl << "          There are no books that match that title." << endl;
}
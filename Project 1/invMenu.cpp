#include "invMenu.h"
#include "bookInfo.h"
#include "strUpper.h"
#include "BookData.h"
#include "Menus.h"

void invMenu() {
	int choice;
	do {
		//displays menu
		cout << menu.getShopHeader() << menu.getInvMenu();
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
	cout << menu.getShopHeader()
		<< "              Book Information" << endl << endl;
	//asks user for a title
	cout << "          Title: ";
	cin.ignore();
	cin.getline(temp, 51);
	//converts to uppercase
	strUpper(temp);
	//finds if the entered title is valid
	for (int i = 0; i < 20; i++) {
		if (book[i].bookMatch(temp) == true) {
			bookInfo(i);
			return;
		}
	}
	cout << endl << endl << "          There are no books that match the entered title.";
}

void addBook() {
	char title1[51], isbn1[14], author1[31], publisher1[31], date1[11];
	int qty1;
	double wholesale1, retail1;

	//looks for an availible space in the array
	for (int i = 0; i < 20; i++) {
		if (book[i].isEmpty() == true) {
			//asks for information input
			cout << menu.getShopHeader()
				<< "                   Add Book" << endl << endl;
			//isbn
			cin.ignore();
			cout << "          ISBN: ";
			cin.getline(isbn1, 14);
			book[i].setISBN(isbn1);
			
			//title
			cout << "          Title: ";
			cin.getline(title1, 51);
			book[i].setTitle(title1);
		
			//author
			cout << "          Author: ";
			cin.getline(author1, 31);
			book[i].setAuthor(author1);

			//publisher
			cout << "          Publisher: ";
			cin.getline(publisher1, 31);
			book[i].setPublisher(publisher1);
			
			//date
			cout << "          Date Added: ";
			cin.getline(date1, 11);
			book[i].setDate(date1);

			//quantity
			cout << "          Quantity-On-Hand: ";
			cin >> qty1;
			book[i].setQty(qty1);

			//wholesale
			cout << "          Wholesale Cost: $";
			cin >> wholesale1;
			book[i].setWholesale(wholesale1);

			//retail
			cout << "          Retail Price: $";
			cin >> retail1;
			book[i].setRetail(retail1);

			cout << endl << endl << "          Book has been entered";
			return;
		}
	}
	cout << endl << "          No more books may be added to the inventory." << endl;
}

void editBook() {
	char title1[51], isbn1[14], author1[31], publisher1[31], date1[11];
	int qty1;
	double wholesale1, retail1;

	char temp[51];
	char choice1;
	int choice2;
	//asks for title of book
	cout << menu.getShopHeader()
		<< "                  Edit Book" << endl << endl;
	//asks user for a title
	cout << "          Title: ";
	cin.ignore();
	cin.getline(temp, 51);
	//converts to uppercase
	strUpper(temp);
	//finds if the entered title is valid
	for (int i = 0; i < 20; i++) {
		if (book[i].bookMatch(temp) == true) {
			bookInfo(i);
			//displays menu for which information is to be edited
			do {
				cout << endl << endl << "          What information would you like to edit?" << endl << endl
					<< menu.getEditMenu();
				do {
					cout << endl << "          Enter Your Choice: ";
					cin >> choice2;
					switch (choice2) {
					case 1:
						cout << "          ISBN: ";
						cin.ignore();
						cin.getline(isbn1, 14);
						book[i].setISBN(isbn1);
						break;
					case 2:
						cout << "          Title: ";
						cin.ignore();
						cin.getline(title1, 14);
						book[i].setTitle(title1);
						break;
					case 3:
						cout << "          Author: ";
						cin.ignore();
						cin.getline(author1, 14);
						book[i].setAuthor(author1);
					case 4:
						cout << "          Publisher: ";
						cin.ignore();
						cin.getline(publisher1, 14);
						book[i].setPublisher(publisher1);
						break;
					case 5:
						cout << "          Date Added: ";
						cin.ignore();
						cin.getline(date1, 14);
						book[i].setDate(date1);
						break;
					case 6:
						cout << "          Quantity-On-Hand: ";
						cin >> qty1;
						book[i].setQty(qty1);
						break;
					case 7:
						cout << "          Wholesale Cost: $";
						cin >> wholesale1;
						book[i].setWholesale(wholesale1);						break;
					case 8:
						cout << "          Retail Price: $";
						cin >> retail1;
						book[i].setRetail(retail1);						break;
					case 9:
						return;
						break;
					default:
						cout << endl << "          Please enter a number in the range 1 - 9" << endl;
					}
				} while (choice2 > 9 || choice2 < 1);
			} while (choice2 != 9);
			return;
		}
	}
	//displays error if no matches are found
	cout << endl << endl << "          There are no books that match the entered title.";
}

void deleteBook() {
	char temp[51];
	char choice;
	bool loop = false;
	//asks for title of book
	cout << menu.getShopHeader()
		<< "                  Delete Book" << endl << endl;
	
	//asks user for a title
	cout << "          Title: ";
	cin.ignore();
	cin.getline(temp, 51);
	//converts to uppercase
	strUpper(temp);
	//finds if the entered title is valid
	for (int i = 0; i < 20; i++) {
		if (book[i].bookMatch(temp) == true) {
			bookInfo(i);
			//asks for user's verification
			do {
				cout << endl << "          Are you sure you want to delete this book's information? (y/n): ";
				cin >> choice;
				if (choice == 'y')
					book[i].removeBook();
				else if (choice == 'n')
					cout << endl << "          Canceled book deletion.";
				//if invalid character is entered, verificaton will be asked again
				else {
					cout << endl << endl << "          Please enter a valid character!";
					loop = true;
				}
			} while (loop == true);
			return;
		}
	}
	//displays error if no matches are found
	cout << endl << "          There are no books that match that title." << endl;
}
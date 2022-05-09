#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <cctype>
using namespace std;

class Menus {		//class that stores menu layouts
private:
	char shopHeader[39] = "\n\n           Serendipity Booksellers\n";
	char mainMenu[143] = "                   Main Menu\n\n          1. Cashier Module\n          2. Inventory Database Module\n          3. Report Module\n          4. Exit";
	char invMenu[184] = "             Inventory Database\n\n          1. Look Up a Book\n          2. Add a Book\n          3. Edit a Book's Record\n          4. Delete a Book\n          5. Return to the Main Menu";
	char editMenu[228] = "          1. ISBN\n          2. Title\n          3. Author\n          4. Publisher\n          5. Date added\n          6. Quantity-On-Hand\n          7. Wholesale price\n          8. Retail price\n          9. Return to Inventory Menu";
	char repMenu[261] = "                   Reports\n\n          1. Inverntory Listing\n          2. Inverntory Wholesale Value\n          3. Inverntory Retail Value\n          4. Listing by Quantity\n          5. Listing by Cost\n          6. Listing by Age\n          7. Return to Main Menu";
public:
	Menus();	//constructor
	
	char* getShopHeader();		//get functions
	char* getMainMenu();
	char* getInvMenu();
	char* getEditMenu();
	char* getRepMenu();
};

extern Menus menu;

#endif

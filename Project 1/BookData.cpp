/******************************************************************
** Program: Chapter 14, Programming Project 10
** Course: CS226 CRN 36331
** Professor: Ping-Wei Tsai
** Student: Samson Pak
** Due Date: 04/25/22
******************************************************************/
#include "BookData.h"
#include "strUpper.h"
#include "bookInfo.h"

BookData::BookData() {
}

void BookData::setTitle(char* ptr) {
	strUpper(ptr);
	strcpy_s(this->title, ptr);
}
void BookData::setISBN(char* ptr) {
	strUpper(ptr);
	strcpy_s(this->isbn, ptr);
}
void BookData::setAuthor(char* ptr) {
	strUpper(ptr);
	strcpy_s(this->author, ptr);
}
void BookData::setPublisher(char* ptr) {
	strUpper(ptr);
	strcpy_s(this->publisher, ptr);
}
void BookData::setDate(char* ptr) {
	strUpper(ptr);
	strcpy_s(this->date, ptr);
}
void BookData::setQty(int a) {
	this->qty = a;
}
void BookData::setWholesale(double a) {
	this->wholesale = a;
}
void BookData::setRetail(double a) {
	this->retail = a;
}

char* BookData::getTitle() {
	return title;
}
char* BookData::getISBN() {
	return isbn;
}
char* BookData::getAuthor() {
	return author;
}
char* BookData::getPublisher()  {
	return publisher;
}
char* BookData::getDate() {
	return date;
}
int BookData::getQty() {
	return qty;
}
double BookData::getWholesale() {
	return wholesale;
}
double BookData::getRetail() {
	return retail;
}

bool BookData::isEmpty() {
	if (this->title[0] == 0)
		return true;
	else 
		return false;
}
void BookData::removeBook() {
	this->title[0] = 0;
	this->isbn[0] = 0;
}

bool BookData::bookMatch(char* temp) {
	//variable for user verification
	char choice;
	bool loop = false;

	//compares the entered title with the system
	if (strstr(title, temp)) {
		//displays possible matching book
		cout << endl << "          Possible match found: " << title << endl << endl;
		//asks for user's verification
		do {
			cout << "          Is this a correct match?(y/n): ";
			cin >> choice;
			if (choice == 'y')
				return true;
			else if (choice != 'n') {
				cout << endl << endl << "          Please enter a valid character!";
				loop = true;
			}
			//repeats verification if invalid character is entered
		} while (loop == true);
	}
	return false;
}
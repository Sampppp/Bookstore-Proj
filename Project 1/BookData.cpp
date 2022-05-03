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

InvBook::InvBook() {
}

void InvBook::setDate(char* ptr) {
	strUpper(ptr);
	strcpy_s(this->date, ptr);
}
void InvBook::setQty(int a) {
	this->qty = a;
}
void InvBook::setWholesale(double a) {
	this->wholesale = a;
}
void InvBook::setRetail(double a) {
	this->retail = a;
}

char* InvBook::getDate() {
	return date;
}
int InvBook::getQty() {
	return qty;
}
double InvBook::getWholesale() {
	return wholesale;
}
double InvBook::getRetail() {
	return retail;
}

bool InvBook::isEmpty() {
	if (this->getTitle() == 0)
		return true;
	else
		return false;
}
void InvBook::removeBook() {
	setTitle(0);
	setISBN(0);
}
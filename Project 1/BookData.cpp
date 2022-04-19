/******************************************************************
** Program: Chapter 10, Programming Project 6
** Course: CS226 CRN 36331
** Professor: Ping-Wei Tsai
** Student: Samson Pak
** Due Date: 03/28/22
******************************************************************/
#include "BookData.h"
#include "strUpper.h"

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

int BookData::isEmpty() {
	if (this->title[0] == 0)
		return 1;
	else 
		return 0;
}
void BookData::removeBook() {
	this->title[0] = 0;
	this->isbn[0] = 0;
}
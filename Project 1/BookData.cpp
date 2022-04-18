/******************************************************************
** Program: Chapter 10, Programming Project 6
** Course: CS226 CRN 36331
** Professor: Ping-Wei Tsai
** Student: Samson Pak
** Due Date: 03/28/22
******************************************************************/
#include "BookData.h"
#include "strUpper.h"

void setTitle(char* ptr, int i) {
	strUpper(ptr);
	strcpy_s(book[i].title, ptr);
}
void setISBN(char* ptr, int i) {
	strUpper(ptr);
	strcpy_s(book[i].isbn, ptr);
}
void setAuthor(char* ptr, int i) {
	strUpper(ptr);
	strcpy_s(book[i].author, ptr);
}
void setPublisher(char* ptr, int i) {
	strUpper(ptr);
	strcpy_s(book[i].publisher, ptr);
}
void setDate(char* ptr, int i) {
	strUpper(ptr);
	strcpy_s(book[i].date, ptr);
}
void setQty(int a, int i) {
	book[i].qty = a;
}
void setWholesale(double a, int i) {
	book[i].wholesale = a;
}
void setRetail(double a, int i) {
	book[i].retail = a;
}
int isEmpty(int i) {
	if (book[i].title[0] == 0)
		return 1;
	else 
		return 0;
}
void removeBook(int i) {
	book[i].title[0] = 0;
	book[i].isbn[0] = 0;
}
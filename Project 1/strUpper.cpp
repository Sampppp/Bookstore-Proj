/******************************************************************
** Program: Chapter 10, Programming Project 6
** Course: CS226 CRN 36331
** Professor: Ping-Wei Tsai
** Student: Samson Pak
** Due Date: 03/28/22
******************************************************************/
#include "strUpper.h"

void strUpper(char *ptr) {
	while (*ptr != 0) {
		*ptr = toupper(*ptr);
		ptr++;
	}
}
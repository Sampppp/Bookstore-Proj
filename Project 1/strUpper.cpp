#include "strUpper.h"

void strUpper(char *ptr) {
	while (*ptr != 0) {
		*ptr = toupper(*ptr);
		ptr++;
	}
}
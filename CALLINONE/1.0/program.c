#include <stdio.h>

int main() {
	
	int x;
	
	printf("Enter a number: ");

	scanf("%i", &x); // address-of operator
	printf("The given number is: %i\n", x);
	
	return 0;
}

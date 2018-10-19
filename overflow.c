#include <stdio.h>
#include <limits.h>

int main () {

	int number = 1234567;
	int limit = 9;

	for(int i = 1; i < limit; i++){
		number *= i;
		printf("%10d * %d \n",number , i+1);
		if(number > INT_MAX / 8){
			printf("An Overflow has occured!\n");
			break;
		}
	}
	return 0;
}

//Program to tell if a interger number is odd

#include <stdio.h>

int main(void){

int number;
printf("Enter a interger number\n");
scanf("%d",&number);
number =number+1;
if(number % 2 ==0)
    printf("This number is odd");
else{
    printf("%d is not an odd number\n",number-1);
}

return 0;
}


#include <stdio.h>
/*
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6, and 9.
The sum of these multiples is 23. Find the sum of all the multiples of 3 or 5 below 1000. 
Don't forget to use the modulo function. '%'
*/

int main()
{
        int mult = 0;
        int total = 0;

        for (mult = 0; mult <= 999; mult = mult + 1 )
/*              printf("This is the output. %d\n", mult);     */
                if (mult == 3 )
                        total = total + 3;
                else if (mult == 5)
                        total = total + 5;
                else if (mult % 3 == 0 ) 
                        total = total + mult;
                else if (mult % 5 == 0 )
                        total = total + mult;

        printf("%d\n",total);
return(0);
}

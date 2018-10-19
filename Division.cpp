#include <iostream>

using namespace std;

int main(){
    int divisor, dividend, quotient, remainder;

    // first number
    cout << "Enter dividend: ";
    cin >> dividend;

    //second number
    cout << "Enter divisor: ";
    cin >> divisor;

    quotient = dividend / divisor;
    remainder = dividend % divisor;

    cout << "Quotient = " << quotient << endl;
    cout << "Remainder = " << remainder;

    return 0;
}

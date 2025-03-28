/*
Author: Michael Risher
Purpose: program that calculates the monthly payment, total payment and interest paid for a loan on a house;
*/

//system libraries
#include <iostream>  //input/output library
#include <cmath> //pow live here
#include <iomanip> //format plz
using namespace std; //using namespace standard

//user libraries

//global constants not variable
//science, math, conversion, dimension
const float PENNY = 0.01f;

//function prototypes

//execution begins here at main
int main( int argc, char **argv ) {
    //set random number seed

    //declare variables
    float loan,
        interestRate,
        totalPaid,
        monthly,
        interestPaid;
    unsigned short numPayments;

    //initialize variables

    loan = 1113479.50f;
    interestRate = 6.77e-2f / 12.0f; //monthly interest
    numPayments = 30 * 12;

    
    //map/process the inputs -> outputs

    /*
    M = P * ( i * ( 1 + i ) ^ n ) / ( ( 1 + i ) ^ n - 1)
    M is monthly payments
    P is loan amount
    i is interest rate
    n is number payments/months
    */

    float temp = pow( 1 + interestRate, numPayments ); //( 1 + i ) ^ n
    monthly = ( loan * interestRate * temp ) / ( temp - 1 );

    //round up by a penny
    int intPayment = ( monthly + PENNY ) * 100;  //rounds up a penny and shifts it over by 2 places
    monthly = intPayment / 100.0f; //brings it back to a float and shift the to the right by 2 places

    //simulating paying for the loan
    float finalPayment = loan;
    cout << fixed << setprecision( 2 ) << showpoint;
//TODO left off here 
    for( int month = 1; month <= numPayments; month++) {
        
    }


    //display input/outputs

    //clean up memory, close files

    //exit the program
    return 0;
}

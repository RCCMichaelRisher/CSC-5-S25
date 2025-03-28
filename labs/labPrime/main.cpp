/* 
 * Author: Michael Risher
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input Output Library
using namespace std;

//User Libraries

//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes

//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    
    //Declare Variables
    int num, end;


    //Initialize Variables
    cout << "Enter a starting number: ";
    cin >> num;

    cout << "Enter an ending number: ";
    cin >> end;
    //Map/Process the Inputs -> Outputs

    while( num <= end ){
        // cout << num << endl;
        //test that number num is it prime ?

        //is prime testing part
        int divsionCounter = 2;
        bool isPrime = true;
        while( divsionCounter <= ( num - 1 ) ){
            if( num % divsionCounter == 0){ ///its not prime
                isPrime = false;
            }
            divsionCounter++;
        }

        if( isPrime ){
            cout << num << ", ";
        }

        num++;
    }

    

    //Display Inputs/Outputs
    
    //Clean up memory and files
    
    //Exit the Program
    return 0;
}
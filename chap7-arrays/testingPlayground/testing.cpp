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
    
    //Initialize Variables
    
    //Map/Process the Inputs -> Outputs
    int i = 11;
    int test[] = { 10, i, 12};
    i = 15;
    for( int val : test ){
        cout << val << endl;
    }
    
    int c = 0;
    test[ c++ ]++;

    cout << c << ": " << endl;
    for( int val : test ){
        cout << val << endl;
    }
    //Display Inputs/Outputs
    
    //Clean up memory and files
    
    //Exit the Program
    return 0;
}
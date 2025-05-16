/* 
 * Author: Michael Risher
 * Purpose: no checking on stuff
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
    const int size = 3;
    int test[ size ];
    //Initialize Variables
    cout << "test is stored at " << test << endl;
    for( int i = 0; i < size; i++ ){
        test[i] = i;
    }
    
    //Map/Process the Inputs -> Outputs
    
    //Display Inputs/Outputs
    for( int i = -10; i < 90; i++ ){
        cout << i << " = " << test[i] << "|" << endl;
    }
    cout << endl;
    
    //Clean up memory and files
    
    //Exit the Program
    return 0;
}
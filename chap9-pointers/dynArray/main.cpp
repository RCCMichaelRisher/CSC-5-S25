/* 
 * Author: Michael Risher
 * Purpose: dynamic array
 */

//System Libraries
#include <iostream>  //Input Output Library
using namespace std;

//User Libraries

//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes
int *fill( int size );
//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    
    //Declare Variables
    int size;
    int *array;
    
    //Initialize Variables
    cout << "Enter a size ";
    cin >> size;

    array = fill( size );
    
    //Display Inputs/Outputs
    for( int i = 0; i < size; i++ ){
        cout << *( array + i ) << " ";
    }
    cout << endl;
    
    //Clean up memory and files
    delete [] array; //free that memory we claimed
    //Exit the Program
    return 0;
}

int *fill( int size ){
    int *array = new int[size]; //allocate memory for arry
    //Map/Process the Inputs -> Outputs

    //inputted values
    for( int i = 0; i < size; i++ ){
        array[i] = i;
    }

    return array;
}
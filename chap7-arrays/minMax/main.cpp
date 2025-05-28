/* 
 * Author: Michael Risher
 * Purpose: find the min and max with arrays
 * 
 */

//System Libraries
#include <iostream>  //Input Output Library
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes
void fillArr( int arr[], const int size );
int minMax( int arr[], const int size, int &max );
void print( const int arr[], const int size );

//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    srand( time( 0 ) );
    
    //Declare Variables
    const int SIZE = 100;
    int arr[SIZE];
    int min, max;

    
    //Initialize Variables
    fillArr( arr, SIZE ); //fill the array
    //init  min max
    min = arr[0];
    max = arr[0];

    //Map/Process the Inputs -> Outputs
    //figure out how is min max
    min = minMax( arr, SIZE, max);
    
    
    //Display Inputs/Outputs
    //^
    print( arr, SIZE );
    cout << "The min value is " << min << endl;
    cout << "The max value is " << max << endl;
    //Clean up memory and files
    
    //Exit the Program
    return 0;
}

void fillArr( int arr[], const int size ){
    for( int i = 0; i < size; i++ ){
        arr[i] = rand() % 100 + 1; //1-100
    }
}

void print( const int arr[], const int size ){
    for( int i = 0; i < size; i++ ){
        cout << arr[i] << " ";
    }
    cout << endl;
}

//pass max by ref to update that value in main as well
int minMax( int arr[], const int size, int &max ){
    int min = arr[0];

    for( int i = 0; i < size; i++ ){
        if( arr[i] < min ){
            min = arr[i];
        }

        if( arr[i] > max ){
            max = arr[i];
        }

    }

    return min;
}
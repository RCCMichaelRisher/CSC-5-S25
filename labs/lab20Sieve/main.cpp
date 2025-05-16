/* 
 * Author: Michael Risher
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input Output Library
#include <cmath>
using namespace std;

//User Libraries

//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes
int getNumber();
void fillArray( int array[], int n);
void printArray( int array[], int n);
void sieve( int array[], int n );

//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    
    //Declare Variables
    int n;
    
    //Initialize Variables
    n = getNumber();
    int array[ n ];
    fillArray( array, n );
    
    //Map/Process the Inputs -> Outputs
    sieve( array, n );
    //Display Inputs/Outputs
    printArray( array, n );
    //Clean up memory and files
    
    //Exit the Program
    return 0;
}

void sieve( int array[], int n ){
    for( int i = 2; i < n; i++ ){
        if( array[i] != 0 ){ //skips numbers that it has seen as not prime
            for( int j = i * i; j < n; j+= i ){
                array[j] = 0; //erase that number its not prime
            }
        }
    }
}

void fasterSieve( int array[], int n ){
    int stop = sqrt( n );
    for( int i = 2; i < stop; i++ ){
        if( array[i] != 0 ){ //skips numbers that it has seen as not prime
            for( int j = i * i; j < n; j+= i ){
                array[j] = 0; //erase that number its not prime
            }
        }
    }
}

void fillArray( int array[], int n ){
    for( int i = 2; i < n; i++ ){
        array[i] = i;
    }
}


void printArray( int array[], int n ){
    for( int i = 2; i < n; i++ ){
        if( array[i] != 0 )
            cout << array[i] << ", ";
    }
    cout << endl;
}

int getNumber(){
    int n;
    cout << "Enter a number to find primes up to\n> ";
    cin >> n;
    return n;
}
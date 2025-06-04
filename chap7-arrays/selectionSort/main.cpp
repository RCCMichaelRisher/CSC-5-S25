/* 
 * Author: Michael Risher
 * Purpose: selection sort
 */

//System Libraries
#include <iostream>  //Input Output Library
#include <cstdlib>
#include <ctime>

// #include <thread>
// #include <chrono>
using namespace std;

//User Libraries

//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes
void fillArray( int array[], int size );
void print( int array[], int size );
void selectionSort( int array[], int size );
void swapVal( int &a, int &b );


//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    srand( time( 0 ) );
    //Declare Variables
    int size; //size for arr
    do{
        cout << "Enter size for array: ";
        cin >> size;
    } while( size < 5);


    //Initialize Variables
    int array[size];
    //fill array
    fillArray( array, size );

    cout << "unsorted array: ";
    print( array, size );
    cout << endl;

    selectionSort( array, size );
    cout << endl;
    
    cout << "Sorted array: ";
    print( array, size );
    cout << endl;
    //Clean up memory and files
    
    //Exit the Program
    return 0;
}

void fillArray( int array[], int size ){
    for( int i = 0; i < size; i++ ){
        array[i] = rand() % 100;
    }
}

void print( int array[], int size ){
    for( int i = 0; i < size; i++ ){
        cout << array[i] << " ";
    }
}

void selectionSort( int array[], int size ){
    for( int pass = 0; pass < size - 1; pass++ ){ //passes to sort it
        //find min the value 
        int minIdx = pass;
        //find the smallest value
        for( int j = pass + 1; j < size; j++ ){
            if( array[ minIdx ] > array[j] ){ //if the min is no longer the min value. update min
                minIdx = j;
            }
        }

        //swap the values. bring min to the leftmost edge 
        swapVal( array[pass], array[minIdx] );

        //print the progress
        cout << "\r";
        print( array, size );
        cout << flush;
    }
}

void swapVal( int &a, int &b ){
    int temp = a;
    a = b;
    b = temp;
}
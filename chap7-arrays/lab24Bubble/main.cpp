/* 
 * Author: Michael Risher
 * Purpose: bubble sort
 */

//System Libraries
#include <iostream>  //Input Output Library
using namespace std;

//User Libraries

//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes
void fillArray( int array[], int size );
void printArray( int array[], int size );
void bubbleSort( int array[], int size );
void bubbleSortBetter( int array[], int size );
void swapVal( int &a, int &b );

//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    
    //Declare Variables
    int size;

    //Initialize Variables
    cout << "input a size " ;
    cin >> size;

    int array[size];
    //fill the array
    fillArray( array, size );

    //dispaly
    cout << "Unsorted array" << endl;
    printArray( array, size );
    cout << endl;

    //do the sort
    // bubbleSort( array, size );
    bubbleSort( array, size );

    //display the sorted array
    cout << endl << "Sorted array" << endl;
    printArray( array, size );


    //Exit the Program
    return 0;
}


void fillArray( int array[], int size ){
    for( int i = 0; i < size; i++ ){
        array[i] = size - i; //makes it backwards 9,8,7,...etc
    }
}
void printArray( int array[], int size ){
    for( int i = 0; i < size; i++ ){
        cout << array[i] << ", ";
    }
    cout << endl;
}

void bubbleSortBetter( int array[], int size ){
    bool swapped = false;
    int pass = 0;
    do{ //formerly our pass for loop
        swapped = false;
        // cout << "pass " << (++pass) << ":" <<endl;
        for( int i = 0; i < size - 1; i++ ){
            // cout << "\ti=" << i << endl;
            if( array[i] > array[i+1] ){
                swapVal( array[i], array[i+1] );
                swapped = true; //keep track of if you need to do another pass
            }   
        }
        // printArray( array, size );
        //reduce the array since we know we sorted 1 number
        size--;
    } while( swapped );

}

void bubbleSort( int array[], int size ){
    for( int pass = 0; pass < size - 1; pass++ ){
        // cout << "pass " << (pass) << ":" <<endl;
        for( int i = 0; i < size - 1; i++ ){
            // cout << "\ti=" << i << endl;
            if( array[i] > array[i+1] ){
                swapVal( array[i], array[i+1] );
            }   
        }
    }
}


void swapVal( int &a, int &b ){
    int temp = a;
    a = b;
    b = temp;
}
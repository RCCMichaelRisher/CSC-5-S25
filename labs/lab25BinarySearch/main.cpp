/* 
 * Author: Michael Risher
 * Purpose: binary search 
 */

//System Libraries
#include <iostream>  //Input Output Library
#include <ctime>
#include <cstdlib> 
using namespace std;

//User Libraries

//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes
void fill( int arr[], int size );
void print( int arr[], int size );
void sort( int arr[], int size );
int binarySearch(const int array[], int size, int target);

//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    srand( time(0) );
    //Declare Variables
    int size, target;

    cout << "input size for array: ";
    cin >> size;

    int array[size];

    fill( array, size );
    // print( array, size );

    //ask what to search for
    

    //sort the array
    sort( array, size );
    print( array, size );
    cout << "Enter a number to search for: ";
    cin >> target;
    

    int index = binarySearch( array, size, target );

    if ( index == -1 ){
        cout << target << " was not found in the array." << endl;
    } else {
        cout << target << " was found at index " << index << endl;
    }
    
    //Exit the Program
    return 0;
}

//fill the array with randoms
void fill( int arr[], int size ){
    for( int i =0 ; i < size; i++ ){
        arr[i] = rand() % 100;
    }
}

//print the array
void print( int arr[], int size ){
    for( int i =0 ; i < size; i++ ){
        cout << arr[i] << " ";
    }
    cout << endl;
}

//buuble sort sorting
void sort( int arr[], int size ){
    bool swapped;
    do{
        swapped = false;
        for( int i =0; i < size - 1; i++ ){
            if( arr[i] > arr[i + 1] ){
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = true;
            }
        }
        size--;
    } while( swapped );
}

int binarySearch( const int arr[], int size, int target ){
    int left, mid, right;
    left = 0;
    right = size - 1;

    while( left <= right ){
        //find the mid
        mid = left + ( right - left ) / 2;

        if( arr[mid] == target ){
            return mid;
        } else if( arr[mid] < target ){
            //right half of the array
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}
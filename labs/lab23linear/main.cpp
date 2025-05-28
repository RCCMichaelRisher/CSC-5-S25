/* 
 * Author: Michael Risher
 * Purpose: linear search lab
 */

//System Libraries
#include <iostream>  //Input Output Library
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

//User Libraries

//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes
void fillArray( int [], int );
void print( int [], int );
void findElem( int [], int );
vector<int> linearSearch( const int[], int, int );
//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    srand( time( 0 ) );
    //Declare Variables
    int size;
    
    //Initialize Variables
    //get the size from user
    do{
        cout << "Enter the size for the array >= 10 ";
        cin >> size;
    } while( size < 10 );
    int arr[size];
    
    //Map/Process the Inputs -> Outputs
    fillArray( arr, size );
    
    //Display Inputs/Outputs
    print( arr, size );
    //ask the user for what to search
    findElem( arr, size );
    //Clean up memory and files
    
    //Exit the Program
    return 0;
}


void findElem( int arr[], int size ){
    int findMe;
    cout << "Enter a number to find ";
    cin >> findMe;

    //linearSearch
    vector<int> indices = linearSearch( arr, size, findMe );

    //if the vector is not empty there is stuff
    if( indices.size() > 0 ){
        //it was found we have a non -1 index
        cout << findMe << " was found at index ";
        for( int val : indices ){
            cout << val << ", "; 
        }
        cout << endl;
    } else{
        //index was -1 so not there
        cout << findMe << " was not found in the array." << endl;
    }
}
//fill the array with randoms
void fillArray( int arr[], int size ){
    for( int i = 0; i < size; i++ ){
        arr[i] = rand() % 100 + 1; //random from 1 -100
    }
}

//print the array
void print( int arr[], int size ){
    for( int i = 0; i < size; i++ ){
        cout << arr[i] << " ";  
    }
    cout << endl;
}

/*
int linearSearch(const int array[], int size, int target);
array[]: the array to search
size: the total number of elements
target: the value to search for
Returns: the vector of indices of the target if found, or empty vector if not found
*/

vector<int> linearSearch(const int arr[], int size, int target){
    vector<int> locations;
    for( int i = 0; i < size; i++ ){
        if( arr[i] == target ){
            locations.push_back( i );//return i;
        }
    }
    return locations;
}
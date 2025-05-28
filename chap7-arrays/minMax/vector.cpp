/* 
 * Author: Michael Risher
 * Purpose: find the min and max with arrays
 * 
 */

//System Libraries
#include <iostream>  //Input Output Library
#include <cstdlib>
#include <ctime>
#include <vector> //needed library for vectors.
using namespace std;

//User Libraries

//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes
void fillArr( vector<int> &arr, int size );
int minMax( vector<int> arr, int &max );
void print( const vector<int> arr );

//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    srand( time( 0 ) );
    
    //Declare Variables
    vector<int> arr;
    int min, max, size;

    cout << "What size should the vector be? ";
    cin >> size;
    
    //Initialize Variables
    fillArr( arr, size ); //fill the array
    
    //Map/Process the Inputs -> Outputs
    //figure out how is min max
    min = minMax( arr, max);
    
    
    //Display Inputs/Outputs
    //^
    print( arr );
    cout << "The min value is " << min << endl;
    cout << "The max value is " << max << endl;

    //add some stuf the array/vector
    cout << "Adding 5 more things" << endl;
    fillArr( arr, 5 ); //append 5 new things
    min = minMax( arr, max);
    
    print( arr );
    cout << "The min value is " << min << endl;
    cout << "The max value is " << max << endl;

    //Clean up memory and files
    
    //Exit the Program
    return 0;
}

void fillArr( vector<int> &arr, int size ){
    for( int i = 0; i < size; i++ ){
        arr.push_back( rand() % 100 + 1 ); //1-100
    }
}

void print( const vector<int> arr ){
    for( int i = 0; i < arr.size(); i++ ){
        cout << arr[i] << " ";
    }
    cout << endl;
}

//pass max by ref to update that value in main as well
int minMax( vector<int> arr, int &max ){
    int min = arr[0];
    max = arr[0];

    for( int i = 0; i < arr.size(); i++ ){
        if( arr[i] < min ){
            min = arr[i];
        }

        if( arr[i] > max ){
            max = arr[i];
        }

    }

    return min;
}
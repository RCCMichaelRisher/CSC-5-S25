/* 
 * Author: Michael Risher
 * Purpose: compare static arrays with vectors
 */

//System Libraries
#include <iostream>  //Input Output Library
#include <vector>
using namespace std;

//User Libraries

//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes
void fill( int [], int size );
void fill( vector<int> & );
void print( int [], int size );
void print( vector<int> & );
//Execution begins here at main
int main(int argc, char** argv) {
    
    //static array
    int staticAr[5];
    fill( staticAr, 5 );
    cout << "static array" << endl;
    print( staticAr, 5 );

    //dyanmic vector
    vector<int> dynamicVec(5);
    fill( dynamicVec );
    cout << "dynamic array" << endl;
    print( dynamicVec );

    //check the size of the vector
    cout << "Size of vector is " << dynamicVec.size() << endl;
    cout << "Capacity of vector is " << dynamicVec.capacity() << endl;

    cout << endl;
    //add some stuff the vector
    dynamicVec.push_back( 9 ); //add stuff to the back of the vector
    dynamicVec.push_back( 8 ); //add stuff to the back of the vector
    print( dynamicVec );
    //check the size of the vector
    cout << "Size of vector is " << dynamicVec.size() << endl;
    cout << "Capacity of vector is " << dynamicVec.capacity() << endl;

    cout << endl;
    //remove some stuff the vector
    dynamicVec.pop_back(); //remove stuff from the back of the vector
    dynamicVec.pop_back(); //remove stuff from the back of the vector
    print( dynamicVec );
    //check the size of the vector
    cout << "Size of vector is " << dynamicVec.size() << endl;
    cout << "Capacity of vector is " << dynamicVec.capacity() << endl;
    //Exit the Program
    return 0;
}

void fill( int arr[], int size ){
    for( int i = 0; i < size; i++ ){
        arr[i] = i+1;
    }
}

void fill( vector<int> &arr ){
    for( int i = 0; i < arr.size(); i++ ){
        arr[i] = i+1;
    }
}

void print( int arr[], int size ){
    for( int i = 0; i < size; i++ ){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void print( vector<int> &arr ){
    for( int i = 0; i < arr.size(); i++ ){
        cout << arr[i] << " ";
    }
    cout << endl;
}
/* 
 * Author: Michael Risher
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input Output Library
using namespace std;

//User Libraries

//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes
void func( int *n ){
    cout << "func: "<< *n << endl; 
}
//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    
    //Declare Variables
    int number = 42;
    //pointer variable
    int *ptr = &number; //point at number

    cout << "the value of number " << number << endl;
    cout << "the address of number " << &number << endl;
    cout << "value of ptr " << ptr << endl;
    cout << "value pointed to by ptr " << *ptr << endl;

    *ptr = 100; cout << endl << endl;

    cout << "the value of number " << number << endl;
    cout << "the address of number " << &number << endl;
    cout << "value of ptr " << ptr << endl;
    cout << "value pointed to by ptr " << *ptr << endl;

    ptr = nullptr; //no location

    double arr[5] = {1,3,3,4,5};
    cout << arr << " = " << *arr << endl;
    cout << (arr + 1 ) << " = " << *(arr + 1) << endl; //same as arr[1]
 


    int a = 5,b = 6; 

    int *ptr1 = &a;
    int *ptr2 = &b;

    if( ptr1 == ptr2 ){ //what is this comparing? Just the addresses
        cout << "yay" << endl;
    }

    if( *ptr1 == *ptr2 ){ //comparing the values of the pointers
        
    }

    //call func pass  a pointer to it

    func( ptr1 ); //pass a pointer directly
    func( &a ); //reference the var a to get the address


    //dynamic memory allocation
    int *apple = new int; //it lingers after its out of scope
    int *dynArray = new int[10];  //make a new array of size 10
    //done stuff with this array now i to resize and use again
    delete [] dynArray;
    //make it bigger this time round
    dynArray = new int[20];
    
    //Map/Process the Inputs -> Outputs
    
    //Display Inputs/Outputs
    
    //Clean up memory and files
    delete apple;
    //Exit the Program
    return 0;
}
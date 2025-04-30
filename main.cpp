/* 
 * Author: Michael Risher
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input Output Library
#include <string>
using namespace std;

//User Libraries

//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes
void test( int a ){
    cout << a << endl;;
}

//Execution begins here at main
int main(int argc, char** argv) {
    float a = 1.0f;
    test( a );  //demoting a from float to an int

    char b = 2;
    test( b ); //promoting char to int

    //wont promote/demote string to a number
    // string c = "ccc";
    // test( c );

    bool d = true;
    test( d );

    return 0;
}
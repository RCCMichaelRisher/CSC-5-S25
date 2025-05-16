/* 
 * Author: Michael Risher
 * Purpose: program to do averages from the user
 */

//System Libraries
#include <iostream>  //Input Output Library
using namespace std;

//User Libraries

//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes
int getCount();
void inputScores( int [], int );  //( int &, int ); //( int *, int )
float average( int, int );
//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    
    //Declare Variables
    int count;
    int sum; //hold sum
    float avg;
    // int scores[ count ];
    
    //Initialize Variables
    sum = 0;
    count = getCount(); //get the count from user
    //now we have the size so we can init our array
    int scores[ count ];

    //input scores
    inputScores( scores, count );
    
    //Map/Process the Inputs -> Outputs
    //sum the scores
    for( int val : scores ){
        sum += val;
    }
    avg = average( sum, count );
    //Display Inputs/Outputs
    cout << "The average is " << avg << endl;
    
    //Clean up memory and files
    
    //Exit the Program
    return 0;
}

void inputScores( int scores[], int count ){
    for( int i = 0; i < count; i++ ){
        cout << "Enter score[" << i << "]\n> ";
        cin >> scores[i];
    }
}


int getCount(){
    int n; 
    do{
        cout << "Enter the number of scores you want to input\n> ";
        cin >> n;
    } while( n < 1 );
    return n;
}

float average( int sum, int count ){
    
    return sum / static_cast<float>( count );
}
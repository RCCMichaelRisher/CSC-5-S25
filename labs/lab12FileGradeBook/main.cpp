/* 
 * Author: Michael Risher
 * Purpose: lab 12 file grade book
 */

//System Libraries
#include <iostream>  //Input Output Library
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes

//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    
    //Declare Variables
    ifstream inFile; //input file
    string student; //reading input file
    int grade; //reading input file
    string filename;

    float avg;
    float sum; //sum of the grades
    int countStudents; //total students
    int fails; //num fails
    int topScore; //top score
    string topScorer; //name of top scorer

    //Initialize Variables
    sum = 0;
    countStudents = 0;
    fails = 0;
    topScore = -1;
    
    cout << "What is the file name to open from: ";
    getline( cin, filename );
    //open the file
    inFile.open( filename );
    //make sure the opened
    if(!inFile ){
        cout << "Error could not open file" << endl;
        return 1;
    }

    //Map/Process the Inputs -> Outputs
    //read that file
    while( inFile >> student >> grade ){
        //read a line in the file and have the student's name and grade
        char letter;
        if( grade >= 90 ) {
            letter = 'A';
        } else if ( grade >= 80 ){
            letter = 'B';
        } else if ( grade >= 70 ){
            letter = 'C';
        } else if ( grade >= 60 ){
            letter = 'D';
        } else {
            letter = 'F';
        }

        //output their letter grade in this format "Alice: 87 - B"
        cout << student << ": " << grade << " - " << letter << endl;

        //add to the sum for avg
        sum += grade;
        //add to the total students for avg
        countStudents++; //adds 1

        if( grade < 60 ) fails++;

        if( grade > topScore ){
            topScore = grade;
            topScorer = student;
        }
    }
    
    //Display Inputs/Outputs
    cout << "avg: " << sum / countStudents << endl;
    cout << "fails: " << fails << endl;
    
    //Clean up memory and files
    inFile.close();
    //Exit the Program
    return 0;
}
/* 
 * Author: Michael Risher
 * Purpose: gradebook with 2d array used as a table 
 */

//System Libraries
#include <iostream>  //Input Output Library
#include <cstdlib>
#include <ctime> 
#include <iomanip>
#include <vector>

using namespace std;

//User Libraries

//Global Constants not Variables
//Science, Math, Conversions, Dimensions
const int ASSIGNMENTS = 4;  //columns
//Function Prototypes

void fillGrades( int grades[][ASSIGNMENTS], int numStudents );
void displayGrades( const int grades[][ASSIGNMENTS], int numStudents );
void displayGrades( const int grades[][ASSIGNMENTS], int numStudents, float scores[], vector<int> minMax[] ); //overloaded for stats
void calculateGrades( int grades[][ASSIGNMENTS], int numStudents, float scores[], vector<int> minMax[] );


//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    srand( time( 0 ) );
    //Declare Variables
    int numStudents; //size for studnets / rows

    //Initialize Variables
    do{
        cout << "how many students (1-100): ";
        cin >> numStudents;
    } while( numStudents < 1 || numStudents > 100 );

    //size  defined now we decalre the array
    int grades[numStudents][ASSIGNMENTS]; //2d array table with numstudents as rows and assignments as columns
    float scores[ numStudents ];  //total score per student
    vector<int> minMax[ ASSIGNMENTS ]; //min/max for every assignment using the vector to store both min and max

    //fill the grade table
    fillGrades( grades, numStudents );
    
    
    //Display Inputs/Outputs
    cout << "display the grades table before we do stats" << endl;
    displayGrades( grades, numStudents );

    //caculate the student grade and the min/max for each assignment
    calculateGrades( grades, numStudents, scores, minMax );

    //Display Inputs/Outputs
    cout << "display the grades table before we do stats" << endl;
    displayGrades( grades, numStudents, scores, minMax );


    // vector<vector<int>> grades; //example of a 2d vector

    //Clean up memory and files
    
    //Exit the Program
    return 0;
}

void fillGrades( int grades[][ASSIGNMENTS], int numStudents ){
    for( int rows = 0; rows < numStudents; rows++ ){
        for( int cols = 0; cols < ASSIGNMENTS; cols++ ){
            grades[rows][cols] = rand() % 101;
        }
    }
}

void displayGrades( const int grades[][ASSIGNMENTS], int numStudents ){

    cout << fixed << setprecision( 2 );

    cout << "Grades:  " << " | Assignments |" << endl;
    cout << "Student # | ";
    for( int c = 0; c < ASSIGNMENTS; c++ ){
        string a = "a" + to_string( c+1 );
        cout << setw( 4 ) << a << " | ";
    }
    cout << endl;

    //print the grade table
    for( int r = 0; r < numStudents; r++ ){
        cout << "Student " << r + 1 << " | "; //left label
        for( int c = 0; c < ASSIGNMENTS; c++ ){
            cout << setw( 4 ) << grades[r][c] << " | ";
        }
        cout << endl; //newline after row

    }
}

void displayGrades( const int grades[][ASSIGNMENTS], int numStudents, float scores[], vector<int> minMax[] ){
    cout << fixed << setprecision( 2 );

    cout << "Grades:  " << " | Assignments | Score " << endl;
    cout << "Student # | ";
    for( int c = 0; c < ASSIGNMENTS; c++ ){
        string a = "a" + to_string( c+1 );
        cout << setw( 4 ) << a << " | ";
    }
    cout << " score ";
    cout << endl;

    //print the grade table
    for( int r = 0; r < numStudents; r++ ){
        cout << "Student " << r + 1 << " | "; //left label
        for( int c = 0; c < ASSIGNMENTS; c++ ){
            cout << setw( 4 ) << grades[r][c] << " | ";
        }
        cout << setprecision( 1 ) << scores[r] * 100.0f << "%";
        cout << endl; //newline after row
    }

    cout << "Min       | ";
    for( int i = 0; i < ASSIGNMENTS; i++ ){
        cout << setw( 4 ) << minMax[i][0] << " | ";
    }
    cout << endl << "Max       | ";
    for( int i = 0; i < ASSIGNMENTS; i++ ){
        cout << setw( 4 ) << minMax[i][1] << " | ";
    }


}

void calculateGrades( int grades[][ASSIGNMENTS], int numStudents, float scores[], vector<int> minMax[] ){
    //find minmax for each assingment
    for( int assign = 0; assign < ASSIGNMENTS; assign++ ){
        minMax[assign] = vector<int>(2,0); //set the value of minmax at assign to be a 2 element default value of 0 vector

        minMax[assign][0] = grades[0][assign]; //initial setup for min
        minMax[assign][1] = grades[0][assign]; //initial setup for max

        for( int stu = 0; stu < numStudents; stu++ ){ //loop through each student
            if( grades[stu][assign] < minMax[assign][0] ){ //check new min
                minMax[assign][0] = grades[stu][assign];
            }
            //find the max
            if( grades[stu][assign] > minMax[assign][1] ) {
                minMax[assign][1] = grades[stu][assign]; //update max
            }
        }
    }

    //find the score
    for( int stu = 0; stu < numStudents; stu++ ){
        float total = 0;
        for( int assign = 0; assign < ASSIGNMENTS; assign++ ){
            total += grades[stu][assign]; //add all the scores up
        }

        scores[stu] = total / ( 100 * ASSIGNMENTS );
    }
}


/* 
 * Author: Michael Risher
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input Output Library
#include <fstream>
#include <string>
using namespace std;

//User Libraries

//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes
bool openFile( ifstream &inFile );
char calculateLetterGrade(int score) ;
void processStudent(string name, int score, int &total, int &count, int &failingCount, int &topScore, string &topStudent);
float calculateAverage(int total, int count);
void displayMenu();
int getUserInput();
void saveSummary(int count, float average, char averageGrade, string topStudent, int topScore, int failingCount);

//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    
    //Declare Variables
    ifstream infile;
    ofstream outfile;
    string name;
    int score;

    int studentCount = 0, 
    totalScore = 0,
    failCount = 0,
    highScore = -1;

    string topStudent;

    //step 1 read file
    if( !openFile( infile ) ){
        //didnt open trouble
        cout << "failed to open";
        return 1;
    }

    //step 2 process students
    while( infile >> name >> score ){
        processStudent( name, score, totalScore, studentCount, failCount, highScore, topStudent );
    }

    //TODO the other parts like print the menu and have the save summary screen

    return 0;
}

bool openFile( ifstream &infile ){
    string fileName;
    cout << "Enter file Name\n> ";
    getline( cin, fileName );
    infile.open( fileName );

    return infile.is_open();
}

void processStudent(string name, int score, int &total, int &count, int &failingCount, int &topScore, string &topStudent){
    char letterGrade = calculateLetterGrade( score );
    cout << name << ": " << score << " - " << letterGrade << endl;


    count++;
    total += score;

    if( score < 60 ){
        failingCount++;
    }

    if( score > topScore ) {
        topScore = score;
        topStudent = name;
    }
}

char calculateLetterGrade( int score ){
    if( score >= 90 ) {
        return 'A';
    } 
    else if( score >= 80 ) return 'B';
    else if( score >= 70 ) return 'C';
    else if( score >= 60 ) return 'D';
    else return 'F';
}
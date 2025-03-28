/*
Author: Michael Risher
Purpose: Lab 7 banking program
*/

//system libraries
#include <iostream>  //input/output library
#include <string> //string library
using namespace std; //using namespace standard

//user libraries

//global constants not variable
//science, math, conversion, dimension

//function prototypes

//execution begins here at main
int main( int argc, char **argv ) {
    //set random number seed

    //declare variables
    string user, pass; //entered user and pass
    string correctUser = "user";
    string correctPass = "pass";
    int choice;
    float balance = 20.0f;
    float inAmount;


    //initialize variables
    cout << "Welcome to RCC Bank" << endl;
    cout << "Enter the username: ";
    //1 word username so i dont need to getline only when i expect 2 words
    cin >> user;
    cout << "Enter the password: ";
    cin >> pass;

    //map/process the inputs -> outputs
    if( user == correctUser && pass == correctPass ){
        //were in
        cout << "login success" << endl;

        cout << "1. check balance" <<endl;
        cout << "2. deposit money" <<endl;
        cout << "3. withdraw money" <<endl;
        cout << "4. exit" <<endl;
        //cin the user choice
        cin >> choice;

        if( choice == 1 ){
            //check bal
            cout << "Your output is " << balance << endl;
        } else if ( choice == 2 ) {
            //deposit
            cout << "Enter how much money to deposit: ";
            cin >> inAmount;

            if ( inAmount > 0 ){ //it is not negative do the deposit 
                balance += inAmount; //does the same as this line ->  balance = balance + inAmount;
                cout << "Your new balance after depositing " << inAmount << " is " << balance << endl;
            } else {
                cout << "Invalid amount. You can deposit positive dollars" << endl;
            }
        } else if( choice == 3 ){
            //withdraw
            //prompt  for the amount
            cout << "Enter how much to withdraw: " << endl;
            cin >> inAmount;

            if( inAmount > 0 && inAmount <= balance  ){ //non negative and not overdrafting their account
                balance -= inAmount;
                cout << "Your new balance after withdrawing " << inAmount << " is " << balance << endl;
            } else if( inAmount > balance ) { //if you overdrafted
                cout << "Insufficient funds. Your current balance " << balance << endl;
            } else {
                cout << "You cant wihdraw negative money." << endl;
            }
        } else if( choice == 4 ){
            //exit
            cout << "Thank you for using RCC Bank" << endl;
        } else {
            //anything not 1-4
            cout << "Invalid option. Please try again." << endl;
        }
    } else{
        cout << "Wrong username & password"<<endl;
    }

    //display input/outputs

    //clean up memory, close files

    //exit the program
    return 0;
}

/*
Author: Michael Risher
Purpose: to optimize your gas spending
*/

//system libraries
#include <iostream>  //input/output library
#include <iomanip> //format library
using namespace std; //using namespace standard

//user libraries

//global constants not variable
//science, math, conversion, dimension

//function prototypes

//execution begins here at main
int main( int argc, char **argv ) {
    //set random number seed

    //declare variables

    float mpg;
    float gasTankSize;
    float gageReading;
    float toFillTank;

    //station 1 variables
    float st1Distance,
    st1Price,
    st1GasToGetHere,
    st1Cost;

    //station 2 variables
    float st2Distance,
    st2Price,
    st2GasToGetHere,
    st2Cost;

    //initialize variables
    cout << "Enter the mpg for your car: ";;
    cin >> mpg;

    cout << "Enter the size of the tank: ";
    cin >>gasTankSize;

    cout << "enter the current gas gage (percent): ";
    cin >> gageReading;

    //station 1 inputs
    cout << "Station 1" << endl;
    cout << "\tEnter the distance to station 1: ";
    cin >> st1Distance;

    cout << "\tEnter the price at station 1: ";
    cin >> st1Price;


    //station 2 inputs
    cout << "Station 2" << endl;
    cout << "\tEnter the distance to station 2: ";
    cin >> st2Distance;

    cout << "\tEnter the price at station 2: ";
    cin >> st2Price;
    //map/process the inputs -> outputs
    //calculate how much to fill the tank
    toFillTank = gasTankSize * ( 1 - ( gageReading / 100 ) );

    //calculate the gas used to get to stat1 and back
    st1GasToGetHere = ( st1Distance * 2 ) / mpg;

    //station 1 total cost
    st1Cost = st1Price * ( toFillTank + st1GasToGetHere );

    //station 2
    //calculate the gas used to get to station 2 and back
    st2GasToGetHere = ( st2Distance * 2 ) / mpg;

    //get the total cost of the station 2
    st2Cost = st2Price * ( toFillTank + st2GasToGetHere );

    //display input/outputs
    cout << "How many gallons we need to fill up with is: " << toFillTank << endl;
    //station 1 display
    cout << "station 1" << endl;
    cout << "\tHow gas we use to come here and get back home: " << st1GasToGetHere << endl;
    cout << "\tThe total cost is $" << setprecision(2) << fixed << st1Cost << endl << endl;

    //station 2
    cout << "station 2" << endl;
    cout << "\tHow much gas we used to come here and get back home: " << st2GasToGetHere << endl;
    cout << "\tThe total cost is $" << setprecision(2) << fixed << st2Cost << endl;

    //clean up memory, close files

    //exit the program
    return 0;
}

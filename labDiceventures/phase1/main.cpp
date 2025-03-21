/*
Author: Michael Risher
Purpose: 
*/

//system libraries
#include <iostream>  //input/output library
#include <cstdlib> //rand
#include <ctime>
using namespace std; //using namespace standard

//user libraries

//global constants not variable
//science, math, conversion, dimension

//function prototypes

//execution begins here at main
int main( int argc, char **argv ) {
    //set random number seed
    srand( time( 0 ) );

    //declare variables
    int health;
    int attack;
    int gold;
    int dice;

    
    
    //initialize variables
    health = 50;
    attack = 5;
    gold = 0;

    cout << "Welcome to the Dungeon Adventure!" << endl;
    cout << "You have " << health << " health and a Basic Sword (Attack Power: " << attack << ")." << endl;

    //roll the dice
    dice = rand() % 6 + 1;
    cout << "Rolling the dice... You rolled a " << dice << endl;

    //map/process the inputs -> outputs
    switch( dice ){
        case 1:
        case 2:
            //trap stuff
        case 3:
        case 4: 
            //monster encounter
        case 5:
        case 6: 
            //loot
    }

    if( health > 0 ){
        //you lived i guess
    } else {
        //sucks to be you
    }
    //display input/outputs

    //clean up memory, close files

    //exit the program
    return 0;
}

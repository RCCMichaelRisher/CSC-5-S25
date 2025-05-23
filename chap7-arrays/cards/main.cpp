/* 
 * Author: Michael Risher
 * Purpose: generate a deck of cards and hsuffle them using an index. and pull cards to your hand
 */

//System Libraries
#include <iostream>  //Input Output Library
#include <cstdlib> //rand
#include <ctime> //time
#include <string>
using namespace std;

//User Libraries

//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes
void makeDeck( string [], string [], int [], int );
void shuffleDeck( int [], int );
void pickCard( string faces[], string suits[], int index[], int card, int size );
void printDeck( string [], string [], int[], int );
//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    srand( time( 0 ) );
    
    //Declare Variables
    const short DECK_SIZE = 52;
    string faces[ DECK_SIZE ];
    string suits[ DECK_SIZE ];
    int index[ DECK_SIZE ];
    bool picked[ DECK_SIZE ];
    
    //Initialize Variables
    //make the deck of cards
    makeDeck( faces, suits, index, DECK_SIZE );
    // printDeck( faces, suits, index, DECK_SIZE );
    
    shuffleDeck( index, DECK_SIZE );
    // printDeck( faces, suits, index, DECK_SIZE );
    //Map/Process the Inputs -> Outputs

    int hand = 5;
    //simulate all the cards have been picked
    for( int i = 0; i < DECK_SIZE; i++ ){
        pickCard( faces, suits, index, index[i], DECK_SIZE );
    }
    //new redraw 5 more 
    for( int i = 0; i <= hand; i++ ){
        pickCard( faces, suits, index, index[i], DECK_SIZE );
    }
    
    //Display Inputs/Outputs
    
    //Clean up memory and files
    
    //Exit the Program
    return 0;
}

//pick a card from the deck
void pickCard( string faces[], string suits[], int index[], int card, int size ){
    static int pickedCards = 0;
    if( pickedCards < size && card < size ){
        cout << faces[ card ] << " of " << suits[ card ] << endl;
        pickedCards++;
    } else{
        cout << "No cards left" << endl;
        cout << "shuffling a new deck" << endl;
        shuffleDeck( index, size );
        pickedCards = 0;
    }
    
}

//shuffle the index of the cards
void shuffleDeck( int index[], int size ){
    for( int times = 0; times < 7; times++ ){
        for( int i = 0; i < size ; i++ ){
            int card = rand() % size; 
            int temp = index[i];
            index[i] = index[card];
            index[card] = temp;
        }
    }
}

//make a fresh deck from stratch
void makeDeck( string faces[], string suits[], int index[], int size ){
    string posSuits[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
    string posFace[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };

    for( int i = 0; i < 4; i++ ){
        for( int j = 0; j < 13; j++ ){
            suits[ i * 13 + j ] = posSuits[ i ];
            faces[ i * 13 + j ] = posFace[ j ];
        }
    }
    //make the card indices
    for( int i = 0; i < size; i++ ){
        index[i] = i;
        //picked[i] = false;
    }
}

//print the whole deck
void printDeck( string faces[], string suits[], int index[], int size ){
    for( int i = 0; i < size; i++ ){
        cout << faces[ index[ i ] ] << " of " << suits[ index[ i ] ] << endl;
    }

}
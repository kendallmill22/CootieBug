/* ********************************************* */ 
/*                                               */ 
/* title: cootieMain.cpp                         */ 
/* programmer: Kendall Miller                    */ 
/* date: 2-25-2022                               */ 
/*                                               */ 
/* purpose:                                      */ 
/* this program plays the game Cootie.			 */ 
/* 												 */ 
/* inputs: number of games						 */ 
/* outputs: Print - numbers of wins per cootie   */ 
/* 								                 */ 
/* ********************************************* */


#include <iostream>
#include <ctime>
using namespace std;

class cootie{ 								// my class for Cootie Bug
	
	public:
		cootie();							// constructor
		
		int diceRoll();						// rolls dice
		
		int bodyParts(int diceRoll);		// adds body part
		bool compCootie();					// shows completion of cootie bug
	
	private:
		int numHead;						// counts head
		int numThorax;						// counts thorax
		int numEyes;						// counts eyes
		int numAntennae;					// counts antennae
		int numMouth;						// counts mouth
		int numLegs;						// counts legs
};


cootie::cootie(){							//initializes the body parts to zero
	numHead = 0;
	numThorax = 0;
	numEyes = 0;
	numAntennae = 0;
	numMouth = 0;
	numLegs = 0;
		
}
	
		
int cootie::diceRoll(){						// rolls the dice
	
	int rollNum;
	
	rollNum = (rand() % 6) + 1;				// rand function set to 1-6
	
	return rollNum;
	
}


// shows completion of cootie bug
bool cootie::compCootie(){	
	
// will return true if the cootie bug has correct number of parts
	if((numHead >= 1) && (numThorax >= 1) && (numEyes >= 1)
		&& (numAntennae >= 1) && (numMouth >= 1) && (numLegs >= 6)){	

		return true;
	}
	
	else{return false;}
	
}


// adds body part after roll (if applicable)
int cootie::bodyParts(int diceRoll){ 									

	
// does not let player continue with out getting the head
	if (diceRoll == 1){												
		numHead = 1;
		return 0;
	}
	
// does not let player continue with out getting the thorax	
	if ((diceRoll == 2) && (numHead >= 1)){					
		numThorax = 1;
		return 0;
	}
	
// keeps track of other parts and stops adding when they reach their limit	
	if ((diceRoll == 3) && (numHead >= 1) && (numThorax >= 1)){
		numAntennae = 1;
		return 0;
	}
								
	if ((diceRoll == 4)&& (numHead >= 1) && (numThorax >= 1)){
		numEyes = 1;
		return 0;
	}
								
	if ((diceRoll == 5)&& (numHead >= 1) && (numThorax >= 1)){
		numMouth = 1;	
		return 0;						
	}
								
	if ((diceRoll == 6)&& (numHead >= 1) && (numThorax >= 1) && (numLegs < 6)){
		numLegs++;
		return 0;
	}				

	return 0;
}


int main(){

	srand(time(0));										// time function for rand()
	int random = 1;										// for random number and sets random to one for while loop
	int games = 1000000;								// number of games
	int coot1Win = 0;									// keeps track of coot1 wins
	int coot2Win = 0;									// keeps track of coot2 wins
	int finalLeg = 0;									// keeps track of final legs

	for (int i = 0; i < games; i++){					// loops however many games is set
	
		cootie* coot1 = new cootie();					// creates coot1
		cootie* coot2 = new cootie();					// creates coot2
	
			while (random != 0){						// keeps dice rolling
				
				
				random = coot1 -> diceRoll();			// rolls dice for coot1
				coot1 -> bodyParts(random);				// sends dice roll to find body part
	
				if(coot1 -> compCootie() == 1){			// when cootie bug completes 
					coot1Win++;							// adds one to coot1 wins	
					if(random == 6){finalLeg++;}		// counts final legs
					break;								// leaves after win
				}
	
				random = coot2 -> diceRoll();			// rolls dice for coot2
				coot2 -> bodyParts(random);				// sends dice roll to find body part
		
				if (coot2 -> compCootie() == 1){		// when cootie bug completes
					coot2Win++;							// adds one to coot2 wins	
					if(random == 6){finalLeg++;}		// counts final legs
					break;								// Leaves after win
				}
			}
		}
	
	cout << "Coot1 wins: " << coot1Win << endl;			// prints number of coot1 wins
	cout << "Coot2 wins: " << coot2Win << endl;			// prints number of coot2 wins
	cout << "LEGS: " << finalLeg << endl;				// prints number of final legs
	
	return 0;
}



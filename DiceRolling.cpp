#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//The following function outputs a basic greeting to the user
void greeting(int pnum) {
	if(pnum == 1) {
		cout << "Please press \"ENTER\" to roll the die.";
	} else {
		cout << "Please press \"ENTER\" again to roll the second die.";
	}
	cin.ignore();
}

//The following function simulates a die roll
int dieroll(void) {
	int ran;
	srand(time(NULL));
	ran = rand()%6+1;
	cout << "You rolled a " << ran << "." << endl;
	return ran;
}

//The following adds the 1st and 2nd roll together
int dice(int fdie, int sdie) {
    cout << "Your total so far is: " << sdie + fdie << endl;
    return sdie + fdie;
}

// Checks if player won / lost / can keep rolling.
int results(int total) {
	if (total == 7 || total == 11) {
		cout << "You won! Congratulations!";
		return 0;
	} else if (total == 2 || total == 3 || total == 12) {
                cout << "You lose. Try again.";
                return 0;
   	} else {
		cout << "You may continue to roll." << endl << endl;
		return 1;
	}
}

// Main Funtion
int main(void) {
	int counter, total, seconddie, firstdie;
	char secondstart;

	do {
		greeting(1);
   		firstdie = dieroll();
   		greeting(2);
	   	seconddie = dieroll();
	   	total = dice(firstdie, seconddie);
	} while(results(total)!=0);

	cin.ignore();
	return 0;
}


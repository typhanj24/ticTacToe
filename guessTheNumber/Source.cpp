#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int random;
	int rangeSelection;
	int guess = 0;
	vector<int> previousGuesses;
	string userDifficulty;
	bool select = false;
	bool previousGuess = true;
	int attempts;
	int tries = 0;

	srand(time(NULL));

	cout << "Guess that number!" << endl;
	cout << "Pick a difficulty! Enter \"Easy\" or \"Hard\"" << endl;
	cout << "Easy diffculty shows the previous guess and Hard difficulty does not show the previous guesses" << endl;

	while (select == false) {//Difficulty select
		cin >> userDifficulty;

		for (int i = 0; i < userDifficulty.size(); i++) {
			userDifficulty[i] = toupper(userDifficulty[i]);
		}
		if (userDifficulty == "EASY") {
			cout << "You have selected easy difficulty" << endl;
			select = true;
		}

		else if (userDifficulty == "HARD") {
			cout << "You have selected hard difficulty" << endl;
			previousGuess = false;
			select = true;
		}

		else {
			cout << "Error: We did not understand your answer. Please try again." << endl;
		}
	}

	select = false;

	while (select == false) {//Range select
		cout << "Now select one of the ranges:\n1)1 to 10\n2)1 to 100\n3)-1000 to 1000" << endl;
		cin >> rangeSelection;

		if (rangeSelection == 1) {
			cout << "Pick a number between 1 to 10. You have 5 attempts." << endl;;
			random = rand() % 10 + 1;
			attempts = 5;
			select = true;
		}

		else if (rangeSelection == 2) {
			cout << "Pick a number between 1 to 100. You have 7 attempts." << endl;
			random = rand() % 100 + 1;
			attempts = 7;
			select = true;
		}

		else if (rangeSelection == 3) {
			cout << "Pick a number between -1000 to 1000. You have 11 attempts." << endl;
			random = rand() % 2001 + (-1000);
			cout << random << endl;
			attempts = 11;
			select = true;
		}

		else {
			cout << "Error: We did not understand your answer. Please try again." << endl;
		}
	}

	while (tries < attempts && random != guess) {//Guess the number
		if (userDifficulty == "EASY") {//Prints previous guesses if user selected easy mode
			cout << "Previous guesses: ";
			for (int i = 0; i < previousGuesses.size(); i++) {//Prints guess that are in a array
				cout << previousGuesses[i] << " ";
			}
			cout << "\n";
		}
		cout << "Enter guess: ";
		cin >> guess;
		previousGuesses.push_back(guess);//Puts guesses into array
		tries++;
		if (guess != random) {
			cout << "Wrong number! You have " << attempts - tries << " attempts left!" << endl;
		}
	}

	if (random == guess) {
		cout << "Congratulations! You guessed the correct number!" << endl;//Prints when you guess the number
	}

	else {
		cout << "Oops, you could not guess the correct number! The correct number was " << random << endl;//Prints when you could not guess the number
	}

}
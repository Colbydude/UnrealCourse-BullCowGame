#include <iostream>
#include <string>

using namespace std;

// Prototypes.
string GetGuessAndPrintBack();
void PrintIntro();

// The entry point for our application.
int main()
{
	PrintIntro();

	// Loop for the number of turns asking for guesses.
	constexpr int NUMBER_OF_TURNS = 5;
	for (int tries = 1; tries <= NUMBER_OF_TURNS; tries++) {
		GetGuessAndPrintBack();
		cout << endl;
	}

	return 0;
}

// Introduce the game.
void PrintIntro()
{
	constexpr int WORD_LENGTH = 5;

	cout << "Welcome to Bulls and Cows, a fun word game.\n";
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
	cout << endl;

	return;
}

// Get a guess from the player and repeat it back to them.
string GetGuessAndPrintBack()
{
	// Get the guess.
	cout << "Enter your guess: ";

	string Guess = "";
	getline(cin, Guess);

	// Repeat the guess back to them.
	cout << "Your guess was: " << Guess << endl;

	return Guess;
}
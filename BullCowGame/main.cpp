#include <iostream>
#include <string>

using namespace std;

// Prototypes.
void PrintIntro();
void PlayGame();
string GetGuess();
bool AskToPlayAgain();

// The entry point for our application.
int main()
{
	PrintIntro();
	PlayGame();
	AskToPlayAgain();
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

// Loop for the number of turns asking for guesses.
void PlayGame()
{
	constexpr int NUMBER_OF_TURNS = 5;

	for (int tries = 1; tries <= NUMBER_OF_TURNS; tries++) {
		string Guess = GetGuess();

		cout << "Your guess was: " << Guess << endl;
		cout << endl;
	}
}

// Get a guess from the player and repeat it back to them.
string GetGuess()
{
	cout << "Enter your guess: ";

	string Guess = "";
	getline(cin, Guess);

	return Guess;
}

// Ask the player if they want to play again.
bool AskToPlayAgain()
{
	cout << "Do you want to play again? ";
	
	string Response = "";
	getline(cin, Response);

	return (Response[0] == 'y' || Response[0] == 'Y');
}

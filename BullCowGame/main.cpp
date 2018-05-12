#include <iostream>
#include <string>

#include "FBullCowGame.h"

// Prototypes.
void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

// Instantiate a new game.
FBullCowGame BCGame;

// The entry point for our application.
int main()
{
	bool bWantsToPlayAgain = false;

	do {
		PrintIntro();
		PlayGame();
		bWantsToPlayAgain = AskToPlayAgain();
	} while (bWantsToPlayAgain);

	return 0;
}

// Introduce the game.
void PrintIntro()
{
	constexpr int WORD_LENGTH = 5;

	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;

	return;
}

// Loop for the number of turns asking for guesses.
void PlayGame()
{
	int MaxTries = BCGame.GetMaxTries();

	for (int tries = 1; tries <= MaxTries; tries++) {
		std::string Guess = GetGuess();

		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}
}

// Get a guess from the player and repeat it back to them.
std::string GetGuess()
{
	int CurrentTry = BCGame.GetCurrentTry();

	std::cout << "Try " << CurrentTry << ". Enter your guess: ";

	std::string Guess = "";
	std::getline(std::cin, Guess);

	return Guess;
}

// Ask the player if they want to play again.
bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)? ";
	
	std::string Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y' || Response[0] == 'Y');
}

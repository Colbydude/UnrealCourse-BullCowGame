/**
 * This is the console executable, that makes use of the BullCow class.
 * This acts as the view in a MVC pattern, and is responsible for all
 * user interaction. For game logic see the FBullCowGame class.
 */

#include <iostream>
#include <string>

#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

// Prototypes.
void PrintIntro();
void PlayGame();
FText GetGuess();
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
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;

	return;
}

// Loop for the number of tries asking for guesses.
void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	// TODO: Change from FOR to WHILE loop once we are validating tries.
	for (int32 tries = 1; tries <= MaxTries; tries++) {
		FText Guess = GetGuess();

		EGuessStatus Status = BCGame.CheckGuessValidity(Guess);

		// Submit valid guess to the game, and receive counts.
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		
		// Print number of bulls and cows.
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << '.';
		std::cout << std::endl;
	}

	// TODO: Add a game summary.
}

// Get a guess from the player and repeat it back to them.
// TODO: Check for valid guess.
FText GetGuess()
{
	int CurrentTry = BCGame.GetCurrentTry();

	std::cout << "Try " << CurrentTry << ". Enter your guess: ";

	FText Guess = "";
	std::getline(std::cin, Guess);

	return Guess;
}

// Ask the player if they want to play again.
bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)? ";
	
	FText Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y' || Response[0] == 'Y');
}

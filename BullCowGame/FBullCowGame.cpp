#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
	Reset();
}

// Getters.
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
bool FBullCowGame::IsGameWon() const { return false; }

// Functions.
bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	
	return;
}

// Receives a VALID guess, increments turn, and returns count.
BullCowCount FBullCowGame::SubmitGuess(FString)
{
	// Increment the turn number.
	MyCurrentTry++;

	// Setup a return variable.
	BullCowCount BullCowCount;

	// Loop through all letters in the guess.
		// Compare letters against the hidden word.

	return BullCowCount;
}

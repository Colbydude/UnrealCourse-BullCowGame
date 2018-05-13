#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
	Reset();
}

// Getters.
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
bool FBullCowGame::IsGameWon() const { return false; }

// Functions.
bool FBullCowGame::CheckGuessValidity(FString) const
{
	return false;
}

void FBullCowGame::Reset()
{
	const FString HIDDEN_WORD = "planet";
	constexpr int32 MAX_TRIES = 8;

	MyCurrentTry = 1;
	MyHiddenWord = HIDDEN_WORD;
	MyMaxTries = MAX_TRIES;

	return;
}

// Receives a VALID guess, increments turn, and returns count.
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	// Increment the turn number.
	MyCurrentTry++;

	// Setup a return variable.
	FBullCowCount BullCowCount;

	// Loop through all letters in the guess.
	int32 HiddenWordLength = GetHiddenWordLength();
	for (int32 i = 0; i < HiddenWordLength; i++) {
		// Compare letters against the hidden word.
		for (int32 j = 0; j < HiddenWordLength; j++) {
			if (Guess[j] == MyHiddenWord[i]) { // If they match then
				if (i == j) { // If they're in the same place
					BullCowCount.Bulls++; // Increment bulls
				}
				else {
					BullCowCount.Cows++; // Increment cows
				}
			}
		}
	}

	return BullCowCount;
}

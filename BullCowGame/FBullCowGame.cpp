#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
	Reset();
}

// Getters.
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

// Functions.
EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	// If the guess isn't an isogram
	// TODO: write function
	if (false) {
		return EGuessStatus::Not_Isogram;
	}
	// If the guess isn't all lowercase
	// TODO: write function
	else if (false) {
		return EGuessStatus::Not_Lowercase;
	}
	// If the guess length is wrong
	else if (Guess.length() != GetHiddenWordLength()) {
		return EGuessStatus::Wrong_Length;
	}
	else {
		return EGuessStatus::OK;
	}
}

void FBullCowGame::Reset()
{
	const FString HIDDEN_WORD = "planet";
	constexpr int32 MAX_TRIES = 8;

	bGameIsWon = false;
	MyCurrentTry = 1;
	MyHiddenWord = HIDDEN_WORD;
	MyMaxTries = MAX_TRIES;

	return;
}

// Receives a VALID guess, increments turn, and returns count.
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;

	int32 WordLength = GetHiddenWordLength(); // Assuming same length as guess.

	// Loop through all letters in the hidden word.
	for (int32 i = 0; i < WordLength; i++) {
		// Compare letters against the hidden word.
		for (int32 j = 0; j < WordLength; j++) {
			// If they match.
			if (Guess[j] == MyHiddenWord[i]) {
				// If they're in the same place.
				if (i == j) {
					BullCowCount.Bulls++;
				}
				else {
					BullCowCount.Cows++;
				}
			}
		}
	}

	if (BullCowCount.Bulls == WordLength) {
		bGameIsWon = true;
	}
	else {
		bGameIsWon = false;
	}

	return BullCowCount;
}

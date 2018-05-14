#include "FBullCowGame.h"

#include <map>
#define TMap std::map

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
	if (!IsIsogram(Guess)) {
		return EGuessStatus::Not_Isogram;
	}
	// If the guess isn't all lowercase
	// TODO: write function
	else if (!IsLowercase(Guess)) {
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

	// Determine if the game has been won.
	if (BullCowCount.Bulls == WordLength) {
		bGameIsWon = true;
	}
	else {
		bGameIsWon = false;
	}

	return BullCowCount;
}

// Determine if the given word is an isogram.
bool FBullCowGame::IsIsogram(FString Word) const
{
	// Treat 0 and 1 letter words as isograms.
	if (Word.length() <= 1) {
		return true;
	}

	// Setup our map.
	TMap<char, bool> LetterSeen;

	// Loop through characters in the word.
	for (auto Letter : Word) {
		Letter = tolower(Letter);	// Handle mixed case.
		
		if (LetterSeen[Letter]) {
			return false;
		}
		else {
			LetterSeen[Letter] = true;
		}
	}

	return true;
}

// Determine if the given word is all lowercase letters.
bool FBullCowGame::IsLowercase(FString Word) const
{
	for (auto Letter : Word) {
		if (!islower(Letter)) {
			return false;
		}
	}

	return true;
}

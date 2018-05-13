#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame {
public:
	FBullCowGame();

	bool CheckGuessValidity(FString) const; // TODO: Make a more rich return value.
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	int32 GetMaxTries() const;
	bool IsGameWon() const;
	
	void Reset(); // TODO: Make a more rich return value.
	FBullCowCount SubmitGuess(FString);

private:
	int32 MyCurrentTry;
	FString MyHiddenWord;
	int32 MyMaxTries;
};

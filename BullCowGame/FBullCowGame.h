#pragma once
#include <string>

using FString = std::string;
using int32 = int;

class FBullCowGame {
public:
	FBullCowGame();

	int32 GetCurrentTry() const;
	int32 GetMaxTries() const;
	bool IsGameWon() const;
	
	bool CheckGuessValidity(FString); // TODO: Make a more rich return value.
	void Reset(); // TODO: Make a more rich return value.
	// Provide a method for counting bulls & cows, and incrementing try #.

private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
};

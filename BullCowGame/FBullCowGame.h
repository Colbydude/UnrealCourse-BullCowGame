#pragma once
#include <string>

class FBullCowGame {
public:
	FBullCowGame();

	int GetCurrentTry() const;
	int GetMaxTries() const;
	bool IsGameWon() const;
	
	bool CheckGuessValidity(std::string); // TODO: Make a more rich return value.
	void Reset(); // TODO: Make a more rich return value.

private:
	int MyCurrentTry;
	int MyMaxTries;
};

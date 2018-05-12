#pragma once

class FBullCowGame {
public:
	void Reset(); // TODO: Make a more rich return value.
	int GetMaxTries();
	int GetCurrentTry();
	bool IsGameWon();
	bool CheckGuessValidity(string); // TODO: Make a more rich return value.

private:

};

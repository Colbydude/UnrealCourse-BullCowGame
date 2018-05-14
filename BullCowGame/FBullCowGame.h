/*
 * The game logic (no view code or direct user interaction).
 * The game is a simple guess the word game based on Mastermind.
 */

#pragma once
#include <string>

// To make syntax Unreal friendly.
using FString = std::string;
using int32 = int;

// Used to count bulls and cows after a guess.
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

// The status of a guess from player input.
enum class EGuessStatus
{
	Invalid_Status,
	Not_Isogram,
	Not_Lowercase,
	OK,
	Wrong_Length
};

class FBullCowGame
{
public:
	FBullCowGame();

	EGuessStatus CheckGuessValidity(FString) const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	int32 GetMaxTries() const;
	bool IsGameWon() const;
	
	void Reset();
	FBullCowCount SubmitValidGuess(FString);

private:
	bool bGameIsWon;
	int32 MyCurrentTry;
	FString MyHiddenWord;

	bool IsIsogram(FString) const;
	bool IsLowercase(FString) const;
};

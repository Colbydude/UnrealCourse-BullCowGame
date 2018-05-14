#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

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
	
	void Reset(); // TODO: Make a more rich return value.
	FBullCowCount SubmitValidGuess(FString);

private:
	bool bGameIsWon;
	int32 MyCurrentTry;
	FString MyHiddenWord;
	int32 MyMaxTries;

	bool IsIsogram(FString) const;
};

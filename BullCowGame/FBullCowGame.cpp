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

	MyCurrentTry = 1;
	
	return;
}
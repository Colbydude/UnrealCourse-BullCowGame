#include "FBullCowGame.h"

int FBullCowGame::GetCurrentTry() { return MyCurrentTry; }
int FBullCowGame::GetMaxTries() { return MyMaxTries; }

bool FBullCowGame::CheckGuessValidity(std::string)
{
	return false;
}

bool FBullCowGame::IsGameWon()
{
	return false;
}

void FBullCowGame::Reset()
{
	return;
}
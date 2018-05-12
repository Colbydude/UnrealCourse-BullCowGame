#include "FBullCowGame.h"

int FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int FBullCowGame::GetMaxTries() const { return MyMaxTries; }
bool FBullCowGame::IsGameWon() const { return false; }

bool FBullCowGame::CheckGuessValidity(std::string)
{
	return false;
}

void FBullCowGame::Reset()
{
	return;
}
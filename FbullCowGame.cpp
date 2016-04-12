#include "FbullCowGame.h"
using int32 = int;


void FBullCowGame::Reset()
{
	MyCurrentTry = 1;
	MyMaxTries = 3;

	const FString HIDDEN_WORD = "ant";
	MyHiddenWord = HIDDEN_WORD;

	return;
}

//Recives a valid guess, increments  turn, and returns count.
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	//Incriment the turn number
	MyCurrentTry++;
	//Setup a retun variable
	FBullCowCount BullCowCount;
	//Loop through all letters in the guess
	int32 HiddenWordLenth = MyHiddenWord.length();
	for (int32 MHWCHAR = 0; MHWCHAR < HiddenWordLenth ; MHWCHAR++)
	{
		for (int32 GChar = 0; GChar < HiddenWordLenth; GChar++)
		{
			if (Guess[GChar] == MyHiddenWord[MHWCHAR])
			{
				//If they are in the same place
				if (MHWCHAR == GChar)
				{
					BullCowCount.Bulls++;
				}
				else
				{
					BullCowCount.Cows++;
				}
			}
		}
	}
		//Compare letters against the hidden word.

	return BullCowCount;
}

FBullCowGame::FBullCowGame()
{
	Reset();
	return;
}

int FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}

int FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(std::string)
{
	return false;
}

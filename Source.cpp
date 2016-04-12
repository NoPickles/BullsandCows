#include<iostream>
#include<string>
#include"FbullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AsktToPlayAgain();

FBullCowGame BCGame; //Instantiate a new game.


int main()
{
	bool bPlayAgain = false;

	do
	{
		PrintIntro();
		PlayGame();
		bPlayAgain = AsktToPlayAgain();
	} 
	while (bPlayAgain);
	
	return 0;

}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	

	//Loop for the number of turns asking for guesses
	//TODO change from for to while loop
	for (int32 count = 0; count < MaxTries; count++)
	{
		
		FText Guess = GetGuess(); //TODO make loop checking valid

		//Submit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		//Print number of bulls and cows
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << "Cows = " << BullCowCount.Cows;

		std::cout << std::endl;
	}

	//TODO summarise game
}



void PrintIntro()
{
	constexpr int32 WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;

}

//Get a guess from the player

FText GetGuess()
{
	FText Guess = "";
	std::cout << "Try " << BCGame.GetCurrentTry() << ": Enter your guess: ";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AsktToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n)";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}


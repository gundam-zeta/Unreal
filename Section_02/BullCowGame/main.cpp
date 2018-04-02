/*
This is the console executable, that makes use of the Bullcow class
This acts as the view in a MVC pattern, and is reponsible
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"
#include <map>
#define TMap std::map

using FText = FString;
using int32 = int;

void PrintIntro();

void PlayGame();

FText GetValidGuess();

void PrintBack(FText str);

bool AskToplayAgain();

FBullCowGame BCGame; //instantiate a new game



int main()
{
	PrintIntro();
	std::cout << "vous avez des essai au nombre de \n" << BCGame.GetMaxTries() <<"\n";
	bool wannaplay = true;
	do
	{
		PlayGame();
		wannaplay = AskToplayAgain();
	} while (wannaplay == true);

	return 0;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	// loop while asking for guesses while the game is NOT won and the number of turn not attained
	while (BCGame.GetisGameWon() == false &&  BCGame.GetCurrentTry() <= MaxTries)
	{
		std::cout << "Il vous reste: " << MaxTries - BCGame.GetCurrentTry() << "\n";
		FText res = GetValidGuess();
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(res);
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << "Cows = " << BullCowCount.Cows << "\n\n";

	}
	BCGame.PrintGameSummary();
	// TODO summarise game
}

void PrintIntro() {
	// Présentation du jeu
	std::cout << "Bienvenue dans Bulls and Cows, un jeu rigolo \n";
	std::cout << "Pouvez-vous deviner l'isogramme de " << BCGame.GetWordLength() << " lettres \n";
	std::cout << std::endl;
	return;
}

FText GetValidGuess() {
	//avoir une proposition du joueur
	FText Guess = "";
	EGuessStatus status = EGuessStatus::Invalid_Status;
	do {
		std::cout << "vous etes a l'essai n°" << BCGame.GetCurrentTry() << "\n\n";
		std::cout << "saisissez qq chose \n";
		std::getline(std::cin, Guess);
		std::cout << Guess;
		status = BCGame.CheckGuessValidity(Guess);
		switch (status)
		{
		case EGuessStatus::Not_Isogram:
			std::cout << "please enter a isogram word. \n";
			break;
		case EGuessStatus::Wrong_Length:
			std::cout << "please enter a" << BCGame.GetWordLength() << " letter word. \n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "please enter a word in lowercase \n";
			break;
		default:
			std::cout << "default";
			break;
		}
	} while (status != EGuessStatus::OK);
	return Guess;
}

void PrintBack(FText str) {
	//Affiche le résultat de la saisie
	std::cout << "vous avez saisi: \n" << str << "\n";
}

bool AskToplayAgain()
{
	bool flag;
	flag = false;
	std::cout << "Do you wanna play again ?";
	FText Response = "";
	std::getline(std::cin, Response);
	flag = ((Response[0] == 'y') || (Response[0] == 'Y'));
	std::cout << flag;
	return flag;
}

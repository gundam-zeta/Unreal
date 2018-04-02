#include "FBullCowGame.h"
#include <iostream>
#include <string>
#include <map>
#include <ctype.h>

#define TMap std::map

FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;
	const FString HIDDEN_WORD = "job";
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bGameWon = false;
}

int32 FBullCowGame::GetMaxTries() const
{
	TMap<int, int>HiddenWordtoLength{{3,5},{4,6},{5,7},{6,8}};
	return HiddenWordtoLength[GetWordLength()];
}

int32 FBullCowGame::GetCurrentTry()
{
	return MyCurrentTry;
}

int32 FBullCowGame::GetWordLength() const
{
	return MyHiddenWord.length();
}

bool FBullCowGame::GetisGameWon() const
{
	return bGameWon;
}

bool FBullCowGame::IslowerCase(FString guess) const
{
	for (auto Letter : guess)
	{
		if (!islower(Letter))
		{
			std::cout << "mettre des minuscules BOLOS";
			return false;
		}
	}
	return true;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString guess)
{
	// if the guess isn't an isogram
  	  // return an error
	// if the guess isn't all lowercase
	  // return an error
	if (IsIsogram(guess) != true)
	{
		return EGuessStatus::Not_Isogram;
	}
	if (guess.length() != GetWordLength())
	{
		return EGuessStatus::Wrong_Length;
	}
	if (IslowerCase(guess) != true)
	{
		return EGuessStatus::Not_Lowercase;
	}
	else
	{ 
		return EGuessStatus::OK;
	}

}

// receives a VALID guess, increments turn, and 
FBullCowCount FBullCowGame::SubmitValidGuess(FString EntGuess)
{
	FString str = EntGuess;
	MyCurrentTry++;
	FBullCowCount BullCowCount;

	// loop through a ll letters in the game
	 // compare letters 
	int32 WordLength = MyHiddenWord.length(); // assume the same lenghth for hidden word and proposition
	for (int32 i = 0; i < WordLength; i++)
	{
		for (int32 j = 0; j < WordLength; j++) 
		{
			if (str[i] == MyHiddenWord[j] && i == j)
			{
				BullCowCount.Bulls++;
			}
			if (str[i] == MyHiddenWord[j] && i != j)
			{
				BullCowCount.Cows++;
			}

		}

	}
	if (WordLength == BullCowCount.Bulls)
	{
		bGameWon = true;
	}
	return BullCowCount;
}

void FBullCowGame::PrintGameSummary()
{
	if (bGameWon == true)
	{
		std::cout << "\n Bravo vous avez gagné \n";
	}
	else
	{
		std::cout << "\n Perdu dommage \n";
	}
}

bool FBullCowGame::IsIsogram(FString guess) const
{
	if (guess.length() <= 1) { return true; }
	TMap<char, bool> LetterSeen;
	
	for (auto Letter : guess)
	{
		Letter = tolower(Letter);
		if (LetterSeen.count(Letter) > 0)
		{
			std::cout << "pas isogram";
			return false;
		}
		else
		{ 
		LetterSeen[Letter] = true;
		}
	}
	
	return true;
}

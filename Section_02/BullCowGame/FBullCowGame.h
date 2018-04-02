#pragma once
#include <string>
using int32 = int;

using FString = std::string;

struct FBullCowCount 
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

class FBullCowGame {
public:
	FBullCowGame(); //constructor
	void Reset(); // TODO make a more rich return value
	int32 GetMaxTries() const;
	int32 GetCurrentTry();
	int32 GetWordLength() const;
	bool GetisGameWon() const;
	bool IslowerCase(FString) const;
	EGuessStatus CheckGuessValidity(FString); // TODO make a more rich return value
	// provide a method for counting bulls & cows, and increasing try
	FBullCowCount SubmitValidGuess(FString);
	void PrintGameSummary();

// Unused for now
private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	bool IsIsogram(FString) const;
	bool bGameWon = false;

};

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;
void Hangman(string name, int difficulty)
{
	int Max_Wrong = difficulty;
	switch (difficulty)
	{
	case 1: Max_Wrong = 10;
		break;
	case 2: Max_Wrong = 8;
		break;
	case 3: Max_Wrong = 6;
		break;
	default: cout << "That is not a valid answer, please resubmit.\n";
		break;
	}

	//Create a collection of 10 words you had wrote down manually
	vector<string> words;
	words.push_back("EXPLOSION");
	words.push_back("FRAGMENT");
	words.push_back("PARCHMENT");
	words.push_back("TELEGRAPH");
	words.push_back("SUPERIOR");
	words.push_back("COMMAND");
	words.push_back("PROCEDURE");
	words.push_back("POSITION");
	words.push_back("VICTORY");
	words.push_back("DEFEAT");

	//Pick new 3 random words from your collection as the secret code word the recruit has to guess.
	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(), words.end());
	const string THE_WORD = words[0];
	int wrong = 0;
	string soFar(THE_WORD.size(), '-');
	string used = "";

	cout << "Welcome to Keywords II Assessment training: Good Luck!\n";
	//While recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret word
	while ((wrong < Max_Wrong) && (soFar != THE_WORD))
	{
		//Display an overview of what Keywords II is to the recruit 
		//Display an directions to the recruit on how to use Keywords
		cout << name << " You Have " << (Max_Wrong - wrong);
		//Tell recruit how many incorrect guesses he or she has left
		cout << " incorrect guesses left.\n";
		cout << "You've used the following letters:" << used << ".\n";
		//Show recruit the letters he or she has guessed
		cout << "So far, the word is: " << soFar << ".\n";
		//Show player how much of the secret word he or she has guessed
		char guess;
		cout << "Enter your guess " << name << ": ";
		cin >> guess;
		//Get recruit's next gues
		guess = toupper(guess); //Make Uppercase since secret word is uppercase
								//While recruit has entered a letter that he or she has already guessed
								//Get recruit ’s guess

		while (used.find(guess) != string::npos)
		{
			cout << "You've already guessed " << guess << ".\n";
			cout << "Enter your guess " << name << ": ";
			cin >> guess;
			guess = toupper(guess);
		}

		used += guess;
		if (THE_WORD.find(guess) != string::npos)
		{
			cout << "\nCongratulations " << name << "!\n" << guess << " is in the word.\n";
			//update soFar to include newly guess letter
			//Add the new guess to the group of used letters
			for (int i = 0; i < THE_WORD.length(); ++i)
			{
				//If the guess is in the secret word
				//Tell the recruit the guess is correct
				//Update the word guessed so far with the new letter
				if (THE_WORD[i] == guess)
				{
					soFar[i] = guess;
				}
			}
		}

		else
		{
			//Tell the recruit the guess is incorrect
			cout << "Incorrect, " << guess << " isn't in the word " << name << ".\n\n";
			//Increment the number of incorrect guesses the recruit has made
			++wrong;
		}
	}

	//shut down
	//If the recruit has made too many incorrect guesses
	//Tell the recruit that he or she has failed the Keywords II course.
	if (wrong == Max_Wrong)
	{
		cout << "You have failed you're assessment " << name << ".\n";
	}
	else
	{
		//Congratulate the recruit on guessing the secret words
		cout << "Congratulations " << name << "!\n";
	}
	cout << "The word was " << THE_WORD << "!\n";
	cout << "You may continue to the next phase of training.\n";
}

int main()
{
	//Display Title of program to user
	cout << "Welcome to Keywords II - A CIA Training Simulator.\n";
	cout << "========================================================================\n\n";
	//Ask the recruit to login using thier name
	cout << "Please Input Your Name: ";
	//Hold the recruit's name in a var, and address them by it throughout the simulation.
	string name;
	cin >> name;
	cout << "Welcome " << name << ". Please read the following:\n";
	//Display an overview of what Keywords II is to the recruit
	cout << "Keywords II will train you in decrypting messages,\n";
	cout << "You will be given an allotment of attempts in order to guess a word.\n";
	cout << "If you figure out the word within the number of attempts you will pass,\n";
	cout << "If you fail you will be redirected to the main menu to try again.\n";
	cout << "========================================================================\n\n";

	int difficulty;
	cout << "Please select the necessary difficulty level for this simulation:\n";
	cout << "1: Easy // 10 Attempts.\n";
	cout << "2: Medium // 8 Attempts.\n";
	cout << "3: Hard // 6 Attempts.\n";
	cin >> difficulty;
	cout << "You have chosen: " << difficulty << ".  Good luck " << name << ".\n\n";
	cout << "========================================================================\n\n";

	//Create an int var to count the number of simulations being run starting at 1
	int iteration = 1;
	bool playagain = false;
	
	do
	{
		while (iteration < 4)
		{
			//Display the simulation # is staring to the recruit.
			cout << name << ".  This is simulation #" << iteration << ".\n\n";
			Hangman(name, difficulty);
			//Increment the number of simiulations ran counter
			iteration++;
		}
		//Ask the recruit if they would like to run the simulation again
		cout << "Would you like to try again?\n";
		string again;
		cin >> again;
		//If the recruit wants to run the simulation again
		if (again == "Y" || again == "y")
		{
			Hangman(name, difficulty);
			playagain = true;
		}
		else
		{
			//Display End of Simulations to the recruit
			playagain = false;
		}
	} while (playagain);
	
	cout << "This training simulation has concluded.\n";
	//Pause the Simulation with press any key to continue
	system("pause");
	
	return 0;
}

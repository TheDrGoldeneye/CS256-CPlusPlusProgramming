// AGameOf21.cpp : Defines the entry point for the console application.
// This program simulates the rolling of dice.
/*Fadhar J.Castillo
CS 256 C++ Programming
AGameOf21*/


#include "stdafx.h"
#include <string>
#include <iostream>
#include "Die.h"
using namespace std;
int getChoice(int lowerLimit, int upperLimit);

int main()
{
	const int DIE1_SIDES = 6; // Number of sides for die #1
	const int DIE2_SIDES = 6; // Number of sides for die #2
	
	// Create two instances of the Die class.
	Die die1(DIE1_SIDES);
	Die die2(DIE2_SIDES);
	bool gameOver = false;
	
	while(!gameOver)
	{
		int choice = -1;
		//Menu
		cout << "Welcome to Dice 21!" << endl;
		cout << "1. Play" << endl;
		cout << "2. Exit" << endl;
		choice = getChoice(1, 2);
		if (choice = 1)
		{
			int keepPlaying = false;
			int computerScore = 0, playerScore = 0, round = 1;
			do
			{
				//Display the round number
				cout << "\nRound " << round << endl;
				//Display scores
				cout << "Computer Score: " << computerScore << "	Player Score: " << playerScore << endl;
				// Roll the dice for the computer
				die1.roll();
				die2.roll();
				int computerDie1Result = die1.getValue();
				int computerDie2Result = die2.getValue();
				int computerTotal = computerDie1Result + computerDie2Result;
				string strDie2Result = "-";
				//Roll the dice for the player
				die1.roll();
				die2.roll();
				int playerDie1Result = die1.getValue();
				int playerDie2Result = die2.getValue();
				int playerTotal = playerDie1Result + playerDie2Result;

				//Show what they rolled, but hide the second computer die
				cout << "Computer Rolled: " << computerDie1Result << " and " << strDie2Result << endl;
				cout << "Player Rolled:   " << playerDie1Result << " and " << playerDie2Result << endl;
				cout << "Player Total: " << playerTotal << endl;

				//Ask to roll
				cout << "1. Roll" << endl;
				cout << "2. Stand" << endl;
				choice = getChoice(1, 2);

				//Loop as long as the player desires and their score is less than 21
				while (choice == 1 && playerTotal < 21)
				{
					die1.roll();
					die2.roll();
					int playerDie1Result2 = die1.getValue();
					int playerDie2Result2 = die2.getValue();
					playerTotal += playerDie1Result2 + playerDie2Result2;
					cout << endl;
					cout << "Player Rolled:   " << playerDie1Result2 << " and " << playerDie2Result2 << endl;
					cout << "Player Total: " << playerTotal << endl;

					//Ask to roll for while loop
					cout << "1. Roll" << endl;
					cout << "2. Stand" << endl;
					choice = getChoice(1, 2);
				}

				//Computer rolls until it hits 17
				while (computerTotal < 17)
				{
					die1.roll();
					die2.roll();
					int computerDie1Result2 = die1.getValue();
					int computerDie2Result2 = die2.getValue();
					computerTotal += computerDie1Result2 + computerDie2Result2;
					cout << endl;
					cout << "Computer Rolled:   " << computerDie1Result2 << " and " << computerDie2Result2 << endl;
					cout << "Computer Total: " << computerTotal << endl;
				}
				//Check if computer wins
				if (playerTotal > 21 || (computerTotal <= 21 && computerTotal > playerTotal))
				{
					cout << endl;
					cout << "I WIN!!!" << endl;
					computerScore++;
				}
				//Check if player wins
				else if (computerTotal > 21 || (playerTotal <= 21 && playerTotal > computerTotal))
				{
					cout << endl;
					cout << "PLAYER WINS!!!" << endl;
					playerScore++;
				}
				//Verify a draw occured
				else if (computerTotal == playerTotal)
				{
					cout << endl;
					cout << "DRAW!" << endl;
				}
				cout << endl;
				cout << "Keep Playing?" << endl;
				cout << "1. Yes" << endl; 
				cout << "2. No" << endl;
				keepPlaying = getChoice(1, 2);
				if (keepPlaying == 1)
				{
					round++;
				}
				else
				{
					gameOver = true;
				}
			} while (keepPlaying == 1);
		}
		else
		{
			gameOver = true;
		}
		
	}
	return 0;
}

int getChoice(int lowerLimit, int upperLimit)
{
	int choice = 0;
	do
	{
		cin >> choice;
		if (choice < lowerLimit || choice > upperLimit)
		{
			cout << "Invalid input. Try Again." << endl;
		}
	} while (choice < lowerLimit || choice > upperLimit);
	return choice;
}
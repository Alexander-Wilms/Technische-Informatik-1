#include <stdio.h>
#include <time.h>
#include <stdlib.h>
typedef int bool;
#define true 1
#define false 0
#define NUMBEROFGAMES 100000 // 1000000 causes a crash

int main()
{
	srand( time(NULL) ); // Seed for the random numbers
	int wonFrequency[22] = {};
	int lostFrequency[22] = {};
	double chances;
	double rollFrequency[NUMBEROFGAMES] = {};
	double rollSum = 0;
	double averageRolls;
	int i, die1, die2, sum, point, counter;
	bool won, lost, firstrun, wonCounter = 0;
	for(i = 0; i < NUMBEROFGAMES; i++) // 100000 games
	{
		counter = 0; // Initialize variables for a game
		point = 0;
		won = false;
		lost = false;
		firstrun = true;
		while(!won && !lost) // A single game last until someone has lost or won
		{
			counter++;
			die1 = 1 + rand() % 6; // Throw two dice separately
			die2 = 1 + rand() % 6;
			sum = die1 + die2;
			if(firstrun)
				{
				if(sum == 7 || sum == 11) // Wins
				{
					won = true;
					wonFrequency[1]++; // Count
					wonCounter++;
				} else if (sum == 2 || sum == 3 || sum == 12) // Loses
				{
					lost = true;
					lostFrequency[1]++; // Count
				} else // Try once more
				{
					point = sum;
				}
			} else
			{
				if(sum == point) // If in a game that's not the first one, one throws the pointm one wins
				{
					won = true;
					wonCounter++;
					if(counter > 20) // Only count to 20
					{
						wonFrequency[21]++; // Count
					} else
					{
						wonFrequency[counter]++; // Count
					}
				} else if (sum == 7) // Loses
				{
					lost = true;
					if(counter > 20)
					{
						lostFrequency[21]++; // Count
					} else
					{
						lostFrequency[counter]++; // Count
					}
				}
			}
			firstrun = false;
		}
		rollFrequency[i] = counter; // Save the number of rolls the game took
	}
	for(i = 0; i < NUMBEROFGAMES; i++)
	{
		rollSum += rollFrequency[i]; // Add up all rolls
	}
	averageRolls = rollSum / NUMBEROFGAMES; // Average rolls per game
	printf("averageRolls: %f \n", averageRolls);
	printf("Round" "\t" "Won" "\t" "Lost\n");
	for(i = 1; i <= 20; i++)
	{
		printf("%d \t %d \t %d \n", i, wonFrequency[i], lostFrequency[i]);
	}
	printf("> 20 \t %d \t %d \n", wonFrequency[21], lostFrequency[21]);
	chances = (double) wonCounter / NUMBEROFGAMES; // Percentage of won games
	printf("Chances to win: %f \n", chances);
	// Roughly 0.4929. In a completely fair game, on average nobody would win or lose,
	// which would mean the the chance to win/lose would be 0.5
	return (0);
}

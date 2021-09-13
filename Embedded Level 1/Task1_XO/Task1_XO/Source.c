#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define gridSize 9
#define true 1
#define false 0

char gv[gridSize] = { '0','1','2','3','4','5','6','7','8' }; //gridValues

void drawGrid()
{
	printf("%c | %c | %c\n", gv[0], gv[1], gv[2]);
	printf("__|___|__\n");
	printf("%c | %c | %c\n", gv[3], gv[4], gv[5]);
	printf("__|___|__\n");
	printf("%c | %c | %c\n", gv[6], gv[7], gv[8]);
}

// returns 1 if the winner is x and return 0 if the winner is O and -1 if none
int  whoWon()
{
	if (gv[0] == gv[1] && gv[1] == gv[2])
	{
		if (gv[0] == 'X')
			return 1;
		else
			return 0;
	}
	else if (gv[3] == gv[4] && gv[4] == gv[5])
	{

		if (gv[3] == 'X')
			return 1;
		else
			return 0;
	}
	else if (gv[6] == gv[7] && gv[7] == gv[8])
	{

		if (gv[6] == 'X')
			return 1;
		else
			return 0;
	}
	else if (gv[0] == gv[4] && gv[4] == gv[8])
	{

		if (gv[0] == 'X')
			return 1;
		else
			return 0;
	}
	else if (gv[2] == gv[4] && gv[4] == gv[6])
	{

		if (gv[2] == 'X')
			return 1;
		else
			return 0;
	}
	else if (gv[0] == gv[3] && gv[3] == gv[6])
	{

		if (gv[0] == 'X')
			return 1;
		else
			return 0;
	}
	else if (gv[1] == gv[4] && gv[4] == gv[7])
	{

		if (gv[4] == 'X')
			return 1;
		else
			return 0;
	}
	else if (gv[2] == gv[5] && gv[5] == gv[8])
	{

		if (gv[5] == 'X')
			return 1;
		else
			return 0;
	}


	return -1;

}
int isDraw()
{
	for (int i = 0; i < sizeof(gv); i++)
	{
		if (gv[i] != 'X' && gv[i] != 'O')
			return false;
	}
	return true;
}
int main()
{
	int turn = 1; // X is going to be the first player and O is the second
	while (true)
	{

		drawGrid();
		if (turn)
		{
			printf("Player 1 turn\n");
		}
		else
		{
			printf("Player 2 turn\n");
		}

		int input = -1;
		printf("Entrer the number you want to play in :\n");


		// Validation of the input
		int valid = 0;
		while (input == -1)
		{
			scanf("%d", &input);
			if ((input >= 0 && input <= 8) && (gv[input] != 'X' && gv[input] != 'O')) // if the user entered an valid input
			{
				valid = 1;
				if (turn == 1)
					gv[input] = 'X';
				else
					gv[input] = 'O';
			}
			else
			{
				valid = 0;
				printf("ENTER A VALID INPUT!!!!\n");
			}

		}

		// checking if there's a winner
		int winner = whoWon();
		if (winner == 1)
		{
			drawGrid();
			printf("Player 1 WON!!!\n");
			return;
		}
		else if (winner == 0)
		{
			drawGrid();
			printf("Player 2 WON!!!\n");
			return;
		}
		else if (isDraw())
		{
			drawGrid();
			printf("DRAW\n");
			return;
		}
		turn = valid ? !turn : turn; // if invalid data the player will not change 
	}
}
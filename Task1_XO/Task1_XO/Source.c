#include <stdio.h>
#include <stdlib.h>

char grid[10] = { '*', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
int checkwin()
{
	if (grid[1] == grid[2] && grid[2] == grid[3])
		return 1;

	else if (grid[4] == grid[5] && grid[5] == grid[6])
		return 1;

	else if (grid[7] == grid[8] && grid[8] == grid[9])
		return 1;

	else if (grid[1] == grid[4] && grid[4] == grid[7])
		return 1;

	else if (grid[2] == grid[5] && grid[5] == grid[8])
		return 1;

	else if (grid[3] == grid[6] && grid[6] == grid[9])
		return 1;

	else if (grid[1] == grid[5] && grid[5] == grid[9])
		return 1;

	else if (grid[3] == grid[5] && grid[5] == grid[7])
		return 1;

	else if (grid[1] != '1' && grid[2] != '2' && grid[3] != '3' &&
		grid[4] != '4' && grid[5] != '5' && grid[6] != '6' && grid[7]
		!= '7' && grid[8] != '8' && grid[9] != '9')

		return 0;
	else
		return  -1;
}

void board()
{

	printf("\n\n\tTic Tac Toe\n\n");

	printf("Player 1 (X)  -  Player 2 (O)\n\n\n");


	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c \n", grid[1], grid[2], grid[3]);

	printf("_____|_____|_____\n");
	printf("     |     |     \n");

	printf("  %c  |  %c  |  %c \n", grid[4], grid[5], grid[6]);

	printf("_____|_____|_____\n");
	printf("     |     |     \n");

	printf("  %c  |  %c  |  %c \n", grid[7], grid[8], grid[9]);

	printf("     |     |     \n\n");
}

int main()
{
	int player = 1, i, choice;

	char mark;
	do
	{
		board();
		player = (player % 2) ? 1 : 2;

		printf("Player %d, enter a number:  ", player);
		scanf("%d", &choice);

		mark = (player == 1) ? 'X' : 'O';

		if (choice == 1 && grid[1] == '1')
			grid[1] = mark;

		else if (choice == 2 && grid[2] == '2')
			grid[2] = mark;

		else if (choice == 3 && grid[3] == '3')
			grid[3] = mark;

		else if (choice == 4 && grid[4] == '4')
			grid[4] = mark;

		else if (choice == 5 && grid[5] == '5')
			grid[5] = mark;

		else if (choice == 6 && grid[6] == '6')
			grid[6] = mark;

		else if (choice == 7 && grid[7] == '7')
			grid[7] = mark;

		else if (choice == 8 && grid[8] == '8')
			grid[8] = mark;

		else if (choice == 9 && grid[9] == '9')
			grid[9] = mark;

		else
		{
			printf("The move is Invalid ");

			player--;
		}
		i = checkwin();

		player++;
	} while (i == -1);

	board();

	if (i == 1)
		printf("Player %d WON !!!", --player);
	else
		printf("DRAW");
	
}


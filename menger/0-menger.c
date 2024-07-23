#include "menger.h"

/**
 * One - Checks if indices are (1, 1), if so, then square is blank
 *
 * @i: Row Index
 * @j: Column Index
 *
 * Return: 1 if (1, 1), 0 otherwise
 */

int One(int i, int j)
{
	while (i != 0 && j != 0) // While i and j are not 0
	{
		if (i % 3 == 1 && j % 3 == 1) // If i and j are 1
			return (0);

		i /= 3, j /= 3; // Divide i and j by 3
	}
	return (1);
}

/**
 * menger - Draws a 2D Menger Sponge
 *
 * @level: level of the Menger Sponge to draw
 *
 * Return: Nothing
 */
void menger(int level)
{
	int i, j, limit;

	if (level < 0) // If level is less than 0, return
		return;

	for (i = 0, limit = pow(3, level); i < limit; i++) // For i = 0, limit = 3^level, i++
	{
		for (j = 0; j < limit; j++)
		{
			One(i, j) == 1 ? printf("%c", '#') : printf("%c", ' '); // If One(i, j) is 1, print '#', else print ' '
		}
		printf("\n"); // Print new line
	}
}
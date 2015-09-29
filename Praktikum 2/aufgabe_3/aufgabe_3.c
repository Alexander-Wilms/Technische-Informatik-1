#include <stdio.h>

int main(void)
{
	unsigned int input[6];
	unsigned int i, j;
	printf("Geben Sie sechs Zahlen ein: ");
	scanf("%d %d %d %d %d %d", &input[0], &input[1], &input[2], &input[3], &input[4], &input[5]); // 6 Zahlen als Arrayfeder einlesen

	for (i = 0; i < 6; i++) // Für jede Zahl...
	{
		for (j = 1; j <= input[i]; j++) //n Sternchen ausgeben
		{
			printf("*");
		}
		printf("\n");
	}
	rewind(stdin);
	getchar();
}

// SUMME, MITTELWERT, PRODUKT, MAX UND MIN BESTIMMEN

#include <stdio.h>
#include <stdlib.h>

int main( Void )
{
	printf("Bitte drei unterschiedliche Zahlen eingeben:");
	int i = 0;
	char j;
	int runde = 0;

	int int1;
	int int2;
	int int3;

	scanf("%d %d %d", &int1, &int2, &int3);

	int sum = int1 + int2 + int3; // do the calculations
	int avg = sum / 3;
	int prod= int1 * int2 * int3;
	int max;
	int min;
	if(int1 >= int2 && int1 >= int3) // int1 ist max
	{
		max = int1;
		if (int2 <= int3)
		{
			min = int2;
		} else
		{
			min = int3;
		}
	} else if(int2 >= int1 && int2 >= int3) // int2 ist max
	{
		max = int2;
		if(int1 <= int3)
		{
			min = int1;
		} else
		{
			min = int3;
		}
	} else // int3 ist max
	{
		max = int3;
		if(int1 <= int2)
		{
			min = int1;
		} else
		{
			min = int2;
		}
	}
	printf ( "Die Summe ist %d\n", sum);
	printf ( "Der Mittelwert ist %d\n", avg);
	printf ( "Das Produkt ist %d\n", prod);
	printf ( "Der kleinste Wert ist %d\n", min);
	printf ( "Der groesste Wert ist %d\n", max);

	return 0;
}

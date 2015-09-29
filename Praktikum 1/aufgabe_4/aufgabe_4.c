#include <stdio.h>

int main( void )
{
	printf("Bitte eine fuenfstellige ganze Zahl eingeben:");
	char ziffer;
	int zahl = 0;
	int ziffern[5];
	while((ziffer = getchar()) != '\n')
	{
		zahl = 10 * zahl + ziffer - '0';
	}
	int i;
	for(i = 0; i <= 4;i++)
	{
		ziffern[4-i] = zahl % 10; // Zahl Stelle für Stelle in Array kopieren
		zahl = zahl - ziffern[4-i];
		zahl = zahl / 10;
	}
	int j;
	for(j = 0; j <= 4;j++)
	{
		printf( "%d\n", ziffern[j]); // Arrayinhalt ausgeben
	}
	return 0;
}


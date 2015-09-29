// UMWANDLUNG BINAER NACH DEZIMAL

#include <stdio.h>

int main(void)
{
	int input_binary;
	int rest;
	int binary_value = 1; // ... 32 | 16 | 8 | 4 | 2 | 1
	int decimal = 0;
	printf("Geben Sie eine binaere Zahl ein: ");
	scanf("%d", &input_binary);
	int done = 0;
	while (!done)
	{
        if (input_binary == 0) {        // Falls alle Stellen abgearbeitet worden sind
			done = 1;                   // Fertig, beende Schleife
			printf("%d \n", decimal);   // Fertige Dezimalzahl ausgeben
			rewind(stdin);              // Stdin clearen
			getchar();                  // Auf Eingabe warten
		}
		rest = input_binary % 10;                   // Letzte Stelle der momentanen Binärzahl
		decimal = decimal + rest * binary_value;    // Bisherige Dezimalzahl + Stellenwert * momentante Stelle der Binärzahl
		input_binary = input_binary - rest;         // Letzt Stelle der Binärzahl abschneiden
		input_binary = input_binary / 10;
		binary_value = binary_value * 2;            // Stellenwert verdoppeln

	}
}

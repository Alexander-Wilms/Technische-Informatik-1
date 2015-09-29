// EUKLIDSCHER ALGORITHMUS

#include <stdio.h>

int main(void)
{
	int p, q, rest = 1, ggT;
	printf("Geben Sie zwei Zahlen ein: ");
	scanf("%d %d", &p, &q);                        // Beide Zahlen einlesen (Scanf benötigt Adresse
	rest = p % q;                                  // Rest bestimmen
	printf("p \t q \t rest \n");                   // Kopfzeile drucken
	while (rest != 0)                              // Solange der Rest nicht 0 ist
	{
		printf("%d \t %d \t %d \n", p, q, rest);
		p = q;                                  // Verschieben von q & r
		q = rest;                               // q wird zu p & rest wird zu q
		rest = p % q;                           // Rest berechnen
	}
	printf("%d \t %d \t %d \n", p, q, rest);
	ggT = q;                                    // Das letzt q ist der ggT
	printf("\n" "ggT: %d \n", ggT);
	rewind(stdin);
	getchar();
}

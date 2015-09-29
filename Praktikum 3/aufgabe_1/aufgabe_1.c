// ANZAHL DER PYTHAGORAEISCHEN DREIECKE MIT SEITENLAENGEN UNTER 500

#include <stdio.h>

int main(void)
{
    printf("Find a rectangular triangles where all sides are smaller than 500");
	int k1, k2, h, i = 1, counter = 0;
	for(k1 = 1; k1 <= 500; k1++) // Increment cathetus 1 in loop
	{
		for (k2 = 1; k2 <= 500; k2++) // Increment cathetus 2 in loop
		{
			for (h = 1; h <= 500; h++) // Increment hypothenuse in loop
			{
				if (k1*k1 + k2*k2 == h*h) // Check if Pythagorean theorem applies
				{
					printf("%d \t %d \t %d" "\n", k1, k2, h);
					counter++;
				}
			}
		}
	}
	printf("Gefundene Dreiecke: %d \n", counter);
    printf("Die Haelfte davon, %d Dreiecke, kommen zweimal vor", counter / 2);
	getchar();
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    printf("Determine the frequency of results when throwing two dice 6 million times \n");
	int haeufigkeit[14] = {}; //Initialize with 0
	int i, sum = 0;
    srand( time(NULL) ); // Has no return value and should only be called once
	for (i = 1; i <= 6000000; i++)
	{
		++haeufigkeit[(1 + rand() % 6) + (1 + rand() % 6)]; // Increment array[(1 + (0 to 5)) + (1 + (0 to 5))]
	}
	for (i = 2; i <= 12; i++)
	{
        printf("%d \n", haeufigkeit[i]);
		sum += haeufigkeit[i];
	}
	printf("Total: %d \n", sum);
	getchar();
	return 0;
}

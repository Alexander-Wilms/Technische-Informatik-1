// FIND ALL PRIME NUMBERS IN BETWEEN TWO GIVEN NUMBERS

#include <stdio.h>

int main(void)
{
    int i, j, tmp, l, counter_kein_rest;
    printf("Find all prime numbers between two given integers \n");
	i = -1;
	j = -1;
	do
    {
        printf("Enter two numbers: ");
        scanf("%d %d", &i, &j);
        if (i == j) printf("You entered the same number twice \n");
    } while (i == j);

	if (i > j) // i should be the smaller number
	{
		tmp = i; // save i
		i = j; // i shall be the smaller integer
		j = tmp; // and j the bigger one
	}
	i++; // only search in _between_ the given values
	for (i; i < j; i++) // For each number in between the two given ones...
	{
		counter_kein_rest = 0;
		for(l = 2; l < i; l++) // Check if there's a remainder if one divides each one of them (n) by the numbers 2 to (n-1)
		{
			if (i % l == 0) counter_kein_rest++;
		}
		if (counter_kein_rest == 0) // Prime numbers have no divisors other than 1 and themselves
		{
			printf("%d\n", i);
		}
		counter_kein_rest = 0; // reset for the next number to test
	}
	rewind(stdin);
	getchar();

    return 0;
}

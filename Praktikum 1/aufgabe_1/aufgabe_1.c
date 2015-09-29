// DECIMAL TO BINARY

#include <stdio.h>

int main( void )
{
    int number, factor = 1, binary = 0;

    scanf("%d", &number);
    while(number > 0) {
        binary += (number % 2) * factor; // Checken ob die momentane Binärstelle eine 1 oder 0 ist
        number = number / 2;             // Dann den Rest wegschmeissen
        factor *= 10;                    // Und für die nächste Binärstelle wiederholen
    }
    printf ( "%d \n", binary );
    return 0;
}

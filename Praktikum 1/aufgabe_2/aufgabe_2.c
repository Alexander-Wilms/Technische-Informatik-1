#include <stdio.h>
#include <locale.h>

int main ( void )
{
	printf ( "%s\n", "Draußen brüllen Bären und Löwen!" );
	//getchar(); //wait for user
	printf ( "%s\n", "Drau\xE1 \ben br\x81llen B\x84ren und L\x94wen!" );
	//getchar(); // wait for user
	setlocale( LC_ALL, "" ); // use character set of local system
	printf( "%s\n", "Draußen brüllen Bären und Löwen!" );
	getchar(); // wait for user
	return 0;
}

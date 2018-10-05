#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char boxies[] = "_| ";

int main(int argc, char *argv[])
{
	const int m = strlen(boxies);
	while (1)
		printf("%c", boxies[rand() % m]);
}

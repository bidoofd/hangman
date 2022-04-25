#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

static inline char *strlwr(char *str)
{
	unsigned char *p = (unsigned char *)str;

	while (*p)
	{
		*p = tolower((unsigned char)*p);
		p++;
	}

	 return str;
}

void printBlanks(char blanks[][255], int size)
{
	for(int a = 0; a < size * 2; a++)
	{
		printf("%s", blanks[a]);
	}
}

int guess(char word[][255], char guess[][255])
{
	printf("%s", word[0]);
	return 1;
}

int main(void)
{
	char word[1][255];
	char guess[1][255];

	printf("Enter a word for hangman.\n");
	scanf("%s", word[0]);
	strlwr(word[0]);

	int size = (int)strlen(word[0]);

	char blanks[size*2][255];
	for(int a = 0; a < size * 2; a++)
	{
		if(a % 2 == 0)
		{
			strcpy(blanks[a], "_");
		}
		else
		{
			strcpy(blanks[a], " ");
		}
	}

	printBlanks(blanks, size);

	printf("\nGuess a letter.\n");
	scanf("%s", guess[0]);
}

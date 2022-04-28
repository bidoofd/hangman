#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

//string lower

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

//prints blanks of word

void printBlanks(char blanks[][255], int size)
{
	for(int a = 0; a < size * 2; a++)
	{
		printf("%s", blanks[a]);
	}
}

//returns postion of letter in the word

int guessLetter(char word[][255], char guess[][255], int lastPos)
{
	for(int a = lastPos; a < strlen(word[0]); a++)
	{
		if(word[0][a] == guess[0][0])
		{
			return a;
		}
	}
	return -1;
}

//replaces the blanks with the letter guessed, IF
//guess was a valid letter

void replaceBlanks(char blanks[][255], char word[][255], int guessPos[], int size)
{
	int count = 0;
	for(int a = 0; a < size; a++)
	{
		if(a == guessPos[count])
		{
			count++;
			blanks[a * 2][0] = word[0][a];
		}
	}
}

//win condition for blanks

int checkBlanks(char blanks[][255], int size)
{
	for(int a = 0; a < size * 2; a++)
	{
		if(strcmp(blanks[a], "_") == 0)
		{
			return 1;
		}
	}
	return -1;
}

void stickman(int flag)
{
	if(flag == 0)
	{
		printf("\t\t ________\n");
		printf("\t\t|        |\n");
		printf("\t\t|        |\n");
		for(int a = 0; a < 8; a++)
		{
			printf("\t\t         |\n");
		}
		printf("\t\t    -----+-----\n");
	}
	else if(flag == 1)
	{
		printf("\t\t ________\n");
		printf("\t\t|        |\n");
		printf("\t\t|        |\n");
		printf("\t\tO        |\n");
		for(int a = 0; a < 7; a++)
		{
			printf("\t\t         |\n");
		}
		printf("\t\t    -----+-----\n");
	}
	else if(flag == 2)
	{
		printf("\t\t ________\n");
		printf("\t\t|        |\n");
		printf("\t\t|        |\n");
		printf("\t\tO        |\n");
		printf("\t\t|        |\n");
		printf("\t\t|        |\n");
		for(int a = 0; a < 5; a++)
		{
			printf("\t\t         |\n");
		}
		printf("\t\t    -----+-----\n");
	}
	else if(flag == 3)
	{
		printf("\t\t ________\n");
		printf("\t\t|        |\n");
		printf("\t\t|        |\n");
		printf("\t\tO        |\n");
		printf("\t      \\ |        |\n");
		printf("\t       \\|        |\n");
		for(int a = 0; a < 5; a++)
		{
			printf("\t\t         |\n");
		}
		printf("\t\t    -----+-----\n");
	}
	else if(flag == 4)
	{
		printf("\t\t ________\n");
		printf("\t\t|        |\n");
		printf("\t\t|        |\n");
		printf("\t\tO        |\n");
		printf("\t      \\ | /      |\n");
		printf("\t       \\|/       |\n");
		for(int a = 0; a < 5; a++)
		{
			printf("\t\t         |\n");
		}
		printf("\t\t    -----+-----\n");
	}
	else if(flag == 5)
	{
		printf("\t\t ________\n");
		printf("\t\t|        |\n");
		printf("\t\t|        |\n");
		printf("\t\tO        |\n");
		printf("\t      \\ | /      |\n");
		printf("\t       \\|/       |\n");
		printf("\t\t|        |\n");
		printf("\t\t|        |\n");
		printf("\t       /         |\n");
		printf("\t      /          |\n");
		for(int a = 0; a < 3; a++)
		{
			printf("\t\t         |\n");
		}
		printf("\t\t    -----+-----\n");
	}
	else
	{
		printf("\t\t ________\n");
		printf("\t\t|        |\n");
		printf("\t\t|        |\n");
		printf("\t\tO        |\n");
		printf("\t      \\ | /      |\n");
		printf("\t       \\|/       |\n");
		printf("\t\t|        |\n");
		printf("\t\t|        |\n");
		printf("\t       / \\       |\n");
		printf("\t      /   \\      |\n");
		for(int a = 0; a < 3; a++)
		{
			printf("\t\t         |\n");
		}
		printf("\t\t    -----+-----\n");
	}
}

int main(void)
{
	char word[1][255];
	char guess[1][255];
	int flag = 0;
	int flag2 = 0;
	int flag3 = 0;
	int count = 0;
	int count2 = 0;

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

	stickman(flag3);

	printBlanks(blanks, size);

	printf("\nGuess a letter.\n");
	scanf("%s", guess[0]);

	int guessPos[strlen(word[0])];

	while(flag2 != -1)
	{
		for(int a = 0; a < strlen(word[0]); a++)
		{
			flag = guessLetter(word, guess, flag);
			if(flag != -1)
			{
				guessPos[count] = flag;
				count++;
				flag = flag + 1;
			}
			else
			{
				guessPos[count] = flag;
				count2++;
			}
		}
		flag = 0;
		count = 0;
		if(count2 == flag3)
		{
			replaceBlanks(blanks, word, guessPos, size);
			printBlanks(blanks, size);
			printf("\nGuess a letter.\n");
			scanf("%s", guess[0]);
		}
		else
		{
			flag3++;
			stickman(flag3);

		}
		flag2 = checkBlanks(blanks, size);
	}
}

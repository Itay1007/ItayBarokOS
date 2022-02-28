#include "string.h" 

void reverse(char *s)
{
	int i, j;
	char c;
	for(i = 0, j = strlen(s) - 1, i < j; i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

int strlen(char * s)
{
	int i = 0;

	while(s[i])
	{
		i++;
	}
	return i;
}

void push(char c, char * s)
{
	int len = strlen(s);
	s[len] = c;
	s[len + 1] = '\0';
}

void pop(char * s)
{
	int len = strlen(s);
	s[len - 1] = '\0';
}
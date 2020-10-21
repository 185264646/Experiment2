#include <stdio.h>
#include <string.h>
#define isodigit(x) (isdigit(x) && (x) != '8' && (x) != '9')
_Bool is_valid(const char *);
int main(void)
{
	char s[BUFSIZ];
	while (gets(s), !feof(stdin))
	{
		if(is_valid(s))
			puts("Valid");
		else
			puts("Invalid");
	}
	return 0;
}

_Bool is_valid(const char *str)
{
	if(str[0] == '0')
	{
		if(str[1] == 'x' || str[1] == 'X')
		{
			if (strlen(str) == 2)
				return 0;
			for (int i = 2, end = strlen(str); i < end; i++)
				if (!isxdigit(str[i]))
					if (str[i] == 'l' || str[i] == 'L' && str[i + 1] == '\0')
						return 1;
					else
						return 0;
		}
		else
		{
			if (strlen(str) == 1)
				return 1;
			for (int i = 1, end = strlen(str); i < end; i++)
				if (!isodigit(str[i]))
					if (str[i] == 'l' || str[i] == 'L' && str[i + 1] == '\0')
						return 1;
					else
						return 0;
		}
		return 1;
	}
	else if(isdigit(str[0]))
	{
		for (int i = 0, end = strlen(str); i < end; i++)
			if(!isdigit(str[i]))
				if (str[i] == 'l' || str[i] == 'L' && str[i + 1] == '\0')
					return 1;
				else
					return 0;
	}
	else if (str[1] == 'l' || str[1] == 'L' && str[2] == '\0')
		return 1;
	else
		return 0;
	return 1;
}
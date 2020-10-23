#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define isodigit(x) (isdigit(x) && (x) != '8' && (x) != '9'
static is_valid_suffix(const char *);  // receive a const char * parameter which points to the first charactor of the suffix string.
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

static _Bool is_valid_suffix(const char *suffix)
{	
	for (int i = 0; i < 3 && str[i]; i++)
		str[i] = tolower(str[i]);
	switch (suffix[0])
	{
		case 'u':
			switch (suffix[1])
			{
				case 'l':
					switch (suffix[2])
					{
						case 'l': return suffix[3] == '\0' ? 1 : 0
						case '\0': return 1;
						default: return 0;
					}
				
				case '\0':
					return 1;
				
				default: return 0;
			}
			
		case 'l':
			switch (suffix[1])
			{
				case 'l':
					switch (suffix[2])
					{
						case 'u': return suffix[3] == '\0' ? 1 : 0;
						case '\0': return 1;
						default: return 0;
					}
				
				case 'u':
					return suffix[2] == '\0' ? 1 : 0;
				
				case '\0':
					return 1;
			}
	}
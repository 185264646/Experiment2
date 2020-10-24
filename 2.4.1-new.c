// Still couldn't handle situations like 0UlL(should be invalid).
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define isodigit(x) (isdigit(x) && (x) != '8' && (x) != '9')
static _Bool is_valid_suffix(const char *);  // receive a const char * parameter which points to the first charactor of the suffix string.
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
	if(str[0] == '0')  // Might be octal or hexadecimal number
	{
		if(str[1] == 'x' || str[1] == 'X') // Might be hexadecimal
		{
			if (str[2] == '\0') return 0; // A string like "0x" or "0X" is obviously invalid.
			for (int i = 2, end = strlen(str); i < end; i++)
				if (!isxdigit(str[i]))
					if (is_valid_suffix(str + i))
						return 1;
					else
						return 0;
		}
		else  // Might be octal 
		{
			for (int i = 1, end = strlen(str); i < end; i++)
				if (!isodigit(str[i]))
					if (is_valid_suffix(str + i))
						return 1;
					else
						return 0;
		}
		return 1;
	}
	else if(isdigit(str[0]))  // might be decimal
	{
		for (int i = 0, end = strlen(str); i < end; i++)
			if(!isdigit(str[i]))
				if (is_valid_suffix(str + i))
					return 1;
				else
					return 0;
	}
	else if (is_valid_suffix(str + 1)) // a single 0 with suffix.
		return 1;
	else
		return 0;
	return 1;
}

static _Bool is_valid_suffix(const char *suffix)
{
	char temp[4]="";
	for (int i = 0; i < 3 && suffix[i]; i++)
		temp[i] = tolower(suffix[i]);
	switch (temp[0])
	{
		case 'u':
			switch (temp[1])
			{
				case 'l':
					switch (temp[2])
					{
						case 'l': return temp[3] == '\0' ? 1 : 0;
						case '\0': return 1;
						default: return 0;
					}
				
				case '\0':
					return 1;
				
				default: return 0;
			}
			
		case 'l':
			switch (temp[1])
			{
				case 'l':
					switch (temp[2])
					{
						case 'u': return temp[3] == '\0' ? 1 : 0;
						case '\0': return 1;
						default: return 0;
					}
				
				case 'u':
					return temp[2] == '\0' ? 1 : 0;
				
				case '\0':
					return 1;
			}
	}
	return 0;
}

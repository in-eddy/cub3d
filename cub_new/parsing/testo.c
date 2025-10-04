
#include <stdio.h>

int	check_spaces(char *str, int *j)
{
	if (str[(*j) - 1] && str[(*j) - 1] != '1')
		return (0);
	else
	{
		while (str[*j] && (str[*j] == ' ' || str[*j] == '	'))
		{
			(*j)++;
			if (str[*j] == '0' && (str[(*j) + 1] == ' ' || str[(*j) + 1] == '	'))
				(*j)++;
			else
				return (0);
		}
		if (str[*j] && str[*j] != '1')
			return (0);
	}
	return (1);
}

int main ()
{
    
    printf()
}
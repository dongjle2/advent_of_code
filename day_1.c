#include <stdio.h>
#include <string.h>

size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (*s++)
		l++;
	return (l);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*ps1;
	const unsigned char	*ps2;
	size_t				l_s1;
	size_t				l_s2;

	if (!n)
		return (0);
	n--;
	l_s1 = ft_strlen(s1);
	l_s2 = ft_strlen(s2);
	ps1 = (const unsigned char *)s1 + l_s1 - 1;
	ps2 = (const unsigned char *)s2 + l_s2 - 1;
	while (*ps1 && *ps2 && n--)
	{
		if (*ps1 != *ps2)
			return (*ps1 - *ps2);
		ps1--;
		ps2--;
	}
	return (*ps1 - *ps2);
}

int	ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len_needle;
	size_t	i;
	size_t	l;

	i = 0;
	l = 0;
	len_needle = ft_strlen(needle);
	// while (l < len && haystack[i])
	while (haystack[i] && l < len)
	{
		if (haystack[i] == *needle && l + len_needle <= len)
			if (ft_strncmp(haystack + i, needle, len_needle) == 0)
				return (i);
		i++;
		l++;
	}
	return (-1);
}

int	strnstr_re(const char *haystack, const char *needle, size_t len)
{
	size_t	len_needle;
	size_t	i;
	size_t	l;
	size_t	j;

	i = 0;
	l = 0;
	j = 0;
	len_needle = ft_strlen(needle);
	// while (l < len && haystack[i])
	while (haystack[i] || l < len)
	{
		if (haystack[i] == *needle && l + len_needle <= len)
			if (ft_strncmp(haystack + i, needle, len_needle) == 0)
				j = i;
		i++;
		l++;
	}
	if (i == len - 1)
		return (-1);
	return (j);
}

int	l_find(char *buffer)
{
	int	i;
	int	l;
	int	k;	
	int	x[10];

	i = 0;
	l = strlen(buffer) - 1;
	k = 1;
	while (i <= l)
	{
		if ('0' <= buffer[i] && buffer[i] <= '9')
		{
			i = buffer[i];
			break;
		}
		i++;
	}
	x[1] = ft_strnstr(buffer, "one", sizeof(buffer));
	x[2] = ft_strnstr(buffer, "two", sizeof(buffer));
	x[3] = ft_strnstr(buffer, "three", sizeof(buffer));
	x[4] = ft_strnstr(buffer, "four", sizeof(buffer));
	x[5] = ft_strnstr(buffer, "five", sizeof(buffer));
	x[6] = ft_strnstr(buffer, "six", sizeof(buffer));
	x[7] = ft_strnstr(buffer, "seven", sizeof(buffer));
	x[8] = ft_strnstr(buffer, "eight", sizeof(buffer));
	x[9] = ft_strnstr(buffer, "nine", sizeof(buffer));

	l = -1;
	while (k < 10)
	{
		if (0 <= x[k] && x[k] < l)
			l = x[k];
		k++;
	}

	if (l < i)
		return (l);
	// printf("")
		return (i - '0');
}

int strncmp_reverse(const char *s1, const char *s2, size_t n) {
    while (n > 0) {
        if (*s1 != *s2) {
            return *(unsigned char *)s2 - *(unsigned char *)s1;
        }

        if (*s1 == '\0') {
            return 0;  // Both strings are equal up to this point
        }

        s1--;
        s2--;
        n--;
    }

    return -1;  // Both strings are equal
}

int	strnstr_reverse(const char *haystack, const char *needle, size_t len) {
    size_t needle_len = strlen(needle);

    const char *haystack_end = haystack + len - needle_len;

    while (haystack <= haystack_end) {
        if (strncmp_reverse(haystack_end, needle, needle_len) == 0) {
            return (haystack_end - haystack); // Match found
        }
        haystack_end--;
    }

    return (0); // No match found
}

int	r_find(char *buffer)
{
	int	l;
	int	x[10];
	int	k;
	int	tmp;

	l = strlen(buffer) - 1;
	k = 1;
	while (0 <= l)
	{
		if ('0' <= buffer[l] && buffer[l] <= '9')
		{
			l = buffer[l];
			break;
		}
		l--;
	}
	x[1] = strnstr_re(buffer, "one", sizeof(buffer));
	x[2] = strnstr_re(buffer, "two", sizeof(buffer));
	x[3] = strnstr_re(buffer, "three", sizeof(buffer));
	x[4] = strnstr_re(buffer, "four", sizeof(buffer));
	x[5] = strnstr_re(buffer, "five", sizeof(buffer));
	x[6] = strnstr_re(buffer, "six", sizeof(buffer));
	x[7] = strnstr_re(buffer, "seven", sizeof(buffer));
	x[8] = strnstr_re(buffer, "eight", sizeof(buffer));
	x[9] = strnstr_re(buffer, "nine", sizeof(buffer));

	tmp = -1;
	while (k < 10)
	{
		if (tmp < x[k])
			tmp = x[k];
		k++;
	}

	if (tmp < l)
		return (l - '0');
	else
		return (k);
}

int sol (void)
{
	FILE	*pFile;
	char	buffer[100];
	int		ret = 0;

	pFile = fopen ("day_1_input.txt","r");
	if (pFile == NULL)
	{
	  perror("Error opening file");
	  return (1);
	}
	while (fgets(buffer, sizeof(buffer), pFile) != NULL)
	{
		ret += 10 * l_find(buffer) + r_find(buffer);
		printf("%d\n", ret);
	}
    fclose (pFile);

  return ret;
}

int	main(void)
{
	int	ret = sol();
	printf("%d\n", ret);
	return (0);
}

#include "libmx.h"

char *mx_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	str = mx_strnew(len);
	unsigned slen = mx_strlen(s);

	if (!str || !s || start > slen)
		return NULL;
	
    i = 0;

	while (i < len) {
		str[i] = s[i + start];
		i++;
	}
	return str;
}

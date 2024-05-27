
#include"../so_long.h"

static int	ft_check_char(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim_end(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1);
	while (end && ft_check_char(s1[end - 1], set))
		end--;
	str = (char *)s1;
	str = (char *)malloc(sizeof(*s1) * (end + 1));
	if (!str)
		return (NULL);
	i = 0;
    start = 0; 
	while (i < end)
		str[i++] = s1[start++];
	str[i] = 0;
	return (str);
}
// #include<stdio.h>
// int main()
// {
//     char *s1 ="AAZAABonjour toiSDSAFAAAAAAAAAA";
//     char *set = "A";
// 	// char *set = NULL;
//     char *check;

//     check = ft_strtrim(s1,set);
//     printf("%s",check);
// 		system("leaks -q -fullContent $(ps -o pid= -p $PPID)");
//     return (0); 
// }
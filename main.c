#include "libft.h"

int main()
{
	char **mat;

	mat = ft_split("      split this for   me  !       ", ' ');
	while(*mat)
		printf("%s\n", *mat++);
		printf("%c\n", mat[0][0]);
	return (0);
}

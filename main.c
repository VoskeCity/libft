#include "libft.h"

int main()
{
	char *str = "01234";
	size_t size = 10;
	char *ret = ft_substr(str, 10, size);

	if (!strncmp(ret, "", 1))
	{
		free(ret);
		exit(TEST_SUCCESS);
	}
	free(ret);
	exit(TEST_FAILED);

	return (0);
}

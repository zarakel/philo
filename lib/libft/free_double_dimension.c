#include "libft.h"
#include <stdlib.h>

void	free_double_dimension(char **str)
{
	char	**tmp;

	tmp = str;
	while (*tmp)
		free(*tmp++);
	free(str);
}

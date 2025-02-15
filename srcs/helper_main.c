#include "so_long.h"

bool	ft_isvalid(char *str)
{
	int	length;

	length = ft_strlen(str);
	if (ft_strncmp(&str[length - 4], ".ber", 4) != 0)
		return (false);
	return (true);
}

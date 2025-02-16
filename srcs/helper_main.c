#include "so_long.h"

bool	ft_isvalid(const char *str)
{
	int	length;

	length = ft_strlen(str);
	if (ft_strncmp(&str[length - 4], ".ber", 4) != 0)
	{
		ft_error("INVALID FILE NAME/EXTENSION!");
		return (false);
	}
	return (true);
}

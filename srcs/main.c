#include "so_long.h"

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		ft_printf("the program starts correctly!\n");
		if (ft_isvalid((const char *)argv[1]))
			ft_printf("Valid!\n");
		else
			ft_printf("Invalid!\n");
	}
	else
	{
		if (argc > 2)
			ft_error("too many arguments!");
		if (argc < 2)
			ft_error("some arguments missing!");
	}
	return (0);
}

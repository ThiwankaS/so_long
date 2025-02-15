#include "so_long.h"

int main(int argc, char *argv[])
{
	if(argc == 2)
	{
		ft_printf("the program starts correctly!\n");
		ft_printf("%s\n",argv[1]);
	}
	else
	{
		if(argc > 2)
			ft_error("too many arguments!");
		if(argc < 2)
			ft_error("some arguments missing!");
	}
	return (0);
}

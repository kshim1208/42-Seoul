#include <stdio.h>

void	ft_function()
{
	static int	i = 0;

	printf("on func %d\n", i);

	i++;
}

int	main()
{
	ft_function();

	ft_function();

	ft_function();

	ft_function();

	ft_function();


}

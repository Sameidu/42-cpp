#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		int j = 0;
		while (++j < argc)
		{
			int i = -1;
			while (argv[j][++i])
				std::cout << (char)toupper(argv[j][i]);
		}
	}
	std::cout << std::endl;
	return (0);
}

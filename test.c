#include "ft_printf.h"

int main()
{
	ft_printf("%c", '0');
	ft_printf(" %c ", '0');
	ft_printf("%c", '0' -256);
	ft_printf("%c %c %c", '0', 0, '1');
	ft_printf("%c %c %c", ' ', ' ', ' ');
	ft_printf("%c %c %c", '1','2','3');
	ft_printf("%c %c %c", '2','1',0);
	ft_printf("%c %c %c", 0,'1','2');

	return 0;
}
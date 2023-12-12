#include "ft_printf.h"

int main() {

	// int c = 456784;
	// int k = 0, j = 0;
	// int addr = 3;
	// ft_printf("This is pure no format ft_printf test : Hi\n");
	// ft_printf("This is format_c test : ");
	// c = format_c('a');
	// ft_printf("\n");
	// ft_printf("This is format_s test : ");
	// s = format_s("Hello My name is daehlee. This is format %s test.");
	// ft_printf("\n");
	// ft_printf("Format functions return int value -> ");
	// printf("C : %d, S : %d\n",c, s);
	// k = printf("%p", &addr);
	// printf("\n")
	// k = printf("%d", c);
	// printf("\n");
	// j = format_d(c);

	// printf ("\nprintf : %d, format_pointer  : %d",k, j);
	printf("%x, %X\n", -10, 10);
	format_x(-10, 1);
	printf("\n");
	format_x(10, 2);
	return 0;
}
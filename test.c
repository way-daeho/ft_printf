#include "ft_printf.h"

int main() {
	printf("%d : %s", 3, "IH");
	int a = printf("%d : %s", 3, "IH\n");
	printf("%d", a);
}
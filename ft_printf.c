#include <stdarg.h>
#include <stdio.h>
#include <string.h>

int ft_printf(const char *format, ...)
{
	va_list ap;
	char	*new_s;
	void	*args;
	int		i;

	va_start(ap, format);
	// s = *va_arg(ap, char *);
	i = 0;

	while (format[i] != 0)
	{
		i++;
	}
	if (va_arg)
	printf("%c", va_arg(ap, int));

	va_end(ap);
	return (0);	
}

int main(void)
{
	ft_printf("x ds");
	printf("\n");
	return (0);
}
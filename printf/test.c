
#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	char *str;
	unsigned int l;
	
	l = 744674407;
	str = "hello world";
	ft_printf("Print hex [%020X]\n", l);
	printf("Print hex [%020X]\n", l);
	ft_printf("Print string. [%s]\nprint pointer [%p]\n", str, str);
	printf("Print string. [%s]\nprint pointer [%p]\n", str, str);
	ft_printf("Print str. [%-5.2s]\n", NULL);
	printf("Print str. [%-5.2s]\n", NULL);
	ft_printf("Print char. [%20c]\n", 'd');
	printf("Print char. [%20c]\n", 'd');
	ft_printf("Print str. [%20.1s]\n", "abcdefghij");
	printf("Print str. [%20.1s]\n", "abcdefghij");
	ft_printf("Print int. [%-20i]\n", 13);
	printf("Print int. [%-20i]\n", 13);
	ft_printf("Print ptr. [%20p]\n", str);
	printf("Print ptr. [%20p]\n", str);
	ft_printf("Print str. [%-*.2s]\n", -5, "null");
	printf("Print str. [%-*.2s]\n", -5, "null");
	ft_printf(	"\t%00000000004\n", -1);
	printf(	"\t%00000000004d\n", -1);
	ft_printf("Print int. [%10.2u]\n", 130);
	printf("Print int. [%0-8.5i]\n", 34);
	return (0);
}
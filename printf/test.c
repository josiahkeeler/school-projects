
#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	char *str;
	unsigned int l;

	l = 744674407;
	str = "hello world";
	ft_printf("Print hex [%X]\n", l);
	printf("Print hex [%X]\n", l);
	ft_printf("Print string. [%s]\nprint pointer [%p]\n", str, str);
	printf("Print string. [%s]\nprint pointer [%p]\n", str, str);
	ft_printf("Print str. [%-5.2s]\n", "hi");
	printf("Print str. [%-5.2s]\n", "hi");
	ft_printf("Print char. [%20c]\n", 'd');
	printf("Print char. [%20c]\n", 'd');
	ft_printf("Print str. [%-20s]\n", "abcdefghij");
	printf("Print str. [%-20s]\n", "abcdefghij");
	ft_printf("Print int. [%-20i]\n", 13);
	printf("Print int. [%-20i]\n", 13);
	ft_printf("Print ptr. [%20p]\n", str);
	printf("Print ptr. [%20p]\n", str);
	return (0);
}
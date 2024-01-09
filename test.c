
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <limits.h>
#define UINTPTR_MAX       18446744073709551615UL
int main()
{
	size_t i;

	i = 18446744073709551616UL;
	printf("%lu\n",  i);
}
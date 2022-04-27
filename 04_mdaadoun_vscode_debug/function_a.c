#include "header.h"

void print_a(char c)
{
	c = 'a';
	write(1,&c,1);
}

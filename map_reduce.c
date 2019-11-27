#include <stdio.h>
#include <stdlib.h>

void reduce(void *src, size_t n, size_t srcb, void *dest, void (*f)(void *, void *, void *)) {
	if (n == 1) { // If there is one last element in the array, don't RECURSE, just perform the function one last time. 
		f(src, dest, dest);
	}
	reduce(src + srcb, n-1, srcb, dest, f);
	f(src, dest, dest);
	// three parameters of f are operand, operand, destination
}

void map(void *src, size_t n, size_t srcb, void *dest, size_t destb, void (* f)(void *, void *))// we use VOID pointers for src and destination because we are UNSURE of the type ( this is generalized map function)
{
  f(src, dest);
  src += srcb;
  dest += destb;
}
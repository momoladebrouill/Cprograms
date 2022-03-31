#include <stdio.h>

int main()
{
	long  a=1;
	long  b=0;
	double  phi;
	int c;
	for (int i = 0; i < 40; ++i)
	{
		c=a+b;
		phi=(double)b/a;
		printf("%g \n",phi);
		a=b;
		b=c;
	};
	return 0;
}
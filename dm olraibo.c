#include <stdio.h>


int p(int n){
	return 2*n*n+12*n+22;
};
int q(int n){
	return n+2;
};
int r(int n){
	return 2*n+5;
};
int main()
{
	printf("| n | q | r |\n");
	printf("|:--:|:--:|:--:|\n");
	for (int n = 0; n <= 100; n++)
	{
		printf("| %d | %d | %d |\n",n,p(n)%q(n),p(n)%r(n));

	};

	return 0;
};
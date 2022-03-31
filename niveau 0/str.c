#include <stdio.h>
/*
%f  : decimal;
%e : scientifique;
%g : je te laisse faire, mais que pour des double;
%i/d : integer/booléan, ils sont un peux étranges ces deux là;
*/
int main()
{
	char momo[15];//limite de lenght
	printf("yep mais ton nom (max 14 char:");
	scanf("%s",momo);
	printf("hello %s!\n",momo);
	return 0;
};
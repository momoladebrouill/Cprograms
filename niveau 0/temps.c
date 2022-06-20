#include <time.h>
#include <stdio.h>
#include <stdbool.h>
int main(){
	int t=time(NULL);
	for (int i = 0; i < 10; ++i)
	{
		while(time(NULL)==t){}
		printf("%li\n",t=time(NULL));
	};
	return 0;
}
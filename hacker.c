#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(){
	srand(15566255);
	for (int i = 0; i < 100000; i += 1)
	{
		if (rand()%2)
		{
			printf("0");
		}else
		{
			printf("1");
		};
		sleep(0.1);
	}
	
	return 0;
};

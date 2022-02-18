#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	srand(time(NULL));
	char fill='o';
	int hauts[]={5,5,5,5,5,5,5,5,5,5};
	for (int i = 0; i < 1000; i += 1)
	{
		for (int j = 0;  j < rand()%10; j += 1)
		{
			printf("%c",fill);
		}
		printf("\n");
	}
	return 0;
	
}

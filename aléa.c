#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	srand(time(NULL));//planter la seed, à partir du temps
	int ut;
	for (int i = 0; i < 10; ++i)
	{	
		ut=rand();
		printf("%i\n",ut);
	};
	return 0;
}

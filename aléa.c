#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	srand(time(NULL));//planter la seed, à partir du temps
	for (int i = 0; i < 10; ++i)
	{
		printf("%i\n",ut);
		ut=rand();
	};
	return 0;
}

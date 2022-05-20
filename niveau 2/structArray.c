#include <stdio.h>
#include <stdlib.h>

typedef struct mess{
	int v; // value 
	struct mess *bro; // next in list
}mess;

int main(int argc, char const *argv[])
{
	mess * first= (mess*) malloc(sizeof(mess)); // first element of the array
	mess * c=first;  // keep its location for further calculation
	for (int i = 0; i < 10; i++)
	{
		first->bro=(mess*) malloc(sizeof(mess));
		first->v=i;
		first=first->bro;

	}
	while(c->bro){
		printf("%i\n", c->v);
		c=c->bro;
	}
	return 0;
}
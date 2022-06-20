#include <stdio.h>
#include <stdlib.h>
#define STADE1 6
#define STADE2 13


void printtable(int * table){
	printf("  ");
	for (int i = 0; i < 13; ++i)
	{
		if (i == STADE1){
			printf("\n%i             %i\n  ",table[STADE2],table[STADE1]);
		}else{
			printf("%i ",table[i]);
		} 

	}
	printf("\n");
}

int play(int player, int position, int * table){
	int from = player*6+position;
		for (; table[from]; --table[from])
		{
			table[player*6+(position++)]++;
		}
	
	printf("played !\n",player);
}

int main(int argc, char const *argv[])
{
	int * table = malloc(sizeof(int)*14);
	for (int i = 0; i < 14; ++i){
		*(i+table) = 4;
	}
	table[STADE1]=1;
	table[STADE2]=2;
	printtable(table);
	play(0,4,table);
	printtable(table);

	return 0;
}
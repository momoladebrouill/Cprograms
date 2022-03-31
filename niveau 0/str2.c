#include <stdio.h>
// un charctère = UNE lettre
// un charactère c'est un nombre
// voir tableau ASCII
int main(){
	char x='a';
	printf("%c\n",x);
	printf("%i\n",x);
	printf("%c\n",97);
	for (int i = 0; i < 128; ++i)
	{
		printf("%i : %c\n",i,i);
	};
	return 0;
}
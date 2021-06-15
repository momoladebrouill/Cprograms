#include <stdio.h>

int main(){
	char momo[15];
	scanf("%s",momo);
	printf("%c\n",momo[0] );
	printf("%c\n",momo[1] );
	printf("%s\n",momo);
	printf("%li\n",sizeof(momo));
	printf("------------\n");
	for (int i = 0; i < sizeof(momo); ++i)
	{
		printf("%i\t%c\n",momo[i],momo[i]);
	}
	return 0;
};

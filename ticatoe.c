#include <stdio.h>
int tabl[9]={1,2,3,4,5,6,7,8,9};

int get(int x,int y){
	if(x<0 || x>2 || y<0 ||y>2){
		return -1;
	}
	return tabl[y*3+x];
}
void rpz(){
	for(int y=0;y<3;y++){
		for(int x=0;x<3;x++){
			printf("%i\t",get(x,y));
		}
		printf("\n");
	}
}
int main(){
	rpz();
	printf("lupercalles\n");
	int result,x,y;
	while(result!=-1){
		scanf("%2i",&result);
		x=(result-1)%3;
		y=(int)(9-result)/3;
		printf("x=%i;y=%i\n",x,y);
	}
	return 0;
}

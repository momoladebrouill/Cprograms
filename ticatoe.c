#include <stdio.h>
int tabl[9]={0};

int get(int x,int y){
	if(x<0 || x>2 || y<0 ||y>2){
		return -1;
	}
	return tabl[y*3+x];
}

void set(int x,int y,int val){
	tabl[x+y*3]=val;
}

void rpz(){
	for(int y=0;y<3;y++){
		for(int x=0;x<3;x++){
			switch(get(x,y)){
				case 1:
					printf("X");
					break;
				case 2:
					printf("O");
					break;
				default :
					printf("_");
			}		
			printf(" ");
		}
		printf("\n");
	}
}

int checkforwin(int x,int y){
	int sumx=0,sumy=0,diag1=0,diag2=0;
	for(int i=0;i<3;i++){
		sumx+=(int) get(x,y)==get(i,y);
		sumy+=(int) get(x,y)==get(x,i);
		diag1+=(int) get(0,0)==get(i,i);
		diag2+=(int) get(0,2)==get(2-i,i);
	}
	if(sumx==3 || sumy==3 || diag1*get(1,1)==3 || diag2*get(1,1)==3){
		return 1;
	}
	sumx=0;
	for(int i=0;i<9;i++){sumx+=(int) tabl[i]==0;}
	if(sumx==0){
		return 1;/*tie*/
	}
	return 0;


}

int main(){
	rpz();
	int result,x,y,tour=0;
	while(result!=-1){
		scanf("%2i",&result);
		x=(result-1)%3;
		y=(int)(9-result)/3;
		set(x,y,tour+1);
		tour=(tour+1)%2;
		rpz();
		if(checkforwin(x,y)){
			printf("Fin");
			result=-1;
		}
	}
	return 0;
}

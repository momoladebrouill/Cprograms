#include <stdio.h>

struct vec{
	int x;
	int y;
};

typedef struct{
	int x;
	int y;
}pos;

typedef struct{
	char nom[30];
	pos posi;
	struct vec depl;
}avion;

typedef struct{
	char c;
	int a:32;
	int b;
}ho;

int main(){
	int a asm 64;
	printf("%li\n",sizeof(ho));
	printf("%li\n",sizeof(a));
	printf("%li\n",sizeof(char[10]));
	
	struct vec grav={5,10};
	pos player={1,1};
	avion airbus={"tristan",{0,0},{1,1}};
	//printf("Crée un veteur x:%d,y:%d\n",grav.x,grav.y);
	/*printf("%s,pos:%d %d,vec:%d %d\n",
		airbus.nom,
		airbus.posi.x,
		airbus.posi.y,
		airbus.depl.x,
		airbus.depl.y
	);*/
	return 0;
}


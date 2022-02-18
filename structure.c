#include <stdio.h>

struct vec
{
	int x;
	int y;
};

typedef struct 
{
	int x;
	int y;
}pos; // pareil sauf pour la déclaration un peu différente

typedef struct
{
	char nom[30];
	pos posi;
	struct vec depl;
}avion;
int main(){
	struct vec grav={5,10};
	pos player={1,1};
	printf("Crée un veteur x:%d,y:%d\n",grav.x,grav.y);
	avion airbus={"tristan",{0,0},{1,1}};
	printf("%s,pos:%d %d,vec:%d %d\n",
		airbus.nom,
		airbus.posi.x,
		airbus.posi.y,
		airbus.depl.x,
		airbus.depl.y
	);
	return 0;
}

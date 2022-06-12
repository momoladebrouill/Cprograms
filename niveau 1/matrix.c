#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define pos(m,x,y) y*m.width+x

typedef struct {
	unsigned int width;
	unsigned int height;
	int *m;
}Matrix;

void print_mat(Matrix M){
	for (int i = 0; i < M.width; ++i){
		for (int j = 0; j < M.height; ++j){
			printf("%i\t",
				*(M.m+i*M.width+j));// cuz why not
		}
		printf("\n");
	}
}

Matrix newM(int width,int height,int def){
	Matrix m;
	m.width = width;
	m.height = height;
	m.m = malloc(width*height*sizeof(int));
	for (int i = 0; i < m.width*m.height; ++i){
		*(i+m.m) = def;// pour faire pleurer Thomas
	}
	return m;
}

Matrix randM(int width,int height){
	Matrix m;
	m.width = width;
	m.height = height;
	m.m = malloc(width*height*sizeof(int));
	for (int i = 0; i < m.width*m.height; ++i){
		*(i+m.m) = rand()%10;// pour faire pleurer Thomas
	}
	return m;	
}

Matrix prod(Matrix a,Matrix b){
	Matrix c=newM(b.width,a.height,0);
	int x,y,k,sum=0;
	for (y = 0; y < c.height; ++y){
		for (x = 0; x < c.width; ++x){
			for (sum = k = 0; k < a.width; ++k){
				sum += a.m[pos(a,k,y)] * b.m[pos(b,x,k)];
			};
			*(pos(c,x,y)+c.m) = sum;
		}
	}
	return c;
}

Matrix identityM(int size){
	Matrix res=newM(size,size,0);
	for (int i = 0; i < size; ++i)
	{
		res.m[i*(size+1)]=1;
	}
	return res;
}

int main(int argc, char const *argv[]){
	srand(time(NULL));//planter la seed, à partir du temps
	Matrix M=newM(3,3,69);
	for(int i=0;i<9;++i){i[M.m]=69+i;}
	print_mat(M);
	printf("\n");

	Matrix a=randM(10,10);
	Matrix b=newM(10,10,0);
	print_mat(a);
	
	printf("\n");
	print_mat(b);
	
	Matrix c = prod(a,b);
	printf("\n");
	print_mat(c);
	return 0;
}
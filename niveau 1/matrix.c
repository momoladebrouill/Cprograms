#include <stdio.h>
#include <stdlib.h>

typedef struct {
	unsigned int width;
	unsigned int height;
	int *m;
}Matrix;

void print_mat(Matrix M){
	for (int i = 0; i < M.width; ++i){
		for (int j = 0; j < M.height; ++j){
			printf("%i\t",*(M.m+i*M.width+j));
		}
		printf("\n");
	}
}

int pos(Matrix m,int x,int y){
	return y*m.width+x;
}

Matrix new(int width,int height,int def){
	Matrix m;
	m.width=width;
	m.height=height;
	m.m=malloc(width*height*sizeof(int));
	for (int i = 0; i < m.width*m.height; ++i)
	{
		m.m[i]=def;
	}
	return m;
}

Matrix prod(Matrix a,Matrix b){
	Matrix c=new(b.width,a.height,0);
	int sum;
	for (int y = 0; y < c.height; ++y){
		for (int x = 0; x < c.width; ++x){
			sum=0;
			for (int k = 0; k < a.width; ++k)
			{
				sum+=a.m[pos(a,k,y)] * b.m[pos(b,x,k)];
			}
			c.m[pos(c,x,y)] = sum;
		}
	}
	return c;
}

int main(int argc, char const *argv[]){
	Matrix M=new(3,3,69);
	for(int i=0;i<9;++i){i[M.m]=69+i;}
	print_mat(M);
	printf("\n");

	Matrix a=new(3,3,1);
	Matrix b=new(3,3,1);
	print_mat(a);
	
	printf("\n");
	print_mat(b);
	
	Matrix c = prod(a,b);
	printf("\n");
	print_mat(c);
	return 0;
}
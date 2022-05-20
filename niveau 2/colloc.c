#include <stdio.h>
#include <stdlib.h>

typedef struct var{
	int v;
}var;

int main() {
    int sum = 0;
    var * ptr = (var*)calloc(10, sizeof(var));
	for (size_t i = 0; i < 10; i++) {
		printf("%i",*(ptr+i));
	}
    if (ptr == NULL) {
        printf("Error! memory not allocated.");
        exit(0);
    }
    printf("Building and calculating the sequence sum of the first 10 terms \n ");
    for (int i = 0; i < 10; ++i) {
		(* (ptr + i)).v= i*2;
        sum += (* (ptr + i)).v;
    }
    printf("Sum = %d", sum);
    free(ptr);
    return 0;
}

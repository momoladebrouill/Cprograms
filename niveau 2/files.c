#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void write(char *fileName, char *content)
{
   FILE *fptr;
   fptr = fopen(fileName,"w");
   for (int i = 0; i < 69; i++) {
     fprintf(fptr,"%d %s",i,content);
   }
   fprintf(fptr, "\n");
   fclose(fptr);
}

char *read(char *fileName)
{
    FILE *file = fopen(fileName, "r");
    char *content;
    size_t n = 0;
    int c;
    content = malloc(1000);
    while ((c = fgetc(file))!= EOF){
        content[n++] = (char) c;
    }
    content[n] = '\0';
    fclose(file);
    return content;
}

int main(){
  char t[1000];
  write("./mmh.txt","quid game");
  strcpy(t,read("./mmh.txt"));
  printf("%s",t );
  return 0;
}

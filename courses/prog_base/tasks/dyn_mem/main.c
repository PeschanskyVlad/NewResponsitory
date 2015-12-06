#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *p=(char*)malloc(50);
puts("Enter string:");
    gets(p);
    int *k = (int*)malloc(sizeof(int));
    int *i = (int*)malloc(sizeof(int));
    *k=0;

while (*p != '\0'){

      if(ispunct(*p)>0){
        *k=*k+1;
       }
        p++;
        }


printf("The number of punctuation: %i",*k);



    return 0;
}

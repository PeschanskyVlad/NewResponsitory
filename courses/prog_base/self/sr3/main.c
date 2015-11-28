#include <stdio.h>
#include <stdlib.h>

int main()
{
    int l,m,i;
    char fName[10];
    char text[100];
    char lm[10];
    char str[]= " ";
    FILE * fp;
printf("Enter L and M:");
    fgets(lm, 10, stdin);
    l = atoi(strtok(lm, str));
    m = atoi(strtok (NULL,str));



    puts("Enter name file");

   gets(fName);

   fp = fopen(fName , "r");
   if(fp == NULL){
    printf("\nOpenError\n");
   }else{
   fgets(text, 100, fp);
   printf("\nElement L = %c\n",text[l]);
printf("Element M = %c\n",text[m]);
   }

fclose (fp);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>


int calc(char str[],int l){
char sogl[] = "BCDFGHJKLMNPQRSTVWXZbcdfghjklmnpqrstvwxz";
int result=0;
if(l==1){
return(1);
}
    if (strchr(sogl,str[l-1])>0){
    result++;
}
result +=calc(str,l-1);
return result;

}




int main()
{
    char sogl[] = "BCDFGHJKLMNPQRSTVWXZbcdfghjklmnpqrstvwxz";
    char str[30];
    int result=0,l;
    gets(str);
    l=strlen(str);
    result=calc(str,l);



printf("Number of consonant letters in line = %i",result);

}

#include <stdio.h>
#include <stdlib.h>



void input(char *fl1[]){
    FILE * fp;
    char str[80];
    char s[]=" ";
    fp=fopen( fl1[1],"r");
    while(str!=EOF){
    fgets(str,sizeof(str),fp);
    change(str,fl1);
    }

    fclose(fp);



}

void change(char str[],char *fl1[]){
      char *res;
      char s[]=" ";
      float d;
      res=strtok(str,s);
      d=atof(res);
      output(d,fl1);
      while (res!=NULL){
            res=strtok(NULL,s);
             d=atof(res);
            output(d,fl1);

      }



}

void output(int d,char *fl1[]){
    FILE * fp;
    fp=fopen(fl1[2],"w");
    fprintf(fp,"%f",d);
    fclose(fp);



}

int main(int arg, char *fl1[])
{

    if (arg!=3){
    printf("Not name of files");
    exit(1);
    }



    FILE * fp;
    if (fopen(fl1[1],"r")==NULL){
        printf("Not a file");
        fclose(fp);
        return 0;
    }else{
    input(fl1);
    }
    fclose(fp);
    return 0;






}

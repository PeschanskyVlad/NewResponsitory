#include "str.h"

int getNumber(const char * str){
char buff[100]="";
int currBuffPos=0;
int j;
int returnInt=0;
    for(j = 0; j <strlen(str); j++){
            if (str[j]=='-'){
            if(currBuffPos!=0){
                returnInt=returnInt+atoi(buff);
                currBuffPos=0;
                buff[0]='\0';
            }
            buff[currBuffPos]=str[j];
            buff[currBuffPos+1]='\0';
            currBuffPos++;
            continue;
        }

        if (isdigit(str[j])==0){
            returnInt=returnInt+atoi(buff);
            currBuffPos=0;
            buff[0]='\0';
            continue;
        }

       if (isdigit(str[j])!=0){
            buff[currBuffPos]=str[j];
            buff[currBuffPos+1]='\0';
            currBuffPos++;

        }

        if (str[j+1]=='\0'){
            returnInt=returnInt+atoi(buff);
        }
    }
return returnInt;
}




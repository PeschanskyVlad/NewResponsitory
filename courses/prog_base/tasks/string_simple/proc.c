char * process(char * resultStr, const char * textLines[],
               int linesNum, const char * extraStr) {
    int i,j,r=0,r1=0;
char  Alf[] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";


    for (j=0;j<linesNum;j++){
        for(i=0;i<strlen(textLines[j]);i++){

         if (strchr(Alf,textLines[j][i])==0){
         r++;
         }
         if (i==strlen(textLines[j])-1&&strchr(Alf,textLines[j][i])>0){
                r++;
         }

        }
    }



     for(i=0;i<strlen(extraStr);i++){

         if (strchr(Alf,extraStr[i])==0){
         r1++;
         }
         if (i==strlen(extraStr)-1&&strchr(Alf,extraStr[i])>0){
                r1++;
         }

        }
        sprintf(resultStr, "%i %i", r, r1);
        return resultStr;

}
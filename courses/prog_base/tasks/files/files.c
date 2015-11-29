void fprocess(const char * pread, const char * pwrite){

   char text[100];

    char sep[]=",";
        FILE * fp;

          char *istr;

   int sum=0,i;

    fp = fopen(pread , "r");

for(i=0;i<8;i++){
    fgets(text, 100, fp);
}
    fclose (fp);
     istr = strtok (text,sep);
     sum=sum+atoi(istr);

        while (istr != NULL) {
                istr = strtok (NULL,sep);


                sum=sum+atoi(istr);
                }
    fp = fopen(pwrite , "w");
   fprintf(fp,"%i",sum);
    fclose (fp);
}
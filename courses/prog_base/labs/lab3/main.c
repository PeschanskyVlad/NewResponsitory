#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


float sumof(int size, float matrix[10][10]){
    int i,j;
    float sum=0;
       for(i=0;i<size;i++){
            for(j=0;j<size;j++){
               sum=sum + matrix[i][j];
            }

    }
    return sum;
}

float sumst(int size,int sums, float matrix[10][10]){
    int i;
    float s=0;
 for(i=0;i<size;i++){
     s=s+matrix[i][sums];

}
return s;
}

int welcome(){
    int i,j,s,k=0,gt;
    char str[3];
     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 2));
     COORD pos;

     for(i=5;i<20;i++){
         pos.Y=i;
          for(j=20;j<60;j++){
                  pos.X=j;
                  SetConsoleCursorPosition(hConsole, pos);
                  if (i==5||j==20){
                         SetConsoleTextAttribute(hConsole, (WORD) ((4 << 4) | 4));
                    printf(" ");
                  }else{
                      if (i==19||j==59){
                            SetConsoleTextAttribute(hConsole, (WORD) ((4 << 4) | 4));
                    printf(" ");

                      }else{
                       SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 4));
                        printf(" ");
                      }
             }



          }

     }
      pos.X=27;
      pos.Y=10;
             SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 0));
      SetConsoleCursorPosition(hConsole, pos);
      printf("Enter matrix size [2..9]");
      pos.X=38;
      pos.Y=11;
       SetConsoleCursorPosition(hConsole, pos);
        SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 0));

      while (TRUE){
             gt=getch();

 if ( gt>=50&gt<=57){
        break;
      }else{
      pos.X=32;
      pos.Y=12;
       SetConsoleCursorPosition(hConsole, pos);
        SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 0));
        printf("Invalid number");
          pos.X=38;
      pos.Y=11;
       SetConsoleCursorPosition(hConsole, pos);
        SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 0));

      }
      }
      return gt-48;
      }

void paint(int size, float matrix[10][10], int com,int help,int nul,int r,int flip,int sum,int sums,int exc,int excc,int pp1, int pp2, float newel,int chel,int dp,int dp1){
    int i,j,a,b;
    float s,st;
    float matr1[size][size];

     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
     COORD pos;

     for(i=1;i<20;i++){
         pos.Y=i;
          for(j=2;j<79;j++){
                  pos.X=j;
                  SetConsoleCursorPosition(hConsole, pos);
                  if (i==1||j==2){
                         SetConsoleTextAttribute(hConsole, (WORD) ((4 << 4) | 4));
                    printf(" ");
                  }else{
                      if (i==19||j==78){
                            SetConsoleTextAttribute(hConsole, (WORD) ((4 << 4) | 4));
                    printf(" ");

                      }else{
                       SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 4));
                        printf(" ");
                      }
             }



          }

     }
     if(r==1){
    create(size,matrix,dp,dp1);
    }
    if(exc==1){
        Mm1(size,matrix);
    }

     if(exc==2){
        Mm2(size,matrix);
    }
     if(excc==1){
        Cc(size,matrix);
    }

    if(chel==1){
     matrix[pp1][pp2]=newel+100;
    }

    if(flip==1){
        flp(size,matrix);
    }

     pos.Y=10-size/2;
    pos.X=38-size/2*5;
     for(i=0;i<size;i++){

          for(j=0;j<size;j++){

          SetConsoleCursorPosition(hConsole, pos);
          if (com==1){
           SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 15));
           }
           else{
            SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 0));
           }

        if(flip==1){

      printf("%.2f",matrix[i][j]);

           }

           else{
           if(nul==1){
           printf("0");
            matrix[i][j]=0;
           }
           else{
                if ( matrix[i][j]==0){
                     printf("%.0f",matrix[i][j]);
                }
                else{
                        if(matrix[i][j]>=100){
                            SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 15));
                            matrix[i][j]=matrix[i][j]-100;
                            printf("%.2f",matrix[i][j]);
                        }
                        else{
            printf("%.2f",matrix[i][j]);
            }
            }
           }

          }
              pos.X=pos.X+6;
          }
            pos.Y++;
            pos.X=38-size/2*5;
          }






SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 4));
    pos.Y=22;
    pos.X=3;
    SetConsoleCursorPosition(hConsole, pos);
    printf("Please, enter your command:");
    pos.Y=23;
    pos.X=4;
    SetConsoleCursorPosition(hConsole, pos);
    printf(">>");
    pos.Y=23;
    pos.X=6;
    SetConsoleCursorPosition(hConsole, pos);

    if (sum==1){
    s=sumof(size,matrix);
     pos.Y=25;
    pos.X=7;
    SetConsoleCursorPosition(hConsole, pos);
    printf("The sum of matrix elements = %.2f",s);
    }

    if (sums>=0&&sums<=size){
        s=sumst(size,sums,matrix);
            pos.Y=25;
    pos.X=7;
    SetConsoleCursorPosition(hConsole, pos);
    printf("The sum of column %i elements = %.2f",sums,s);

    }

    if (help==1){

        pos.Y=25;
    pos.X=7;
    SetConsoleCursorPosition(hConsole, pos);
    printf("random <num1> <num2> - the matrix fills ");
    pos.Y=26;
    pos.X=7;
    SetConsoleCursorPosition(hConsole, pos);
    printf("the numbers in a predetermined range [1..99]");



    pos.Y=28;
    pos.X=7;
    SetConsoleCursorPosition(hConsole, pos);
    printf("null - fills the matrix with zeros");

    pos.Y=30;
    pos.X=7;
    SetConsoleCursorPosition(hConsole, pos);
    printf("changeelement <num1> <num2> <num3> - the first two numbers");
    pos.Y=31;
    pos.X=7;
    SetConsoleCursorPosition(hConsole, pos);
    printf("is index of the element, and third is new value");




    pos.Y=33;
    pos.X=7;
    SetConsoleCursorPosition(hConsole, pos);
    printf("flipH - Flip horizontally");
    pos.Y=35;
    pos.X=7;
    SetConsoleCursorPosition(hConsole, pos);
    printf("sum - the sum of the matrix elements");
      pos.Y=37;
    pos.X=7;
    SetConsoleCursorPosition(hConsole, pos);
    printf("sumcolumn <num1> - the sum of the column elements");

    pos.Y=39;
    pos.X=7;
    SetConsoleCursorPosition(hConsole, pos);
    printf("exchange1 - change the first minimum and");
    pos.Y=40;
    pos.X=7;
    SetConsoleCursorPosition(hConsole, pos);
    printf("maximum latter matrix elements in places");


    pos.Y=42;
    pos.X=7;
    SetConsoleCursorPosition(hConsole, pos);
    printf("exchange2 - change the last minimum and");
    pos.Y=43;
    pos.X=7;
    SetConsoleCursorPosition(hConsole, pos);
    printf("maximum latter matrix elements in places");


    pos.Y=45;
    pos.X=7;
    SetConsoleCursorPosition(hConsole, pos);
    printf("exchangecolumn - Swap column with the greatest");
     pos.Y=46;
    pos.X=7;
    SetConsoleCursorPosition(hConsole, pos);
    printf("amount of items with the least amount of elements");

         pos.Y=48;
    pos.X=7;
    SetConsoleCursorPosition(hConsole, pos);
    printf("Program use function atoi(), for convert sting into number,");
            pos.Y=49;
    pos.X=7;
    SetConsoleCursorPosition(hConsole, pos);
    printf("base value - 0 (if you enter not a number),");
             pos.Y=50;
    pos.X=7;
    SetConsoleCursorPosition(hConsole, pos);
    printf("if you enter string, that starts with allowable number -");
           pos.Y=51;
    pos.X=7;
    SetConsoleCursorPosition(hConsole, pos);
    printf("the number is read, and rubbish ripped.");
    }






}


void flp(int size, float matrix[10][10]){
    int i,j;
    float matr[size][size];
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
                matr[i][j]=matrix[i][size-j-1];

        }
    }

     for(i=0;i<size;i++){
        for(j=0;j<size;j++){
                matrix[i][j]=matr[i][j];

        }
    }

}



void create(int size, float matrix[10][10],int dp,int dp1){
    int i,j;
    for(i=0;i<size;i++){
            for(j=0;j<size;j++){
                matrix[i][j]= (float)rand()/RAND_MAX*(dp1-dp)+dp;
            }

    }
}

void nul(int size, float matrix[10][10]){
    int i,j;
       for(i=0;i<size;i++){
            for(j=0;j<size;j++){
                matrix[i][j]= 0;
            }

    }
}

void Cc(int size, float matrix[10][10]){
int i,j,i1,i2;
float st;
float min=0,max=0,sum=0;
 for(i=0;i<size;i++){
    max=max+matrix[i][0];
       min=min+matrix[i][0];
 }

       for(i=0;i<size;i++){
            for(j=0;j<size;j++){
               sum=sum+matrix[j][i];
            }

            if(sum>=max){
                max=sum;
                i1=i;

            }
           if(sum<=min){
                min=sum;
                i2=i;

            }
            sum=0;

    }

     for(i=0;i<size;i++){
    matrix[i][i1]=matrix[i][i1]+100;
      matrix[i][i2]=matrix[i][i2]+100;
 }


 for(i=0;i<size;i++){

    st=matrix[i][i1];
    matrix[i][i1]=matrix[i][i2];
    matrix[i][i2]=st;
 }

}


void change(int size, float matrix[10][10]){
   float matrix1[size][size];
   int i,j;

     for(i=0;i<size;i++){
            for(j=0;j<size;j++){
                matrix1[i][j]=matrix[i][size-j-1];
            }

    }

      for(i=0;i<size;i++){
            for(j=0;j<size;j++){
                matrix[i][j]=matrix1[i][j];
            }

    }


}




void Mm1(int size, float matrix[10][10]){
    int i,j,i1,j1,i2,j2;
    float min=matrix[0][0],max=matrix[0][0],c;
      for(i=0;i<size;i++){
            for(j=0;j<size;j++){
               if(max<=matrix[i][j]){
                max=matrix[i][j];
                i1=i;
                j1=j;
               }
            }
    }

        for(i=0;i<size;i++){
            for(j=0;j<size;j++){
               if(min>matrix[i][j]){
                min=matrix[i][j];
                 i2=i;
                j2=j;
               }
            }
    }

    c=matrix[i1][j1];
    matrix[i1][j1]=matrix[i2][j2]+100;
    matrix[i2][j2]=c+100;




}


void Mm2(int size, float matrix[10][10]){

 int i,j,i1,j1,i2,j2;
    float min=matrix[0][0],max=matrix[0][0],c;
      for(i=0;i<size;i++){
            for(j=0;j<size;j++){
               if(max<=matrix[i][j]){
                max=matrix[i][j];
                i1=i;
                j1=j;
               }
            }
    }

        for(i=0;i<size;i++){
            for(j=0;j<size;j++){
               if(min>=matrix[i][j]){
                min=matrix[i][j];
                 i2=i;
                j2=j;
               }
            }
    }

    c=matrix[i1][j1];
    matrix[i1][j1]=matrix[i2][j2]+100;
    matrix[i2][j2]=c+100;
}


int main()
{
    int i,j,numst,com=0,help=0,nul =0,r=1,flip=0,sum=0,sums=-1,exc=0,excc=0,pp1=-1,pp2=-1,chel=0,dp=0,dp1=100;
    int size,check=0;
    int i1,i2;
float st,newel=-1;
      char command[30];
   char str[] = " ";
   char *err = "err";
   char *res;
    float result,s=0;
    float matrix[10][10];
    int access;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
     COORD pos;
    srand(time(NULL));
   size= welcome();
   paint(size, matrix,com,help,nul,r,flip,sum,sums,exc,excc,pp1,pp2,newel,chel,dp,dp1);





   while(TRUE){
r=0;
pos.Y=23;
pos.X=6;

for(i=1;i<=83;i++){
SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 0));
SetConsoleCursorPosition(hConsole, pos);
printf(" ");
pos.X++;
}
pos.Y=23;
pos.X=6;
SetConsoleCursorPosition(hConsole, pos);
SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 4));



   fgets(command, 30, stdin);


  for (i=24;i<52;i++){
      pos.Y=i;
    for(j=7;j<81;j++){
        pos.X=j;
SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 0));
SetConsoleCursorPosition(hConsole, pos);
printf(" ");

    }
  }
      res = strtok(command, str);
      if (res == NULL){
        res=err;
      }

      if (strcmp (res, "exit\n")==0){
            break;

      }
      if (strcmp (res, "random")==0){
            com=1;
            r=1;
        dp=(int)atoi(strtok (NULL,str));
        dp1=(int)atoi(strtok (NULL,str));


        if(dp<dp1&&dp>=0&&dp<100&&dp1>0&&dp1<100){
            paint(size, matrix,com,help,nul,r,flip,sum,sums,exc,excc,pp1,pp2,newel,chel,dp,dp1);
            check=1;
        }
        else{check=0;}

      }

        if (strcmp (res, "help\n")==0){
                help=1;
     paint(size, matrix,com,help,nul,r,flip,sum,sums,exc,excc,pp1,pp2,newel,chel,dp,dp1);

            check=1;

      }

      if (strcmp (res, "null\n")==0){
                nul=1;
                com=1;

          paint(size, matrix,com,help,nul,r,flip,sum,sums,exc,excc,pp1,pp2,newel,chel,dp,dp1);

            check=1;

      }

      if(strcmp(res, "changeelement")==0){
            chel=1;
        pp1=(int)atoi(strtok (NULL,str));
        pp2=(int)atoi(strtok (NULL,str));
        newel=(float)atof(strtok (NULL,command));
        if (pp1>=0&&pp1<size){
                if(pp2>=0&&pp2<size){
                        if(newel>=0&&newel<100){
         paint(size, matrix,com,help,nul,r,flip,sum,sums,exc,excc,pp1,pp2,newel,chel,dp,dp1);
         check=1;
                        }else{ check=0;}
                }else{ check=0;}
         }
         else { check=0;}

      }


      if (strcmp (res, "flipH\n")==0){
                com=1;
                flip=1;
             paint(size, matrix,com,help,nul,r,flip,sum,sums,exc,excc,pp1,pp2,newel,chel,dp,dp1);

            check=1;

      }

          if (strcmp (res, "sum\n")==0){
                sum=1;
           paint(size, matrix,com,help,nul,r,flip,sum,sums,exc,excc,pp1,pp2,newel,chel,dp,dp1);

            check=1;

      }

      if (strcmp (res, "sumcolumn")==0){
                sums=atoi(strtok (NULL,command));
                if(sums>=0&&sums<size){
          paint(size, matrix,com,help,nul,r,flip,sum,sums,exc,excc,pp1,pp2,newel,chel,dp,dp1);
               check=1;
                }else
                {
                    check=0;
                }



      }

        if (strcmp (res, "exchange1\n")==0){
                exc=1;
          paint(size, matrix,com,help,nul,r,flip,sum,sums,exc,excc,pp1,pp2,newel,chel,dp,dp1);

            check=1;

      }
        if (strcmp (res, "exchange2\n")==0){
               exc=2;
            paint(size, matrix,com,help,nul,r,flip,sum,sums,exc,excc,pp1,pp2,newel,chel,dp,dp1);

            check=1;

      }

      if (strcmp (res, "exchangecolumn\n")==0){
               excc=1;



             paint(size, matrix,com,help,nul,r,flip,sum,sums,exc,excc,pp1,pp2,newel,chel,dp,dp1);




            check=1;
      }








      if (check==0){
    pos.Y=25;
    pos.X=7;
    SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 4));
    SetConsoleCursorPosition(hConsole, pos);
    printf("Invalid command, try again");

      }



help=0;
check=0;
com=0;
nul=0;
flip=0;
sum=0;
sums=-1;
exc=0;
excc=0;
chel=0;
pp1=-1;
pp2=-1;
newel=-1;


   }



 exit (EXIT_SUCCESS);


}








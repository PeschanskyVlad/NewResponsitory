#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

  void paint(int Centrex, int Centrey, int step){
        float y1,y2,x;
        int i,j,ser;


             HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;

    for(i=0;i<80;i++){
            pos.Y=i;
      for(j=0;j<80;j++)  {
          pos.X=j;

       SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 0));
     SetConsoleCursorPosition(hConsole, pos);
     printf(" ");

      }
    }
    pos.Y=2;
    pos.X=2;
    SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));
     SetConsoleCursorPosition(hConsole, pos);
    printf("F(x) = (x + 3)^3");

     pos.Y=3;
    pos.X=2;
     SetConsoleCursorPosition(hConsole, pos);
      printf("w - move up");
          pos.Y=4;
    pos.X=2;
     SetConsoleCursorPosition(hConsole, pos);
      printf("s - move down");
          pos.Y=5;
    pos.X=2;
     SetConsoleCursorPosition(hConsole, pos);
      printf("a - move left");

          pos.Y=6;
    pos.X=2;
     SetConsoleCursorPosition(hConsole, pos);
      printf("d - move right");

      pos.Y=7;
    pos.X=2;
     SetConsoleCursorPosition(hConsole, pos);
      printf("+ - increase");
      pos.Y=8;
    pos.X=2;
     SetConsoleCursorPosition(hConsole, pos);
      printf("- - reduce");
      pos.Y=9;
    pos.X=2;
     SetConsoleCursorPosition(hConsole, pos);
      printf("c - change");




pos.Y=Centrey;
    pos.X=0;
     for(i=0;i<80;i++){
     SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 4));
     SetConsoleCursorPosition(hConsole, pos);
     if(abs(Centrex-pos.X)%step==0){
            printf("*");

     }else{
     printf("-");
     }
     pos.X++;
     }

     pos.Y=0;
     pos.X=Centrex;
     for(i=0;i<80;i++){
     SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 4));
     SetConsoleCursorPosition(hConsole, pos);
      if(abs(Centrey-pos.Y)%step==0){
            printf("*");

     }else{
     printf("|");
     }
     pos.Y++;
     }


     for(i=0;i<80;i++){

 pos.X=i;
         y1=Centrey-pow((float)(i+3-Centrex),3)/(10/(float)step);
         if (y1<80&&y1>0){

        pos.Y=y1;
       SetConsoleCursorPosition(hConsole, pos);
           SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 0));

            printf(" ");


              if ((int)abs(y2 -y1)>1){
            for( j =1; j<(int)y2-y1;j++){
                pos.Y=y2-j;

                ser=(int)(y2-y1)/2;
            if(j<ser){
                pos.X=i-1;
            }
            else{
                pos.X=i;
            }
            SetConsoleCursorPosition(hConsole, pos);
                 SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 0));
                 printf(" ");

            }
         }

             y2=y1;


           }

     }

    }





  void paint1(int Centrex, int Centrey, int step){
        float y1,y2,x;
        int i,j,ser;


             HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;

    for(i=0;i<80;i++){
            pos.Y=i;
      for(j=0;j<80;j++)  {
          pos.X=j;

       SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 0));
     SetConsoleCursorPosition(hConsole, pos);
     printf(" ");

      }
    }
    pos.Y=2;
    pos.X=2;
    SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));
     SetConsoleCursorPosition(hConsole, pos);
    printf("F(x) = (((x + 3)^3 + 13)%25+1)");

         pos.Y=3;
    pos.X=2;
     SetConsoleCursorPosition(hConsole, pos);
      printf("w - move up");
          pos.Y=4;
    pos.X=2;
     SetConsoleCursorPosition(hConsole, pos);
      printf("s - move down");
          pos.Y=5;
    pos.X=2;
     SetConsoleCursorPosition(hConsole, pos);
      printf("a - move left");

          pos.Y=6;
    pos.X=2;
     SetConsoleCursorPosition(hConsole, pos);
      printf("d - move right");

      pos.Y=7;
    pos.X=2;
     SetConsoleCursorPosition(hConsole, pos);
      printf("+ - increase");
      pos.Y=8;
    pos.X=2;
     SetConsoleCursorPosition(hConsole, pos);
      printf("- - reduce");
      pos.Y=9;
    pos.X=2;
     SetConsoleCursorPosition(hConsole, pos);
      printf("c - change");


pos.Y=Centrey;
    pos.X=0;
     for(i=0;i<80;i++){
     SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 4));
     SetConsoleCursorPosition(hConsole, pos);
     if(abs(Centrex-pos.X)%step==0){
            printf("*");

     }else{
     printf("-");
     }
     pos.X++;
     }

     pos.Y=0;
     pos.X=Centrex;
     for(i=0;i<80;i++){
     SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 4));
     SetConsoleCursorPosition(hConsole, pos);
      if(abs(Centrey-pos.Y)%step==0){
            printf("*");

     }else{
     printf("|");
     }
     pos.Y++;
     }


     for(i=0;i<80;i++){

 pos.X=i;
         y1= Centrey-((int)(pow((i+3-Centrex),3)+13)%25+1)/(10/(float)step);
         if (y1<80&&y1>0){

        pos.Y=y1;
       SetConsoleCursorPosition(hConsole, pos);
           SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 0));

            printf(" ");


              if ((int)abs(y2 -y1)>1){
            for( j =1; j<(int)y2-y1;j++){
                pos.Y=y2-j;

                ser=(int)(y2-y1)/2;
            if(j<ser){
                pos.X=i-1;
            }
            else{
                pos.X=i;
            }
            SetConsoleCursorPosition(hConsole, pos);
                 SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 0));
                 printf(" ");

            }
         }

             y2=y1;


           }

     }

    }




int main()
{


  int  Centrex=40;
   int Centrey=40;


int i,j,step=10,ser,gt,pa1=0;
float y1,y2,x;


paint(Centrex, Centrey, step);
while(TRUE){
    gt=getch();


    switch(gt){
    case 119:
        Centrey--;
          if (pa1==0){
                paint(Centrex, Centrey, step);

        }

        else{
           paint1(Centrex, Centrey, step);

        }
        break;
    case 97:
        Centrex--;
          if (pa1==0){
                paint(Centrex, Centrey, step);

        }

        else{
           paint1(Centrex, Centrey, step);

        }
        break;
    case 115:
        Centrey++;
          if (pa1==0){
                paint(Centrex, Centrey, step);

        }

        else{
           paint1(Centrex, Centrey, step);

        }
         break;
    case 100:
        Centrex++;
           if (pa1==0){
                paint(Centrex, Centrey, step);

        }

        else{
           paint1(Centrex, Centrey, step);

        }
         break;
    case 99:
        if (pa1==0){
                paint1(Centrex, Centrey, step);
                pa1=1;
        }

        else{
           paint(Centrex, Centrey, step);
                pa1=0;
        }

         break;
          case 43:
              if (step<=20){
              step++;
                 if (pa1==0){
                paint(Centrex, Centrey, step);

        }

        else{
           paint1(Centrex, Centrey, step);

        }
              }

         break;
          case 45:
             if (step>=5){
              step--;
                if (pa1==0){
                paint(Centrex, Centrey, step);

        }

        else{
           paint1(Centrex, Centrey, step);

        }
              }

         break;
    }



    gt=0;

}

}






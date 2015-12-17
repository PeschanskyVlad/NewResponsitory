#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>


/*
    w - 119
    s - 115
    a - 97
    d - 100
    Enter - 13
    */

struct snake{
int x[1000];
int y[1000];
int length;
};

struct food{
int x;
int y;
int status;
};

struct record{
char name[20];
int n_record;
};

int main_menu(){

     int i,j,result=1,gt;

     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 2));
     COORD pos;

     while(TRUE){

     for(i=3;i<8;i++){
         pos.Y=i;
          for(j=25;j<55;j++){
                  pos.X=j;
                  SetConsoleCursorPosition(hConsole, pos);

                         if(i==3||i==7||j==25||j==54){
                     if(result==1){
                              SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 4));
                                }else{
                    SetConsoleTextAttribute(hConsole, (WORD) ((4 << 4) | 4));}
                  }
                  else{
                       SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 4));
                  }
                        printf(" ");

             }



          }
          pos.X=38;
          pos.Y=5;
           SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 0));
      SetConsoleCursorPosition(hConsole, pos);
      printf("Start");


          for(i=10;i<15;i++){
         pos.Y=i;
          for(j=25;j<55;j++){
                  pos.X=j;
                  SetConsoleCursorPosition(hConsole, pos);
                       if(i==10||i==14||j==25||j==54){
                      if(result==2){
                              SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 4));
                                }else{
                    SetConsoleTextAttribute(hConsole, (WORD) ((4 << 4) | 4));}
                  }
                  else{
                       SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 4));
                  }
                        printf(" ");

             }



          }
          pos.X=36;
          pos.Y=12;
           SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 0));
      SetConsoleCursorPosition(hConsole, pos);
      printf("Settings");

          for(i=17;i<22;i++){
         pos.Y=i;
          for(j=25;j<55;j++){
                  pos.X=j;
                  SetConsoleCursorPosition(hConsole, pos);

                         if(i==17||i==21||j==25||j==54){

                                if(result==3){
                              SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 4));
                                }else{
                    SetConsoleTextAttribute(hConsole, (WORD) ((4 << 4) | 4));}
                  }
                  else{
                       SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 4));
                  }
                        printf(" ");

             }



          }
          pos.X=38;
          pos.Y=19;
             SetConsoleCursorPosition(hConsole, pos);
           SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 0));
      printf("Exit");

     gt=getch();
     if (gt==119){
        if(result>1){
result--;
}
     }
      if (gt==115){
    if(result<3){
result++;
}
     }
      if (gt==13){
        return result;

     }


     }
     }



void new_snake(struct snake *s){
int i;
s->length=10;
for(i=0;i<1000;i++){
    if(i<10){
        s->x[i]=37+i;
         s->y[i]=12;


    }
    else{
        s->x[i]=0;
         s->y[i]=0;


    }
}

}

void add_food(struct food *f){
      HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD pos;
    srand(time(NULL));
    if(f->status==0){
          pos.X=f->x;
       pos.Y=f->y;
       SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 0));
        SetConsoleCursorPosition(hConsole, pos);
       printf(" ");


       f->x=rand()%78+1;
       f->y=rand()%24+1;
       f->status=1;

    }

       pos.X=f->x;
       pos.Y=f->y;
       SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 15));
        SetConsoleCursorPosition(hConsole, pos);
       printf(" ");





}




int game(struct snake *s,struct food *f,int difficulty_level, struct record r[]){

   int gt=97,gt1=97,i,j,score=0;
     int x,y,x1,y1;


      HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD pos;
      new_snake(s);
       SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 0));
       get_name(r);
       SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 0));
      system("cls");



while (TRUE){
    SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 0));

          add_food(f);

            pos.Y=0;
        for(i=0;i<80;i++){
            pos.X=i;
        SetConsoleTextAttribute(hConsole, (WORD) ((4 << 4) | 15));
        SetConsoleCursorPosition(hConsole, pos);
       printf(" ");
        }

            pos.X=0;
        for(i=0;i<25;i++){
            pos.Y=i;
        SetConsoleTextAttribute(hConsole, (WORD) ((4 << 4) | 15));
        SetConsoleCursorPosition(hConsole, pos);
       printf(" ");
        }
           pos.X=79;
        for(i=0;i<25;i++){
            pos.Y=i;
        SetConsoleTextAttribute(hConsole, (WORD) ((4 << 4) | 15));
        SetConsoleCursorPosition(hConsole, pos);
       printf(" ");
        }



          pos.Y=25;
        for(i=0;i<80;i++){
            pos.X=i;
        SetConsoleTextAttribute(hConsole, (WORD) ((4 << 4) | 15));
        SetConsoleCursorPosition(hConsole, pos);
       printf(" ");
        }

        pos.X=30;
        pos.Y=25;
        SetConsoleCursorPosition(hConsole, pos);
        SetConsoleTextAttribute(hConsole, (WORD) ((4 << 4) | 0));
        printf("Length: %i", s->length);

        pos.X=50;
        pos.Y=25;
        SetConsoleCursorPosition(hConsole, pos);
        SetConsoleTextAttribute(hConsole, (WORD) ((4 << 4) | 0));
        printf("Score: %i", score);




 for(i=0;i<s->length;i++){
        pos.X=s->x[i];
        pos.Y=s->y[i];
        SetConsoleCursorPosition(hConsole, pos);
        SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 15));
        printf(" ");

        pos.X=x;
        pos.Y=y;
         SetConsoleCursorPosition(hConsole, pos);
        SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 0));
        printf(" ");

 }

    Sleep(100/difficulty_level);

 if(kbhit()){
      gt=getch();
    }
    if(gt!=115&&gt!=119&&gt!=97&&gt!=100){
        gt=gt1;
    }




    if(gt==115&&gt1==119){
        gt=119;
    }
     if(gt==119&&gt1==115){
        gt=115;
    }
     if(gt==100&&gt1==97){
        gt=97;
    }
     if(gt==97&&gt1==100){
        gt=100;
    }
    x=s->x[0];
    y=s->y[0];

    switch(gt){
case 97:
    s->x[0]--;
        break;
case 100:
    s->x[0]++;
       break;
case 115:
s->y[0]++;
       break;
case 119:
    s->y[0]--;
       break;
    }

    if(s->x[0]==f->x&&s->y[0]==f->y){
        score++;
    }
    for(i=1;i<s->length;i++){
        if(s->x[0]==s->x[i]&&s->y[0]==s->y[i]){
                SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 0));
        system("cls");
        pos.X=37;
        pos.Y=12;
        SetConsoleCursorPosition(hConsole, pos);
        SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));
        printf("Total score: %i",score);
            add_record(r,score);
            Sleep(1000);
            return score;
        }
    }

    if(s->x[0]==0||s->x[0]==79||s->y[0]==0||s->y[0]==25){
             SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 0));
        system("cls");
        pos.X=37;
        pos.Y=12;
        SetConsoleCursorPosition(hConsole, pos);
        SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));
        printf("Total score: %i",score);
            add_record(r,score);
            Sleep(1000);
          return score;
    }

if(score>=100&&difficulty_level<9){
    system("cls");
    new_snake(s);
    pos.X=36;
    pos.Y=12;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));
    printf("Level increased");
    Sleep(400);

}


        for (i=1;i<s->length;i++){
        x1=s->x[i];
        y1=s->y[i];

        s->x[i]=x;
        s->y[i]=y;

      x=x1;
      y=y1;

      if(s->x[s->length-1]==f->x&&s->y[s->length-1]==f->y){
        s->length++;
        s->x[s->length-1]==f->x;
        s->y[s->length-1]==f->y;
        f->status=0;
    }

    }

gt1=gt;
}
}

void add_record(struct record r[], int score){
int i,i1;
int a,b;
char str[20],str1[20];
    struct record *rd;

    for(i=0;i<5;i++){

        if(r[i].n_record<=score){
                strcpy(str,r[i].name);
                a=r[i].n_record;
                strcpy(r[i].name,r[6].name);
                r[i].n_record=score;
            break;
        }
    }
    i1=i+1;


    for(i=i1;i<5;i++){
              strcpy(str1,r[i].name);
              b=r[i].n_record;
              strcpy(r[i].name,str);
              r[i].n_record=a;
              a=b;
              strcpy(str,str1);





    }

}

int settings(int difficulty_level,struct record r[]){
          int i,j,result=1,gt,temp=0,temp1,del=0;

           HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(hConsole, (WORD) ((0 << 0) | 0));
     COORD pos;
          system("cls");



     while(TRUE){

               HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(hConsole, (WORD) ((0 << 0) | 0));
     COORD pos;
          system("cls");


            for(i=2;i<7;i++){
         pos.Y=i;
          for(j=25;j<55;j++){
                  pos.X=j;
                  SetConsoleCursorPosition(hConsole, pos);

                         if(i==2||i==6||j==25||j==54){
                     if(result==1){
                              SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 4));
                                }else{
                    SetConsoleTextAttribute(hConsole, (WORD) ((4 << 4) | 4));}
                  }
                  else{
                       SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 4));
                  }
                        printf(" ");

             }



          }
              pos.X=29;
          pos.Y=4;
           SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 0));
      SetConsoleCursorPosition(hConsole, pos);
      printf("Change difficulty level");


       for(i=10;i<15;i++){
         pos.Y=i;
         for(j=25;j<55;j++){
                  pos.X=j;
                  SetConsoleCursorPosition(hConsole, pos);

                         if(i==10||i==14||j==25||j==54){
                     if(result==2){
                              SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 4));
                                }else{
                    SetConsoleTextAttribute(hConsole, (WORD) ((4 << 4) | 4));}
                  }
                  else{
                       SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 4));
                  }
                        printf(" ");

             }



          }
              pos.X=31;
          pos.Y=12;
           SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 0));
      SetConsoleCursorPosition(hConsole, pos);
      printf("Watch record list");

             for(i=18;i<23;i++){
         pos.Y=i;
         for(j=25;j<55;j++){
                  pos.X=j;
                  SetConsoleCursorPosition(hConsole, pos);

                         if(i==18||i==22||j==25||j==54){
                     if(result==3){
                              SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 4));
                                }else{
                    SetConsoleTextAttribute(hConsole, (WORD) ((4 << 4) | 4));}
                  }
                  else{
                       SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 4));
                  }
                        printf(" ");

             }



          }
              pos.X=33;
          pos.Y=20;
           SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 0));
      SetConsoleCursorPosition(hConsole, pos);
      printf("To main menu");

          gt=getch();
     if (gt==119){
        if(result>1){
result--;
}
     }
      if (gt==115){
    if(result<3){
result++;
}
     }
      if (gt==13){


        switch(result){
    case 1:temp = change_level(difficulty_level);
    break;
    case 2: show_records(r);
    break;
    case 3: return temp;
    break;
        }

     }
     del=0;
     }
     }

     int change_level(int difficulty_level){
         int i,j,gt,temp=0;
         HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
         COORD pos;
         SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 0));
         system("cls");
     while(TRUE){

                 for(i=6;i<20;i++){
         pos.Y=i;
         for(j=20;j<60;j++){
                  pos.X=j;
                  SetConsoleCursorPosition(hConsole, pos);

                         if(i==6||i==19||j==20||j==59){



                    SetConsoleTextAttribute(hConsole, (WORD) ((4 << 4) | 4));
                  }
                  else{
                       SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 4));
                  }
                        printf(" ");

             }



          }

          pos.X=25;
          pos.Y=10;
            SetConsoleCursorPosition(hConsole, pos);
               SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 0));
        printf("Enter difficulty level [1..9]");
        pos.X=25;
          pos.Y=12;
            SetConsoleCursorPosition(hConsole, pos);
               SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 0));
        printf("Current level of difficulty: %i",difficulty_level);
        pos.X=28;
          pos.Y=14;
            SetConsoleCursorPosition(hConsole, pos);
               SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 0));
        printf("Press Enter to confirm");
        gt=getch();
        switch(gt){
    case 13:
        return temp;
        break;
           case 49:
               difficulty_level=1;

        break;
           case 50:
                difficulty_level=2;
        break;
           case 51:
                difficulty_level=3;
        break;
           case 52:
                difficulty_level=4;
        break;
           case 53:
                difficulty_level=5;
        break;
           case 54:
                difficulty_level=6;
        break;
           case 55:
                difficulty_level=7;
        break;
           case 56:
                difficulty_level=8;
        break;
           case 57:
                difficulty_level=9;
        break;
        }



     }
     }


     void show_records(struct record r[]){
          int i,j,gt,temp=0;
         HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
         COORD pos;
         SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 0));
         system("cls");

              for(i=4;i<23;i++){
         pos.Y=i;
         for(j=20;j<60;j++){
                  pos.X=j;
                  SetConsoleCursorPosition(hConsole, pos);

                         if(i==4||i==22||j==20||j==59){



                    SetConsoleTextAttribute(hConsole, (WORD) ((4 << 4) | 4));
                  }
                  else{
                       SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 4));
                  }
                        printf(" ");

             }
              }


             pos.X=34;
             pos.Y = 6;
              SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 0));
               SetConsoleCursorPosition(hConsole, pos);
               printf("Press Enter to exit.");

             pos.Y = 7;
             for (i=0;i<5;i++){
                    pos.Y++;
                    SetConsoleCursorPosition(hConsole, pos);
                    printf(r[i].name);
                    pos.Y++;
                    SetConsoleCursorPosition(hConsole, pos);
                    printf("Score: %i",r[i].n_record);
                    pos.Y++;



             }




          while(TRUE){
           gt=getch();
           if(gt==13){
            break;
           }
           }




     }



     void get_name(struct record r[]){

         int i,j,gt,temp=0;
         HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
         COORD pos;
         char str[20];
         SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 0));
         system("cls");

        for(i=6;i<20;i++){
         pos.Y=i;
         for(j=20;j<60;j++){
                  pos.X=j;
                  SetConsoleCursorPosition(hConsole, pos);

                         if(i==6||i==19||j==20||j==59){



                    SetConsoleTextAttribute(hConsole, (WORD) ((4 << 4) | 4));
                  }
                  else{
                       SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 4));
                  }
                        printf(" ");

             }



          }

           pos.X=28;
          pos.Y=10;
            SetConsoleCursorPosition(hConsole, pos);
               SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 0));
        printf("Enter player name:");
             pos.X=28;
          pos.Y=12;
            SetConsoleCursorPosition(hConsole, pos);

     fgets(r[6].name,19,stdin);



     }
void input(struct record r[]){
    int i;
    FILE * fp;
    fp = fopen("records.txt" , "r");
    char str[20];
    if(fp==NULL){

    }else{
    for(i=0;i<5;i++){
        fgets(r[i].name,20,fp);
         fgets(str,20,fp);
         r[i].n_record=atoi(str);
    }
    fclose(fp);
    }

}

void output(struct record r[]){
      int i;
    FILE * fp;
    fp = fopen("records.txt" , "w");
    char str[20];
    for(i=0;i<5;i++){
        fprintf(fp,r[i].name);
      fprintf(fp,"%i\n",r[i].n_record);
    }
    fclose(fp);
}



int main()
{

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD pos;
    struct snake sn={0,0,0};
         struct food food={0,0,0};
         struct record r[7]={{"-",0},{"-",0},{"-",0},{"-",0},{"-",0}};
        system("mode con:cols=80 lines=27");
 struct snake *s;
 s=&sn;
  struct food *f;
 f=&food;
 int difficulty_level=3,temp=0;
 input(r);



    int punct;

    while(TRUE){
            SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 0));
    system("cls");
     punct = main_menu();
      switch(punct){
  case 1:temp = game(s,f,difficulty_level,r);
  output(r);
      break;
  case 2:temp= settings(difficulty_level,r);
  break;
  case 3:
exit (EXIT_SUCCESS);
  break;
        }


    }
}

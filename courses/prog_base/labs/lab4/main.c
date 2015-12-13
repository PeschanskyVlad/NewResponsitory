#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

struct robots{
char name[10];
int hp;
int dps;
int accuracy;
int evasion;
int slot[4];
int status;
};

struct modul{
int m_hp;
int m_dps;
int m_accuracy;
int m_evasion

};


void welcome(){
    int i,j,s,k=0,gt;
    char str[3];
     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 2));
     COORD pos;

     for(i=5;i<20;i++){
         pos.Y=i;
          for(j=15;j<65;j++){
                  pos.X=j;
                  SetConsoleCursorPosition(hConsole, pos);
                  if (i==5||j==15){
                         SetConsoleTextAttribute(hConsole, (WORD) ((4 << 4) | 4));
                    printf(" ");
                  }else{
                      if (i==19||j==64){
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
      printf("Welcome on the robots arena ");
        pos.X=24;
      pos.Y=12;
             SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 0));
      SetConsoleCursorPosition(hConsole, pos);
      printf("Use w,s,a,d to select menu items,");
        pos.X=24;
      pos.Y=13;
             SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 0));
      SetConsoleCursorPosition(hConsole, pos);
      printf("and Enter to confirm your choice.");


            pos.X=29;
      pos.Y=15;
             SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 0));
      SetConsoleCursorPosition(hConsole, pos);
      printf("Press Enter to continue ");
pos.X=29;
      pos.Y=16;
         SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 4));
      SetConsoleCursorPosition(hConsole, pos);
       printf(" ");

      while (TRUE){
            gt=getch();

 if (gt==13){
        break;
         SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 0));
      }
      }
}

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
          pos.X=37;
          pos.Y=5;
           SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 0));
      SetConsoleCursorPosition(hConsole, pos);
      printf("Fight!");


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
          pos.X=32;
          pos.Y=12;
           SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 0));
      SetConsoleCursorPosition(hConsole, pos);
      printf("Customize robots");

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
          pos.X=30;
          pos.Y=19;
             SetConsoleCursorPosition(hConsole, pos);
           SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 0));
      printf("Exit and Save robots");

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




int customize_main(struct robots robots_list[],struct modul modul_list[]){
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
          for(j=4;j<20;j++){
                  pos.X=j;
                  SetConsoleCursorPosition(hConsole, pos);

                         if(i==2||i==6||j==4||j==19){
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
              pos.X=6;
          pos.Y=4;
           SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 0));
      SetConsoleCursorPosition(hConsole, pos);
      printf("Change robot");


       for(i=10;i<15;i++){
         pos.Y=i;
         for(j=4;j<20;j++){
                  pos.X=j;
                  SetConsoleCursorPosition(hConsole, pos);

                         if(i==10||i==14||j==4||j==19){
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
              pos.X=6;
          pos.Y=12;
           SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 0));
      SetConsoleCursorPosition(hConsole, pos);
      printf("Delete robot");

             for(i=18;i<23;i++){
         pos.Y=i;
          for(j=4;j<20;j++){
                  pos.X=j;
                  SetConsoleCursorPosition(hConsole, pos);

                         if(i==18||i==22||j==4||j==19){
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
              pos.X=6;
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
    case 1:temp1=customize_robot(robots_list,modul_list,del);
    break;
    case 2:del=1;
    temp1=customize_robot(robots_list,modul_list,del);
    break;
    case 3: return temp;
    break;
        }

     }
     del=0;
     }
     }


     int customize_robot(struct robots rb[],struct modul md[],int del){
     int i,j,result=1,gt,temp=0;
         HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(hConsole, (WORD) ((0 << 0) | 0));
     COORD pos;

     while(TRUE){



          for(i=2;i<7;i++){
         pos.Y=i;
         for(j=25;j<35;j++){
                  pos.X=j;
                  SetConsoleCursorPosition(hConsole, pos);

                         if(i==2||i==6||j==25||j==34){
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
               SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 0));
          if (rb[0].status==0){
              pos.X=29;
          pos.Y=4;
      SetConsoleCursorPosition(hConsole, pos);
      printf("+");
      }
       else{
             pos.X=27;
          pos.Y=4;
      SetConsoleCursorPosition(hConsole, pos);
      printf(rb[0].name);
      }


         for(i=2;i<7;i++){
         pos.Y=i;
         for(j=38;j<48;j++){
                  pos.X=j;
                  SetConsoleCursorPosition(hConsole, pos);

                         if(i==2||i==6||j==38||j==47){
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
               SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 0));
          if (rb[1].status==0){
              pos.X=42;
          pos.Y=4;
      SetConsoleCursorPosition(hConsole, pos);
      printf("+");
      }
       else{
             pos.X=40;
          pos.Y=4;
      SetConsoleCursorPosition(hConsole, pos);
      printf(rb[1].name);
      }


        for(i=2;i<7;i++){
         pos.Y=i;
         for(j=51;j<61;j++){
                  pos.X=j;
                  SetConsoleCursorPosition(hConsole, pos);

                         if(i==2||i==6||j==51||j==60){
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
               SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 0));
          if (rb[2].status==0){
              pos.X=55;
          pos.Y=4;
      SetConsoleCursorPosition(hConsole, pos);
      printf("+");
      }
      else{
             pos.X=53;
          pos.Y=4;
      SetConsoleCursorPosition(hConsole, pos);
      printf(rb[2].name);
      }


          for(i=2;i<7;i++){
         pos.Y=i;
         for(j=64;j<74;j++){
                  pos.X=j;
                  SetConsoleCursorPosition(hConsole, pos);

                         if(i==2||i==6||j==64||j==73){
                     if(result==4){
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
               SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 0));

              pos.X=67;
          pos.Y=4;
      SetConsoleCursorPosition(hConsole, pos);
      printf("Back");


      SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));
       pos.X=25;
        pos.Y=23;
        SetConsoleCursorPosition(hConsole, pos);
          printf("Select one of the three available cells.               ");
        pos.X=25;
        pos.Y=24;
        SetConsoleCursorPosition(hConsole, pos);
          printf("                                                       ");





           gt=getch();
     if (gt==97){
        if(result>1){
result--;
}
     }
      if (gt==100){
    if(result<4){
result++;
}
     }
      if (gt==13){
         if(del==1){
                if (result==4){
                   return temp;
                }
            rb[result-1].hp=100;
            rb[result-1].dps=40;
            rb[result-1].accuracy=60;
            rb[result-1].evasion=10;
            rb[result-1].status=0;
            rb[result-1].slot[0]=-1;
            rb[result-1].slot[1]=-1;
            rb[result-1].slot[2]=-1;
            rb[result-1].slot[3]=-1;

         }else{

        switch(result){
    case 1: temp = tuning(result, rb,md);
    break;
    case 2:temp = tuning(result, rb,md);
    break;
    case 3: temp = tuning(result, rb,md);
    break;
    case 4:return temp;
        }

         }
     }
     }
     }


     int tuning(int result, struct robots rb[],struct modul mb[]){
     int i,j,r=1,gt,temp=0;
     result--;


     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD pos;

      while(TRUE){
    SetConsoleTextAttribute(hConsole, (WORD) ((15 << 0) | 0));


      pos.X=25;
     pos.Y=10;
        SetConsoleCursorPosition(hConsole, pos);
     printf("Robot name:        ");
     pos.X=25;
     pos.Y=10;
        SetConsoleCursorPosition(hConsole, pos);
     printf("Robot name: ");
     printf(rb[result].name);

     pos.X=25;
     pos.Y=11;
        SetConsoleCursorPosition(hConsole, pos);
     printf("Robot HP =         ");

     pos.X=25;
     pos.Y=11;
        SetConsoleCursorPosition(hConsole, pos);
     printf("Robot HP = %i", rb[result].hp);

       pos.X=25;
     pos.Y=12;
        SetConsoleCursorPosition(hConsole, pos);
     printf("Robot damage =         ");

       pos.X=25;
     pos.Y=12;
        SetConsoleCursorPosition(hConsole, pos);
     printf("Robot damage = %i", rb[result].dps);
            pos.X=25;
     pos.Y=13;
        SetConsoleCursorPosition(hConsole, pos);
     printf("Robot accuracy =       ");

          pos.X=25;
     pos.Y=13;
        SetConsoleCursorPosition(hConsole, pos);
     printf("Robot accuracy = %i", rb[result].accuracy);

     pos.X=25;
     pos.Y=14;
        SetConsoleCursorPosition(hConsole, pos);
     printf("Robot evasion =        ");

          pos.X=25;
     pos.Y=14;
        SetConsoleCursorPosition(hConsole, pos);
     printf("Robot evasion = %i", rb[result].evasion);

SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));

       pos.X=25;
     pos.Y=16;
     SetConsoleCursorPosition(hConsole, pos);
     printf("Available slots:");


     pos.X=25;
     pos.Y=18;
     SetConsoleCursorPosition(hConsole, pos);
      if(r==1){
                              SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 0));
                                }else{
                    SetConsoleTextAttribute(hConsole, (WORD) ((4 << 4) | 0));}


     if(rb[result].slot[0]>=0&&rb[result].slot[0]<5){
         printf("%i",rb[result].slot[0]);

     }else{
       printf(" ");

     }


      pos.X=27;
     pos.Y=18;
     SetConsoleCursorPosition(hConsole, pos);
      if(r==2){
                              SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 0));
                                }else{
                    SetConsoleTextAttribute(hConsole, (WORD) ((4 << 4) | 0));
                  }

     if(rb[result].slot[1]>=0&&rb[result].slot[1]<5){
       printf("%i",rb[result].slot[1]);

     }else{
       printf(" ");

     }

      pos.X=29;
     pos.Y=18;
     SetConsoleCursorPosition(hConsole, pos);
      if(r==3){
                              SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 0));
                                }else{
                    SetConsoleTextAttribute(hConsole, (WORD) ((4 << 4) | 0));
                  }
     if(rb[result].slot[2]>=0&&rb[result].slot[2]<5){
       printf("%i",rb[result].slot[2]);

     }else{
       printf(" ");

     }

      pos.X=31;
     pos.Y=18;
     SetConsoleCursorPosition(hConsole, pos);
      if(r==4){
                              SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 0));
                                }else{
                    SetConsoleTextAttribute(hConsole, (WORD) ((4 << 4) | 0));
                  }
     if(rb[result].slot[3]>=0&&rb[result].slot[3]<5){
         printf("%i",rb[result].slot[3]);

     }else{
       printf(" ");

     }

         pos.X=33;
     pos.Y=18;
     SetConsoleCursorPosition(hConsole, pos);
      if(r==5){
                              SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 0));
                                }else{
                    SetConsoleTextAttribute(hConsole, (WORD) ((4 << 4) | 0));
                  }
                   printf("confirm");


                   SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));
        pos.X=25;
        pos.Y=23;
            SetConsoleCursorPosition(hConsole, pos);
          printf("Select slot, and press enter to add/change module.     ");
            pos.X=25;
        pos.Y=24;
            SetConsoleCursorPosition(hConsole, pos);
          printf("Select 'confirm', if you finished setting.             ");






                gt=getch();
     if (gt==97){
        if(r>1){
r--;
}
     }
      if (gt==100){
    if(r<5){
r++;
}
     }
      if (gt==13){
        switch(r){
    case 1:{rb[result].slot[0]=change(mb,rb,result);
    break;}
    case 2:{rb[result].slot[1]=change(mb,rb,result);
    break;}
    case 3:{rb[result].slot[2]=change(mb,rb,result);
    break;}
    case 4:{rb[result].slot[3]=change(mb,rb,result);
    break;}
    case 5:{rb[result].status=1;
        return temp;}
        }



      }


     }
}

int change( struct modul md[],struct robots rb[],int result){
    int i,j,r=0,gt;
     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(hConsole, (WORD) ((0 << 0) | 0));
     COORD pos;
    while(TRUE){

         for(i=11;i<21;i++){
         pos.Y=i;
         for(j=51;j<74;j++){
                  pos.X=j;
                  SetConsoleCursorPosition(hConsole, pos);

                         if(i==11||i==20||j==51||j==73){

                    SetConsoleTextAttribute(hConsole, (WORD) ((4 << 4) | 4));}

                  else{
                       SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 4));
                  }
                        printf(" ");

             }
          }

          pos.X=60;
          pos.Y=12;
          SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 0));
           SetConsoleCursorPosition(hConsole, pos);
           printf("Modul[%i]",r);
           pos.X=61;
          pos.Y=13;
           SetConsoleCursorPosition(hConsole, pos);
           printf("Bonus");

            pos.X=58;
     pos.Y=15;
        SetConsoleCursorPosition(hConsole, pos);
     printf("HP     ", md[r].m_hp);
            pos.X=58;
     pos.Y=15;
        SetConsoleCursorPosition(hConsole, pos);
     printf("HP %i", md[r].m_hp);
       pos.X=58;
     pos.Y=16;
        SetConsoleCursorPosition(hConsole, pos);
     printf("Damage    ", md[r].m_dps);
       pos.X=58;
     pos.Y=16;
        SetConsoleCursorPosition(hConsole, pos);
     printf("Damage %i", md[r].m_dps);
       pos.X=58;
     pos.Y=17;
        SetConsoleCursorPosition(hConsole, pos);
     printf("Accuracy     ", md[r].m_accuracy);
     pos.X=58;
     pos.Y=17;
        SetConsoleCursorPosition(hConsole, pos);
     printf("Accuracy %i", md[r].m_accuracy);
        pos.X=58;
     pos.Y=18;
        SetConsoleCursorPosition(hConsole, pos);
     printf("Evasion      ", md[r].m_evasion);
          pos.X=58;
     pos.Y=18;
        SetConsoleCursorPosition(hConsole, pos);
     printf("Evasion %i", md[r].m_evasion);

     pos.X=52;
     pos.Y=16;
      SetConsoleCursorPosition(hConsole, pos);
      if(gt==97){
        SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 15));
      }else{
          SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 0));
      }
      printf("<");

          pos.X=72;
     pos.Y=16;
      SetConsoleCursorPosition(hConsole, pos);
      if(gt==100){
        SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 15));
      }else{
          SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 0));
      }
      printf(">");
SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));
       pos.X=25;
        pos.Y=23;
            SetConsoleCursorPosition(hConsole, pos);
          printf("Select module, and press Enter to confirm your choice.");

            pos.X=25;
        pos.Y=24;
            SetConsoleCursorPosition(hConsole, pos);
          printf("                                                       ");


             gt=getch();
             if (gt==97){
        if(r>0){
r--;
}
     }
      if (gt==100){
    if(r<3){
r++;
}
}

if(gt==13){
if(rb[result].slot[r]>=0){
            rb[result].hp-=md[rb[result].slot[r]].m_hp;
             rb[result].dps-=md[rb[result].slot[r]].m_dps;
              rb[result].accuracy-=md[rb[result].slot[r]].m_accuracy;
              if (rb[result].accuracy<0){
    rb[result].accuracy=0;
}
if (rb[result].accuracy>100){
    rb[result].accuracy=100;
}
 rb[result].evasion-=md[rb[result].slot[r]].m_evasion;
 if (rb[result].evasion<0){
    rb[result].evasion=0;
}
if (rb[result].evasion>100){
    rb[result].evasion=100;
}
}


rb[result].hp+=md[r].m_hp;
rb[result].dps+=md[r].m_dps;
rb[result].accuracy+=md[r].m_accuracy;
if (rb[result].accuracy<0){
    rb[result].accuracy=0;
}
if (rb[result].accuracy>100){
    rb[result].accuracy=100;
}
rb[result].evasion+=md[r].m_evasion;
if (rb[result].evasion<0){
    rb[result].evasion=0;
}
if (rb[result].evasion>100){
    rb[result].evasion=100;
}

    return r;
}

}
}



int fight_main(struct robots rb[]){
    int i,j,temp=0,result=1,gt;
    int ps=0;
    int st1=-1;
    int st2=-1;
    int status[]={-1,-1};
     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(hConsole, (WORD) ((0 << 0) | 0));
     COORD pos;

  while(TRUE){
        SetConsoleTextAttribute(hConsole, (WORD) ((0 << 0) | 0));
        system("cls");
               for(i=1;i<6;i++){
         pos.Y=i;
          for(j=4;j<20;j++){
                  pos.X=j;
                  SetConsoleCursorPosition(hConsole, pos);

                         if(i==1||i==5||j==4||j==19){
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
              pos.X=9;
          pos.Y=3;
           SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 0));
      SetConsoleCursorPosition(hConsole, pos);
      printf("Start!");




              for(i=7;i<10;i++){
         pos.Y=i;
          for(j=4;j<20;j++){
                  pos.X=j;
                  SetConsoleCursorPosition(hConsole, pos);

                         if(i==7||i==9||j==4||j==19){
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
              pos.X=6;
          pos.Y=8;
           SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 0));
      SetConsoleCursorPosition(hConsole, pos);
      if (st1==-1){
      printf("+");}else{
      printf(rb[st1].name);}


           for(i=11;i<14;i++){
         pos.Y=i;
          for(j=4;j<20;j++){
                  pos.X=j;
                  SetConsoleCursorPosition(hConsole, pos);

                         if(i==11||i==13||j==4||j==19){
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
              pos.X=6;
          pos.Y=12;
           SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 0));
      SetConsoleCursorPosition(hConsole, pos);
      if (st2==-1){
      printf("+");}else{
          printf(rb[st2].name);}


           for(i=19;i<24;i++){
         pos.Y=i;
          for(j=4;j<20;j++){
                  pos.X=j;
                  SetConsoleCursorPosition(hConsole, pos);

                         if(i==19||i==23||j==4||j==19){
                     if(result==4){
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
              pos.X=6;
          pos.Y=21;
           SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 0));
      SetConsoleCursorPosition(hConsole, pos);
      printf("To main menu");


      SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));
       pos.X=24;
        pos.Y=22;
        SetConsoleCursorPosition(hConsole, pos);
          printf("Select two robots for battle. To select a robot, press");
        pos.X=24;
        pos.Y=23;
        SetConsoleCursorPosition(hConsole, pos);
          printf("Enter on an empty slot. Select the Start! to begin.   ");



                gt=getch();
     if (gt==119){
        if(result>1){
result--;
}
     }
      if (gt==115){
    if(result<4){
result++;
}}

     if (gt==13){


    switch(result){
    case 1:
        if(st1>=0&&st2>=0){
        temp=FIGHT( rb,st1,st2);
        }
    break;
    case 2:{
        ps=1;
       st1 = sel(ps,rb);
    break;}
    case 3:
        ps=2;
       st2= sel(ps,rb);
    break;
    case 4: return temp;
        }

     }
  }
}

int sel(int ps, struct robots rb[]){
      HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(hConsole, (WORD) ((0 << 0) | 0));
     COORD pos;
    int i,arr[]={-1,-1,-1},j,j1=0,gt,result=0;

   for(i=0;i<3;i++){
       if(rb[i].status==1){
       arr[j1]=i;
       j1++;
       }
    }


    if(j1==0){
        return -1;
    }


    while(TRUE){
            if (ps==1){
            for(i=7;i<10;i++){
                pos.Y=i;
                for(j=4;j<20;j++){
                  pos.X=j;
                  SetConsoleCursorPosition(hConsole, pos);

                         if(i==7||i==9||j==4||j==19){

                    SetConsoleTextAttribute(hConsole, (WORD) ((4 << 4) | 4));}else{
                          SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 4));

                    }


                        printf(" ");

             }



          }
              pos.X=6;
          pos.Y=8;
           SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 0));
      SetConsoleCursorPosition(hConsole, pos);
      printf(rb[arr[result]].name);


       pos.X=4;
     pos.Y=8;
      SetConsoleCursorPosition(hConsole, pos);
      if(gt==97){
        SetConsoleTextAttribute(hConsole, (WORD) ((4 << 4) | 15));
      }else{
          SetConsoleTextAttribute(hConsole, (WORD) ((4 << 4) | 0));
      }
      printf("<");

          pos.X=19;
     pos.Y=8;
      SetConsoleCursorPosition(hConsole, pos);
      if(gt==100){
        SetConsoleTextAttribute(hConsole, (WORD) ((4 << 4) | 15));
      }else{
          SetConsoleTextAttribute(hConsole, (WORD) ((4 << 4) | 0));
      }
      printf(">");

                     gt=getch();
     if (gt==97){
        if(result>0){
result--;
}
     }
      if (gt==100){
    if(result<j1-1){
result++;
}}

     if (gt==13){
            return arr[result];

        }

     }

       if(ps==2){



               for(i=11;i<14;i++){
         pos.Y=i;
          for(j=4;j<20;j++){
                  pos.X=j;
                  SetConsoleCursorPosition(hConsole, pos);

                         if(i==11||i==13||j==4||j==19){

                    SetConsoleTextAttribute(hConsole, (WORD) ((4 << 4) | 4));}else{
                          SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 4));

                    }


                        printf(" ");

             }



          }
              pos.X=6;
          pos.Y=12;
           SetConsoleTextAttribute(hConsole, (WORD) ((3 << 4) | 0));
      SetConsoleCursorPosition(hConsole, pos);
     printf(rb[arr[result]].name);


       pos.X=4;
     pos.Y=12;
      SetConsoleCursorPosition(hConsole, pos);
      if(gt==97){
        SetConsoleTextAttribute(hConsole, (WORD) ((4 << 4) | 15));
      }else{
          SetConsoleTextAttribute(hConsole, (WORD) ((4 << 4) | 0));
      }
      printf("<");

          pos.X=19;
     pos.Y=12;
      SetConsoleCursorPosition(hConsole, pos);
      if(gt==100){
        SetConsoleTextAttribute(hConsole, (WORD) ((4 << 4) | 15));
      }else{
          SetConsoleTextAttribute(hConsole, (WORD) ((4 << 4) | 0));
      }
      printf(">");

                gt=getch();
     if (gt==97){
        if(result>0){
result--;
}
     }
      if (gt==100){
    if(result<j1-1){
result++;
}}

     if (gt==13){
            return arr[result];

        }





    }





    }
}




int FIGHT(struct robots rb[],int st1,int st2){
       HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
srand(time(NULL));
     int i,j,temp=0,hp1=rb[st1].hp,hp2=rb[st2].hp;
     COORD pos;
             pos.X=29;
            pos.Y=18;
         SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 15));
            SetConsoleCursorPosition(hConsole, pos);
            printf(" ");
            pos.X=30;
            pos.Y=18;
         SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 15));
            SetConsoleCursorPosition(hConsole, pos);
            printf(" ");
              pos.X=30;
            pos.Y=17;
           SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 15));
            SetConsoleCursorPosition(hConsole, pos);
            printf(" ");
            pos.X=31;
            pos.Y=18;
      SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 15));
            SetConsoleCursorPosition(hConsole, pos);
            printf(" ");
              pos.X=31;
            pos.Y=17;
          SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 15));
            SetConsoleCursorPosition(hConsole, pos);
            printf(" ");
              pos.X=32;
            pos.Y=18;
          SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 15));
            SetConsoleCursorPosition(hConsole, pos);
            printf(" ");
              pos.X=33;
            pos.Y=18;
        SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 15));
            SetConsoleCursorPosition(hConsole, pos);
            printf(" ");
              pos.X=31;
            pos.Y=16;
      SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 15));
            SetConsoleCursorPosition(hConsole, pos);
            printf(" ");
               pos.X=32;
            pos.Y=16;
       SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 15));
            SetConsoleCursorPosition(hConsole, pos);
            printf(" ");


               pos.X=74;
            pos.Y=18;
         SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 15));
            SetConsoleCursorPosition(hConsole, pos);
            printf(" ");
               pos.X=73;
            pos.Y=18;
         SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 15));
            SetConsoleCursorPosition(hConsole, pos);
            printf(" ");
               pos.X=72;
            pos.Y=18;
         SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 15));
            SetConsoleCursorPosition(hConsole, pos);
            printf(" ");
               pos.X=71;
            pos.Y=18;
         SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 15));
            SetConsoleCursorPosition(hConsole, pos);
            printf(" ");
               pos.X=70;
            pos.Y=18;
         SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 15));
            SetConsoleCursorPosition(hConsole, pos);
            printf(" ");
               pos.X=73;
            pos.Y=17;
         SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 15));
            SetConsoleCursorPosition(hConsole, pos);
            printf(" ");
               pos.X=72;
            pos.Y=17;
         SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 15));
            SetConsoleCursorPosition(hConsole, pos);
            printf(" ");
               pos.X=72;
            pos.Y=16;
         SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 15));
            SetConsoleCursorPosition(hConsole, pos);
            printf(" ");
               pos.X=71;
            pos.Y=16;
         SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 15));
            SetConsoleCursorPosition(hConsole, pos);
            printf(" ");





    while(TRUE){

                   pos.Y=8;
        pos.X=29;
         SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));
            SetConsoleCursorPosition(hConsole, pos);
            printf("               ");

        pos.Y=8;
        pos.X=29;
         SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));
            SetConsoleCursorPosition(hConsole, pos);
            printf(rb[st1].name);


            pos.Y=8;
            pos.X=70;
            SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));
            SetConsoleCursorPosition(hConsole, pos);
            printf("            ");

            pos.Y=8;
            pos.X=70;
            SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));
            SetConsoleCursorPosition(hConsole, pos);
            printf(rb[st2].name);





             pos.Y=10;
        pos.X=29;
         SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));
            SetConsoleCursorPosition(hConsole, pos);
            printf("HP =        ");

        pos.Y=10;
        pos.X=29;
         SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));
            SetConsoleCursorPosition(hConsole, pos);
            if(hp1<0){
                printf("HP = 0");
            }else{
            printf("HP = %i",hp1);
            }


            pos.Y=10;
            pos.X=70;
            SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));
            SetConsoleCursorPosition(hConsole, pos);
            printf("HP =        ");

            pos.Y=10;
            pos.X=70;
            SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));
            SetConsoleCursorPosition(hConsole, pos);
            if(hp2<0){
                printf("HP = 0");
            }else{
           printf("HP = %i",hp2);
            }

               pos.Y=12;
            pos.X=29;
            SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));
            SetConsoleCursorPosition(hConsole, pos);
            printf("              ");

            pos.Y=12;
            pos.X=29;
            SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));
            SetConsoleCursorPosition(hConsole, pos);
            printf("Dmg = %i",rb[st1].dps);

                pos.Y=12;
            pos.X=70;
            SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));
            SetConsoleCursorPosition(hConsole, pos);
            printf("             ");

            pos.Y=12;
            pos.X=70;
            SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));
            SetConsoleCursorPosition(hConsole, pos);
            printf("Dmg = %i",rb[st2].dps);





            if(hp1<=0&&hp2<=0){

                            pos.Y=8;
                            pos.X=49;
                            SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));
                            SetConsoleCursorPosition(hConsole, pos);
                            printf("Draw!");
                              Sleep(4000);
                            return temp;

            }else{



                    if(hp1<=0){

                            pos.Y=8;
                            pos.X=47;
                            SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));
                            SetConsoleCursorPosition(hConsole, pos);
                          printf(rb[st2].name);

                          pos.Y=8;
                            pos.X=47+strlen(rb[st2].name);
                            SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));
                            SetConsoleCursorPosition(hConsole, pos);
                            printf("wins!");
                             Sleep(4000);
                            return temp;

            }
             if(hp2<=0){

                            pos.Y=8;
                            pos.X=47;
                            SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));
                            SetConsoleCursorPosition(hConsole, pos);

                            printf(rb[st1].name);
                             pos.Y=8;
                           pos.X=47+strlen(rb[st1].name);
                            SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));
                            SetConsoleCursorPosition(hConsole, pos);
                            printf("wins!");
                            Sleep(4000);
                            return temp;

            }
            }




            for(i=33;i<71;i++){
                pos.X=i;
                pos.Y=16;
                   SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 15));
            SetConsoleCursorPosition(hConsole, pos);
            printf(" ");
            Sleep(20);
            pos.X=i;
                pos.Y=16;
             SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 0));
            SetConsoleCursorPosition(hConsole, pos);
            printf(" ");
            }
              for(i=70;i>33;i--){
                pos.X=i;
                pos.Y=16;
                   SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 15));
            SetConsoleCursorPosition(hConsole, pos);
            printf(" ");
            Sleep(20);
            pos.X=i;
                pos.Y=16;
             SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 0));
            SetConsoleCursorPosition(hConsole, pos);
            printf(" ");
            }


            if(rand()%100<rb[st2].accuracy){
                    if(rand()%100>rb[st1].evasion){
                        pos.Y=14;
                        pos.X=29;
                        SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));
                        SetConsoleCursorPosition(hConsole, pos);
                        printf("Damage!  ");
                        hp1-=rb[st2].dps;
                        }
                        else{
                            pos.Y=14;
                            pos.X=29;
                            SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));
                            SetConsoleCursorPosition(hConsole, pos);
                            printf("Miss!        ");
                            }
                            }else{
                            pos.Y=14;
                            pos.X=29;
                            SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));
                            SetConsoleCursorPosition(hConsole, pos);
                            printf("Miss!       ");
                }


                if(rand()%100<rb[st1].accuracy){
                if(rand()%100>rb[st2].evasion){
                        pos.Y=14;
                        pos.X=70;
                        SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));
                        SetConsoleCursorPosition(hConsole, pos);
                        printf("Damage!  ");
                      hp2-=rb[st1].dps;
                        }
                        else{
                            pos.Y=14;
                            pos.X=70;
                            SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));
                            SetConsoleCursorPosition(hConsole, pos);
                            printf("Miss!        ");
                            }
                            }else{
                            pos.Y=14;
                            pos.X=70;
                            SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));
                            SetConsoleCursorPosition(hConsole, pos);
                            printf("Miss!       ");
                }

            /*

             if(rand()%100<rb[st1].accuracy){
                if(rand()%100>rb[st2].evasion){
                    rb[st2].hp-=rb[st1].dps;
                }else{}
            }else{}


            */



            Sleep(200);





    }

}

void input(struct robots *r){
    FILE * fp;
    int i,j;
    char str[20];
    fp = fopen("data.txt" , "r");
    if(fp==NULL){}else{
     for (j=0;j<3;j++){

            fgets(str,sizeof(str),fp);
            strcpy(r->name,str);
            fgets(str,sizeof(str),fp);
            r->hp=atoi(str);
            fgets(str,sizeof(str),fp);
            r->dps=atoi(str);
            fgets(str,sizeof(str),fp);
            r->accuracy=atoi(str);
            fgets(str,sizeof(str),fp);
            r->evasion=atoi(str);
            fgets(str,sizeof(str),fp);
            r->status=atoi(str);
            for (i=0;i<4;i++){
             fgets(str,sizeof(str),fp);
             r->slot[i]=atoi(str);
            }
            r++;
     }
}
     fclose(fp);

}

void output(struct robots *r){
    FILE * fp;
    int i,j;

     fp = fopen("data.txt" , "w");
     for (j=0;j<3;j++){
         fprintf(fp,r->name);
       //  fprintf(fp,"\n");
         fprintf(fp,"%i\n",r->hp);
         fprintf(fp,"%i\n",r->dps);
         fprintf(fp,"%i\n",r->accuracy);
         fprintf(fp,"%i\n",r->evasion);
         fprintf(fp,"%i\n",r->status);
            for (i=0;i<4;i++){
                fprintf(fp,"%i\n",r->slot[i]);
            }
        r++;
    }

     fclose (fp);

}










int main()
{
    int gt,temp;
    int punct;
    struct robots robots_list[3]={{"Adept",100,40,60,10,{-1,-1,-1,-1},0},{"Stalker",100,40,60,10,{-1,-1,-1,-1},0},{"Zealot",100,40,60,10,{-1,-1,-1,-1},0}};
    struct modul modul_list[4]={{+20,+10,+10,0},{0,+20,+30,+10},{-10,+40,+40,+30},{+60,+25,-10,-10}};
    struct robots * r;
    r=&robots_list;
   input(r);
   welcome();
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(hConsole, (WORD) ((0 << 0) | 0));
     COORD pos;
while(TRUE){
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(hConsole, (WORD) ((0 << 0) | 0));
     COORD pos;
  system("cls");
  punct = main_menu();
  switch(punct){
  case 1:temp = fight_main(robots_list);
      break;
  case 2: temp=customize_main(robots_list,modul_list);
  break;
  case 3:
      r=&robots_list;
      output(r);
exit (EXIT_SUCCESS);
  break;
        }
}


}

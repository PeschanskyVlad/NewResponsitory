#include <windows.h>
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int i,a=0,b=0;
    int c,d,x,y,clr=0,clr1=0,stclr1=1,clr2=0,stclr2=1;


COORD pos;
pos.X=80;
pos.Y=0;


while(a<13){

    for(i=80-a;i>0+a;i--){
    pos.X--;
   switch(clr%8){
    case 0:
        SetConsoleTextAttribute(hConsole, (WORD) ((4 << 4) | 2));
        break;
        case 1:
            SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 2));
            break;
            case 2:
           SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 2));
           break;
                case 3:
                   SetConsoleTextAttribute(hConsole, (WORD) ((4 << 4) | 2));
                   break;
                    case 4:
                        SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 2));
                        break;
                        case 5:
                            SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 2));
                            break;
                            case 6:
                                SetConsoleTextAttribute(hConsole, (WORD) ((4 << 4) | 2));
                                break;
                                case 7:
                                    SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 2));
                                    break;
                                    }



    SetConsoleCursorPosition(hConsole, pos);
     printf("*");
    Sleep(10);
    clr++;
    }
    clr=0;

    for (i=1+a;i<25-a;i++){
      pos.Y++;
      switch(clr1%8){
case 0:
    SetConsoleTextAttribute(hConsole, (WORD) ((4 << 4) | 2));
    break;
case 1:
    SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 2));
    break;
case 2:
    SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 2));
    break;
case 3:
    SetConsoleTextAttribute(hConsole, (WORD) ((4 << 4) | 2));
    break;
case 4:
    SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 2));
    break;
    case 5:
    SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 2));
    break;
    case 6:
    SetConsoleTextAttribute(hConsole, (WORD) ((4 << 4) | 2));
    break;
    case 7:
    SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 2));
    break;
        }
             SetConsoleCursorPosition(hConsole, pos);
             printf("*");
              Sleep(10);
clr1++;

    }
    clr1=2*stclr1;
    stclr1++;



    for (i=1+a;i<80-a;i++){
              pos.X++;
                 switch(clr%8){
    case 0:
        SetConsoleTextAttribute(hConsole, (WORD) ((4 << 4) | 2));
        break;
        case 1:
            SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 2));
            break;
            case 2:
           SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 2));
           break;
                case 3:
                   SetConsoleTextAttribute(hConsole, (WORD) ((4 << 4) | 2));
                   break;
                    case 4:
                        SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 2));
                        break;
                        case 5:
                            SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 2));
                            break;
                            case 6:
                                SetConsoleTextAttribute(hConsole, (WORD) ((4 << 4) | 2));
                                break;
                                case 7:
                                    SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 2));
                                    break;
                                    }
             SetConsoleCursorPosition(hConsole, pos);
             printf("*");
              Sleep(10);
              clr++;

    }
    clr=0;
    for(i=24-a;i>1+a;i--){
        pos.Y--;
                   switch(clr2%8){
case 0:
    SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 2));
    break;
case 1:
    SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 2));
    break;
case 2:
    SetConsoleTextAttribute(hConsole, (WORD) ((4 << 4) | 2));
    break;
case 3:
    SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 2));
    break;
case 4:
    SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 2));
    break;
    case 5:
    SetConsoleTextAttribute(hConsole, (WORD) ((4 << 4) | 2));
    break;
    case 6:
    SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 2));
    break;
    case 7:
    SetConsoleTextAttribute(hConsole, (WORD) ((4 << 4) | 2));
    break;
        }
        SetConsoleCursorPosition(hConsole, pos);
             printf("*");
              Sleep(10);
               clr2++;
    }
    a++;
    clr2=2*stclr2;
    stclr2++;
}


}

#include <stdio.h>
#include <stdlib.h>

const char permitted_values[] = {"0123456789aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ"};
char* convert(char*, unsigned int , unsigned int);
char* convert_fractional(char *,unsigned int , unsigned int);

int char_to_int (char c)
{
  int res;

  switch (c)
    {
      case '0': res = 0; break;
      case '1': res = 1; break;
      case '2': res = 2; break;
      case '3': res = 3; break;
      case '4': res = 4; break;
      case '5': res = 5; break;
      case '6': res = 6; break;
      case '7': res = 7; break;
      case '8': res = 8; break;
      case '9': res = 9; break;
      case 'A':
      case 'a': res = 10; break;
      case 'B':
      case 'b': res = 11; break;
      case 'C':
      case 'c': res = 12; break;
      case 'D':
      case 'd': res = 13; break;
      case 'E':
      case 'e': res = 14; break;
      case 'F':
      case 'f': res = 15; break;
      case 'G':
      case 'g': res = 16; break;
      case 'H':
      case 'h': res = 17; break;
      case 'I':
      case 'i': res = 18; break;
      case 'J':
      case 'j': res = 19; break;
      case 'k':
      case 'K': res = 20; break;
      case 'L':
      case 'l': res = 21; break;
      case 'M':
      case 'm': res = 22; break;
      case 'N':
      case 'n': res = 23; break;
      case 'o':
      case 'O': res = 24; break;
      case 'P':
      case 'p': res = 25; break;
      case 'q':
      case 'Q': res = 26; break;
      case 'r':
      case 'R': res = 27; break;
      case 's':
      case 'S': res = 28; break;
      case 'T':
      case 't': res = 29; break;
      case 'U':
      case 'u': res = 30; break;
      case 'V':
      case 'v': res = 31; break;
      case 'W':
      case 'w': res = 32; break;
      case 'X':
      case 'x': res = 33; break;
      case 'Y':
      case 'y': res = 34; break;
      case 'Z':
      case 'z': res = 35; break;

      default:

        abort ();
    }

  return res;
}

char int_to_char (int n)
{
  char res;

  switch (n)
    {
     case 0: res = '0'; break;
      case 1: res = '1'; break;
      case 2: res = '2'; break;
      case 3: res = '3'; break;
      case 4: res = '4'; break;
      case 5: res = '5'; break;
      case 6: res = '6'; break;
      case 7: res = '7'; break;
      case 8: res = '8'; break;
      case 9: res = '9'; break;
      case 10: res = 'A'; break;
      case 11: res = 'B'; break;
      case 12: res = 'C'; break;
      case 13: res = 'D'; break;
      case 14: res = 'E'; break;
      case 15: res = 'F'; break;
      case 16: res = 'G'; break;
      case 17: res = 'H'; break;
      case 18: res = 'I'; break;
      case 19: res = 'J'; break;
      case 20: res = 'K'; break;
      case 21: res = 'L'; break;
      case 22: res = 'M'; break;
      case 23: res = 'N'; break;
      case 24: res = 'O'; break;
      case 25: res = 'P'; break;
      case 26: res = 'Q'; break;
      case 27: res = 'R'; break;
      case 28: res = 'S'; break;
      case 29: res = 'T'; break;
      case 30: res = 'U'; break;
      case 31: res = 'V'; break;
      case 32: res = 'W'; break;
      case 33: res = 'X'; break;
      case 34: res = 'Y'; break;
      case 35: res = 'Z'; break;



      default:

        abort ();
    }

  return res;
}



char* ns_convert(char* number, unsigned int sourceBase, unsigned int destBase)
{


    char *conv1;
    char *conv2;
    char result1[100]="";
    char result2[100]="";
    char *integer_part;
    char *fractional_part;
    int fp=1;
    integer_part=strtok(number,".");

    fractional_part=strtok(NULL,".");

    if(fractional_part==NULL||fractional_part=='\0'){
    fp=0;
    }


    if(check(integer_part,sourceBase,destBase)==0){
        return  "\0";
    }
    conv1=convert(integer_part,sourceBase,destBase);
    strcpy(result1,conv1);


    if(fp==1){
    if(check(fractional_part,sourceBase,destBase)==0){
        return  "\0";
    }

    conv2=convert_fractional(fractional_part,sourceBase,destBase);
    strcpy(result2,conv2);
    strcat(result1,result2);
    }


   return result1;

}



char* convert(char *integer_part, unsigned int sourceBase, unsigned int destBase){
    int result=0;

    int i;
    char str[20]="";
    char c_v;
    char str1[5]="";
    char result_integer_part[100]="\0";
    for(i=strlen(integer_part)-1;i>=0;i--){
        result+=char_to_int(integer_part[i])*pow(sourceBase,abs(i-strlen(integer_part)+1));
    }

    while(result!=0){
        int temp;
        temp=result%destBase;

        c_v=int_to_char(temp);
        str1[0]=c_v;

        strcat(result_integer_part,str1);
        result=result/destBase;
    }


    char r_result[100]="\0";


    for(i=0;i<strlen(result_integer_part);i++){
        r_result[i]=result_integer_part[strlen(result_integer_part)-1-i];

    }


    return r_result;

}

char* convert_fractional(char *fractional_part,unsigned int sourceBase, unsigned int destBase){
int i;
int i_p;
double result;
char i_p1;
 char c_v;
    char str1[5]="";

char r_result[15]=".";
for(i=0;i<strlen(fractional_part);i++){



        result+=(1/pow((double)sourceBase,i+1))*char_to_int(fractional_part[i]);
}

for(i=0;i<12;i++){
    result*=destBase;
    i_p=result;
    if(i_p==0){
        break;
    }
    c_v=int_to_char(i_p);
    str1[0]=c_v;
    strcat(r_result,str1);
    result-=i_p;
}
return r_result;

}

int check(char *number,unsigned int part,unsigned int part1){
    char str[55]="\0";
    char nd[64];
    int i1;
    strcpy(nd,number);
    int i;
    char *istr;
    int check_long;
    if(part1<2||part1>36){
        return 0;
    }

    if(part<2||part>36){
        return 0;
    }

    if(part<=10){
        check_long=part;

    }
    if(part>10){
    check_long=10+(part-10)*2;

    }

    strncpy(str,permitted_values,check_long);

i1=strlen(nd);
    for(i=0;i<strlen(nd);i++){

    istr=strchr(str, nd[i]);
       if(istr==NULL){
        return 0;
       }
    }
    return 1;

}
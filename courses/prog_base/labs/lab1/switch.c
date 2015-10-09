#include <math.h>
int exec(int op, int a, int b) {
   int result;
   int c;
   //int i;
  // int a1;
   if (op<0){
    c=b;
    b=a;
    a=c;
    op=abs(op);
   }

if (op<100){
switch(op){
case 0:
    result=-a;
    break;
case 1:
    result=a+b;
    break;
case 2:
    result=a-b;
    break;
case 3:
    result=a*b;
    break;
case 4:
    result=a/b;
    break;
case 5:
    result=abs(a);
    break;
case 6:
       // result=a+b;
    result=pow(a,b);
  /* a1=a;
   i=1;
   while(i<b){
    a1=a1*a;
    i++;
   }
   result=a1;*/
   break;
case 7:
case 13:
case 77:
    result=a%b;
    break;
case 8:
    if(a>b){
        result=a;
    }
    else{
        result=b;
    }
    break;
case 9:
    if(a<b){
        result=a;
    }
    else{
        result=b;
    }
    break;
case 10:
    b=abs(b)%8;
    switch(b){
    case 0:
        result=abs(a)*sizeof(char);
        break;
    case 1:
        result=abs(a)*sizeof(signed char);
        break;
    case 2:
        result=abs(a)*sizeof(short);
        break;
    case 3:
        result=abs(a)*sizeof(unsigned int);
        break;
    case 4:
        result=abs(a)*sizeof(long);
        break;
    case 5:
        result=abs(a)*sizeof(unsigned long long);
        break;
    case 6:
        result=abs(a)*sizeof(float);
        break;
    case 7:
        result=abs(a)*sizeof(double);
        break;

    }
    break;
case 11:
   result=9*M_PI*cos((1)*a*b)/a;
    break;
default:
    result=(op % abs(a + 1)) + (op % abs(b + 1));
    break;
    }

}
if (op>100){
    result=-1;
}


   return result;
}

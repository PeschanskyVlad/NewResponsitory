#include <math.h>

int exec(int op, int a, int b) {
   int result;
      int c;
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
    result=pow(a,b);
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
    result=abs(a)*sizeof(abs(b)%8);
    break;
case 11:
   result=(9)*M_PI*cos((1)*a*b)/a;
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

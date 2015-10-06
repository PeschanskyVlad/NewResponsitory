#include <math.h>
int satisfies(int a, int b, int c) {
   int result;
   int d,sum;


       if(c>b){
        d=b;
        b=c;
        c=d;
       }
       if (b>a){
        d=a;
        a=b;
        b=d;
       }
        if(c>b){
        d=b;
        b=c;
        c=d;
       }

   if (a<0&&b<0&&c<0){

       sum=b+a;
       c=abs(c);

       if(/*(log(c)/log(2))==int(log(c)/log(2))*/(c&(c-1))==0&&c<256&&sum<-256){
        result= 1;
       }
       else{
        if(sum>-256&&abs(sum)>c){
            result= 1;
        }
        else{
            result= 0;
        }
       }




   }
   else{

    if (a<0||b<0||c<0){


   if (b<0||c<0){
           if((b+c)*8>-256){result= 1;
           }
           else{result= 0;
           }
        }

     if (c<0){
          if(c>-256){result= 1;
          }
          else{result= 0;
          }
        }



    }
   }

   if (a>=0&&b>=0&&c>=0){

    if (c == 0){
        result = 0;
    }
    else{
        if (a == 0){
            result= 1;
        }
        else{
                if(a%c==0){
                    result= 1;
                }
                else{
                    result= 0;
                }


        }
    }
   }
   return result;
}

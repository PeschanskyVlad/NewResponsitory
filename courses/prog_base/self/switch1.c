#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  int n;
  int m;
  int code;
  double result;
  scanf("%i",&n);
  scanf("%i",&m);
  scanf("%i",&code);
  if (code<=999&&code>=10){

  switch(code){

  default:{
    result=(60*n+m);
     printf("%f",result);
  }
  case  44:{
      result=(60*n+m)*0.77;
      printf("%f",result);
      break;
  }

  case  62:{
      result=(60*n+m)*0.8;
      printf("%f",result);
      break;
  }

  case  32:{
      result=(60*n+m)*0.95;
      printf("%f",result);
      break;
  }

 case 692:
 case 697:
 {
      result=(60*n+m)*1.5;
      printf("%f",result);
      break;
  }

  }

  }
    return 0;
}

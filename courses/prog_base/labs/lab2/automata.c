int run(int moves[], int movesLen, int res[], int resLen){
     int avtom[5][5];
     int i,j,stan=0,LocRes=0,Num,s=0,brk=0;
     enum cnst{ A = 0, B, C, D};
      avtom[0][A]=A;
     avtom[0][B]=B;
     avtom[0][C]=C;
     avtom[0][D]=D;

     avtom[1][0]=9;
      avtom[2][0]=13;
      avtom[3][0]=18;
      avtom[4][0]=108;
      for (i=0;i<resLen;i++){
        res[i]=0;
      }
      for(i=0;i<movesLen;i++){
      Num=moves[i];
      for(j=1;j<=4;j++){
        if(Num==avtom[j][0]){
            s++;
        }
      }
      if(s==0){
            break;
        }
        switch (Num){
        case 9:
            {


            switch(stan){
            case 0:
               res[LocRes]=11;
               LocRes++;
               stan=1;
               break;
            case 1:

                brk=1;
                break;
            case 2:
              res[LocRes]=0;
              LocRes--;
               stan=0;
               break;
            case 3:

                brk=1;
                break;

            }
            break;
            }
        case 13:
            {


            switch(stan){
            case 0:
                res[LocRes]=55;
               LocRes++;
               stan=2;
               break;

            case 1:
                res[LocRes]=0;
               LocRes--;
               stan=1;
               break;
            case 2:
                res[LocRes]=5;
               LocRes++;
               stan=3;
               break;
            case 3:

                brk=1;
                break;
            }
            break;
            }
        case 18:
            {
            switch(stan){
            case 0:
                res[LocRes]=101;
               LocRes++;
               stan=3;
               break;
            case 1:
                res[LocRes]=1;
               LocRes++;
               stan=2;
               break;
            case 2:
               i--;
               stan=1;
               break;
            case 3:

                brk=1;
                break;
            }
            break;
            }
        case 108:
                 {


            switch(stan){
            case 0:
                stan=0;
                break;
            case 1:

                brk=1;
                break;
            case 2:
               res[LocRes]=11;
               LocRes++;
               stan=2;
               break;
            case 3:
                res[LocRes]=2;
               LocRes++;
               stan=1;
               break;
            }
            break;
            }
        }
        if (brk==1){
            break;
        }
      }

      for(i=0;i<resLen;i++){
        if(res[i]==0){
            break;
        }
        s=0;
        printf("%i ",res[i]);

      }
      return i;
}

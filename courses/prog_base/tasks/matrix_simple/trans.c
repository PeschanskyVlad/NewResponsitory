void fillRand(int mat[4][4]){
int i,j;
for (i=0;i<=3;i++){
 for (j=0;j<=3;j++){
        mat[i][j]=pow(-1,rand()%2)*(rand()%1000);
      }
}
}

void rotateCW270(int mat[4][4]){
int i,j;
int matc [4][4];
for (i=0;i<=3;i++){
 for (j=0;j<=3;j++){
        matc[i][j]=mat[i][j];
      }
}

for (i=0;i<=3;i++){
 for (j=0;j<=3;j++){
        mat[j][i]=matc[i][abs(3-j)];
      }
}




}


void flipH(int mat[4][4]){
int i,j;
int matc [4][4];
for (i=0;i<=3;i++){
 for (j=0;j<=3;j++){
        matc[i][j]=mat[i][j];
      }
}


for (i=0;i<=3;i++){
 for (j=0;j<=3;j++){
        mat[i][j]=matc[i][abs(3-j)];
      }
}



}
void transposMain(int mat[4][4]){
    int i,j;
int matc [4][4];
for (i=0;i<=3;i++){
 for (j=0;j<=3;j++){
        matc[i][j]=mat[i][j];
      }
}

for (i=0;i<=3;i++){
 for (j=0;j<=3;j++){
        mat[i][j]=matc[j][i];
      }
}



}
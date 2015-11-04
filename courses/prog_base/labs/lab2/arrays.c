void fillRand3(int arr[], int size){
    int i;
  for(i=0;i<=size;i++){

        arr[i]=rand()%2;
    }
}
int checkRand3(int arr[], int size){
int i,r;
r=1;
  for(i=0;i<=size;i++){
        if (arr[i]!=0&&arr[i]!=1){
            r=0;
            break;
        }
    }
    return r;
}

float meanValue(int arr[], int size)
{
int i;
float s=0;
for(i=0;i<=size;i++){
      s=s+arr[i];
        }
        s=s/size;
    return s;
}



int minValue(int arr[], int size){
  int i,min;
  min=arr[0];
   for(i=0;i<=size;i++){
        if(min>=arr[i]){
            min=arr[i];
        }
    }
    return min;
}

int meanIndex(int arr[], int size){
    int i,min,in,s;
 s=meanValue( arr,  size);


   for(i=size;i>=0;i--){
        if(min>=abs(arr[i]-s)){
            min=arr[i];
            in=i;
        }
    }
    return in;
}


int minIndex(int arr[], int size){
  int i,min,in;
  min= minValue( arr,  size);
  for(i=size;i>=0;i--){
        if(min>=arr[i]){
            min=arr[i];
            in=i;
        }
    }

return in;
}

int maxOccurance(int arr[], int size){
int i,i1,a1,max,max1,j;
int mas [size][3];
for(i=0;i<=size;i++){
    mas[i][0]=0;
    mas[i][1]=0;
    mas[i][2]=0;
}


mas[0][0]=arr[0];
mas[0][2]=1;
for(j=0;j<=size;j++){

a1=arr[j];
for(i=0;i<=size;i++){
  if(a1==mas[i][0])
  {
mas[i][0]=a1;
mas[i][1]++;
mas[i][2]=1;
  goto m1;
}
if(mas[i][2]==0){
    mas[i][0]=a1;
 mas[i][1]++;
 mas[i][2]=1;
  goto m1;
}
}
  m1:;
}


max=mas[0][1];
i1=0;

for(i=0;i<=size;i++){
    if (max<mas[i][1]){
        max=mas[i][1];
        i1=i;
    }
}
max1=mas[i1][0];


for(i=0;i<=size;i++){
    if (max==mas[i][1]){
        if(max1<mas[i][0]){
            max1=mas[i][0];
        }
    }

}
return max1;





}


void fillRandMM(int arr1[], int arr2[],int size ){
  int i;
  for(i=0;i<=size;i++){
        arr1[i]=rand()%2;
        arr2[i]=rand()%2;
    }
}



int diff(int arr1[], int arr2[], int res[], int size){
    int i;
    int i1 = 1;
for(i=0;i<=size;i++){
        res[i]=arr1[i]-arr2[i];
    if(res[i]!=0){
        i1=0;

    }
}
return i1;
}


void add(int arr1[], int arr2[], int res[], int size){
    int i;
    for(i=0;i<=size;i++){
            res[i]=arr1[i]+arr2[i];

    }
}

int lteq(int arr1[], int arr2[], int size){
int i;
    int i1 = 1;
    for(i=0;i<=size;i++){
        if(arr1[i]>arr2[2]){
                i1=0;

        }
    }
    return i1;

}


void land(int arr1[], int arr2[], int res[], int size){
    int i;
    for(i=0;i<=size;i++){
            res[i]=arr1[i]&&arr2[i];

    }

}


#include <stdio.h>
#include <stdlib.h>
#define smth 4


struct animals{
char animal[10];
char animal_name[10];
int animal_number;
};


int count(int,struct animals * arr);

void print(struct animals * pVar){
printf("Animal number: %i\n", pVar->animal_number);
printf("Kind of animal: %s\n", pVar->animal);
printf("Animal name: %s\n", pVar->animal_name);

}

void change(struct animals * pVar, const char * newValue){
    strcpy(pVar->animal_name, newValue);
}

int main()
{

    int kk,index;
    char in[6];
int i;
    char newValue[30];
    struct animals animals_list[smth] = {{"dog", "Bob", 1},{"cat","Tom",2},{"elephant","Dony", 3},{"crocodile","Riki",4}};
    int size = sizeof(animals_list)/sizeof(animals_list[0]);


 struct animals * a;
 a=&animals_list;

for(i=0;i<size;i++){
    print(a);
    puts(" ");
    a++;

    }


     kk=count(size, animals_list);
    printf("\nNumber of cats: %i\n",kk);
    printf("\nEnter number of changed name animal:");
    index=atoi(gets(in));
    puts("Enter new name:");
   gets(newValue);
  change(&animals_list[index-1], newValue);
  puts(" ");
  a=&animals_list;
 for(i=0;i<index-1;i++){
        a++;
 }
print(a);







}

int count(int size, struct animals arr[size]){
 int i, kk=0;
    for (i=0;i<size;i++){
         if (strcmp(arr[i].animal, "cat")==0){
           kk++;
         }
    }

    return kk;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct pr{
    char name[20];
    int birthYear;
    char Graduate_degree[20];
    float average_score;

};

struct project{
    char name[20];
    int Pr_month;
    int Number_of_lines;
    float cost;

};

void filling1(struct pr * p){
strcpy(p->name,"Ivan");
p->birthYear=1989;
strcpy(p->Graduate_degree,"KPI");
p->average_score=4.5;
p++;
strcpy(p->name,"Bill");
p->birthYear=1975;
strcpy(p->Graduate_degree,"DUT");
p->average_score=5.1;
}


void filling2(struct project * p1){
strcpy(p1->name,"Project1");
p1->Pr_month=2;
p1->Number_of_lines=1565;
p1->cost=45.6;
p1++;
strcpy(p1->name,"Project2");
p1->Pr_month=4;
p1->Number_of_lines=1298;
p1->cost=39.3;
}

void output1(struct pr * p){
puts(p->name);
printf("%i\n",p->birthYear);
puts(p->Graduate_degree);
printf("2%f\n",p->average_score);
p++;
puts(" ");
puts(p->name);
printf("%i\n",p->birthYear);
puts(p->Graduate_degree);
printf("2%f\n",p->average_score);
}

void output2(struct project * p1){
puts(p1->name);
printf("%i\n",p1->Pr_month);
printf("%i\n",p1->Number_of_lines);
printf("2%f\n",p1->cost);
p1++;
puts(" ");
puts(p1->name);
printf("%i\n",p1->Pr_month);
printf("%i\n",p1->Number_of_lines);
printf("2%f\n",p1->cost);
}

void memoryIn1(struct pr * p){
p=malloc(sizeof(struct pr));
}

void memoryIn2(struct project * p1){
p1=malloc(sizeof(struct project));
}

void memoryOut1(struct pr * p){
free(p);
}

void memoryOut2(struct project * p1){
free(p1);
}

void input1(struct pr * p){
    char str[20];
    pust("Enter programist name:")
gets(str);
strcpy(p->name,str);
pust("Enter programist birth year:")
gets(str);
p->birthYear=atoi(str);
pust("Enter programist university:")
gets(str);
strcpy(p->Graduate_degree,str);
pust("Enter programist average score:")
gets(str);
p->average_score=atof(str);
p++;
pust("Enter programist name:")
gets(str);
strcpy(p->name,str);
pust("Enter programist birth year:")
gets(str);
p->birthYear=atoi(str);
pust("Enter programist university:")
gets(str);
strcpy(p->Graduate_degree,str);
pust("Enter programist average score:")
gets(str);
p->average_score=atof(str);
}

void input2(struct project * p1){

             char str[20];
    pust("Enter project name:")
gets(str);
strcpy(p1->name,str);
pust("Enter project create month:")
gets(str);
p1->Pr_month=atoi(str);
   pust("Enter project number of lines:")
gets(str);
p1->Number_of_lines=atoi(str);
 pust("Enter project cost:")
gets(str);
p1->cost=atof(str);
p1++;
    pust("Enter project name:")
gets(str);
strcpy(p1->name,str);
pust("Enter project create month:")
gets(str);
p1->Pr_month=atoi(str);
   pust("Enter project number of lines:")
gets(str);
p1->Number_of_lines=atoi(str);
 pust("Enter project cost:")
gets(str);
p1->cost=atof(str);


}



int main()
{
    struct pr prog[2];
    struct project pt[2];
    struct pr * p;
    struct project *p1;
    p=&prog;
    filling1(p);
      p1=&pt;
    filling2(p1);
    output1(p);
    puts(" ");
    output2(p1);

    memoryIn1();
    memoryIn2();
    memoryOut1();
    memoryOut2();
    input1();
    input2();



}

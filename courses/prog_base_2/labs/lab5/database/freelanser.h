#ifndef FREELANSER_H_INCLUDED
#define FREELANSER_H_INCLUDED
#define STRL 1000

typedef struct freelancer_s
{
    unsigned int id;
    char name[STRL];
    char surname[STRL];
    double salary;
    int completedProjects;
    char birthDate[STRL];

} freelancer_t;

void freelancerPrint(freelancer_t * fl);

freelancer_t * freelanserNew();



#endif // FREELANSER_H_INCLUDED

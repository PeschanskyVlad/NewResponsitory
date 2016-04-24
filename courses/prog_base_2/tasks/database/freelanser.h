#ifndef FREELANSER_H_INCLUDED
#define FREELANSER_H_INCLUDED

typedef struct freeLanser_s
{
    unsigned int id;
    char name[100];
    char surname[100];
    double salary;
    int completedProjects;
    char birthDate[100];

} freeLanser_t;

void freeLanser_print(freeLanser_t * fl);



#endif // FREELANSER_H_INCLUDED

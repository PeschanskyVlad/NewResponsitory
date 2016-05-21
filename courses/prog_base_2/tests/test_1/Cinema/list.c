#include "list.h"
#define constSize 100

#define noProject 404


struct factory{
    char name[constSize];
    char admin[constSize];
    worker_t workers[constSize];
    int quantityWorkers;
    progect_t progects[constSize];
    int quantityProgects;

};

struct worker{
 char name[constSize];

 int progectId;
};

struct progect{
    char name[constSize];
    int id;
    worker_t workers[constSize];
    int quantityWorkers;
};

factory_t factory_new(const char * aName){

    factory_t self = (factory_t)malloc(sizeof(struct factory));
    strcpy(self->name, aName);

    self->quantityWorkers=0;
    self->quantityProgects=0;

    return self;
}

void setAdmin(const char * aName, factory_t self){
    strcpy(self->admin, aName);
}

char  *getAdmin(factory_t self){
    return self->admin;
}

void newWorker(factory_t factory,const char * aName){
    worker_t self = (worker_t)malloc(sizeof(struct worker));
    self->progectId = noProject;
    strcpy(self->name, aName);

    factory->workers[factory->quantityWorkers]=self;
    factory->quantityWorkers++;
}

void getWorkers(factory_t self){
printf("\nThe company employed %i workers.\n",self->quantityWorkers);
for (int i=0;i<self->quantityWorkers;i++){
    printf("Worker %i:\n%s, working on a draft with id %i.\n",i,self->workers[i]->name,self->workers[i]->progectId);
}
}

void addWorkertoProgect(const char * aName, int addedProjectId,factory_t self){

    int key=0;
    int tmp=0;

    for (int i=0;i<self->quantityProgects;i++){
    if(self->progects[i]->id ==addedProjectId){key++;tmp++;}
    }
    if(key==0){
        return;
    }


    for (int i=0;i<self->quantityWorkers;i++){
        if(strcmp(aName,self->workers[i]->name)==0){
            if(self->workers[i]->progectId==noProject){
              self->workers[i]->progectId=addedProjectId;

              //self->progects[tmp]->workers[self->progects[tmp]->quantityWorkers]=self->workers[i]; Эти строки крашат прогу.
             // self->progects[tmp]->quantityWorkers++;
              return;
            }
            return;
        }
    }


}

void newProject(const char * aName,int id,factory_t factory){

progect_t self = (progect_t)malloc(sizeof(struct progect));
strcpy(self->name, aName);
self->id = id;
self->quantityWorkers =0;
//self->workers[100]=(worker_t)malloc(sizeof(struct worker)*100);
factory->progects[factory->quantityProgects]=self;
factory->quantityProgects++;
}

void getProjects(factory_t self){
printf("\nThe company %s is working on %i projects.\n",self->name,self->quantityProgects);
for (int i=0;i<self->quantityProgects;i++){
    printf("Project %i:\n%s\nProject id: %i\nAmount of workers: %i",i,self->progects[i]->name,self->progects[i]->id,self->progects[i]->quantityWorkers);


}
puts("");
}






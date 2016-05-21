#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

typedef struct factory * factory_t;
typedef struct worker * worker_t;
typedef struct progect * progect_t;

factory_t factory_new(const char * aName);
void newWorker(factory_t self,const char * aName);
void newProject(const char * aName,int id,factory_t self);

void setAdmin(const char * aName, factory_t self);
void addWorkertoProgect(const char * aName, int addedProjectId,factory_t self);

char * getAdmin(factory_t self);
void getWorkers(factory_t self);
void getProjects(factory_t self);





#endif // LIST_H_INCLUDED

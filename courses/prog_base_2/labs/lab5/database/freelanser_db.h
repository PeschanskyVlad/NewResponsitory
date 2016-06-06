#ifndef FREELANSER_DB_H_INCLUDED
#define FREELANSER_DB_H_INCLUDED
#pragma once
#include <stdlib.h>
#include <time.h>
#include "freelanser.h"
#define FILE_NAME "freelancers.db"
#include "list.h"
#include <sqlite3.h>

typedef struct freeLanser dataBase;

dataBase * createNewDatabase(const char * db_file);
void deleteDatabase(dataBase * self);


int freelancersCount(dataBase * self);

void freelancerGetNeeded(dataBase * self,List_t * list, int * K, float * salary, int * state);

void freelancerAdd(dataBase * self, int Id, const char * name,const char * surname,double salary, unsigned int completedProjects,const char * birthDate);
freelancer_t * freelancerGet(dataBase * self, unsigned int  id);

void freelancerDelete(dataBase * self, unsigned int id);

int isContaint(List_t * list,int id);


//freelancer_t * get_neededFreeLanser(dataBase * self,  float salary, int * pcount);

#endif // FREELANSER_DB_H_INCLUDED

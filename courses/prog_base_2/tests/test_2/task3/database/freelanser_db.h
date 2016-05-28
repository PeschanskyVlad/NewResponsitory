#ifndef FREELANSER_DB_H_INCLUDED
#define FREELANSER_DB_H_INCLUDED
#pragma once
#include <stdlib.h>
#include <time.h>
#include "freelanser.h"
#define FILE_NAME "freelansers.db"
#include "list.h"
#include "server.h"
#include "socket.h"
#include "server.h"

typedef struct freeLanser dataBase;

dataBase * createNewDatabase(const char * db_file);
void deleteDatabase(dataBase * self);

int count_freeLansers(dataBase * self);


void add_freeLanser(dataBase * self, freeLanser_t * des);
freeLanser_t * get_freeLanser(dataBase * self, unsigned int id);
void change_freeLanser(dataBase * self, freeLanser_t * des);
void delete_freeLanser(dataBase * self, unsigned int id);


freeLanser_t * get_neededFreeLanser(dataBase * self,  float salary, int * pcount);

#endif // FREELANSER_DB_H_INCLUDED

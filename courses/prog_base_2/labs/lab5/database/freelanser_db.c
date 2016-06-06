#include "freelanser.h"
#include "freelanser_db.h"
#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_NAME "Freelancer"
#include "list.h"


struct freeLanser {
    sqlite3 * db;
};

dataBase * createNewDatabase(const char * db_file)
{
    dataBase * self = malloc(sizeof(struct freeLanser));
    int rc = 0;

    rc = sqlite3_open(db_file, &(self->db));

    if (SQLITE_ERROR == rc) {
        printf("can't open database\n");
        exit(1);
    }
    return self;
}

void deleteDatabase(dataBase * self)
{
    sqlite3_close(self->db);
    free(self);
}


static void fill_freelanser(sqlite3_stmt * stmt, freelancer_t * fl)
{
    int id = sqlite3_column_int(stmt, 0);
    const unsigned char * name = sqlite3_column_text(stmt, 1);
    const unsigned char * surname = sqlite3_column_text(stmt, 2);
    double salary = sqlite3_column_double(stmt, 3);
    int completedProjects = sqlite3_column_int(stmt, 4);
    const unsigned char * birthDate =  sqlite3_column_text(stmt, 5);
   // puts("here");
   // puts(name);
   // puts(surname);
    strcpy(fl->name, (char *)name);
    strcpy(fl->surname, (char *)surname);
    fl->id = id;
    fl->completedProjects = completedProjects;
    fl->salary = salary;
    strcpy(fl->birthDate, (char *)birthDate);

}

int freelancersCount(dataBase * self)
{
    sqlite3_stmt * stmt = NULL;
    const char * sql = "SELECT COUNT(*) FROM " TABLE_NAME ";";

    sqlite3_prepare_v2(self->db, sql, -1, &stmt, NULL);

    int rc = sqlite3_step(stmt);
    if (SQLITE_ERROR == rc) {
        printf("can't select count\n");
        exit(1);
    }
    int count = sqlite3_column_int(stmt, 0);
    sqlite3_finalize(stmt);

    return count;
}

void freelancerGetNeeded(dataBase * self,List_t * list, int * K, float * salary, int * state)
{
    int count = 0;
    sqlite3_stmt *stmt = NULL;
    const char *sql = malloc(1000);

    switch(*state){
case 1:
    sprintf(sql, "SELECT * FROM Freelancer WHERE Salary > ?1 ;");
    break;
case 2:
    sprintf(sql, "SELECT * FROM Freelancer WHERE Salary < ?1 ;");
    break;
case 0:
default:
    sprintf(sql, "SELECT * FROM Freelancer WHERE Salary = ?1 ;");
    break;
    }


    int rc = sqlite3_prepare_v2(self->db, sql, strlen(sql) + 1, &stmt, NULL);

    sqlite3_bind_double(stmt, 1, *salary);

    if(SQLITE_OK != rc){

        return;
    }

     while(count<*K){
        rc = sqlite3_step(stmt);
        if(SQLITE_ERROR == rc){

            return;
        }
        else {
            if(SQLITE_DONE == rc){

                break;
            }

            freelancer_t * tmpFreelancer = freelanserNew();
            fill_freelanser(stmt, tmpFreelancer);
            List_add(list,List_getSize(list),tmpFreelancer);

            count++;

        }
    }

    printf("\nCount: %i\n",count);
    free(sql);
    sqlite3_finalize(stmt);


}

void freelancerGetAll(dataBase * self, List_t * list){


    sqlite3_stmt *stmt = NULL;



    int rc = sqlite3_prepare_v2(self->db, "SELECT * FROM Freelancer;", -1, &stmt, NULL);

    if(SQLITE_OK != rc){
        printf("SQLITE_ERROR = %i\n",rc);
        return;
    }
    while(1){
        rc = sqlite3_step(stmt);
        if(SQLITE_ERROR == rc){
             printf("SQLITE_ERROR = %i\n",rc);
            return;
        }
        else {
            if(SQLITE_DONE == rc){

                break;
            }
            freelancer_t * tmpFreelancer = freelanserNew();
            fill_freelanser(stmt, tmpFreelancer);
            List_add(list,List_getSize(list),tmpFreelancer);



        }
    }
    sqlite3_finalize(stmt);

}



void freelancerAdd(dataBase * self, int Id, const char * name,const char * surname,double salary, unsigned int completedProjects,const char * birthDate)
{
    int rc  = 0;
    sqlite3_stmt * stmt = NULL;
    const char *sql;
    sql = "INSERT INTO Freelancer VALUES ( ? , ? , ? ,  ? , ? , ? );";
    sqlite3_prepare_v2(self->db,sql, strlen(sql) + 1, &stmt, 0);



    rc = sqlite3_bind_int(stmt, 1, Id); if (SQLITE_OK != rc) {puts("SOLITE_ERROR on id"); return;}

    rc = sqlite3_bind_text(stmt, 2, name, strlen(name), SQLITE_STATIC); if (SQLITE_OK != rc) {puts("SOLITE_ERROR on name"); return;}

    rc = sqlite3_bind_text(stmt, 3, surname, strlen(surname), SQLITE_STATIC); if (SQLITE_OK != rc) {puts("SOLITE_ERROR on surname"); return;}

    rc = sqlite3_bind_double(stmt, 4, salary); if (SQLITE_OK != rc) {puts("SOLITE_ERROR on salary"); return;}

    rc = sqlite3_bind_int(stmt, 5, completedProjects); if (SQLITE_OK != rc) {puts("SOLITE_ERROR on completedProjects"); return;}

    rc = sqlite3_bind_text(stmt, 6, birthDate, strlen(birthDate), SQLITE_STATIC); if (SQLITE_OK != rc) {puts("SOLITE_ERROR on birthDate"); return;}

    rc = sqlite3_step(stmt); //if (SQLITE_OK != rc) {printf("SOLITE_ERROR rc = %i\n",rc); return;}
    sqlite3_finalize(stmt);
    return;
}



void freelancerDelete(dataBase * self, unsigned int id)
{
    sqlite3_stmt * stmt;
    char * sql = "DELETE FROM "TABLE_NAME" "
                 "WHERE Id = ?;";

    sqlite3_prepare_v2(self->db, sql, strlen(sql), &stmt, NULL);

    sqlite3_bind_int(stmt, 1, id);

    sqlite3_step(stmt);

    sqlite3_finalize(stmt);
    return;
}

freelancer_t * freelancerGet(dataBase * self, unsigned int id)
{

    freelancer_t * fl = NULL;

    int tmpId = id;

    sqlite3_stmt * stmt;
    char * sql = "SELECT  * FROM Freelancer "
                 "WHERE Id = ?";


    sqlite3_prepare_v2(self->db, sql, strlen(sql), &stmt, NULL);


    sqlite3_bind_int(stmt, 1, tmpId);


    sqlite3_step(stmt);
    fl = malloc(sizeof(freelancer_t));

   // fl->id = *id;
    fill_freelanser(stmt, fl);
    sqlite3_finalize(stmt);
    return fl;
}

int isContaint(List_t * list,int id){
    for(int i = 0;i<List_getSize(list);i++){
        freelancer_t * t = List_get(list,i,NULL);
        if(t->id == id){
            return i;
        }
    }
    return -1;
}






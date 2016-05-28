#include "freelanser.h"
#include "freelanser_db.h"
#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_NAME "Freelanser"


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


static void fill_freelanser(sqlite3_stmt * stmt, freeLanser_t * fl)
{
    int id = sqlite3_column_int(stmt, 0);
    const unsigned char * name = sqlite3_column_text(stmt, 1);
    const unsigned char * surname = sqlite3_column_text(stmt, 2);
    double salary = sqlite3_column_double(stmt, 3);
    int completedProjects = sqlite3_column_int(stmt, 4);
    const unsigned char * birthDate =  sqlite3_column_text(stmt, 5);



    strcpy(fl->name, (char *)name);
    strcpy(fl->surname, (char *)surname);
    fl->id = id;
    fl->completedProjects = completedProjects;
    fl->salary = salary;
    strcpy(fl->birthDate, (char *)birthDate);

}

int count_freeLansers(dataBase * self)
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

freeLanser_t * get_neededFreeLanser(dataBase * self, float salary, int * sum)
{
    int rc = 0;
    int count = 0;
    int temp_count = 0;
    freeLanser_t * designers = NULL;
    sqlite3_stmt * stmt;


    sqlite3_prepare_v2(self->db, "SELECT COUNT (*) FROM Freelanser "
                 "WHERE Salary > ? ;", -1, &stmt, 0);


    sqlite3_bind_double(stmt, 1, salary);

    rc = sqlite3_step(stmt);
    count = sqlite3_column_int(stmt, 0);
    //printf("count = %i",count);
    sqlite3_finalize(stmt);

    designers = malloc(sizeof(freeLanser_t) * count);

    rc = sqlite3_prepare_v2(self->db, "SELECT * FROM Freelanser "
                "WHERE Salary > ? ;", -1, &stmt, NULL);


    rc = sqlite3_bind_double(stmt, 1, salary);

    for(temp_count = 0; temp_count < count; temp_count++)
    {
        rc = sqlite3_step(stmt);

        fill_freelanser(stmt, &(designers[temp_count]));
    }
    *sum = temp_count;

    sqlite3_finalize(stmt);
    return designers;
}



void add_freeLanser(dataBase * self, freeLanser_t * des)
{
    int rc  = 0;
    sqlite3_stmt * stmt = NULL;

    sqlite3_prepare_v2(self->db, "INSERT INTO Freelanser (Id, Name, Surname, Salary, CompletedProjects, BirthDate) "
                 "VALUES ( ? , ? , ? ,  ? , ? , ? );", -1, &stmt, 0);

    rc = sqlite3_bind_int(stmt, 1, des->id); if (SQLITE_OK != rc) {puts("SOLITE_ERROR on id"); return;}

    rc = sqlite3_bind_text(stmt, 2, des->name, strlen(des->name), SQLITE_STATIC); if (SQLITE_OK != rc) {puts("SOLITE_ERROR on name"); return;}

    rc = sqlite3_bind_text(stmt, 3, des->surname, strlen(des->surname), SQLITE_STATIC); if (SQLITE_OK != rc) {puts("SOLITE_ERROR on surname"); return;}

    rc = sqlite3_bind_double(stmt, 4, des->salary); if (SQLITE_OK != rc) {puts("SOLITE_ERROR on salary"); return;}

    rc = sqlite3_bind_int(stmt, 5, des->completedProjects); if (SQLITE_OK != rc) {puts("SOLITE_ERROR on completedProjects"); return;}

    rc = sqlite3_bind_text(stmt, 6, des->birthDate, strlen(des->birthDate), SQLITE_STATIC); if (SQLITE_OK != rc) {puts("SOLITE_ERROR on birthDate"); return;}

    rc = sqlite3_step(stmt); //if (SQLITE_OK != rc) {printf("SOLITE_ERROR rc = %i\n",rc); return;}
    sqlite3_finalize(stmt);
    return;
}

void delete_freeLanser(dataBase * self, unsigned int id)
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

freeLanser_t * get_freeLanser(dataBase * self, unsigned int id)
{

    freeLanser_t * fl = NULL;
    sqlite3_stmt * stmt;
    char * sql = "SELECT  * FROM Freelanser "
                 "WHERE Id = ?";


    sqlite3_prepare_v2(self->db, sql, strlen(sql), &stmt, NULL);


    sqlite3_bind_int(stmt, 1, id);


    sqlite3_step(stmt);
    fl = malloc(sizeof(freeLanser_t));
    fl->id = id;
    fill_freelanser(stmt, fl);
    sqlite3_finalize(stmt);
    return fl;
}


void change_freeLanser(dataBase * self, freeLanser_t * fl)
{
    //puts("In change");
    int rc  = 0;
    sqlite3_stmt * stmt = NULL;




    rc = sqlite3_prepare_v2(self->db, "UPDATE  Freelanser SET Name = ?, Surname = ?, Salary = ?, CompletedProjects = ?, HireDate = ?"
                            "WHERE Id = ?;", -1, &stmt, 0);


    rc = sqlite3_bind_text(stmt, 1, fl->name, strlen(fl->name), SQLITE_STATIC);

    rc = sqlite3_bind_text(stmt, 2, fl->surname, strlen(fl->surname), SQLITE_STATIC);
   // puts(fl->surname);

    rc = sqlite3_bind_double(stmt, 3, (fl->salary));

    rc = sqlite3_bind_int(stmt, 4, fl->completedProjects);

    rc = sqlite3_bind_text(stmt, 5, fl->birthDate, strlen(fl->birthDate), SQLITE_STATIC);

    rc = sqlite3_bind_int(stmt, 6, fl->id);
    //printf("%i",fl->id);



    rc = sqlite3_step(stmt);
   // printf("\n%i\n",rc);
    sqlite3_finalize(stmt);

    return;
}





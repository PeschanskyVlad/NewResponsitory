#include "freelancer.h"
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <time.h>
#include <libxml/xmlmemory.h>
#define STRING_LENGTH_MAX 100


static void get_freelanser(freelanser_t * freelanser, xmlNodePtr fl);
freelanser_t * freelanserNew();

void freelancerAddParam(List_t * self,const char * name,const char * surname,const char * birthdate,int age, float salary,const char * company,const char * companyPosition){

   // puts(company);

   // printf("Name: %s\nSurname: %s\nBirthdate: %s\nAge: %i\nSalary %.2f\nCompany: %s\nCompany position %s\n", name, surname, birthdate, age, salary, company, companyPosition);
      freelanser_t *  tmpFreelancer = freelanserNew();
      strcpy(tmpFreelancer->name,name);
      strcpy(tmpFreelancer->surname,surname);

      strcpy(tmpFreelancer->pD->birthdate,birthdate);
      tmpFreelancer->pD->age=age;
      tmpFreelancer->pD->workExperience=salary;

       strcpy(tmpFreelancer->pos->company,company);
       strcpy(tmpFreelancer->pos->name,companyPosition);
      List_add(self,List_getSize(self),tmpFreelancer);


}

void freelansersAdd(List_t * freelansers, const char * fileName)
{

    int i=0;
    LIBXML_TEST_VERSION

    xmlDocPtr file;
    xmlNodePtr cur;

    file = xmlParseFile(fileName);

    if (file == NULL ) {
        fprintf(stderr,"Missing file!\n");
        return;
    }
    cur = xmlDocGetRootElement(file);
    if (cur == NULL) {
        fprintf(stderr,"Useless file!\n");
        xmlFreeDoc(file);
        return;
    }

    xmlNodePtr fl = cur->children->next;
    int count = numberOfElements(fileName);
    freelanser_t * tmpFreelancer[count];

    for(int i = 0; i < count && fl != NULL; fl = fl->next, i++)
    {
        if(fl->type != XML_ELEMENT_NODE)
        {
            i--;
            continue;
        }

        tmpFreelancer[i] = freelanserNew();
        get_freelanser(tmpFreelancer[i], fl);

        List_add(freelansers,i,tmpFreelancer[i]);
    }
}

position_t * freelanserNewPosition(){
    position_t * self = malloc(sizeof(struct position));
    self->company = malloc(sizeof(char)*100);
    self->name = malloc(sizeof(char)*100);
    return self;
}

personalData_t * freelanserNewPersonalData(){
    personalData_t * self = malloc(sizeof(struct personalData));
    self->birthdate = malloc(sizeof(char)*100);
    return self;
}


freelanser_t * freelanserNew(){

    freelanser_t * self = malloc(sizeof(struct freelanser));


    self -> pos = freelanserNewPosition();
    self -> pD = freelanserNewPersonalData();
    return self;
}


int numberOfElements(const char * fileName){
 int count = 0;
    xmlDocPtr file;
     file = xmlParseFile(fileName);
    xmlNode * xRootEl;
    xRootEl = xmlDocGetRootElement(file);
    for(xmlNode * xCur = xRootEl->children; NULL != xCur ;xCur = xCur->next){
        if(XML_ELEMENT_NODE == xCur->type){
            count++;
        }
    }
    return count;
}


static void copy_xmlcontents_to_buffer(char * buffer, xmlNodePtr data)
{
    char * content = xmlNodeGetContent(data);
    strcpy(buffer, content);
    //xmlFree(content);
}

void freelansersPrint(freelanser_t * freelanser){

    printf("name : %s\n", freelanser->name);
        printf("surname : %s\n", freelanser->surname);
        printf("position(company : %s) : %s\n", freelanser->pos->company, freelanser->pos->name);
        printf("age : %i\n",freelanser->pD->age);
        printf("workExperience : %.2f\n",freelanser->pD->workExperience);
        printf("birthdate : %s\n",freelanser->pD->birthdate);//ctime(&(freelanser->pD->birthdate)));
        puts("\n");
}




static void get_freelanser(freelanser_t * freelanser, xmlNodePtr fl)
{
    xmlNodePtr fl_child = fl->children->next;
    do
    {
        if(fl_child->type != XML_ELEMENT_NODE)
            continue;

        if(xmlStrEqual(fl_child->name, "name"))
        {
            copy_xmlcontents_to_buffer(freelanser->name, fl_child);
        }

        else if(xmlStrEqual(fl_child->name, "surname"))
        {
            copy_xmlcontents_to_buffer(freelanser->surname, fl_child);
        }


        else if(xmlStrEqual(fl_child->name, "position"))
        {
            copy_xmlcontents_to_buffer(freelanser->pos->name, fl_child);
            copy_xmlcontents_to_buffer(freelanser->pos->company, fl_child);

            char * company = xmlGetProp(fl_child, "company");
            strcpy(freelanser->pos->company, company);
            free(company);
        }

        else if(xmlStrEqual(fl_child->name, "personalData"))
        {
            xmlNodePtr des_child_stats = fl_child->children->next;
            do
            {
                if(des_child_stats->type != XML_ELEMENT_NODE)
                    continue;

                if(xmlStrEqual(des_child_stats->name, "age"))
                {
                    char buffer[STRING_LENGTH_MAX];
                    copy_xmlcontents_to_buffer(buffer, des_child_stats);
                    int age = atoi(buffer);
                    freelanser->pD->age = age;
                }

                else if(xmlStrEqual(des_child_stats->name, "workExperience"))
                {
                    char buffer[STRING_LENGTH_MAX];
                    copy_xmlcontents_to_buffer(buffer, des_child_stats);
                    float workExperience = atof(buffer);
                    freelanser->pD->workExperience = workExperience;
                }

                else if(xmlStrEqual(des_child_stats->name, "birthdate"))
                {/*
                    struct tm birthdate;
                    memset(&birthdate, 0, sizeof(struct tm));
                    char buffer[STRING_LENGTH_MAX];
                    copy_xmlcontents_to_buffer(buffer, des_child_stats);
                    sscanf(buffer, "%i-%i-%i", &(birthdate.tm_year), &(birthdate.tm_mon), &(birthdate.tm_mday));
                    birthdate.tm_year -= 1900;
                    birthdate.tm_mon -= 1;
                    freelanser->pD->birthdate = mktime(&birthdate);*/
                    copy_xmlcontents_to_buffer(freelanser->pD->birthdate, des_child_stats);


                }
            }while((des_child_stats = des_child_stats->next) != NULL);
        }
    }while((fl_child = fl_child->next)!=NULL);
}

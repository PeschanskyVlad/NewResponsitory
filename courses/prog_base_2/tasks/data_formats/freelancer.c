#include "freelancer.h"
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <time.h>
#include <libxml/xmlmemory.h>


static void get_freelanser(freelanser * freelanser, xmlNodePtr fl);

void find_freelansers(freelanser * freelansers, size_t required_quantity)
{
    LIBXML_TEST_VERSION

    xmlDocPtr file;
    xmlNodePtr cur;
    file = xmlParseFile("freelancer.xml");


    cur = xmlDocGetRootElement(file);


    xmlNodePtr fl = cur->children->next;
    for(int i = 0; i < required_quantity && fl != NULL; fl = fl->next, i++)
    {
        if(fl->type != XML_ELEMENT_NODE)
        {
            i--;
            continue;
        }
        get_freelanser(&freelansers[i], fl);
    }
    xmlFreeDoc(file);
}

static void copy_data(char * buffer, xmlNodePtr data)
{
    char * content = xmlNodeGetContent(data);
    strcpy(buffer, content);
}


static void get_freelanser(freelanser * freelanser, xmlNodePtr fl)
{
    xmlNodePtr fl_child = fl->children->next;
    do
    {
        if(fl_child->type != XML_ELEMENT_NODE)
            continue;

        if(xmlStrEqual(fl_child->name, "name"))
        {
            copy_data(freelanser->name, fl_child);
        }

        else if(xmlStrEqual(fl_child->name, "surname"))
        {
            copy_data(freelanser->surname, fl_child);
        }


        else if(xmlStrEqual(fl_child->name, "position"))
        {
            copy_data(freelanser->pos.name, fl_child);
            copy_data(freelanser->pos.company, fl_child);

            char * company = xmlGetProp(fl_child, "company");
            strcpy(freelanser->pos.company, company);
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
                    char buffer[100];
                    copy_data(buffer, des_child_stats);
                    int age = atoi(buffer);
                    freelanser->pD.age = age;
                }

                else if(xmlStrEqual(des_child_stats->name, "workExperience"))
                {
                    char buffer[100];
                    copy_data(buffer, des_child_stats);
                    float workExperience = atof(buffer);
                    freelanser->pD.workExperience = workExperience;
                }

                else if(xmlStrEqual(des_child_stats->name, "birthdate"))
                {
                    copy_data(freelanser->pD.birthdate, des_child_stats);

                }
            }while((des_child_stats = des_child_stats->next) != NULL);
        }
    }while((fl_child = fl_child->next)!=NULL);
}

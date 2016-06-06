#ifndef XML_H_INCLUDED
#define XML_H_INCLUDED
#include "list.h"
#include "freelancer.h"

char * xmlFreelancersToMessage(List_t *list);
char * xmlFreelancerToMessage(freelanser_t *self, int id);

#endif // XML_H_INCLUDED

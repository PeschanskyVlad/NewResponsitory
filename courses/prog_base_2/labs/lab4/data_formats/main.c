#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "freelancer.h"
#include <libxml/parser.h>
#include <libxml/tree.h>
#include "list.h"
#include "server.h"

int main() {

    List_t freelansers = List_new();
    freelansersAdd(freelansers,"freelancer.xml");
    //List_remove(freelansers,0,NULL);

   // printf("%i",List_getSize(freelansers));



    serverStart(freelansers);


	return 0;
}



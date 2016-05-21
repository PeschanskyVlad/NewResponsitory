#include <stdlib.h>  // !
#include <stdarg.h>  // !
#include <stddef.h>  // !
#include <setjmp.h>  // !

#include <cmocka.h>
#include "list.h"





int main(void) {

    factory_t Roshen = factory_new("ROSHEN");

    setAdmin("mrChocolate",Roshen);
    printf("%s\n",getAdmin(Roshen));

    newWorker(Roshen,"Tom");
    newWorker(Roshen,"Taras");

    newProject("Tort",10,Roshen);

    getWorkers(Roshen);
    getProjects(Roshen);

    addWorkertoProgect("Tom",10,Roshen);

    getProjects(Roshen);


}

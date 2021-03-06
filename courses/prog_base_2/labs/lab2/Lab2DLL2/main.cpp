#include "main.h"
#include <stdio.h>
#include <stdlib.h>


bool DLL_EXPORT check(Queue_t queue)
{
    if(Queue_getSum(queue)>100){
           return true;

    }
     return false;

}

void DLL_EXPORT react(Queue_t queue){
    while(Queue_getSum(queue)>50){
            int temp=Queue_dequeue(queue);
            if(temp>0){
                temp=-temp;
            }
            Queue_enqueue(queue,temp);
        }
}


extern "C" DLL_EXPORT BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            // attach to process
            // return FALSE to fail DLL load
            break;

        case DLL_PROCESS_DETACH:
            // detach from process
            break;

        case DLL_THREAD_ATTACH:
            // attach to thread
            break;

        case DLL_THREAD_DETACH:
            // detach from thread
            break;
    }
    return TRUE; // succesful
}

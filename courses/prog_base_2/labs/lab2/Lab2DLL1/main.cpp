#include "main.h"

// a sample exported function
bool DLL_EXPORT check(Queue_t queue)
{
    if(Queue_tail(queue)<0){
     return true;
    }
     return false;

}

void DLL_EXPORT react(Queue_t queue){
    int tempSize=Queue_getSize(queue);
    for(int i=0;i<tempSize-1;i++){
            Queue_dequeue(queue);
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

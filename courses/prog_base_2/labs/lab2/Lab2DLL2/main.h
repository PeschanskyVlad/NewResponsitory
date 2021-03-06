#ifndef __MAIN_H__
#define __MAIN_H__

#include <windows.h>

/*  To use this exported function of dll, include this header
 *  in your project.
 */

#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif


#ifdef __cplusplus
extern "C"
{
#endif

#include "queue.h"
bool DLL_EXPORT check(Queue_t queue);
void DLL_EXPORT react(Queue_t queue);

#ifdef __cplusplus
}
#endif

#endif // __MAIN_H__

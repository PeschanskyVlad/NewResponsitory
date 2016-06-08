#include <stdlib.h>
#include <stdio.h>

int compare(char self)
{
     if(self == '0' || self == '2' ||self == '4' || self == '6'){
        return 1;
    }

   if(self == '1' || self == '3' || self == '5' ||self == '7'){
        return 2;
    }
}


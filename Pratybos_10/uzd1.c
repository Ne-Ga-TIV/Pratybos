#include <stdlib.h>


size_t myStrLen(const char *str)
{
    size_t len = 0;
    for(; *str; str++, len++)
        ;

    return len;
}

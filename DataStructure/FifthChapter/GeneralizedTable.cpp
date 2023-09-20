
#include "..\header\unity.h"

typedef enum
{
    ATOM,
    LIST
} ELemTag;
typedef int AtomType;

typedef struct GLNode
{
    ELemTag tag;
    union
    {
        AtomType atom;
        struct
        {
            struct GLNode *hp, *tp;
        } ptr;
    };
} *GList;
#include "Typedef.h"
typedef struct{
    uint32 cost;
    uint32 supplier;
}PartInfo;
typedef struct{
    uint32 n_parts;
    struct SUBASSYPART{
        uint8 partno[10];
        uint16 quan;
    }*part;
}SubassyInfo;
typedef enum{
    PART,
    SUBASSY
}Type;
typedef struct{
    uint8 partno[10];
    uint32 quan;
    Type type;
    union{
        PartInfo *part;
        SubassyInfo *subassy;
    }info;
}InvRec;

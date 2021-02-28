#include "Inventor.h"
InvRec *CreateSubassyRecord(uint32 n_parts)
{
    InvRec *new_rec;
    //为new_rec分配空间
    new_rec = (InvRec)malloc(sizeof(InvRec));
    if (NULL != new_rec)
    {
        new_rec->info.subassy = (SubassyInfo *)malloc(sizeof(SubassyInfo));
        if (NULL != new_rec->info.subassy)
        {
            //为零件获取一个足够大的数组
            new_rec->info.subassy->part = (struct SUBASSYPART *)malloc(n_parts * 
                sizeof(struct SUBASSYPART));
            if (new_rec->info.subassy->part != NULL)
            {
                //获取内存，填充我们已经知道的字段，然后返回
                new_rec->type = SUBASSY;
                new_rec->info.subassy->n_parts = n_parts;
                return new_rec;
            }
            //内存已用完，释放我们原先分配的内存
            free(new_rec->info.subassy);
        }
        free(new_rec);
    }
    return NULL;
}
void DiscardInventorRecord(InvRec *record)
{
    switch(record->type)
    {
    //删除记录中的变体部分
        case PART:
            free(record->info.part);
            break;

        case SUBASSY:
            free(record->info.subassy->part);
            free(record->info.subassy);
    }
    //删除记录的主体部分
    free(record);
}

InvRec *CreateSubassyRecord1(uint32 n_parts)
{
    InvRec *ptrInvRec;
    ptrInvRec = (InvRec *)malloc(sizeof(InvRec));
    if (NULL != ptrInvRec)
    {
        ptrInvRec->info.subassy = (SubassyInfo *)malloc(sizeof(SubassyInfo));
        if (NULL != ptrInvRec->info.subassy)
        {
            ptrInvRec->info.subassy->part = (struct SUBASSYPART)malloc(sizeof(struct SUBASSYPART));
            if (NULL != ptrInvRec->info.subassy->part)
            {
                ptrInvRec->info.type = SUBASSY;
                ptrInvRec->info.subassy->n_parts = n_parts;
                return ptrInvRec;
            }
            free(ptrInvRec->info.subassy);
        }
        free(ptrInvRec);
    }
    return NULL;
}
void DiscardInventorRecord1(InvRec *record)
{
    switch (record->type)
    {
        case SUBASSY:
            free(record->info.subassy->part);
            free(record->info.subassy);
            break;
        case PART:
            free(record->info.part);
            break;
    }
    free(record);
}

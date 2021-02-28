#include "DLink.h"

void dlink_init(dlink_t *dlink)
{
    dlink->head.prev = dlink->head.next = &dlink->head;
}

u32 dlink_is_empty(dlink_t *dlink)
{
    return (dlink->head.prev == &dlink->head) ? 1 : 0;
}

void dlink_move(dlink_t *dlink_dst, dlink_t *dlink_src)
{
    if (dlink_is_empty(dlink_src))
    {
        dlink_init(dlink_dst);
    }
    else
    {
        //list head pointers to the new head
        dlink_src->head.next->prev = &dlink_dst->head;
        dlink_src->head.prev->next = &dlink_dst->head;
        dlink_dst->head.prev = dlink_src->head.prev;
        dlink_dst->head.next = dlink_src->head.next;
        dlink_init(dlink_src);
    }
}

void dlink_insert_after(dlink_entry_t *t, dlink_entry_t *entry)
{
    dlink_entry_t *_plink = t;
    entry->prev = t;
    entry->next = t->next;
    _plink->next->prev = entry;
    _plink->next = entry;
    
}

void dlink_push(dlink_t *dlink, dlink_entry_t *entry)
{
    dlink_insert_after(&dlink->head, entry);
}

void dlink_push_tail(dlink_t *dlink, dlink_entry_t *entry)
{
    dlink_insert_after(dlink->head.prev, entry);
}

void dlink_remove_entry(dlink_entry_t *entry)
{
    dlink_entry_t *_plink = entry->prev;
    dlink_entry_t *_nlink = entry->next;
    _plink->next = entry->next;
    _nlink->prev = entry->prev;
    entry->prev = NULL;
    entry->next = NULL;
}

dlink_entry_t * dlink_pop(dlink_t *dlink)
{
    if (dlink_is_empty(dlink))
    {
        return NULL;
    }
    else
    {
        dlink_entry_t *entry = dlink->head.next;
        dlink_remove_entry(entry);
        return entry;
    }
}

dlink_entry_t * dlink_peek_head(dlink_t *dlink)
{
    if (dlink_is_empty(dlink))
    {
        return NULL;
    }
    return dlink->head.next;
}

dlink_entry_t * dlink_peek_tail(dlink_t *dlink)
{
    if (dlink_is_empty(dlink))
    {
        return NULL;
    }
    return dlink->head.prev;
}

dlink_entry_t * dlink_pop_tail(dlink_t *dlink)
{
    if (dlink_is_empty(dlink))
    {
        return NULL;
    }
    else
    {
        dlink_entry_t *entry = dlink->head.prev;
        dlink_remove_entry(entry);
        return entry;
    }
}






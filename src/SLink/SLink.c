#include "SLink.h"
//从tail挂链
void slink_push_tail(slink_head_t *head, slink_entry_t *entry)
{
    if (head->first == NULL)
    {
        head->first = entry;
    }
    else
    {
        head->last->next = entry;
    }
    head->last = entry;
    head->last->next = NULL;
}
//从head挂链
void slink_push_head(slink_head_t *head, slink_entry_t *entry)
{
    if (head->last == NULL)
    {
        head->last = entry;
        head->first = entry;
        head->last->next = NULL;
    }
    else
    {
        entry->next = head->first;
        head->first = entry;
    }
}
//获取某一个entry，然后从link里面摘链
void slink_remove_entry(slink_head_t *head, slink_entry_t *entry)
{
    slink_entry_t *s = head->first;
    slink_entry_t *pre = (slink_entry_t *)head;

    while (s)
    {
        if (s == entry)
        {
            pre->next = s->next;
            s->next = NULL;
            if (s == head->last)
            {
                head->last = (pre == (slink_entry_t *)head) ? NULL : pre;
            }
            break;
        }
        pre = s;
        s = s->next;
    }
}
//从link head摘链
slink_entry_t *slink_remove_first(slink_head_t *head)
{
    slink_entry_t *f = head->first;

    if (f)
    {
        head->first = f->next;
        if (head->last == f)
        {
            head->last = head->first; // head->last and head->first both should be NULL
        }
    }

    return f;
}

//获取link first node
slink_entry_t *slink_get_first(slink_head_t *head)
{
    return head->first;
}

//link复制
void slink_move(slink_head_t *dst, slink_head_t *src)
{
    dst->first = src->first;
    dst->last  = src->last;
    slink_head_init(src);
}



































#ifndef _DOUBLE_LINKED_LIST
#define _DOUBLE_LINKED_LIST

#include "Type.h"

/************************************double link list**********************************/
typedef struct _dlink_entry_t{
    struct _dlink_entry_t *prev;
    struct _dlink_entry_t *next;
}dlink_entry_t;

typedef struct _dlink_t{
    dlink_entry_t head;
}dlink_t;

#define dlink_foreach(dlink, entry)   \
    for                               \
    (                                 \
        (entry) = (dlink)->head.next; \
        (entry) != &(dlink)->head;    \
        (entry) = (entry)->next       \
    )

#define dlink_foreach_safe(dlink, entry, entry2)               \
    for                                                        \
    (                                                          \
        (entry) = (dlink)->head.next, (entry2) = (entry)->next;\
        (entry) != &(dlink)->head;                             \
        (entry) = (entry2), (entry2) = (entry)->next           \
    )

#define dlink_foreach_reverse(dlink, entry) \
    for                                     \
    (                                       \
        (entry) = (dlink)->head.prev;       \
        (entry) != &(dlink)->head;          \
        (entry) = (entry)->prev             \
    )

#ifndef field_offset
#define field_offset(type, field) ((unsigned int) &(((type *) 0)->field))
#endif

#ifndef container_of //获取entry对应节点的首地址
#define container_of(address, type, field) \
    ((type *) ((char *)(address) - (char *)(&((type *) 0)->field)))
#endif



void dlink_init(dlink_t *dlink);
u32 dlink_is_empty(dlink_t *dlink);
void dlink_move(dlink_t *dlink_dst, dlink_t *dlink_src);
void dlink_insert_after(dlink_entry_t *t, dlink_entry_t *entry);
void dlink_push(dlink_t *dlink, dlink_entry_t *entry);
void dlink_push_tail(dlink_t *dlink, dlink_entry_t *entry);
void dlink_remove_entry(dlink_entry_t *entry);
dlink_entry_t * dlink_pop(dlink_t *dlink);
dlink_entry_t * dlink_peek_head(dlink_t *dlink);
dlink_entry_t * dlink_peek_tail(dlink_t *dlink);
dlink_entry_t * dlink_pop_tail(dlink_t *dlink);



















#endif

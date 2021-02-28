#pragma once
/**************************single link************************/

//typedef
typedef struct _slink_entry_t{
    struct _slink_entry_t *next;
}slink_entry_t;

typedef struct _slink_head_t{
    slink_entry_t *first;
    slink_entry_t *last;
}slink_head_t;

//define
#define slink_head_init(head) \
    do                            \
    {                             \
        (head)->first = NULL;     \
        (head)->last  = NULL;     \
    }while(0);

#define slink_init(head) slink_head_init(head)
#define slink_is_empty(head) ((head)->first == NULL)
#define slink_is_not_empty(head) (!slink_is_empty(head))
#define slink_pop(head) slink_remove_first(head)

#define slink_foreach(head, entry) \
    for                            \
    (                              \
        (entry) = (head)->next;    \
        (entry) != 0;              \
        (entry) = (entry)->nex     \
    )

//func declaration
extern void slink_push_tail(slink_head_t head, slink_entry_t entry);
extern void slink_push_head(slink_head_t head, slink_entry_t entry);
extern void slink_remove_entry(slink_head_t head, slink_entry_t entry);
extern slink_entry_t *slink_remove_first(slink_head_t head);
extern slink_entry_t *slink_get_first(slink_head_t head);
extern void slink_move(slink_head_t *dst, slink_head_t *src);






















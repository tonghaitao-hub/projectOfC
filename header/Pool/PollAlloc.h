#pragma once
typedef struct _pool_ent_t{
    struct _pool_ent_t *next;
}pool_ent_t;

typedef struct _pool_t{
    struct _pool_ent_t *free;
    void               *base;
#ifdef POOL_DEBUG
    u32 ent_sz;//pool element size, debugging purpose
    u32 nr_ent;//maximum number of elements, debugging purpose
    u32 nr_got;//number of element already allocated, debugging purpose
#endif
}pool_t;


void *pool_get(pool_t *pool);
void pool_put(pool_t *pool, void *p);
void pool_init(pool_t *pool, u32 ent_sz, u32 nr_ent, void *buf);









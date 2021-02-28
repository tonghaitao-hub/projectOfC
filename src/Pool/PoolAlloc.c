void *pool_get(pool_t *pool)
{
    pool_ent_t *ent = pool->free;
    if (ent)
    {
        pool->free = ent->next;
        
        #ifdef POOL_DEBUG
        pool->nr_got++;
        #endif
    }
    return ent;
}

void pool_put(pool_t *pool, void *p)
{
    pool_ent_t *ent = p;
    
    #ifdef POOL_DEBUG
    pool->nr_got--;
    #endif
    
    ent->next = pool->free;
    pool->free = ent;
}

void pool_init(pool_t *pool, u32 ent_sz, u32 nr_ent, void *buf)
{
    pool_ent_t *ent = (pool_ent_t *)buf;

    pool->free = ent;
    pool->base = buf;

    #ifdef POOL_DEBUG
    pool->nr_ent = nr_ent;
    pool->ent_sz = ent_sz;
    pool->nr_got = 0;
    #endif

    while(nr_ent)
    {
        ent->next = (pool_ent_t *)((char *)ent + ent_sz);
        ent = ent->next;
        nr_ent--;
    }
    ent->next = 0;
}




































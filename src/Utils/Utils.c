void memory_set(void *_dst, u8 pattern, u32 nr_bytes)
{
    u8 *dst = (u8 *)_dst;
    while(nr_bytes--)
    {
        *dst++ = pattern;
    }
}



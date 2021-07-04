#include "Thread.h"

bool sum(float arr[], u32 len, double *sum_ptr)
{
    u32 block_size = len / MAX_THREADS;
    if (block_size < MIN_BLOCK_SIZE)
        block_size = MIN_BLOCK_SIZE;
    sum_arg args = {arr, len, block_size, 0.0};
    if (parallel_sum(&args))
    {
        *sum_ptr = args.sum;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

u32 parallel_sum(void *arg)
{
    sum_arg *argp = (sum_arg *)arg;
    if (argp->len <= argp->block_size)
    {
        for (u32 i = 0; i < argp->len; ++i)
        {
            argp->sum += argp->start[i];
        }
        return TRUE;
    }
    else
    {
        u32 mid = argp->len / 2;
        sum_arg arg2 = {argp->start+mid, argp->len-mid, argp->block_size, 0};
        argp->len = mid;
        thread_t th;
        u32 res = 0;
        if (thread_create(&th, parallel_sum, arg) != thread_success)
        {
            return FALSE;
        }


        if (!parallel_sum(&arg2))
        {
            thread_detach(th);
            return FALSE;
        }
        thread_join(th, &res);
        if (!res)
        {
            return FALSE;
        }

        argp->sum += arg2.sum;
        return TRUE;
    }
}



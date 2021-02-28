#include <threads.h>
#include <stdbool.h>

#define MAX_THREADS           8   //所创建线程数量的最大值
#define MIN_BLOCK_SIZE        100 //一个数组块的最小值
#define thread_create(thr, func, arg)       thrd_create(thr, func, arg)
#define thread_join(thr, result)            thrd_join(thr, result)
#define thread_detach(thr)                  thrd_detach(thr)
#define thread_current()                    thrd_current()
#define thread_equal(thr0, thr1)            thrd_equal(thr0, thr1)
#define thread_sleep(duration, remaining)   thrd_sleep(duration, remaining)
#define thread_t                            thrd_t
#define thread_success                      thrd_success


typedef struct _sum_arg{
    float *start;
    u32    len;
    u32    block_size;
    double sum;
}sum_arg;


u32 parallel_sum(void *arg); //线程函数的原型








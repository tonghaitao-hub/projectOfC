#include "Queue.h"
#include "Stack.h"
#include "Sales.h"
#include "Compare.h"
#include "ReviewProgramer.h"
//extern uint32 gArray[];
extern uint32 *a;
extern uint32 b[];
extern uint32 c[];
int main()
{
#if ENLINKQUEUE
    int temp;
    ElemType e;
    LinkQueue Q;
    LinkQueue *linkQue = &Q;
    InitLinkQueue(linkQue);
    for (temp = 0; temp < 10; temp++)
    {
        e = temp;
        EnLinkQueue(linkQue, e);
        printf("EnLinkQueue, e = %d\n", e);
    }
    for (temp = 0; temp < 10; temp++)
    {
        DeLinkQueue(linkQue, &e);
        printf("DeLinkQueue, e = %d\n", e);
    }
    DestroyLinkQueue(linkQue);
    printf("destroy linkqueue\n");
#elif ENSQQUEUE
    int temp;
    int queueLength;
    ElemType e;
    SqQueue Q;
    SqQueue *sqQue = &Q;
    InitSqQueue(sqQue);
    for (temp = 0; temp < 10; temp++)
    {
        e = temp * temp;
        EnSqQueue(sqQue, e);
        printf("EnSqQueue, e = %d\n", e);
    }
    queueLength = SqQueueLength(sqQue);
    printf("SqQueueLength = %d\n", queueLength);
    for (temp = 0; temp < 10; temp++)
    {
        DeSqQueue(sqQue, &e);
        printf("DeSqQueue, e = %d\n", e);
    }
    queueLength = SqQueueLength(sqQue);
    printf("SqQueueLength = %d\n", queueLength);
#elif ENSTACK
    int temp;
    ElemType e;
    Stack S;
    Stack *stack = &S;
    InitStack(stack);
    for (temp = 0; temp < 10; temp++)
    {
        e = temp * 10;
        Push(stack, e);
        printf("push e = %d into stack\n", e);
    }
    for (temp = 0; temp < 10; temp++)
    {
        Pop(stack, &e);
        printf("pop e = %d out of stack\n", e);
    }
#elif ENDOULINKQUEUE
    TestDouLinkQueue();
#elif DOSHOPPING
    DoShopping();
#elif CALLBACK
    TestCallBack();
#elif ARRAYSORT
    ArraySort();
#elif GENERICSTACK
    TestGenericStack();
#elif REVIEWPROGRAMER
    //InputAndOutput();
    //(void)CallRearRange();
    //(void)CheckSum();
    //(void)GetLongestRowAndPrint();
    //int32 totalNum = 0;
    //totalNum = GetBraceNumInProgramer();
    //printf("the total num of brace is %d\n", totalNum);
    //GetTypeRange();
    //StaticOutput();
    //TestSwitchDefault();
    //CallCalcSqrRoot();
/*10*/
    //uint32 max;
    //scanf("%d", &max);
    //CalcPrimesInRange(max);
/*11*/
#if 0
    uint32 max;
    scanf("%d", &max);
    CalcPrimesInPrimes(max);
#endif
/*12*/
#if 0
    uint32 a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    IsWhatTriangle(a, b, c);
#endif
/*13*/
#if 0
    uint8 src[20] = "ABCDEFGHIJK\n\0";
    uint8 dst[20] = "";
    uint32 n = 13;
    printf("\033[47;34m dst:%s, dst len:%d, sizeof:%d\n\033[0m", dst, strlen((const int8*)dst), sizeof(dst));
    CopynChar(src, dst, n);
    printf("dst:%s, dst len:%d, sizeof:%d\n", dst, strlen((const int8*)dst), sizeof(dst));
#endif 
/*14*/
#if 0
    PrintNeighborSame();
#endif
/*15*/
#if 0
    int8 src[30] = "abcdefghijklmnopqrstuvwxyzABC";
    int8 dst[30] = "";
    uint32 len = 0;
    len = SubStr(dst, src, 3, 5);
    printf("dst[30]: %s\n", dst);
    printf("len: %d\n", len);
#endif
/*16*/
#if 0
    int8 string[] = "baby    ,I  love   you\n";
    printf("org string: %s\n", string);
    DeleteBlank(string);
    printf("new string: %s\n", string);
#endif
#if 0//sizeof/隐式类型转换
    int8 a = 127;
    int8 b = 128;
    int8 c = 0;
    int8 d;
    d = a + b;
    c = sizeof(a = b+1);
    printf("a.%d, b.%d, c.%d, d.%d\n", a, b, c, d);

    int e = 9393945;
    float f = e;
    printf("e.%d, d.%f\n", e, f);
    
    int g = 0, h = 0, i = 0;
    h = g + g++;
    printf("g + g++ = %d, g.%d\n", h, g);
    g = 0;
    h = g + ++g;
    printf("g + ++g = %d, g.%d\n", h, g);
    g = 0;
    h = g + (++g);
    printf("g + (++g) = %d, g.%d\n", h, g);
    g = 0;
    i = ++g + g;
    printf("++g + g = %d, g.%d\n", i, g);
    g = 0;
    h = g++ + g;
    printf("g++ + g = %d, g.%d\n", h, g);
    g = 0;
    h = g+++g;
    printf("g+++g = %d, g.%d\n", h, g);
#endif
#if 0//三目运算符实现闰年计算
    uint32 year;
    uint8 leap_year = 0;
    scanf("%d %d", &year, &leap_year);
    printf("leap_year.%d\n", leap_year);
    leap_year = (year % 4 == 0) ? ((year % 100 != 0) || (year % 400 == 0) ? TRUE : FALSE) : FALSE; 
    printf("year %d %s leap year\n", year, leap_year ? "is" : "is not");
#endif
#if 0//运算符优先级
    int32 b = -25;
    int32 a = 10;
    int32 c;
    int32 d;
    int32 e;
    int32 f;
    int32 g;
    int32 h = 0;
    c = a | ((b<<a) & b);// |的优先级低于&
    d = (a | (b<<a)) & b;
    e = !~b++;
    f = !(~b++);
    g = ~(!b++);
    h = -25 << 1;
    printf("%X, %d\n", c, c);
    printf("%X, %d\n", d, d);
    printf("%d\n", e);
    printf("%d\n", f);
    printf("%d\n", g);
    printf("%d\n", h);
#endif
/*17*/
#if 0
    StandardInAndOutput();
#endif
/*18*/
#if 0//密码输入和加密输出
    SecretStandardInAndOutput();
#endif
/*19*/
#if 0
    uint32 dst;
    uint32 value;
    value = 15;
    dst = ReverseBits(value);
#endif
/*20*///清零和置位某一个bit
#if 0
    uint8 bitArray[4] = {0xff, 0xff, 0xff, 0xff};
    uint32 bitNumber = 3;
    int value = 1;
    printf("bf: %X, %X, %X, %X\n", bitArray[0], bitArray[1], bitArray[2], bitArray[3]);
    ClrBit(bitArray, bitNumber);
    printf("af: %X, %X, %X, %X\n", bitArray[0], bitArray[1], bitArray[2], bitArray[3]);
    SetBit(bitArray, bitNumber);
    printf("af: %X, %X, %X, %X\n", bitArray[0], bitArray[1], bitArray[2], bitArray[3]);
#endif
/*21*/
#if 0
    (void)StoreBitField(0xffff, 0x123, 15, 4);
#endif
/*22*///查找source字符串中匹配chars字符串中任何字符的第一个字符，返回它的位置
#if 0
    int8 *source = "ABCDEFG";
    int8 *chars = "OOPEEDASD";
    int8 const *ret;
    ret = FindChar(source, chars);
    printf("ret: %p\n", ret);
#endif
/*23*///删除字符串的子串
#if 0
    int8 str[20] = "abcdefghijk";
    int8 str1[10] = "bc";
    int8 *srcStr = str;
    int8 *subStr = str1;
    DelSubStr(srcStr, subStr);
    printf("src: %s, sub: %s\n", srcStr, subStr);
#endif
/*24*///字符串的反向排序
#if 0
    uint8 string[20] = "ABCDEFGHIJKLMN";
    printf("before Reverse: %s\n", string);
    ReverseString(string);
    printf("after Reverse: %s\n", string);
#endif
/*25*///质数统计
#if 0
    PrintPrimesInMax();
#endif
/*26*///用bit存储质数
#if 0
    StorePrimesByBits();
#endif
/*27*///计算每间隔1000范围内的质数个数
#if 0
    CalcTotalPrimesInMax();
#endif
#if 0
    Transaction trans;
    trans.quantity = 0x1122;
    uint8 typeChar = (uint8)trans.quantity;
    //trans.product[0] = 0;
    printf("1: %p, 2: %p, 3: %p, 4: %p\n", &trans.product, &trans.quantity, &trans.unitPrice, &trans.totalAmount);
    printf("typeChar: %x, trans.quantity: %x\n", typeChar, trans.quantity);
    
    printf("offset0: %d\n", offsetof(Transaction, product));
    printf("offset1: %d\n", offsetof(Transaction, quantity));
    printf("offset2: %d\n", offsetof(Transaction, unitPrice));
    printf("offset3: %d\n", offsetof(Transaction, totalAmount));
#endif
/*28*///通过名字查找电话号码
#if 0
    int8 perName[20] = "";
    gets(perName);
    LookUpAddr(perName);
    LookUpPhoNum(perName);
#endif
/*29*///通过可变参数计算不同个数数值的平均值
#if 0
    uint32 a = 1;
    uint32 b = 2;
    uint32 c = 3;
    uint32 d = 4;
    uint32 e = 5;
    float average2 = 0;
    float average3 = 0;
    average2 = Average(4, a, b, c, d);
    average3 = Average(5, a, b, c, d, e);
    printf("average2: %f, average3: %f\n", average2, average3);
#endif
/*30*///计算数组和指针所占内存的大小
#if 0
    uint32 array[4] = {0};
    uint32 *ptr32 = NULL;
    //uint8 *ptr8 = NULL;
    (void)SizeOfPtr(array);
    printf("sizeof(array) = %d\n", sizeof(array));
    (void)SizeOfPtr(ptr32);
    //(void)SizeOfPtr(ptr8);
#endif
/*31*///fibonacci函数的第n个数，包括迭代和递归实现
#if 0
    uint64 n = 47;
    uint64 ret, ret1;
    clock_t begin, end;
    clock_t begin1, end1;
    double cost;
    double cost1;
    begin = clock();
    ret = FibonacciByRecursion(n);
    end = clock();
    cost = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("cost: %fsecs, end: %d, begin: %d, ret: %ld\n", 
        cost, end, begin, ret);

    begin1 = clock();    
    ret1 = FibonacciByIterate(n);
    end1 = clock();
    cost1 = (double)(end1 - begin1) / CLOCKS_PER_SEC;
    printf("cost1: %fsecs, end1: %d, begin1: %d, ret1: %ld\n", 
        cost1, end1, begin1, ret1);
#endif
/*31*///fibonacci函数的第n个数，包括迭代和递归实现,时间计算
#if 0
    uint64 n = 45;
    uint64 ret, ret1;
    struct timeval start;
    struct timeval end;
    uint64 timer;
    gettimeofday(&start, NULL);

    ret = FibonacciByRecursion(n);
    printf("ret: %ld\n", ret);
    //gettimeofday(&end, NULL);
    ret1 = FibonacciByIterate(n);
    gettimeofday(&end, NULL);
    timer = 1000000 * (end.tv_sec - start.tv_sec) + 
        end.tv_usec - start.tv_usec;
    printf("timer: %ld us\n", timer);
    printf("ret1: %ld\n", ret1);
#endif
/*32*///厄米多项式
#if 0
    uint32 n = 3;
    uint32 x = 2;
    uint32 ret;
    scanf("%d", &n);
    scanf("%d", &x);
    ret = Hermite(n, x);
    printf("H%d(%d) = %d\n", n, x, ret);
#endif
/*33*///最大公约数
#if 0
    uint32 m;
    uint32 n;
    uint32 ret;
    scanf("%d%d", &m, &n);
    ret = GreatestCommonDivisor(m, n);
    printf("gcd of m and n is %d\n", ret);
#endif
/*34*/
#if 0
    uint32 ret = 0;
    int8 string[10] = "";
    gets(string);
    ret = AsciiToInteger(string);
    printf("(string)%s -> (uint32)%d\n", string, ret);
#endif
/*35*/
#if 0
    int32 ret = 0;
    ret = MaxList(3, 4, 8, 10, 800, -1);
    printf("ret = %d\n", ret);
#endif
/*36*/
#if 0
    int32 a = 4;
    float b = 5.2223334;
    int8  c = 't';
    int8  d[20] = "tonghaitao";
    myPrintf("a:%d, b:%f, c:%c, d:%s\n", a, b, c, d);
#endif
/*37*/
#if 0
    testPrintf();
#endif
/*38*/
#if 0
    uint64 amount = 1234546948;
    int8 buffer[LONG] = "";
    printf("amount1: %lu\n", amount);
    WrittenAmount(amount, buffer);
    printf("amount2: %lu\n", amount);
    printf("En: %s\n", buffer);
#endif
#if 0
    uint32 array[10] = {0};
    uint32 *ptr = array;
    uint8 i;
    for (i = 0; i < 11; i++)
    {
        printf("array + %d = %p, value: %d\n", i, &array[i], array[i]);
    }
    for (ptr = &array[10]; ptr > &array[0];)
    {
        *--ptr = 0;
        printf("%d ", *ptr);
    }
    printf("\n");
    for (ptr = &array[0]; ptr < &array[10];)
    {
        *ptr++ = 1;
        printf("%d ", *(ptr-1));
    }
    printf("\n");
#endif
#if 0 //数组名作为实参时，相当于一个地址
    uint32 total = 0;
    uint32 j = 0;
    uint32 array[3] = {1, 2, 3};
    uint32 func(uint32 *ptr)
    {
        uint32 i = 0;
        uint32 ret = 0;
        for (i = 0; i < 3; i++)
        {
            ret += *ptr++;
        }
        return ret;
    }
    total = func(array);
    printf("total: %d\n", total);
    for (j = 0; j < 3; j++)
    {
        printf("array+%d: %p\n", j, array + j);
    }
#endif
#if 0//register定义临时变量用于提高效率
    register uint64 i;
    uint32 a = 0;
    struct timeval start;
    struct timeval end;
    uint64 timer;
    gettimeofday(&start, NULL);
    for (i = 0; i < 600000; i++)
    {
        a++;
        a--;
        a++;
        a--;
    }
    gettimeofday(&end, NULL);
    timer = 1000000 * (end.tv_sec - start.tv_sec) + 
        end.tv_usec - start.tv_usec;
    printf("timer: %ld us\n", timer);
    printf("i ptr is %p\n", &i);

#endif
#if 0//字节对齐，以及结构体所占内存大小
    uint8 len = 0;
    typedef struct{
        uint8 a;
        uint16 b;
        uint32 c;
    }S1;
    typedef struct{
        uint8 d;
        S1 s3;
        uint16 g;
        uint16 i;
        
        uint8 e;
        uint32 f;
        uint8 h;
    }S2;
    printf("offsetof(a):%d\n", offsetof(S1, a));
    printf("offsetof(s3):%d\n", offsetof(S2, s3));
    printf("offsetof(e):%d\n", offsetof(S2, e));
    printf("offsetof(f):%d\n", offsetof(S2, f));
    printf("offsetof(g):%d\n", offsetof(S2, g));
    printf("offsetof(h):%d\n", offsetof(S2, h));
    printf("offsetof(i):%d\n", offsetof(S2, i));
    printf("S1:%d, S2:%d\n", sizeof(S1), sizeof(S2));
#endif
#if 0 //计算数组大小及&a与a以及pa的区别
    int32 a[4] = {0};
    int32 b[2][3] = {{0}, {0}};
    //int32 *c = &(b+1);
    int32 *p = a;
    int32 (*pa)[4] = (int32 (*)[4])a;
    printf("sizeof(a) = %d\n", sizeof(a));
    printf("sizeof(&a)= %d\n", sizeof(&a));
    printf("sizeof(&a[0]) = %d\n", sizeof(&a[0]));
    printf("sizeof(p) = %d\n", sizeof(p));
    printf("sizeof(pa) = %d\n", sizeof(pa));
    printf("sizeof(b) = %d\n", sizeof(b));
    printf("sizeof(&b) = %d\n", sizeof(&b));
    printf("sizeof(&(b[0][0])) = %d\n", sizeof(&b[0]));
    printf("a = %p\n", a);
    printf("&a = %p\n", &a);
    printf("&a+1 = %p\n", &a+1);
    //printf("&(a+1) = %p\n", &(a+1));
    printf("a+1 = %p\n", a+1);
    printf("p = %p\n", p);
    printf("p+1 = %p\n", p+1);
    printf("pa+1 = %p\n", pa+1);
    printf("pa = %p\n", pa);
    printf("pa+1 = %p\n", pa+1);
    printf("b = %p\n", b);
    printf("&b+1 = %p\n", &b+1);
    //printf("&(b+1) = %p\n", &(b+1));//不能这样操作lvalue required as unary ‘&’ operand
    //printf("&(b+1) = %p\n", c);
    printf("&b[0] = %p\n", &b[0]);
    printf("&b[1] = %p\n", &b[1]);
#endif
#if 0//指针和数组的区别
    uint8 message1[] = "hello";
    uint8 *message2 = "hello";
    printf("sizeof(message1) = %d\n", sizeof(message1));
    printf("sizeof(message2) = %d\n", sizeof(message2));
    printf("message1 = %p\n", message1);
    printf("message2 = %p\n", message2);
    printf("message1 = %x\n", (uint32)message1);
    printf("message2 = %d\n", (uint32)message2);
    printf("strlen(message1) = %d\n", strlen(message1));
    printf("strlen(message2) = %d\n", strlen(message2));
#endif
#if 0//#pragma 预处理指令详解
#pragma message("message pragma")
#pragma pack(1)
    typedef struct{
        uint8 a;
        uint16 b[8];
        double c;
    }S_PACK;
#pragma pack()
    typedef struct{
        uint8 a;
        uint16 b;
        double c;
        S_PACK spack[10];
    }S_NOPACK;
    S_NOPACK spack;
    printf("offsetof(S_PACK b) = %d\n", offsetof(S_PACK, b));
    printf("offsetof(S_PACK c) = %d\n", offsetof(S_PACK, c));
    printf("sizeof(S_PACK) = %d\n", sizeof(S_PACK));
    printf("offsetof(S_NOPACK b) = %d\n", offsetof(S_NOPACK, b));
    printf("offsetof(S_NOPACK c) = %d\n", offsetof(S_NOPACK, c));
    printf("sizeof(S_NOPACK) = %d\n", sizeof(S_NOPACK));
    printf("first "
    "second "
    "third\n");

    printf("&spack.a = %p\n", &spack.a);
    printf("&spack.b = %p\nsizeof(spack.b) = %d\n", &spack.b, sizeof(spack.b));
    printf("&spack.c = %p\n", &spack.c);
    printf("&spack.spack = %p\n", &spack.spack);
    printf("sizeof(spack.spack) = %d\n", sizeof(spack.spack));
#endif
#if 0//39.stack
    STACK_T S;
    ElementType e;
    uint32 iterator;

    
    Init_Stack(&S);
    printf("Push\n");
    printf("stacksize: %d\n", S.stacksize);
    for (iterator = 0; iterator < 12; iterator++)
    {
        e = iterator;
        printf("Push %d to stack\n", e);
        Push_Stack(&S, e);
    }
    printf("stacksize: %d\n", S.stacksize);
    GetTop_Stack(&S, &e);
    printf("Top is %d\n", e);
    printf("Pop\n");
    for (iterator = 12; iterator > 0; iterator--)
    {
        Pop_Stack(&S, &e);
        printf("Poped %d\n", e);
    }
    GetTop_Stack(&S, &e);
    //printf("Top is %d\n", e);
#endif

#if 0//40.seq queue
    SeqQueue SQ;
    SeqQueue *SQPtr = &SQ;
    ElementType e;
    uint32 iterator;
    uint8 length = 0;
    InitQueue_Seq(SQPtr);
    for (iterator = 0; iterator < MAXQUEUESIZE; iterator++)
    {
        e = iterator;
        if (RET_OK == EnQueue_Seq(SQPtr, e))
        {
            printf("%d enqueue suc\n", e);
        }
        else
        {
            printf("%d enqueue failed\n", e);
        }
        length = QueueLength_Seq(SQPtr);
        printf("length of queue is %d\n", length);
    }
    for (iterator = 0; iterator < MAXQUEUESIZE; iterator++)
    {
        if (RET_OK == DeQueue_Seq(SQPtr, &e))
        {
            printf("%d dequeue suc\n", e);
        }
        else
        {
            printf("dequeue failed\n");

        }
    }
    length = QueueLength_Seq(SQPtr);
    printf("length of queue is %d\n", length);
    
#endif
#if 0 //41.single link queue
    SLQueue SLQ;
    ElementType e;
    uint32 iterator;
    RESULT ret;
    InitQueue_SingleLink(&SLQ);
    printf("1.count:%d\n", QueueCount_SingleLink(&SLQ));
    for (iterator = 0; iterator < 5; iterator++)
    {
        e = iterator;
        ret = EnQueue_SingleLink(&SLQ, e);
        if (RET_OK == ret)
        {
            printf("%d enqueue suc\n", e);
        }
    }
    printf("2.count:%d\n", QueueCount_SingleLink(&SLQ));
    for (iterator = 0; iterator < 6; iterator++)
    {
        ret = DeQueue_SingleLink(&SLQ, &e);
        if (RET_OK == ret)
        {
            printf("%d dequeue suc\n", e);
        }
    }
    printf("3.count:%d\n", QueueCount_SingleLink(&SLQ));
    DeleteQueue_SingleLink(&SLQ);
#endif
#if 0 //4//42.link stack
    LinkStack LStack;
    ElementType e;
    uint32 iterator;
    RESULT ret;
    InitStack_Link(&LStack);
    for (iterator = 0; iterator < 5; iterator++)
    {
        e = iterator;
        ret = PushStack_link(&LStack, e);
        if (RET_OK != ret)
        {
            printf("push %d failed\n", e);
        }
        printf("%d push suc\n", e);
    }
    printf("count:%d\n", LStack.count);
    DeleteStack_Link(&LStack);
    InitStack_Link(&LStack);
    
    for (iterator = 0; iterator < 5; iterator++)
    {
        e = iterator;
        ret = PushStack_link(&LStack, e);
        if (RET_OK != ret)
        {
            printf("push %d failed\n", e);
        }
        printf("%d push suc\n", e);
    }
    printf("count:%d\n", LStack.count);
    for (iterator = 0; iterator < 6; iterator++)
    {
        ret = PopStack_Link(&LStack, &e);
        if (RET_OK == ret)
        {
            printf("%d pop suc\n", e);
        }
    }

    //DeleteStack_Link(&LStack);
#endif
#if 0//double link queue
    DLinkQueue DLQ;
    uint8 iterator;
    ElementType e;
    InitQueue_DoubleLink(&DLQ);
    for (iterator = 0; iterator < 5; iterator++)
    {
        e = iterator;
        EnQueue_DoubleLink(&DLQ, e);
        printf("enqueue e:%d.\n", e);
    }
    QueueCount_DoubleLink(&DLQ);
    for (iterator = 0; iterator < 6; iterator++)
    {
        if (RET_OK == DeQueue_DoubleLink(&DLQ, &e))
        {
            printf("dequeue e:%d.\n", e);
        }
    }
    QueueCount_DoubleLink(&DLQ);
    DeleteQueue_DoubleLink(&DLQ);
    DeleteQueue_DoubleLink(&DLQ);
    
#endif
#if 0//位域、联合体
    typedef struct S{
        uint16 a : 4;
        uint16 : 0;
        uint16 b : 12;
        uint16 : 4;
        uint16 c : 8;
        //uint8 : 1;
        uint8 d : 7;
        uint8 : 2;
        uint8 e;
    }SS;
    typedef union U{
        SS s;
        uint64 n;
    }UU;
    typedef union F{
        float f;
        uint32 i;
    }FI;
    typedef enum{
        ZERO = 0,
        ONE,
        TWO,
        THREE,
        FOUR,
        FIVE
    }NUM;
    UU x;
    x.n = 0;
    x.s.a = 0xF;
    x.s.b = 0x7F;
    x.s.c = 0xF;
    x.s.d = 0x7;
    x.s.e = 0xff;
    printf("sizeof(UU):%d, sizeof(SS):%d, x.a:%x, x.b:%x, x.c:%x x.n:%llx\n", 
        sizeof(UU), sizeof(SS), x.s.a, x.s.b, x.s.c, x.n);

    FI fi;
    fi.f = 3.14159;
    printf("fi.i:%d, sizeof(fi):%d\n", fi.i, sizeof(fi));
    printf("fi.f:%f\n", fi.f);

    NUM n = FIVE;
    printf("sizeof(n):%d, n: %d\n", sizeof(n), n);

    uint64 u64 = 9223372036854775807;
    printf("sizeof(long int): %d, sizeof(ll int):%d\n, u64: %lld\n", sizeof(long int), sizeof(long long int), u64);
#endif
#if 0//记录汽车销售系统信息
    typedef enum{
        PURE_CASH,
        CASH_LOAN,
        LEASE
    }SALES_TYPE_E;
    typedef struct{
        float msrp;
        float sales_price;
        float sales_tax;
        float licensing_fee;
    }PURE_CASH_T;
    typedef struct{
        float msrp;
        float sales_price;
        float sales_tax;
        float licensing_fee;
        float doun_payment;
        uint32 loan_duration;
        float interest_rate;
        float monthly_payment;
        uint8 bank[21];
    }CASH_LOAN_T;
    typedef struct{
        float msrp;
        float sales_price;
        float down_payment;
        float security_deposit;
        float monthly_payment;
        float lease_term;
    }LEASE_T;
    typedef union{
        PURE_CASH_T pure_cash;
        CASH_LOAN_T cash_loan;
        LEASE_T lease;
    }PAYMENT_INFO_U;
    typedef struct{
        uint8 cust_name[21];
        uint8 cust_addr[41];
        uint8 model[21];
        SALES_TYPE_E type;
        PAYMENT_INFO_U payment_info;
    }SALES_INFO_T;
#endif
#if 0
    int32 a = -20;
    uint32 b = 6;
    uint32 c = a + b;
    uint8 d = a+b;
    uint64 e = (uint64)c;
    if (a + b > 0)
    {
        printf("c:%d d:0x%x e:%lld sizeof(e): %d \nsigned to unsigned\n", c, d, e, sizeof(e));
    }
    else
    {
        printf("unsigned to signed\n");
    }
#endif

#if 0//44.转换表
    double a;
    double b;
    double result = 0;
    a = 5;
    b = 4;
    result = gOperFunc[OP_ADD](a, b);
    printf("%f + %f = %f\n", a, b, result);
    result = gOperFunc[OP_SUB](a, b);
    printf("%f - %f = %f\n", a, b, result);
    result = gOperFunc[OP_MUL](a, b);
    printf("%f * %f = %f\n", a, b, result);
    result = gOperFunc[OP_DIV](a, b);
    printf("%f / %f = %f\n", a, b, result);
#endif

#if 0
    uint32 u32 = 0;
    uint64 u64 = 49999305222222225;
    int32 i32 = -4;
    uint64 u64_1 = 0;
    int64 i64 = 0;
    uint16 u16 = 0;
    
    u32 = u64 + i32;
    u64_1 = u64 + i32;
    i64 = u64 + i32;
    u16 = u64 + i32;
    printf("u32: %x\n, u64_1: %llx\n, i64: %llx\n, u16: %x\n", u32, u64_1, i64, u16);
    printf("u8: %d\n, u16: %d\n, u32: %d\n, u64: %d\n, long int: %d\n", sizeof(uint8), sizeof(uint16), 
        sizeof(uint32), sizeof(uint64), sizeof(long int));
#endif

#if 0//45.回调函数
    uint32 param = 30;
    CallBackFunc1(FunctionA, param);
    CallBackFunc2(FunctionB, param);
#endif
#if 0
/*
46.声明返回指向同类型函数的指针的函数
*/
    
    StateMachine();
    //printf("sizeof(gArray): %d\n", sizeof(gArray));//编译出错，对一个不完全类型进行sizeof操作
#endif
#if 0//switch a with b
//编译提示表达式未定义warning: operation on ‘tempB’ may be undefined [-Wsequence-point]
uint32 tempA = 5;
uint32 tempB = 10;
printf("a.%d, b.%d\n", tempA, tempB);

tempB ^= tempA ^= tempB ^= tempA;//warning
printf("a.%d, b.%d\n", tempA, tempB);

tempA ^= tempB;
tempB ^= tempA;
tempA ^= tempB;
printf("a.%d, b.%d\n", tempA, tempB);

tempA = ++tempA;//warning
printf("a.%d, b.%d\n", tempA, tempB);

tempA = ++tempB * ++tempB;//warning
printf("a.%d, b.%d\n", tempA, tempB);

#endif
#if 0
/*
47.8.7问题4测试某个字符串是否是回文
*/
int8 buf[] = "abcba";
int8 buf1[] = {'a', 'b', 'c', 'b', 'a', '\0'};
uint32 ret;
printf("buf.%p, buf1.%p\n", buf, buf1);
ret = strcmp(buf, buf1);
printf("ret.%d\n", ret);
ret = IsPalindrome(buf);
printf("ret.%d\n", ret);
ret = IsPalindrome(buf1);
printf("ret.%d\n", ret);
#endif

#if 0
/*
48.8.7问题7测试数组和指针对效率的影响
*/
clock_t start, end;
start = clock();
printf("s.%d\n", start);
Try1();
end = clock();
printf("e.%d\n", end);
CalcTimeWaste(start, end);

start = clock();
printf("s.%d\n", start);
Try2();
end = clock();
printf("e.%d\n", end);
CalcTimeWaste(start, end);

start = clock();
printf("s.%d\n", start);
Try3();
end = clock();
printf("e.%d\n", end);
CalcTimeWaste(start, end);

start = clock();
printf("s.%d\n", start);
Try4();
end = clock();
printf("e.%d\n", end);
CalcTimeWaste(start, end);

start = clock();
printf("s.%d\n", start);
Try5();
end = clock();
printf("e.%d\n", end);
CalcTimeWaste(start, end);

start = clock();
printf("s.%d\n", start);
Try6();
end = clock();
printf("e.%d\n", end);
CalcTimeWaste(start, end);

#endif
#if 0
/*
49.8.7问题8测试数组和指针的交替使用风险
*/
//extern uint32 *gA;
//extern uint32 gB[];
uint32 x, y;
x = gA[3];
y = gB[3];
Print();
printf("gA[3].%d, gB[3].%d, gA.%p, gB.%p\n", x, y, gA, gB);

#endif
#if 0
/*
50.8.8编程练习3计算美国公民收入所得税
*/
double income = 394995;
double tax;
tax = SingleTax(income);
printf("income.%f, tax.%f\n", income, tax);
#endif
/*
53.8.8编程练习5矩阵乘法
*/
#if 0
uint32 M1[3][4] = {
                    {0, 2, 3, 4},
                    {0, 2, 3, 4},
                    {0, 2, 3, 4}
};
uint32 M2[4][3] = {
                    {1, 2, 3},
                    {1, 2, 3},
                    {1, 2, 3},
                    {1, 2, 3}
};
uint32 RM[3][3] = {0};
Matrix_Multiply(M1, M2, RM, 3, 4, 3);
uint32 i, j;
for (i = 0; i < 3; i++)
{
    for (j = 0; j < 3; j++)
    {
        printf("%d ", RM[i][j]);
    }
    printf("\n");
    
}
#endif
/*
54.8.8编程练习伪数组位置确定
*/
#if 0
int32 offset;
int32 arrayInfo[21] = {3, 4, 6, 1, 5, -3, 3};
offset = Array_Offset(arrayInfo, 4, 1, 3);
printf("offset = %d\n", offset);
#endif

/*
55.8.8编程练习国际象棋8皇后不能互相攻击
*/
#if 1
Board_Init();
Place_Queen(0);
#endif
/*
56.数组和指针的区别(数组和指针存在关联，但绝不相等)
*/
#if 1
    uint32 x, y;
    printf("b.%p\n", b);
    printf("&b.%p\n", &b);
    printf("c.%p\n", c);
    x = 1;//a[3];//core dump(segmentation fault)
    y = b[3];
    printf("&b[3].%p\n", &b[3]);
    printf("a.%p, &a[0].%p, &a.%p, b.%p, a[3].%d, b[3].%d\n", a, &a[0], &a, b, x, y);
#endif
#endif
    return TRUE;
}

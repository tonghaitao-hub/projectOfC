/*********************************************************
Date:2019.2.18
Author:tonghaitao
Function:review programer
*********************************************************/
#include "ReviewProgramer.h"
/*
1、from page 2
*/
#ifdef REARRANGE
uint32 CallRearRange(void)
{
    int32 n_columns; //进行处理的列标号
    int32 columns[MAX_COLS]; //需要处理的列数
    char input[MAX_INPUT1];
    char output[MAX_INPUT1];

    //读取该串列标号0 3 10 12 -1
    n_columns = ReadColNum(columns, MAX_COLS);
    //读取、处理和打印剩余的输入行
    while (gets(input) != NULL)
    {
        printf("Original input: %s\n", input);
        RearRange(output, input, n_columns, (int32 const *)columns);
        printf("RearRanged line:%s\n", output);
    }
    return TRUE;
}
int32 ReadColNum(int32 columns[], uint32 max)
{
    uint32 num = 0;
    int ch;

    //取得列标号，如果所取的数小于0则停止
    while(num < max && scanf("%d", &columns[num]) == 1 && columns[num] >= 0)
    {
        num += 1;
    }
    //确认已经读取的标号为偶数个，因为它们是以对的形式出现
    if (num % 2 != 0)
    {
        puts("Last column number is not paired.");
        return FALSE;
    }

    //丢弃改该行中包含最后一个数字的那部分内容
    while((ch = getchar()) != EOF && ch != '\n')
    {
        ;
    }
    return num;
}

void RearRange(char *output, char const *input, uint32 n_columns, int const columns[])
{
    int32 col;
    int32 output_col;
    int32 len;

    len = strlen(input);
    output_col = 0;

    //处理每对列标号
    for (col = 0; col < n_columns; col += 2)
    {
        int32 nchars;// = columns[col + 1] - columns[col] + 1;
        //如果输入行结束或输出行数组已满，就结束任务
        //if (columns[col] >= len || output_col == MAX_INPUT1 - 1)
        //{
        //    break;
        //}
        if (output_col == MAX_INPUT - 1)
        {
            break;
        }

        if (columns[col] >= len)
        {
            continue;
        }

        if (col + 1 > n_columns)
        {
            nchars = len - columns[col];
        }
        else
        {
            nchars = columns[col + 1] - columns[col] + 1;
        }
        
        if (nchars <= 1)
        {
            printf("columns error, begin small than end!\n");
            break;
        }
        
        //如果输出行数据不够，只复制可以容纳的数据
        if (output_col + nchars > MAX_INPUT - 1)
        {
            nchars = MAX_INPUT1 - output_col -1;
        }

        //复制数据
        strncpy(output + output_col, input + columns[col], nchars);
        output_col += nchars;
    }
    output[output_col] = '\0';
}

/*
2:  1.8编程练习。2
*/
void InputAndOutput(void)
{
    uint8 ch;
    uint32 line = 0;
    uint8 atBeginning = 1;
    while((ch = getchar()) != EOF)
    {
        if (1 == atBeginning)
        {
            atBeginning = 0;
            line += 1;
            printf("%d ", line);
        }
        putchar(ch);
        if ('\n' == ch)
        {
            atBeginning = 1;
        }
    }
    return;
}

/*
3:  1.8编程练习。3
*/
uint32 CheckSum()
{
    uint32 checksum = 0;
    int8 ch;

    while((ch = getchar()) != EOF && ch != '\n')
    {
        putchar(ch);
        checksum += ch;
    }

    printf("\n%d\n", checksum);
    return checksum;
}

/*
4:  1.8编程练习。4
*/
int8 GetLongestRowAndPrint()
{
    uint32 length = 0;
    char longest[MAX];
    char input[MAX];

    while(gets(input) != NULL)
    {
        int len = strlen(input);

        if (len > MAX)
        {
            printf("input longer than 1000\n");
            return FALSE;
        }

        if (length < len)
        {
            length = len;
            strcpy(longest, input);
        }
    }

    if (length > 0)
    {
        printf("the longest string %s length is %d\n", longest, length);
    }
    return TRUE;
}

/*
5:  2.8编程练习。2
****获取程序中配对成功的花括号
*/
uint32 GetBraceNumInProgramer(void)
{
    int8 ch;
    int32 count = 0;
    uint32 ret = 0;

    while((ch = getchar()) != EOF && ch != '\n')
    {
        if (ch == '{')
        {
            count++;
        }
        else if (ch == '}')
        {
            count--;
            if (count == 0)
            {
                ret++;
            }
        }

        if (count < 0)
        {
            break;
        }
        
    }

    if (count < 0)
    {
        printf("the right brace appears before the left brace or right more than left brace!\n");
    }
    else if (count > 0)
    {
        printf("the left brace more than right brace!\n");
    }
    else
    {
        printf("paired ok!\n");
    }
    
    return ret;
    
}
/*
6:  3.13问题。1
****获取机器整型范围
*<limits.h><float.h>
*/
void GetTypeRange(void)
{
    uint8 i = 10;
    uint8 *p = &i;
    int32 temp = 0;
    int32 *count = &temp;
    float tempFloat = 1.88, tempFloat1 = 3.293, tempFloat2;
    tempFloat++;
    tempFloat2 = tempFloat - tempFloat1;
    printf("tempFloat = %g\n", tempFloat);
    printf("tempFloat1 = %03.6f\t tempFloat2 = %#2.1g\n", tempFloat1, tempFloat2);
    printf("char: %d\n", sizeof(char));
    printf("short int: %3.4d\n", sizeof(short int));
    printf("int: %d\n", sizeof(int));
    printf("long int: %d\n", sizeof(long int));
    printf("long long int: %d\n", sizeof(long long int));
    printf("float: %d\n", sizeof(float));
    printf("double: %d\n", sizeof(double));
    printf("SCHAR_MIN: %d\t SCHAR_MAX:%d\t UCHAR_MAX:%d\n", SCHAR_MIN, SCHAR_MAX, UCHAR_MAX);
    printf("INT_MIN: %d\t INT_MAX:%d\t UINT_MAX:%u\n", INT_MIN, INT_MAX, UINT_MAX);
    printf("LONG_MIN: %ld\t LONG_MAX:%ld\t ULONG_MAX:%lu\n", LONG_MIN, LONG_MAX, ULONG_MAX);
    printf("FLT_MAX: %g\t FLT_MIN: %g\n", FLT_MAX, FLT_MIN);
    printf("DBL_MAX: %g\t DBL_MIN: %g\n", DBL_MAX, DBL_MIN);
    printf("p: %p\n", p);
    printf("i: %d\n", *p);
    printf("p: %n\n", count);
    printf("p: %n\n", count);
    printf("count: %d\n", *count);
}

/*
7:  3.13问题。8
****获取机器整型范围
*
*/
void StaticOutput()
{
    char *szStringA = "Hello, world!";
    char *szStringB = "Hello, world!";
    char szStringC[] = "Hello, world!";
    char szStringD[] = "Hello, world!";
    //*szStringA = '-';
    printf("A:%s\n", szStringA);
    printf("B:%s\n", szStringB);
    printf("*szStringA:%c\n", *szStringA);
    szStringC[0] = '-';
    printf("C:%s\n", szStringC);
    printf("D:%s\n", szStringD);
}
/*
8:  4: switch case 
****关于default
*
*/
void TestSwitchDefault()
{
    uint8 temp;
    for (temp = 0; temp < 5; temp++)
    {
        switch(temp)
        {
            case 1:
                printf("case 1\n");
                break;
            default:
                printf("temp: %d, default\n", temp);
                goto gotoflag;
                break;
            case 3:
            gotoflag:
                printf("case 3\n");
                break;
        }
    }
    
}
/*
9:  4.14问题。1
****calculate square root
*
*/
float CalcSqrRoot(float posNum)
{
    assert((uint8)(posNum >= 1));
    float ai=0, aj=1;
    while(ai != aj)
    {
        if (ai != 0)
        {
            aj = ai;
        }
        ai = DIV(aj + DIV(posNum, aj), 2);
        printf("[%s][%s][%d][%s][%s][%d]----ai: %f, aj: %f\n", 
        __FILE__, __FUNCTION__, __LINE__, __DATE__, __TIME__, __STDC__, ai, aj);
    }
    return ai;
}
void CallCalcSqrRoot()
{
    float posNum;
    scanf("%f", &posNum);
    (void)CalcSqrRoot(posNum);
}
/*
10:  4.14问题。2
****calculate primes in the range 1-100
*
*/
static uint8 IsPrime(uint32 integer)
{
    uint8 flag = TRUE;
    uint32 tempi;
    if (integer == 1)
    {
        flag = FALSE;
        return flag;
    }
    for (tempi = 2; tempi < DIV(integer, 2) + 1; tempi++)
    {
        if (MODE(integer, tempi) == 0)
        {
            flag = FALSE;
        }
    }
    return flag;
}
uint32 CalcPrimesInRange(uint32 max)
{
    uint32 tempi;
    uint32 totalCnt = 0;
    for (tempi = 1; tempi <= max; tempi++)
    {
        if (IsPrime(tempi))
        {
            printf("%5d ", tempi);
            totalCnt++;
            if (MODE(totalCnt, 10) == 0)
            {
                printf("\n");
            }
        }
    }
    printf("\n");
    printf("the total count of prime range in 1-%d is %d\n", max, totalCnt);
    return totalCnt;
}
/*
11.primes in primes
*/
#define MAXPRIME 100000
uint32 primes[MAXPRIME] = {1, 1, 0};
uint32 primesInPrimes[MAXPRIME] = {0};
void CalcPrimesInPrimes(uint32 max)
{
    uint32 i, j;
    uint32 temp = 0;
    uint32 rowCnt = 0;
    //uint32 n;
    //primes[0] = 0;
    //primes[1] = 0;
    //primes[2] = 1;
    assert(max < MAXPRIME);
    for (i = 2; i < MAXPRIME; i++)
    {
        //printf("1, i = %d, primes = %d\n", i, primes[i]);
        if (primes[i] == 0)
        {
            //printf("2\n");
            for (j = i+i; j < MAXPRIME; j += i)
            {
                primes[j] = 1;
            }
            primesInPrimes[i] = ++temp;
        } 
    }
    
    for (i = 1; i < max; i++)
    {
        //printf("3\n");
        if (primes[i] == 0 && primes[primesInPrimes[i]] == 0)
        {
            printf("primes[%5u] = %5u, pinp[%5u] = %5u \n", i, primes[i], i, primesInPrimes[i]);
            rowCnt++;
            if (MODE(rowCnt, 10) == 0)
            {
                printf("\n");
            }
        }
    }
    printf("\n");
}

/*
12:  4.14问题。3
*/
void IsWhatTriangle(uint32 a, uint32 b, uint32 c)
{
    assert(a > 0 && b > 0 && c > 0);
    assert(a < (b+c) && b < (a+c) && c < (b+a));
    if (a == b && b == c)
    {
        printf("equilateral\n");
    }
    else if (a == b || b == c || a == c)
    {
        printf("isosceles\n");
    }
    else
    {
        printf("scalene\n");
    }
}

/*
13:  4.14问题。4
*/
void CopynChar(uint8 *src, uint8 *dst, int n)
{
    uint32 lengthOfstr = 0;
    uint32 temp;
    for (temp = 0; src[temp] != '\0'; temp++)
    {
        lengthOfstr++;
    }
    printf("len of src:%d\n", lengthOfstr);
    
    for (temp = 0; temp < n; temp++)
    {
        if (temp < lengthOfstr)
        {
            dst[temp] = src[temp];
        }
        else
        {
            dst[temp] = '\0';
        }
    }
}
/*
14:  4.14问题。5
*/
void PrintNeighborSame()
{
    int8 flag = 0;
    int8 previous[10] = "";
    int8 next[10] = "";
    gets(previous);
    printf("/////\n");
    while((uint32)gets(next) != EOF)
    {
        if(strcmp(next, previous) != 0 && flag == 1)
        {
            printf("same: %s\n", previous);
            flag = 0;
        }

        if (strcmp(next, previous) == 0)
        {
            flag = 1;
        }
        else
        {
            flag = 0;
        }
        strcpy(previous, next);
    }
}

/*
15:  4.14问题。6
*/
uint32 SubStr(int8 dst[], int8 src[], int start, int len)
{
    uint32 iterator;
    uint32 lenSrc = 0;
    uint32 lenRet = 0;
    for (iterator = 0; src[iterator] != '\0'; iterator++)
    {
        lenSrc++;
    }
    if (start >= lenSrc || start < 0 || len <= 0)
    {
        dst[0] = '\0';
        lenRet = 0;
    }
    else
    {
#if 0
        while(len > 0 && *(src+start) != '\0')
        {
            *(dst++) = *(src++ + start);
            lenRet++;
            len--;
        }
#endif
#if 1
        for (iterator = 0; iterator < len; iterator++)
        {
            if (start + iterator < lenSrc)
            {
                dst[iterator] = src[iterator+start];
                lenRet++;
            }
            else
            {
                break;
            }
        }
#endif
    }
    dst[iterator] = '\0';
    return lenRet;
}
/*
16:  4.14问题。7
*/
void DeleteBlank(int8 string[])
{
    uint32 i, j;
    uint8 flag = 0;
    for (i=0; string[i]!='\0'; i++)
    {
        while(string[i] == ' ' && flag == 1)
        {
            for (j=i; string[j]!='\0'; j++)
            {
                string[j] = string[j+1];
            }
            string[j] = '\0';
        }

        if (string[i] == ' ')
        {
            flag = 1;
        }
        else
        {
            flag = 0;
        }
    }
}
/*
17: 5.9问题。1
*/
void StandardInAndOutput(void)
{
    int8 ch;
    while ((ch = getchar()) != EOF)
    {
        if (ch >= 'A' && ch <= 'Z')
        {
            ch -= 'A' - 'a';
        }
        putchar(ch);
    }
}
/*
18: 5.9问题。2
*/
void SecretStandardInAndOutput(void)
{
    int8 ch;
    while ((ch = getchar()) != EOF)
    {
        if ((ch >= 'A' && ch <= 'M') || (ch >= 'a' && ch <= 'm'))
        {
            ch += 13;
        }
        else if ((ch >= 'N' && ch <= 'Z') || (ch >= 'n' && ch <= 'z'))
        {
            ch -= 13;
        }
        putchar(ch);
    }
}
/*
19: 5.9问题。3
*/
uint32 ReverseBits(uint32 value)
{
    uint32 dst = 0;
    int temp;
    for (temp = 1; temp != 0; temp <<= 1)
    {
        printf("temp: %d\n", temp);
        dst <<= 1;
        if (value & 1)
        {
            dst |= 1;
        }
        //dst <<= 1;//不能先复制再移位，会导致最终结果左移移位
        value >>= 1;
    }
    printf("temp: %d\n", temp);
    printf("dst: %x\n", dst);
    return dst;
}
/*
20: 5.9问题。4
*/
uint32 CharOffSet(uint32 bitNumber)
{
    return DIV(bitNumber, 8);
}
uint32 BitOffSet(uint32 bitNumber)
{
    return MODE(bitNumber, 8);
}
void SetBit(uint8 bitArray[], uint32 bitNumber)
{
    bitArray[CharOffSet(bitNumber)] |= 1 << BitOffSet(bitNumber);
}
void ClrBit(uint8 bitArray[], uint32 bitNumber)
{
    bitArray[CharOffSet(bitNumber)] &= ~(1 << BitOffSet(bitNumber));
}
void AssignBit(uint8 bitArray[], uint32 bitNumber, int value)
{
    if (value != 0)
    {
        SetBit(bitArray, bitNumber);
    }
    else
    {
        ClrBit(bitArray, bitNumber);
    }
}
int32 TestBit(uint8 bitArray[], uint32 bitNumber)
{
    if ((bitArray[CharOffSet(bitNumber)] & (1 << BitOffSet(bitNumber))) != 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/*
21: 5.9问题。5
*/
int32 StoreBitField(int32 orgValue, int32 valueToStore, uint32 startBit, uint32 endBit)
{
    int32 mask = 0;
    int32 umask = 0;
    uint32 temp;
    int retValue = 0;
    for (temp = endBit; temp <= startBit; temp++)
    {
        mask |= 1<<temp;
    }
    umask = ~mask;
    orgValue &= umask;
    valueToStore <<= endBit;
    valueToStore &= mask;
    retValue = orgValue | valueToStore;
    printf("orgValue: 0x%X, valueToStore: 0x%X, retValue: 0x%X\n", orgValue, valueToStore, retValue);
    return retValue;
}

/*
22: 6.18问题。1
*/
int8 const *FindChar(int8 const *source, int8 const *chars)
{
#if 1//solution 1
    uint8 temp1, temp2;
    uint8 srcLen, desLen;
    srcLen = strlen(source);
    desLen = strlen(chars);
    if ((source == NULL) || (chars == NULL) || srcLen == 0 || desLen == 0)
    {
        return NULL;
    }
    for (temp1 = 0; temp1 < srcLen; temp1++)
    {
        for (temp2 = 0; temp2 < desLen; temp2++)
        {
            if (*(source + temp1) == *(chars + temp2))
            {
                return (source + temp1);
            }
        }
    }
    return NULL;
#else //solution 2
    char *ps = source;
    char *pc = NULL;
    if (source == NULL || chars == NULL)
    {
        return NULL;
    }
    while (*ps != '\0')
    {
        pc = chars;
        while (*pc != '\0')
        {
            if (*ps == *pc)
            {
                return ps;
            }
            pc++;
        }
        ps++;
    }
    return NULL;
#endif
}
/*
23: 6.18问题。2
*/
int32 DelSubStr(int8 *srcStr, int8 const *subStr)
{
    uint8 lenSrc;
    uint8 lenSub;
    uint8 temp1, temp2, temp3;
    lenSrc = strlen(srcStr);
    lenSub = strlen(subStr);
    if (srcStr == NULL || subStr == NULL || lenSrc == 0 || lenSub == 0)
    {
        return FALSE;
    }
    for (temp1 = 0; temp1 < lenSrc; temp1++)
    {
        if (*(srcStr + temp1) == *subStr)
        {
            for (temp2 = 1; temp2 < lenSub; temp2++)
            {
                if (*(srcStr + temp1 + temp2) != *(subStr + temp2))
                {
                    return FALSE;
                }
            }
            for (temp3 = temp1; temp3 < lenSrc; temp3++)
            {
                *(srcStr + temp3) = *(srcStr + temp3 + lenSub);
            }
            *(srcStr + temp3) = '\0';
            return TRUE;
        }
    }
    return FALSE;
}
/*
24: 6.18问题。3
*/
void ReverseString(uint8 *string)
{
    uint8 temp;
    uint8 *head = string;
    uint8 *tail = string;

    while(*tail != '\0')
    {
        tail++;
    }
    tail--;
    while(head < tail)
    {
        temp = *head;
        *head = *tail;
        *tail = temp;
        head++;
        tail--;
    }
}
/*
25: 6.18问题。4
*/
void Eratosthenes(uint8 primes[])
{
    uint32 i = 0;
    uint32 i_P;
    uint32 j;
    uint32 j_P;
    for (i = 1; i < MAX; i++)
    {
        if (primes[i] == 1)
        {
            i_P = 2 * i + 1;
            for (j = 2 * i_P; j < 2 * MAX + 1; j += i_P)
            {
                if (j % 2 == 1)
                {
                    j_P = (j - 1) / 2;
                    primes[j_P] = 0;
                }
            }
        }
    }
}
void PrintPrimesInMax()
{
    uint32 i;
    uint32 count = 0;
    uint8 primes[MAX];
    for (i = 1; i < MAX; i++)
    {
        primes[i] = 1;
    }

    printf("the prime range is 2 to %d\n", MAX * 2 + 1);
    Eratosthenes(primes);
    printf("2\n");
    for (i = 1; i < MAX; i++)
    {
        if (1 == primes[i])
        {
            printf("%d ", i * 2 + 1);
            count++;
            if (count % 10 == 0)
            {
                printf("\n");
            }
        }
    }
}
/*
26: 6.18问题。5
*/
void StorePrimesByBits(uint8 *array)
{
    //uint8 array[MAX_SIZE_ARRAY];
    uint32 number;
    uint32 bit_number;
    uint8 *sp;
    //uint8 count;

    for (sp = array; sp < &array[MAX_SIZE_ARRAY];)
    {
        *sp++ = 0xff;
    }

    for (number = 3; number <= MAX; number += 2)
    {
        bit_number = (number - 3) / 2;
        if (TestBit(array, bit_number) == 0)
        {
            continue;
        }
        while ((bit_number += number) <= MAX_BIT_NUMBER)//be caution,the boundary of the max must be covered
        {
            //printf("%d, %d\t", TestBit(array, bit_number), bit_number);
            ClrBit(array, bit_number);
            //printf("%d\n", TestBit(array, bit_number));
        }
    }
/*
    printf("2\n");
    for (bit_number = 0, number = 3; number <= MAX; bit_number += 1, number += 2)
    {
        if (TestBit(array, bit_number))
        {
            printf("%d ", number);
            count++;
            if (count % 10 == 0)
            {
                printf("\n");
            }
        }
    }
    printf("\n");
*/
}
/*
27: 6.18问题。6
*/
void CalcTotalPrimesInMax()
{
    uint32 primesNum[MAX / 1000 + 1] = {1};
    uint8 array[MAX_SIZE_ARRAY];
    uint32 number;
    uint32 bit_number;
    uint32 iterator;
    
    StorePrimesByBits(array);

    for (bit_number = 0, number = 3; number <= MAX; bit_number += 1, number += 2)
    {
        if (TestBit(array, bit_number))
        {
            primesNum[number / 1000] += 1;
        }
    }

    for (iterator = 0; iterator < MAX/1000+1; iterator++)
    {
        printf("%d ~ %d: %d\n", iterator*1000, (iterator+1)*1000, primesNum[iterator]);
    }
}
/*
28: 7.4ADR和黑盒
*/
static int8 name[MAX_PERSONS][NAME_LENGTH] = {
                                                "tonghaitao",
                                                "pujingyao"
                                                };
static int8 address[MAX_PERSONS][ADDR_LENGTH] = {
                                                    "brintain in SiChuan of China",
                                                    "brintain in SiChuan of China"
                                                    };
static int8 phone[MAX_PERSONS][PHONE_LENGTH] = {
                                                    "18200399042",
                                                    "13568920746"
                                                    };

/*
用户不能直接访问此接口和上面定义的static变量
*/
static int32 FindEntry(int8 const *nameToFine)
{
    int entry;
    for (entry = 0; entry < MAX_PERSONS; entry++)
    {
        if (strcmp(nameToFine, name[entry]) == 0)
        {
            return entry;
        }
    }
    return -1;
}

int8 const *LookUpAddr(int8 const *name)
{
    int entry;
    entry = FindEntry(name);
    printf("entry: %d\n", entry);
    if (entry == -1)
    {
        printf("no persons info\n");
        return NULL;
    }
    else
    {
        printf("\033[0m\033[0;41m%s\033[0m the person's address is \033[0;41m%s\033[0m\n", name, address[entry]);
        printf("length: %d\n", strlen(address[entry]));
        return address[entry];
    }
}

int8 const *LookUpPhoNum(int8 const *name)
{
    int entry;
    entry = FindEntry(name);
    printf("entry: %d\n", entry);
    if (entry == -1)
    {
        printf("no persons info\n");
        return NULL;
    }
    else
    {
        printf("%s the person's phone num is %s\n", name, phone[entry]);
        return phone[entry];
    }
}

/*29*///通过可变参数计算不同个数数值的平均值
float Average(uint32 nValues, ...)
{
    va_list var_arg;
    uint32 count;
    float sum = 0;

    /*准备访问可变参数*/
    va_start(var_arg, nValues);

    /*添加取自可变参数列表的值*/
    for (count = 0; count < nValues; count++)
    {
        sum += va_arg(var_arg, uint32);
        printf("sum: %f, count: %d\n", sum, count);
    }

    /*完成处理可变参数*/
    va_end(var_arg);

    return sum / nValues;
}
/*30*///计算数组和指针所占内存的大小
uint32 SizeOfPtr(uint32 *ptr)
{
    uint32 size;
    size = sizeof(ptr);
    printf("size of ptr is %d\n", size);
    return size;
}
/*31*///fibonacci函数的第n个数，包括迭代和递归实现
uint64 FibonacciByRecursion(uint64 n)
{
    if (n <= 2)
    {
        return 1;
    }
    else
    {
        return FibonacciByRecursion(n-1) + FibonacciByRecursion(n-2);
    }
}
uint64 FibonacciByIterate(uint64 n)
{
    struct timeval start;
    struct timeval end;
    unsigned long timer;
    gettimeofday(&start, NULL);
    uint64 prevValue = 1;
    uint64 lastValue = 1;
    uint64 result = 1;
    while (n > 2)
    {
        n--;
        result = prevValue + lastValue;
        prevValue = lastValue;
        lastValue = result;
    }
    gettimeofday(&end, NULL);
    timer = 1000000 * (end.tv_sec - start.tv_sec) + 
        end.tv_usec - start.tv_usec;
    printf("timer: %ldus\n", timer);
    printf("result: %ld\n", result);
    return result;
}
/*
32: 7.11问题。1
Hn(x) = 1 :n <= 0
      = 2x :n = 1
      = 2xHn-1(x) - 2(n-1)Hn-2(x) : n >= 2
*/
uint32 Hermite(uint32 n, uint32 x)
{
    if (n <= 0)
    {
        return 1;
    }
    else if (n == 1)
    {
        return 2 * x;
    }
    else// if (n >= 2)
    {
        return 2 * x * Hermite(n-1, x) - 2 * (n-1) * Hermite(n-2, x);
    }
}
/*
33: 7.11问题。2
求最大公约数
gcd(M, N) = N        :M % N = 0
          = gcd(N, R):M % N = R, R > 0 
*/
uint32 GreatestCommonDivisor(uint32 m, uint32 n)
{
    uint32 temp = 0;
    if (m < 0 || n < 0)
    {
        return 0;
    }
#if 0 //递归实现
    if (m % n == 0)
    {
        return n;
    }
    else
    {
        temp = m % n;
        return GreatestCommonDivisor(n, temp);
    }
#else //迭代实现
    while (m % n != 0)
    {
        temp = m % n;
        m = n;
        n = temp;
    }
    return n;
#endif
}
/*
34: 7.11问题。3
ascii 转化成integer
*/

uint32 AsciiToInteger(int8 *string)
{
    uint32 ret;
    int8 *tempPtr = string;
    while(*tempPtr != '\0')
    {
        if (*tempPtr >= '0'  && *tempPtr <= '9')
        {
            ret *= 10;
            ret += *tempPtr - '0'; 
        }
        else
        {
            return 0;
        }
        tempPtr++;
    }
    return ret;
}
/*
35: 7.11问题。4
检查任意数目的整型参数并返回它们中的最大值
*/
int32 MaxList(uint32 x, ...)
{
    int32 max = 0;
    int32 temp = 0;
    va_list var_list;
    va_start(var_list, x);
    do
    {
        temp = va_arg(var_list, int32);
        if (temp > max)
        {
            max = temp;
        }
    }while(temp > 0);
    va_end(var_list);
    return max;
}
/*
36: 7.11问题。5
实现一个简化的printf函数
*/
void print_integer(int32 temp)
{
    printf("%d", temp);
}
void print_float(float temp)
{
    printf("%f", temp);
}
void myPrintf(int8 *string, ...)
{
    int8 *ptr = string;
    int8 *ptr1 = NULL;
    va_list var_list;
    va_start(var_list, string);

    while (*ptr != '\0')
    {
        if (*ptr == '%')
        {
            //ptr++;
            switch(*++ptr)
            {
                case 'd':
                    print_integer(va_arg(var_list, int32));
                    break;
                case 'f':
                    print_float(va_arg(var_list, double));
                    break;
                case 'c':
                    putchar(va_arg(var_list, int32));
                    break;
                case 's':
                    ptr1 = va_arg(var_list, int8 *);
                    while(*ptr1 != '\0')
                    {
                        putchar(*ptr1++);
                    }
                    break;
                default:
                    break;
            }
        }
        else
        {
            putchar(*ptr);
        }
        ptr++;
    }
    va_end(var_list);
}
/*
37: 
测试printf函数中的%f是double类型还是float类型
*/
void testPrintf()
{
    //int32 a = 0;
    //int32 b = 0;
    //int32 c = 5;
    //float d = 0.0f;
    
    //printf("a = %f, b = %d\n", a, b);
    //printf("a = %f, b = %d\n", a, b, c);
    //printf("a = %lf, b = %d\n", a, b, c);
    //printf("d = %f, c = %d\n", d, c);
    //printf("d = %d, c = %d\n", d, c);
}
/*
38: 7.11问题。6
将数值转换成单词形式，并存储在buffer中
*/
int8 *unit[10] = {
                    " ", " one", " two", " three", " four",
                    " five", " six", " seven", " eight", " nine"
};
int8 *ten[10] = {
                    " ten", "eleven", " twelve", " thirteen", " fourteen",
                    " fifteen", " sixteen", " seventeen", " eightteen", " nineteen"
};
int8 *decade[10] = {
                    " ", " ", " twenty", " thirty", " forty", " fifty", " sixty",
                    "seventy", "eighty", "ninety"
};
void WrittenAmount(uint64 amount, int8 *buffer)
{
    uint64 n = 100000000;
    uint32 temp;
    if (amount / n != 0)
    {
        temp = amount / n;
        amount %= n;
        WrittenAmount(temp, buffer);
        strcat(buffer, " billion");
    }

    n = 100000;
    if (amount / n != 0)
    {
        temp = amount / n;
        amount %= n;
        WrittenAmount(temp, buffer);
        strcat(buffer, " million");
    }

    n = 1000;
    if (amount / n != 0)
    {
        temp = amount / n;
        amount %= n;
        WrittenAmount(temp, buffer);
        strcat(buffer, " thousand");
    }

    n = 100;
    if (amount / n != 0)
    {
        temp = amount / n;
        amount %= n;
        WrittenAmount(temp, buffer);
        strcat(buffer, " hundred");
    }

    n = 10;
    if (amount / n != 0)
    {
        temp = amount / n;
        amount %= n;
        if (temp == 1)
        {
            strcat(buffer, ten[amount]);
        }
        else
        {
            strcat(buffer, decade[temp]);
            if (amount != 0)
            {
                strcat(buffer, unit[amount]);
            }
        }
    }
    else
    {
        strcat(buffer, unit[amount]);
    }
    //printf("amount: %ld\n", amount);
    //printf("En: %s\n", buffer);
}
/*
39: seq stack。
*/
RESULT Init_Stack(STACK_T *S)
{
    //S->base = (ElementType *)malloc(STACK_SIZE * sizeof(ElementType));
    S->base = (ElementType *)malloc(STACK_SIZE * sizeof(ElementType));//warning*** glibc detected *** ./edit1: realloc(): invalid next size: 0x08aa8008 ***
    if (NULL == S->base)
    {
        return RET_OVERFLOW;
    }
    S->top = S->base;
    S->stacksize = STACK_SIZE;
    return RET_OK;
}
RESULT Push_Stack(STACK_T *S, ElementType e)
{
    if (RET_FULL == IsFull_Stack(S))
    {
        printf("stack is full, realloc memory, stacksize: %d\n", S->stacksize);
        S->base = (ElementType *)realloc(S->base, (S->stacksize + STACK_INC) * sizeof(ElementType));
        if (NULL == S->base)
        {
            printf("realloc memory fail\n");
            return RET_OVERFLOW;
        }
        S->top = S->base + S->stacksize;
        S->stacksize = S->stacksize + STACK_INC;
    }
    *S->top++ = e;
    return RET_OK;
}
RESULT Pop_Stack(STACK_T *S, ElementType *e)
{
    if (RET_EMPTY == IsEmpty_Stack(S))
    {
        printf("stack is empty, can't pop\n");
        return RET_EMPTY;
    }
    *e = *--S->top;
    return RET_OK;
}
RESULT IsEmpty_Stack(STACK_T *S)
{
    if (S->top == S->base)
    {
        return RET_EMPTY;
    }
    return RET_FALSE;
}
RESULT IsFull_Stack(STACK_T *S)
{
    if ((S->top - S->base) >= S->stacksize)
    {
        printf("stack is full\n");
        return RET_FULL;
    }
    return RET_FALSE;
}
RESULT GetTop_Stack(STACK_T *S, ElementType *e)
{
    if (RET_EMPTY == IsEmpty_Stack(S))
    {
        printf("stack is empty, get top failed\n");
        return RET_FALSE;
    }
    *e = *(S->top - 1);
    return RET_OK;
}

/*
40: sequential queue。
*/
RESULT InitQueue_Seq(SeqQueue *SQ)
{
    SQ->base = (ElementType *)malloc(MAXQUEUESIZE * sizeof(ElementType));
    if (NULL == SQ->base)
    {
        return RET_OVERFLOW;
    }
    SQ->front = SQ->rear = 0;
    return RET_OK;
}
RESULT EnQueue_Seq(SeqQueue *SQ, ElementType e)
{
    if((SQ->rear + 1) % MAXQUEUESIZE == SQ->front)
    {
        printf("queue is full,%d enqueue failed\n", e);
        return RET_FULL;
    }
    SQ->base[SQ->rear] = e;
    SQ->rear = (SQ->rear + 1) % MAXQUEUESIZE;
    return RET_OK;
}
RESULT DeQueue_Seq(SeqQueue *SQ, ElementType *e)
{
    if (SQ->rear == SQ->front)
    {
        printf("queue is empty,dequeue failed\n");
        return RET_EMPTY;
    }
    *e = SQ->base[SQ->front];
    SQ->front = (SQ->front + 1) % MAXQUEUESIZE;
    return RET_OK;
}
uint32 QueueLength_Seq(SeqQueue *SQ)
{
    return (SQ->rear + MAXQUEUESIZE - SQ->front) % MAXQUEUESIZE;
}

/*
41.single link queue
*/
RESULT InitQueue_SingleLink(SLQueue *SLQ)
{
    SLQ->front = SLQ->rear = (SLQNodePtr)malloc(sizeof(SLQNode));
    if (NULL == SLQ->front)
    {
        return RET_OVERFLOW;
    }
    SLQ->front->next = NULL;
    return RET_OK;
}
RESULT EnQueue_SingleLink(SLQueue *SLQ, ElementType e)
{
    SLQNodePtr tempPtr;
    tempPtr = (SLQNodePtr)malloc(sizeof(SLQNode));
    if (NULL == tempPtr)
    {
        return RET_OVERFLOW;
    }
    tempPtr->data = e;
    tempPtr->next = NULL;
    SLQ->rear->next = tempPtr;
    SLQ->rear = tempPtr;
    return RET_OK;
}
RESULT DeQueue_SingleLink(SLQueue *SLQ, ElementType *e)
{
    SLQNodePtr tempPtr;
    if (0 == QueueCount_SingleLink(SLQ))
    {
        printf("single link queue is empty, can't dequeue\n");
        return RET_EMPTY;
    }
    tempPtr = SLQ->front->next;
    *e = tempPtr->data;
    SLQ->front->next = tempPtr->next;
    if (SLQ->rear == tempPtr)
    {
        SLQ->rear = SLQ->front;
    }
    free(tempPtr);
    return RET_OK;
}
RESULT DeleteQueue_SingleLink(SLQueue *SLQ)
{
    SLQNodePtr tempPtr;
    while(SLQ->front)
    {
        tempPtr = SLQ->front->next;
        free(SLQ->front);
        SLQ->front = tempPtr;
    }
    return RET_OK;
}
uint8 QueueCount_SingleLink(SLQueue *SLQ)
{
    SLQNodePtr tempPtr;
    uint8 count = 0;
    tempPtr = SLQ->front;
    while(tempPtr->next)
    {
        count++;
        tempPtr = tempPtr->next;
    }
    return count;
}

/*
42.link stack
*/
RESULT InitStack_Link(LinkStack *LStack)
{
    if (NULL == LStack)
    {
        return RET_OVERFLOW;
    }
    LStack->top = NULL;
    LStack->count = 0;
    return RET_OK;
}
RESULT PushStack_link(LinkStack *LStack, ElementType e)
{
    StackNodePtr tempPtr;
    tempPtr = (StackNodePtr)malloc(sizeof(StackNode));
    printf("alloc tempPtr:%p\n", tempPtr);
    if (NULL == tempPtr)
    {
        return RET_OVERFLOW;
    }
    tempPtr->data = e;
    tempPtr->next = LStack->top;
    LStack->top = tempPtr;
    LStack->count++;
    return RET_OK;
    
}
RESULT PopStack_Link(LinkStack *LStack, ElementType *e)
{
    StackNodePtr tempPtr;
    if (0 == LStack->count)
    {
        printf("link stack is empty, popstack failed\n");
        return RET_EMPTY;
    }
    tempPtr = LStack->top;
    *e = tempPtr->data;
    LStack->top = tempPtr->next;
    LStack->count--;
    free(tempPtr);
    return RET_OK;
}
RESULT GetTopStack_Link(LinkStack *LStack, ElementType *e)
{
    if (0 == LStack->count)
    {
        printf("link stack is empty, get top failed\n");
    }
    *e = LStack->top->data;
    return RET_OK;
}
RESULT DeleteStack_Link(LinkStack *LStack)
{
    StackNodePtr tempPtr;
    while(LStack->top)
    {
        tempPtr = LStack->top;
        printf("free LStack->top:%p, data%p, node%p, sizeof(StackNode):%d, &LStack->top%p, &LStack->count%p----\n", 
            LStack->top, &LStack->top->data, &LStack->top->next, sizeof(StackNode), &LStack->top, &LStack->count);
        free(LStack->top);
        LStack->top = tempPtr->next;
    }
    return RET_OK;
}

/*
43.double link queue(双向链表)
*/
extern RESULT InitQueue_DoubleLink(DLinkQueue *DLQ)
{
    DLQ->head = DLQ->tail = (DLQNodePtr)malloc(sizeof(DLQNode));
    if (NULL == DLQ->head)
    {
        return RET_OVERFLOW;
    }
    DLQ->head->bwd = NULL;
    DLQ->head->fwd = NULL;
    return RET_OK;
}
extern RESULT EnQueue_DoubleLink(DLinkQueue *DLQ, ElementType e)
{
    DLQNodePtr tempPtr;
    tempPtr = (DLQNodePtr)malloc(sizeof(DLQNode));
    if (NULL == tempPtr)
    {
        return RET_OVERFLOW;
    }
    tempPtr->data = e;
    if (DLQ->tail != DLQ->head)
    {
        tempPtr->bwd = DLQ->tail;
        tempPtr->fwd = NULL;
        DLQ->tail->fwd = tempPtr;
        DLQ->tail = tempPtr;
    }
    else
    {
        tempPtr->bwd = NULL;
        tempPtr->fwd = DLQ->head;
        DLQ->head->fwd = tempPtr;
        DLQ->tail = tempPtr;
    }
    return RET_OK;
}
extern RESULT DeQueue_DoubleLink(DLinkQueue *DLQ, ElementType *e)
{
    DLQNodePtr tempPtr;
    if (DLQ->head == DLQ->tail)
    {
        printf("queue is empty\n");
        return RET_EMPTY;
    }
    tempPtr = DLQ->head->fwd;
    *e = tempPtr->data;
    if (DLQ->head->fwd != DLQ->tail)
    {
        DLQ->head->fwd = tempPtr->fwd;
        tempPtr->fwd->bwd = DLQ->head;
    }
    else
    {
        DLQ->head->bwd = NULL;
        DLQ->head->fwd = NULL;
        DLQ->tail = DLQ->head;
    }
    free(tempPtr);
    return RET_OK;
}
extern RESULT DeleteQueue_DoubleLink(DLinkQueue *DLQ)
{
    uint8 queueCnt = 0;
    if (NULL == DLQ->head)
    {
        printf("the queue is NULL\n");
        return RET_OVERFLOW;
    }
    while(DLQ->head)
    {
        DLQ->tail = DLQ->head;
        free(DLQ->head);
        DLQ->head = DLQ->tail->fwd;
        queueCnt++;
    }
    return RET_OVERFLOW;
}
extern uint8 QueueCount_DoubleLink(DLinkQueue *DLQ)
{
    uint8 queueCnt = 0;
    DLQNodePtr tempPtr;
    tempPtr = DLQ->head->fwd;
    while(tempPtr)
    {
        printf("tempPtr:%p\n", tempPtr);
        queueCnt++;
        tempPtr = tempPtr->fwd;
    }
    printf("queueCnt:%d\n", queueCnt);
    return RET_OK;
}

/*
44.转换表
*/
double Add(double a, double b)
{
    return a + b;
}
double Sub(double a, double b)
{
    return a - b;
}
double Mul(double a, double b)
{
    return a * b;
}
double Div(double a, double b)
{
    return a / b;
}
OPER_FUNC gOperFunc[] = {Add, Sub, Mul, Div};
//double (*gOperFunc[10])(double, double) = {Add, Sub, Mul, Div};
/*
45.回调函数
*/
uint32 FunctionA(uint32 param)
{
    printf("called functionA, param.%d\n", param);
    return 0xA;
}

uint32 FunctionB(uint32 param)
{
    printf("called functionB, param.%d\n", param);
    return 0xB;
}

uint32 CallBackFunc1(PFUNC_CB_T pCallBack, uint32 param)
{
    uint32 ret;
    ret = pCallBack(param);
    printf("CallBackFunc1: ret.%x\n", ret);
    return ret;
}
uint32 CallBackFunc2(uint32 (*ptr)(), uint32 param)
{
    uint32 ret;
    ret = (*ptr)(param);
    printf("CallBackFunc2: ret.%x\n", ret);
    return ret;
}
/*
46.声明返回指向同类型函数的指针的函数
*/
FUNCPTR Start(), Stop();
FUNCPTR State1(), State2();
FUNCPTR Start()
{
    printf("Start\n");
    return (FUNCPTR)State1;
}
FUNCPTR Stop()
{
    printf("Stop\n");
    return NULL;
}
FUNCPTR State1()
{
    printf("state1\n");
    return (FUNCPTR)State2;
}

FUNCPTR State2()
{
    printf("state2\n");
    return (FUNCPTR)Stop;
}
void StateMachine()
{
    PTRFUNCPTR state = Start;
    while(state != Stop)
    {
        state = (PTRFUNCPTR)(*state)();
    }
    
}
//uint32 gArray[] = {1, 2, 3};
/*
47.8.7问题4测试某个字符串是否是回文
*/

uint32 IsPalindrome(int8 *buf)
{
    printf("buf.%p\n", buf);
    uint8 *ptrFront, *ptrRear;
    ptrFront = buf;
    ptrRear = buf;
    while (*ptrRear != '\0')
    {
        printf("rear.%c\n", *ptrRear);
        ptrRear++;
    }
    ptrRear--;
    while (ptrFront < ptrRear)
    {
        if (*ptrFront != *ptrRear)
        {
            break;
        }
        ptrFront++;
        ptrRear--;
    }
    if (ptrFront >= ptrRear)
    {
        return TRUE;
    }
    return FALSE;
}


/*
48.8.7问题7测试数组和指针对效率的影响
*/
uint32 x[SIZE];
uint32 y[SIZE];
uint32 i;
uint32 *ptr1, *ptr2;
void Try1()
{//0.45s
    for (i = 0; i < SIZE; i++)
    {
        x[i] = y[i];
    }
}
void Try2()
{//0.24s
    for (i = 0, ptr1 = x, ptr2 = y; i < SIZE; i++)
    {
        *ptr1++ = *ptr2++;
    }
}
void Try3()
{//0.18s
    for (ptr1 = x, ptr2 = y; ptr1 - x < SIZE;)
    {
        *ptr1++ = *ptr2++;
    }
}

void Try4()
{//0.09s
    register uint32 j;
    register uint32 *ptr3, *ptr4;
    for (j = 0, ptr3 = x, ptr4 = y; j < SIZE; j++)
    {
        *ptr3++ = *ptr4++;
    }
}

void Try5()
{//0.18s
    register uint32 j;
    //register uint32 *ptr3, *ptr4;
    for (j = 0, ptr1 = x, ptr2 = y; j < SIZE; j++)
    {
        *ptr1++ = *ptr2++;
    }
}

void Try6()
{//0.10s
    //register uint32 j;
    register uint32 *ptr3, *ptr4;
    for (ptr3 = x, ptr4 = y; ptr3 - x < SIZE;)
    {
        *ptr3++ = *ptr4++;
    }
}

double CalcTimeWaste(clock_t start, clock_t end)
{
    double ret;
    ret = (double)(end - start) / CLOCKS_PER_SEC;
    printf("time.%f\n", ret);
    return ret;
}

/*
49.8.7问题8测试数组和指针不相同
*/
uint32 gA[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
uint32 *gB = gA;
void Print()
{
    printf("gA[3].%d, gB[3].%d, gA.%p, gB.%p\n", gA[3], gB[3], gA, gB);
}
/*
50.8.8编程练习3计算美国公民收入所得税
*/
static double income_limits[] = {0, 23350, 56550, 117950, 256500, DBL_MAX};
static float base_tax[] = {0, 3502.5, 12798.5, 31832.5, 81710.5};
static float percentage[] = {0.15, 0.28, 0.31, 0.36, 0.396};
double SingleTax(double income)
{
    int category;
    assert(income > 0);
    for (category = 1; income > income_limits[category]; category++);
    category--;
    printf("category.%d\n", category);
    return base_tax[category] + percentage[category] * (income - income_limits[category]);
}

/*
51.8.8编程练习3判断是否是单位矩阵
*/
uint32 Identify_Matrix(uint32 matrix[][10])
{
    register uint32 row, col;
    for (row = 0; row < 10; row++)
    {
        for (col = 0; col < 10; col++)
        {
        /*
            if (matrix[row][col] != (col == row))
            {
                return FALSE;
            }*/
            if (row == col)
            {
                if (matrix[row][col] != 1)
                {
                    return FALSE;
                }
                else
                {
                    if (matrix[row][col] != 0)
                    {
                        return FALSE;
                    }
                }
            }
        }
    }
    return TRUE;
}
/*
52.8.8编程练习4判断是否是单位矩阵(任意大小的矩阵)
*/

uint32 Identify_Matrix_nRow(uint32 *matrix, uint32 n)
{
    uint32 row, col;
    for (row = 0; row < n; row++)
    {
        for (col = 0; col < n; col++)
        {
            if (*matrix++ != (row == col))
            {
                return FALSE;
            }
        }
    }
    return TRUE;
}

/*
53.8.8编程练习5矩阵乘法
*/
void Matrix_Multiply(uint32 *M1, uint32 *M2, uint32 *RM, uint32 x, uint32 y, uint32 z)
{
    uint32 i, j, k;
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < z; j++)
        {
            uint32 *p1, *p2;
            p1 = M1 + i * y;
            p2 = M2 + j;
            for (k = 0; k < y; k++)
            {
                *RM += *p1 * *p2;
                p1++;
                p2 += z;
            }
            RM++;
        }
    }
}

/*
54.8.8编程练习伪数组位置确定
*/
/*use subscript*/
#if 0
uint32 Array_Offset(uint32 arrayinfo[], ...)
{
    uint32 temp[10];
    uint32 ret;
    VA_LIST var_list;
    uint32 i;

    if (arrayinfo[0] < 1 || arrayinfo[0] > 10)
    {
        return FALSE;
    }
    VA_START(var_list, arrayinfo);
    for (i = 0; i < arrayinfo[0]; i++)
    {
        temp[i] = VA_ARG(var_list, int32);
    }

    VA_END(var_list);
    for (i = 1; i < arrayinfo[0]; i++)
    {
        if (i%2 == 0 && arrayinfo[2*i] <= temp[i] && arrayinfo[2*i-1] >= temp[i])
        {
            return FALSE;
        }
        ret *= (arrayinfo[2*i] - arrayinfo[2*i-1] + 1);
        ret += temp[i] - arrayinfo[2*i-1];
    }
    return ret;    
}
#else
int32 Array_Offset(int32 arrayinfo[], ...)
{
    int32 nDim;
    int32 s[10];
    int32 hi, lo;
    int32 offset;
    int32 i;
    
    VA_LIST var_list;
    VA_START(var_list, arrayinfo);

    nDim = *arrayinfo++;
    if (nDim < 1 || nDim > 10)
    {
        printf("error.1\n");
        return -1;
    }
    for (i = 0; i < nDim; i++)
    {
        s[i] = VA_ARG(var_list, int32);
        printf("s[%d].%d\n", i, s[i]);
    }

    VA_END(var_list);

    offset = 0;
    for (i = 0; i < nDim; i++)
    {
        lo = *arrayinfo++;
        hi = *arrayinfo++;

        if (s[i] < lo || s[i] > hi)
        {
            printf("error.2, hi.%d, lo.%d, s[%d].%d\n", hi, lo, i, s[i]);
            return -1;
        }
        offset *= hi - lo + 1;
        offset += s[i] -lo;
    }
    return offset;
    
}
#endif

/*
55.8.8编程练习国际象棋8皇后不能互相攻击
*/
int32 board[8][8];
void DBG_PRINT()
{
    int32 i, j;
    static uint32 n_solutions = 0;
    n_solutions++;
    printf("Solution #%d\n", n_solutions);
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            if (board[i][j])
            {
                printf("Q ");
            }
            else
            {
                printf("+ ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int32 conflicts(int32 row, int32 col)
{
    int32 i;
    for (i = 1; i < 8; i++)
    {
        if (row - i >= 0 && board[row-i][col])
        {
            return 1;
        }
        if (col - i >= 0 && board[row][col-i])
        {
            return 1;
        }
        if (col + i < 8 && board[row][col+i])
        {
            return 1;
        }
        if (row - i >= 0 && col - i >= 0 && board[row-i][col-i])
        {
            return 1;
        }
        if (row - i >= 0 && col + i < 8 && board[row - i][col+i])
        {
            return 1;
        }
    }
    return 0;
}

void Board_Init()
{
    int32 i, j;
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            board[i][j] = 0;
        }
    }
    //DBG_PRINT();
}
void Place_Queen(int32 row)
{
    int32 col;
    for (col = 0; col < 8; col++)
    {
        board[row][col] = 1;
        //printf("111: row.%d, col.%d\n", row, col);
        if (row == 0 || !conflicts(row, col))
        {
            
            if (row < 7)
            {
                //printf("row.%d, col.%d\n", row, col);
                Place_Queen(row + 1);
            }
            else
            {
                DBG_PRINT();
            }
        }
        board[row][col] = 0;
    }
}

/*
56.8.8编程练习国际象棋8皇后不能互相攻击
*/
uint32 a[10] = {1, 2, 3, 4};
uint32 *b = a;
uint32 c[10] = {1, 1, 1, 1, 1};


#endif

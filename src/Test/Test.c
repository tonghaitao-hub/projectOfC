#include "Test.h"
#include <math.h>
//#include "Thread.h"

u32 a[5] = {1, 3, 5, 6, 3};
u32 *b = a;

void getpwd(char *pwd, int pwdlen)
{
    char ch = 0;
    //char c;
    int i = 0;
    while (i < pwdlen) {
        ch = getchar();
        //while((c = getchar()) != '\n' && c != EOF);
        if (ch == '\r') {//回车结束输入
            printf("\n");
            break;
        }

        if (ch == '\b' && i > 0) {//按下删除键
            i--;
            printf("\b \b");
        } else if (isprint(ch)) {//输入可打印字符
            pwd[i] = ch;
            printf("*");
            i++;
        }
        printf("\ni=%d\n", i);
    }
    pwd[i] = 0;
}
void mystery(int n)
{
    n += 5;
    n  /= 5;
    printf("%s\n", "**********" + 10 - n);
}

void test()
{
    DBGPRINTF("test func start\n");
#if PTRDIFFWITHARRAY
    //extern u32 *a;
    //extern u32 b[];

    extern u32 a[5];
    extern u32 *b;

    u32 x, y;
    u32 *ptrA = a;
    u32 *ptrA3 = &a + 3;
    u32 *ptrB3 = b + 3;
    x = a[3];
    y = b[3];
    DBGPRINTF("a[3] = %d\nb[3] = %d\nptrA = %p\nptrA[3] = %p\nptrB[3] = %p\n", x, y, ptrA, ptrA3, ptrB3);
    u32 *ptrAA = &a;
    u32 *ptrBB = &b;
    DBGPRINTF("ptr&a = %p, value.%d\n", ptrAA, *ptrAA);
    DBGPRINTF("ptr&b = %p, value.%d\n", ptrBB, *ptrBB);
#endif
#if BINARY_OCTONARY_DECIMAL
    u32 octo = 0175;
    u32 bin = 0b101;//0B101;
    u32 decimal = 165;
    u32 hex = 0x122;
    DBGPRINTF("octo 0175:decimal.%-6d, oct.0%-6o, hex.0x%-6x\n", octo, octo, octo);
    DBGPRINTF("bin 0B101:decimal.%-6d, oct.0%-6o, hex.0x%-6x\n", bin, bin, bin);
    DBGPRINTF("deci  165:decimal.%-6d, oct.0%-6o, hex.0x%-6x\n", decimal, decimal, decimal);
    DBGPRINTF("hex 0x122:decimal.%-6d, oct.0%-6o, hex.0x%-6x\n", hex, hex, hex);
#endif

#if CHAR_DIFF_WITH_STRING
    char string[] = "dadlkasdfljasd";
    u32 strsize = sizeof(string);
    u32 c = 'yes';
    DBGPRINTF("string.%s, strsize.%d\n", string, strsize);
    DBGPRINTF("c.%s, %c, %d\n", &c, c, c);
#endif

#if IS_SUPPORT_NESTED_COMMENTS
    char *string = /*/**/"*/"/*"/**/;//另外一种检测是否支持嵌套注释的方法是/*/*/0*/**/1,如果支持则结果为1，如果不支持则为0*1,结果为0
    char *support = "*/";
    char *notsupport = "/*";
    char *result = NULL;
    if (strcmp(string, support) == 0)
    {
        result = "support";
    }
    else if (strcmp(string, notsupport) == 0)
    {
        result = "not support";
    }
    else
    {
        DBGPRINTF("error string\n");
    }
    DBGPRINTF("nested comments is %s\n", result);//如果不允许嵌套注释，输出为*/,允许则输出/*
#endif
#if TEMP_TEST
    int a = 0xffffffff;
    int b = -0x1;
    float f = 0;
    typedef union _mbyte {
        struct {
            char call_id : 7;
            char rsv : 1;
        } bits;
        char config;
    } mbyte;
    mbyte byte;
    byte.config = 0x7f;
    DBGPRINTF("a.%d, a.%#x, byte.bits.call_id.%d, config.%d\n", a, a, byte.bits.call_id, byte.config);
    DBGPRINTF("b.%d, b.%#x, byte.bits.call_id.%d, config.%d\n", b, b, byte.bits.call_id, byte.config);
    DBGPRINTF("f.%g\n", f);
#endif
#if VAR_TYPE_FLOAT_DOUBLE_INT
    typedef union _float_type {
        float f;
        struct {
            u32 nMant : 23;     //尾数
            u32 nExp  : 8;       //指数
            u32 nSign : 1;      //符号位
        } ui;
    } float_type;
    float_type ft;
    ft.f = 128.101;//19.22233333;
    DBGPRINTF("float.%f, nSign.%#x, nExp.%#x, nMant.%#x\n", ft.f, ft.ui.nSign, ft.ui.nExp, ft.ui.nMant);
#endif
#if WIDE_NARROW_CHAR
    wchar_t web_url[] = L"http://c.biancheng.net";
    //wchar_t web_name[] = L"C语言中文网";
    wchar_t web_name[] = L"DDDDDDDDD";
    //setlocale(LC_ALL, "zh_CN");//将本地环境设置成简体中文
    wprintf(L"web_url: %ls \nweb_name: %ls \n", web_url, web_name);
    DBGPRINTF("web_url: %ls \nweb_name: %ls \n", web_url, web_name);
    DBGPRINTF("web_name: C语言中文网\n");

    
    wchar_t a = L'A';  //英文字符（基本拉丁字符）
    wchar_t b = L'9';  //英文数字（阿拉伯数字）
    wchar_t c = L'中';  //中文汉字
    wchar_t d = L'国';  //中文汉字
    wchar_t e = L'。';  //中文标点
    wchar_t f = L'ヅ';  //日文片假名
    wchar_t g = L'?';  //特殊符号
    wchar_t h = L'?';  //藏文
   
    //将本地环境设置为简体中文
    setlocale(LC_ALL, "zh-CN");
    //使用专门的 putwchar 输出宽字符
    putwchar(a);  putwchar(b);  putwchar(c);  putwchar(d);
    putwchar(e);  putwchar(f);  putwchar(g);  putwchar(h);
    putwchar(L'\n');  //只能使用宽字符
   
    //使用通用的 wprintf 输出宽字符
    wprintf(
        L"Wide chars: %lc %lc %lc %lc %lc %lc %lc %lc\n",  //必须使用宽字符串
        a, b, c, d, e, f, g, h
    );
    DBGPRINTF(
        "100%%12=%d \n100%%-12=%d \n-100%%12=%d \n-100%%-12=%d \n",
        100%12, 100%-12, -100%12, -100%-12
    );
#endif
#if SCANF_FUNCTION
    //int a, b, c;
    //scanf("%d %d", &a, &b);
    //printf("a+b=%d\n", a+b);
    //scanf("%d   %d", &a, &b);
    //printf("a+b=%d\n", a+b);
    //scanf("%d, %d, %d", &a, &b, &c);
    //printf("a+b+c=%d\n", a+b+c);
   
    //scanf("%d is bigger than %d", &a, &b);
    //printf("a(%d)-b(%d)=%d\n", a, b, a-b);

    //char d;
    //d = getchar();
    //printf("d: %c\n", d);
    //char e = getche();
    //printf("e: %c\n", e);
    char author[30], lang[30], url[30];
    gets(author);
    printf("author: %s\n", author);
    gets(lang);
    printf("lang: %s\n", lang);
    gets(url);
    printf("url: %s\n", url);
#endif
#if PRINTF_FUNCTION
    printf("C语言中文网");
    fflush(stdout);//本次输出结束后立即清空缓冲区
    sleep(5);
    printf("http://c.biancheng.net\n");

    int a = 1, b = 2;
    char c;
    scanf("a=%d", &a);
    while((c = getchar()) != '\n' && c != EOF);//在下次读取前清空缓冲区
    scanf("b=%d", &b);
    printf("a=%d, b=%d\n", a, b);
#endif
#if SET_PASSWORD
    char pwd[PWDLEN+1];
    printf("Input password: ");
    getpwd(pwd, PWDLEN);
    printf("The password is : %s \n", pwd);
#endif

#if IF_ELSE_SWITCH
    u32 a, b;
    DBGPRINTF("Input number b please:\n");
    scanf("%d", &b);
    u32 c = (a=b);
    if (a = b)
        DBGPRINTF("true(a=b(%d)), a=%d, b=%d\n", c, a, b);
    else
        DBGPRINTF("false(a=b(%d)), a=%d, b=%d\n", c, a, b);
#endif

#if MYSTERY_FUNCTION
    u8 n;
    scanf("%c", &n);
    mystery(n);
#endif

#if DAYS_IN_A_MONTH_OF_A_YEAR

#endif

    DBGPRINTF("test func end\n");
}

void how_many_days_in_a_month_of_a_year()
{
    u32 year, month, days;
    printf("Input the year and month please:\n");
    scanf("%d %d", &year, &month);
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            days = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            days = 30;
            break;
        case 2:
            if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
                days = 29;
            else
                days = 28;
            break;
        default:
            printf("month is wrong!!!\n");
            break;
    }
    printf("%d year %d month have %d days.\n", year, month, days);
}
void count_number_letters_space_and_others()
{
    u32 letters_cnt = 0;
    u32 digit_cnt = 0;
    u32 space_cnt = 0;
    u32 others_cnt = 0;
    char string[100] = {0};
    char *ptr = string;
    printf("Input a string please:\n");
    //scanf("%s", ptr);
    while((*ptr = getchar()) != '\n') {
        if ((*ptr >= 'a' && *ptr <= 'z') || (*ptr >= 'A' && *ptr <= 'Z'))
            letters_cnt++;
        else if (*ptr >= '0' && *ptr <= '9')
            digit_cnt++;
        else if (*ptr == ' ')
            space_cnt++;
        else
            others_cnt++;
        ptr++;
    }
    printf("string: %s\n", string);
    printf("letters_cnt.%d, digit_cnt.%d, space_cnt.%d, others_cnt.%d.\n", letters_cnt, digit_cnt, space_cnt, others_cnt);
}

void calc_compose_1yuan_with_125cent()
{
    s32 count = 0;
    register s32 i = 0;
    register s32 j = 0;
    register s32 k = 0;
    s32 steps = 0;
    for (i = 0; i <= 100/1; i++) {
        for (j = 0; j <= (100 - i)/2; j++) {
            for (k = 0; k <= (100 - i - 2*j)/5; k++) {
                steps++;
                if ((i + 2*j + 5*k) == 100) {
                    count++;
                    //DBGPRINTF("count.%d: %d(1), %d(2), %d(5)\n", count, i, j, k);
                    //if (count > 33) {
                    //    assert(0);
                    //}
                }
            }
        }
    }
    DBGPRINTF("there is %d ways to compose 100 with 1 2 5(steps.%d)\n", count, steps);
    /*
    for (i = 0; i <= 100/5; i++) {
        for (j = 0; j <= (100 - 5*i)/2; j++) {
            for (k = 0; k <= (100 - 5*i - 2*j); k++) {
                steps++;
                if ((i + 2*j + 5*k) == 100) {
                    count++;
                    //DBGPRINTF("count.%d: %d(1), %d(2), %d(5)\n", count, i, j, k);
                    //if (count > 33) {
                    //    assert(0);
                    //}
                }
            }
        }
    }
    DBGPRINTF("there is %d ways to compose 100 with 1 2 5(steps.%d)\n", count, steps);
    */
    steps = 0;
    count = 0;
    for (i = 0; i <= 100/5; i++) {
        for (j = 0; j <= (100 - 5*i)/2; j++) {
                steps++;
                //if ((i + 2*j + 5*k) == 100) {
                    count++;
                    //DBGPRINTF("count.%d: %d(1), %d(2), %d(5)\n", count, i, j, k);
                    //if (count > 33) {
                    //    assert(0);
                    //}
                //}
        }
    }
    DBGPRINTF("there is %d ways to compose 100 with 1 2 5(steps.%d)\n", count, steps);
}

void print_nine_nine_multiplication_table()
{
    u32 i, j, n;
    //左三角打印
    DBGPRINTF("左三角打印\n");
    for (i = 1; i <= 9; i++) {
        for (j = 1; j <= i; j++) {
            DBGPRINTF("%d*%d=%2d ", i, j, i*j);
        }
        DBGPRINTF("\n");
    }
    //右三角打印
    DBGPRINTF("右三角打印\n");
    for (i = 1; i <= 9; i++) {
        for (n = 1; n <= 9-i; n++) {
            DBGPRINTF("       ");
        }
        for (j = 1; j <= i; j++) {
            DBGPRINTF("%d*%d=%2d ", i, j, i*j);
        }
        DBGPRINTF("\n");
    }
    //倒左三角打印
    DBGPRINTF("倒左三角打印\n");
    for (i = 1; i <= 9; i++) {
        for (j = i; j <= 9; j++) {
            DBGPRINTF("%d*%d=%2d ", i, j, i*j);
        }
        DBGPRINTF("\n");
    }
    //倒右三角打印
    DBGPRINTF("倒右三角打印\n");
    for (i = 1; i <= 9; i++) {
        for (j = 1; j <= 9; j++) {
            if (j < i)
                DBGPRINTF("       ");
            else
                DBGPRINTF("%d*%d=%2d ", i, j, i*j);
        }
        DBGPRINTF("\n");
    }
}
void print_rhombus(u32 row_col)
{
    u32 i, j;
    for (i = 0; i < 2*row_col+2; i++) {
        if (i % 2 == 1) {//奇数行不打印
            DBGPRINTF("\n");
        } else {//偶数行打印*
            if (i <= row_col) {//*数量递增
                for (j = 0; j <= row_col; j++) {
                    if (j >= (row_col - i) / 2 && j <= (row_col + i) / 2)
                        DBGPRINTF("*");
                    else
                        DBGPRINTF(" ");
                }  
            } else {//*数量递减
                for (j = 0; j < row_col; j++) {
                    if (j >= (i - row_col) / 2 && j <= (i - row_col) / 2 + 2 * row_col - i)
                        DBGPRINTF("*");
                    else
                        DBGPRINTF(" ");
                }
            }
        }
    }
}

u32 print_rhombus1()
{
    int line;  // 菱形总行数
    int column;  // 菱形总列数
    int i;  // 当前行
    int j;  // 当前列
    DBGPRINTF("请输入菱形的行数(奇数)：");
    scanf("%d", &line);
    if(line%2==0){  // 判断是否是奇数
        DBGPRINTF("必须输入奇数！\n");
        exit(1);
    }
    column = line;  // 总行数和总列数相同
    for(i=1; i<=line; i++){  // 遍历所有行
        if(i<(line+1)/2+1){  // 上半部分（包括中间一行）
            for(j=1; j<=column; j++){  // 遍历上半部分的所有列
                if( (column+1)/2-(i-1)<=j && j<=(column+1)/2+(i-1) ){
                    DBGPRINTF("*");
                }else{
                    DBGPRINTF(" ");
                }
            }
        }else{  // 下半部分
            for(j=1; j<=column; j++){  // 遍历下半部分的所有列
                if( (column+1)/2-(line-i)<=j && j<=(column+1)/2+(line-i) ){
                    DBGPRINTF("*");
                }else{
                    DBGPRINTF(" ");
                }
            }
        }
        DBGPRINTF("\n");
    }
    return 0;
}
void hundred_yuan_buy_hundred_chickens()
{
    u32 i, j, k;//公鸡、母鸡、小鸡
    u32 count = 0;
    u32 cal_times = 0;
    for (i = 0; i < 100/5; i++) {
        for (j = 0; j < 100/3; j++) {
            for (k = 0; k < 100; k+=3) {
                if ((i+j+k) == 100 && (5*i+3*j+k/3) == 100) {
                    count++;
                    DBGPRINTF("count%d: %d只公鸡, %d只母鸡, %d只小鸡\n", count, i, j, k);
                }
                cal_times++;
            }
        }
    }
    DBGPRINTF("calc times is %d\n", cal_times);
}
extern double pow(double x, double y);

void calc_PI_value()
{
    u32 i;
    int numer, denomin;//分子和分母:numerator and denominator
    double PI = 0.0;
    for (i = 1; i < 1000000; i++) {
        if ((i + 1) % 2 == 0)
            numer = 1;
        else
            numer = -1;
        //numer = pow(-1, i+1);//(-1)^(i+1);
        denomin = 2 * i - 1;
        PI += (double)numer / denomin;
        //if (((double)numer / denomin < 0.000001) && ((double)numer / denomin > -0.000001)) {
        //if (fabs((double)numer / denomin) < 1e-6) {
                //DBGPRINTF("i = %d, numer / denomin = %lf\n", i, (double)numer / denomin);
                //DBGPRINTF("π= %lf\n", 4 * PI);
                //assert(0);
        //}
        //if (i < 1000) {
        //    DBGPRINTF("i.%d: %lf(numer.%d, denomin.%d)\n", i, (double)numer / denomin, numer, denomin);
        //}
    }
    PI = 4*PI;
    DBGPRINTF("π= %lf\n", PI);
}

int calc_PI_value1()
{
    float s=1;
    float pi=0;
    float i=1.0;
    float n=1.0;
    while(fabs(i)>=1e-6){
        pi+=i;
        n=n+2;
        // 这里设计的很巧妙，每次正负号都不一样 
        s=-s; 
        i=s/n;
    }
    pi=4*pi;
    printf("pi的值为：%.6f\n",pi);
    
    return 0;
}

typedef unsigned int uint32_t;
uint32_t ArrayMerge(uint32_t Asize, uint32_t *A, uint32_t Bsize, uint32_t *B, uint32_t *C) {
//请写出代码
    uint32_t i = 0, j = 0;
    uint32_t Csize = 0;
    if (A == NULL || B == NULL || (Asize == 0 && Bsize == 0)) {
        return 0;
    }
    if (Asize == 0) {
        for (j = 0; j < Bsize;) {
          	if (Csize == 0) {
            	C[Csize] = B[j];
                Csize++;
            } else {
            	if (C[Csize-1] != B[j]) {
                    C[Csize] = B[j];
                    Csize++;
            	}
            }
            j++;
        }
    } else if (Bsize == 0) {
        for (i = 0; i < Asize;) {
            if (Csize == 0) {
            	C[Csize] = A[i];
                Csize++;
            } else {
            	if (C[Csize-1] != A[i]) {
                    C[Csize] = A[i];
                    Csize++;
            	}
            }
            i++;
        }
    } else {
        while (i < Asize || j < Bsize) {
            if (i == Asize) {
                if (Csize == 0) {
                	C[Csize] = B[j];
                    Csize++;
                    DBGPRINTF("B[%u]=%u, Csize.%u\n", j, B[j], Csize);
                } else {
                	if (C[Csize-1] != B[j]) {
                        C[Csize] = B[j];
                        Csize++;
                        DBGPRINTF("B[%u]=%u, Csize.%u\n", j, B[j], Csize);
                	}
                }
                j++;
            } else if (j == Bsize) {
                if (Csize == 0) {
                    C[Csize] = A[i];
                    Csize++;
                    DBGPRINTF("A[%u]=%u, Csize.%u\n", i, A[i], Csize);
                } else {
                    if (C[Csize-1] != A[i]) {
                        C[Csize] = A[i];
                        Csize++;
                        DBGPRINTF("A[%u]=%u, Csize.%u\n", i, A[i], Csize);
                    }
                }
                i++;
            } else {
                if (A[i] < B[j]) {
                    if (Csize == 0) {
        	            C[Csize] = A[i];
           	            Csize++;
           	            DBGPRINTF("A[%u]=%u, Csize.%u\n", i, A[i], Csize);
        	        } else {
        	            if (C[Csize-1] != A[i]) {
                	        C[Csize] = A[i];
               	            Csize++;
               	            DBGPRINTF("A[%u]=%u, Csize.%u\n", i, A[i], Csize);
        	            }
        	        }
                    i++;
                } else if (A[i] > B[j]) {
                    if (Csize == 0) {
        	            C[Csize] = B[j];
            	        Csize++;
            	        DBGPRINTF("B[%u]=%u, Csize.%u\n", j, B[j], Csize);
    	            } else {
        	            if (C[Csize-1] != B[j]) {
                	        C[Csize] = B[j];
                	        Csize++;
                	        DBGPRINTF("B[%u]=%u, Csize.%u\n", j, B[j], Csize);
        	            }
        	        }
                    j++;
                } else {
                    if (Csize == 0) {
        	            C[Csize] = A[i];
           	            Csize++;
           	            DBGPRINTF("A[%u]=%u, Csize.%u\n", i, A[i], Csize);
    	            } else {
        	            if (C[Csize-1] != A[i]) {
                	        C[Csize] = A[i];
               	            Csize++;
               	            DBGPRINTF("A[%u]=%u, Csize.%u\n", i, A[i], Csize);
        	            }
        	        }
                    i++;
                    j++;
                }
            }
        }
    }
    printf("Csize = %u\n", Csize);
    return Csize;
}
int aliTest() 
{
    uint32_t A[] = {1,3,5,11,22,55,87};
    uint32_t B[] = {1,2,2,3,8,11,25};
    uint32_t C[10];
    uint32_t Csize;
    uint32_t i;
    Csize = ArrayMerge(sizeof(A)/sizeof(uint32_t), A, sizeof(B)/sizeof(uint32_t), B, C);
    printf("C[%u]: ", Csize);
    for (i = 0; i < Csize; ++i) {
        printf("%u ", C[i]);
    }
    printf("\n");
    return 0;
}

typedef struct var_array {
    u32 array_ba[0];
    u32 array[2];
    u32 array_end[0];
} var_array_t;

void array0_test()
{
    var_array_t var_arr;
    DBGPRINTF("var_arr.array_ba = %p\n", var_arr.array_ba);
    DBGPRINTF("var_arr.array_end = %p\n", var_arr.array_end);
    DBGPRINTF("sizeof(var_array_t) = %d\n", sizeof(var_array_t));
    DBGPRINTF("sizeof(var_array_t.array_ba) = %d\n", sizeof(var_arr.array_ba));
    DBGPRINTF("sizeof(var_array_t.array_end) = %d\n", sizeof(var_arr.array_end));
    DBGPRINTF("&var_array_t.var_arr = %p\n", &var_arr);
    DBGPRINTF("&var_array_t.array_ba = %p\n", &var_arr.array_ba);
    DBGPRINTF("&var_array_t.array = %p\n", &var_arr.array);
    DBGPRINTF("var_array_t.array = %p\n", var_arr.array);
    DBGPRINTF("&var_array_t.array_end = %p\n", &var_arr.array_end);
}
void judge_number_is_prime()
{
    u32 number;
    DBGPRINTF("请输入一个数(方法1):\n");
    scanf("%d", &number);

    u32 i;
    bool isprime = TRUE;
    for (i = 2; i < number; i++) {
        if (number % i == 0) {
            isprime = FALSE;
            break;
        }
    }
    DBGPRINTF("%d is%sprime\n", number, isprime ? " " : " not ");

    DBGPRINTF("请再输入一个数(方法2):\n");
    scanf("%d", &number);
    u32 squareroot;
    squareroot = sqrt(number);
    for (i = 2; i <= squareroot; i++) {
        if (number % i == 0) {
            isprime = FALSE;
            break;
        }
    }
    DBGPRINTF("%d is%sprime\n", number, isprime ? " " : " not ");
}

void perfect_number_in_range()
{
    u32 max;
    register u32 i, j;
    u32 sum;
    DBGPRINTF("输入一个数:(求1到这个范围内的完数)\n");
    scanf("%d", &max);
    for (i = 2; i <= max; i++) {
        sum = 0;
        for (j = 1; j <= i/2; j++) {
            if (i % j == 0) {
                sum += j;
            }
        }
        if (sum == i) {
            DBGPRINTF("%d is a perfect number\n", i);
        }
    }
}

void close_number_in_range()
{
    u32 max;
    register u32 i, j;
    u32 sumA, sumB;
    DBGPRINTF("输入一个数:(求1到这个范围内的亲密数)\n");
    scanf("%d", &max);

    for (i = 2; i <= max; i++) {
        sumA = 0;
        for (j = 1; j <= i/2; j++) {
            if (i % j == 0) {
                sumA += j;
            } 
        }
        sumB = 0;
        for (j = 1; j <= sumA/2; j++) {
            if (sumA % j == 0) {
                sumB += j;
            }
        }
        if (sumB == i && i < sumA) {
            DBGPRINTF("A(%9d) and B(%9d) is close numbers\n", i, sumA);
        }
    }
}

u32 fish(u32 n, u8 person)
{
    u32 ret = FALSE;
    u32 fishOnePerson;

    if (!(n >= 1)) {
        return FALSE;
    }
    if ((n - 1) % 5 == 0) {
        fishOnePerson = (n - 1) / 5;
        //DBGPRINTF("%d fishes, %d person(one person %d fishes)!!!\n", n, person, fishOnePerson);
        if (person <= 1) {
            ret = TRUE;
        } else {
            person--;
            ret = fish(4 * fishOnePerson, person);
        }
    } else {
        ret = FALSE;
    }
    return ret;
}

void divide_fish_issue()
{
    u32 fishes = 1;
    u8 person = 5;
    while (fish(fishes, person) == FALSE) {
        fishes++;
    }
    DBGPRINTF("%d fishes, %d person!!!\n", fishes, person);
}
u32 how_old_is_the_person(u32 person)
{
    u32 ages;
    if (person < 1 || person > 5){
        DBGPRINTF("wrong person\n");
        return 0;
    }
    if (person == 1) {
        ages = 10;
    } else {
        ages = how_old_is_the_person(person-1) + 2;
    }
    return ages;
}
void how_old_is_n_person()
{
    u32 person;
    u32 ages;
    DBGPRINTF("which person's age do you want to know?(input a number plz):\n");
    scanf("%d", &person);
    ages = how_old_is_the_person(person);
    DBGPRINTF("the %dth person is %d years old\n", person, ages);
}
void delete_asterisk(char *dest, const char *src, u32 srcLen)
{
    u32 first, end;
    u32 temp = 0;
    u32 idx = 0;
    if (srcLen > 50) {
        DBGPRINTF("string size is too big\n");
        assert(0);
    }
    DBGPRINTF("srcLen.%d\n", srcLen);
    
    char str1[50] = {0};
    char str2[50] = {0};
    char str3[50] = {0};
    //str1
    while (src[temp] == '*' && temp < srcLen) {
        temp++;
    }
    first = temp;
    DBGPRINTF("first.%d\n", first);
    if (first == srcLen - 1) {
        strcpy(dest, src);
        return;
    }
    strncpy(str1, src, first);
    
    //str3
    temp = srcLen - 1;
    idx = 0;
    while (src[temp] == '*' && temp > 0) {
        temp--;
        str3[idx] = '*';
        idx++;
    }
    end = temp;
    DBGPRINTF("end.%d\n", end);
    if (end == 0) {
        assert(0);
    }
    
    //str2
    idx = 0;
    for (temp = first; temp <= end; temp++) {
        //DBGPRINTF("temp(%d), src[%d](%c)\n", temp, temp, src[temp]);
        if (src[temp] != '*') {
            str2[idx] = src[temp];
            idx++;
        }
    }
    
    strcat(dest, str1);
    //DBGPRINTF("str1.%s\n", str1);
    //DBGPRINTF("dest.%s\n", dest);
    strcat(dest, str2);
    //DBGPRINTF("str2.%s\n", str2);
    //DBGPRINTF("dest.%s\n", dest);
    strcat(dest, str3);
    //DBGPRINTF("str3.%s\n", str3);
    //DBGPRINTF("dest.%s\n", dest);
    
}
void delete_asterisk_in_the_string()
{
    char strSrc[STRLEN] = {0};
    char strDest[STRLEN] = {0};
    u32 len;
    DBGPRINTF("Input a string plz(only asterisks and letters can be entered)\n");
    gets(strSrc);
    len = strlen(strSrc);
    delete_asterisk(strDest, strSrc, len);
    puts(strDest);
}

void get_the_last_number_lose_game()//抽火柴游戏
{
/*
    u32 lastNum = 21;
    u32 gotNum = 0;
    u32 restNum = 0;
    u32 people = 0;
    u32 computer = 0;
    DBGPRINTF("一共%d根火柴,谁先抽到第21根谁就输(一次只能抽1~4根,不能不抽也不能多抽), 加油哦!!!!!\n", lastNum);
    DBGPRINTF("game start>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    while (gotNum < lastNum) {
        if (gotNum == lastNum -1) {
            DBGPRINTF("people: 1");
            DBGPRINTF("\nYOU LOSE\n");
            break;
        }
        
        DBGPRINTF("people:");
        scanf("%d", &people);
        if (people < 1 || people > 4) {
            DBGPRINTF("你违规了，重新输入\n");
            continue;
        }
        restNum = lastNum - gotNum - people;
        
        if (restNum == 0) {
            computer = 0;
        } else {
            computer = 5 - people;
        }
        DBGPRINTF("computer: %d\n", computer);
        
        restNum -= computer;
        DBGPRINTF("目前还剩 %d 根火柴\n", restNum);
        
        gotNum = lastNum - restNum;
    }

    if (people == 0) {
        DBGPRINTF("\nYOU WIN\n");
    } else if (gotNum != lastNum - 1) {
        DBGPRINTF("\nYOU LOSE\n");
    }
    DBGPRINTF("\nGAME OVER>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    */

    int computer, people, spare = 21;
    printf(" -----------------------------------------\n");
    printf(" --------  你不能战胜我,不信试试  --------\n");
    printf(" -----------------------------------------\n\n");
    printf("Game begin:\n\n");
    while(1)
    {
        printf(" ----------  目前还有火柴 %d 根 ----------\n", spare);
        printf("People:");
        scanf("%d", &people);
        if(people<1 || people>4 || people>spare)
        {
            printf("你违规了，你取的火柴数有问题!\n\n");
            continue;
        }
        spare = spare - people;
        if( spare==0 )
        {
            printf("\nComputer win! Game Over!\n");
            break;
        }
        computer = 5 - people;
        spare = spare - computer;
        printf("Computer:%d  \n", computer);
        if( spare==0 )
        {
            printf("\nPeople win! Game Over!\n");
            break;
        }
    }
}
#define X 8
#define Y 8
int chess[X][Y];
u64 totaltimes = 0;
int gtag = 1;

int nextxy(int *x, int *y, int count)  /*找到基于x,y位置的下一个可走的位置*/
{
    totaltimes++;
    //DBGPRINTF("x(%d) y(%d) count(%d) gtag(%d) totaltimes(%lld)\n", *x, *y, count, gtag, totaltimes);
    switch(count)
    {
        case 0:
            if(*x+2<=X-1 && *y-1>=0 && chess[*x+2][*y-1]==0)
            {
                *x=*x+2;
                *y=*y-1;
                return 1;
            }
            break;
        case 1:
            if(*x+2<=X-1 && *y+1<=Y-1 && chess[*x+2][*y+1]==0)
            {
                *x=*x+2;
                *y=*y+1;
                return 1;
            }
            break;
        case 2:
            if(*x+1<=X-1 && *y-2>=0 && chess[*x+1][*y-2]==0)
            {
                *x=*x+1;
                *y=*y-2;
                return 1;
            }
            break;
        case 3:
            if(*x+1<=X-1 && *y+2<=Y-1 && chess[*x+1][*y+2]==0)
            {
                *x=*x+1;
                *y=*y+2;
                return 1;
            }
            break;
        case 4:
            if(*x-2>=0 && *y-1>=0 && chess[*x-2][*y-1]==0)
            {
                *x=*x-2;
                *y=*y-1;
                return 1;
            }
            break;
        case 5:
            if(*x-2>=0 && *y+1<=Y-1 && chess[*x-2][*y+1]==0)
            {
                *x=*x-2;
                *y=*y+1;
                return 1;
            }
            break;
        case 6:
            if(*x-1>=0 && *y-2>=0 && chess[*x-1][*y-2]==0)
            {
                *x=*x-1;
                *y=*y-2;
                return 1;
            }
            break;
        case 7:
            if(*x-1>=0 && *y+2<=Y-1 && chess[*x-1][*y+2]==0)
            {
                *x=*x-1;
                *y=*y+2;
                return 1;
            }
            break;
        default:
            break;
    }
    return 0;
}

int TravelChessBoard(int x, int y, int tag)  /*深度优先搜索地"马踏棋盘"*/
{
    int x1=x, y1=y, flag=0, count=0;
    chess[x][y]=tag;
    gtag = tag;
    if(tag == X*Y)
    {
        return 1;
    }
    flag=nextxy(&x1, &y1, count);
    while(flag==0 && count<7)
    {
        count=count+1;
        flag=nextxy(&x1, &y1, count);
    }
    while(flag)
    {
        if(TravelChessBoard(x1, y1, tag+1))
            return 1;
        x1=x;
        y1=y;
        count=count+1;
        flag=nextxy(&x1, &y1, count);  /*寻找下一个(x,y)*/
        while(flag==0 && count<7)
        {  /*循环地寻找下一个(x,y)*/
            count=count+1;
            flag=nextxy(&x1, &y1, count);
        }
    }
    if(flag == 0)
        chess[x][y]=0;
    return 0;
}

void horse_travel_chessboard()
{
    int i, j;
    for(i=0; i<X; i++)
        for(j=0; j<Y; j++)
            chess[i][j]=0;
    if(TravelChessBoard(4, 4, 1))
    {
        for(i=0; i<X; i++)
        {
            for(j=0; j<Y; j++)
                printf("%-5d", chess[i][j]);
            printf("\n");
        }
        printf("The horse has travelled the chess borad\n");
    }
    else
        printf("The horse cannot travel the chess board\n");
    return;
}
void matrix_transpose()
{
    u32 row, col;
    u32 temp;
    u32 matrix[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8}, 
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    DBGPRINTF("原始矩阵:\n");
    for (row = 0; row < 4; row++) {
        for (col = 0; col < 4; col++) {
            DBGPRINTF(" %-5d", matrix[row][col]);
        }
        DBGPRINTF("\n");
    }
    for (row = 0; row < 4; row++) {
        for (col = 0; col < 4; col++) {
            if (col > row) {
                temp = matrix[row][col];
                matrix[row][col] = matrix[col][row];
                matrix[col][row] = temp;
            }
        }
    }
    
    DBGPRINTF("转置矩阵:\n");
    for (row = 0; row < 4; row++) {
        for (col = 0; col < 4; col++) {
            DBGPRINTF(" %-5d", matrix[row][col]);
        }
        DBGPRINTF("\n");
    }
    
}
#define N 5

void magic_square()
{
    u32 n;
    u32 *matrix;
    u32 idx;
    u32 i, j;
    DBGPRINTF("魔方阵的行数是:(请输入一个奇数)\n");
    scanf("%d", &n);
    if (n%2 == 0) {
        n = n+1;
    }
    //alloc memory
    matrix = (u32 *)malloc(n*n*sizeof(u32));
    DBGPRINTF("alloc %d byte\n", n*n*sizeof(u32));
    //fill value
    i = 0;
    j = n/2;
    for (idx = 1; idx <= n*n; idx++) {
        matrix[i*n+j] = idx;
        
        if (idx % n == 0) {
            i = i+1;
        } else {
            if (i == 0) {
                i = n-1;
            } else {
                i = i-1;
            }
            
            if (j == n-1) {
                j = 0;
            } else {
                j = j+1;
            }
        }
    }
    //DBGPRINTF("matrix[26] = %d\n", matrix[26]);//check memory overflow
    //print
    u32 row, col;
    for (row = 0; row < n; row++) {
        for (col = 0; col < n; col++) {
            DBGPRINTF("  %5d", matrix[row*n + col]); 
        }
        DBGPRINTF("\n");
    }
    free(matrix);
#if 0
    int a[N][N] = {{0}};
    //int a[N][N] = {0};
    int k, t, x, y;
    i=0;  /*自然数1的行标*/
    j=N/2;  /*自然数1的列标*/
    t=N-1;  /*最后一行、最后一列的下标*/
    for(k=1; k<=N*N; k++)
    {
        a[i][j]=k;
        x=i;
        y=j;
        if(i == 0)
            i=t;
        else
            i=i-1;
        if(j != t)
            j=j+1;
        else
            j=0;
        if(a[i][j]!=0)
        {
            i=x+1;
            j=y;
        }
    }
    printf("生成的5-魔方阵为：");
    for(i=0; i<N; i++)
    {
        printf("\n");
        for(j=0; j<N; j++)
        {
            printf("%3d", a[i][j]);
        }
    }
    printf("\n");
#endif
}
void shake_elbows_game()
{
    u32 countA = 0, countB = 0;
    u32 winA = 0, winB = 0, deuce = 0;
    u32 idx = 0;
    u32 times = 0;
    srand((unsigned int)time(NULL));//设置随机种子
    rand();//初始化随机数
    for (times = 0; times < 10; times++) {
        countA = 0;
        countB = 0;
        for (idx = 0; idx < 6; idx++) {
            countA += rand()%6+1;
            countB += rand()%6+1;
        }
        DBGPRINTF("countA(%d), countB(%d)\n", countA, countB);
        if (countA > countB) {
            winA++;
        } else if (countA < countB) {
            winB++;
        } else {
            deuce++;
        }
    }
    DBGPRINTF("winA(%d) winB(%d) deuce(%d)\n", winA, winB, deuce);
    if (winA > winB) {
        DBGPRINTF("\nperson A wins.\n\n");
    } else if (winA < winB) {
        DBGPRINTF("\nperson B wins,\n\n");
    } else {
        DBGPRINTF("\ndeuce(平局)\n\n");
    }
}

float cal(float x, float y, u8 op)
{
    switch(op) {
        case 0: 
            return x+y;
        case 1:
            return x-y;
        case 2:
            return x*y;
        case 3:
            return x/y;
        //case 4:
            //return (u32)x%(u32)y;
        default:
            DBGPRINTF("error op\n");
            return 0.0;
    }
}
float calc_model1(float a, float b, float c, float d, u8 op0, u8 op1, u8 op2)//((a # b) # c) # d
{
    float ret1, ret2, ret3;
    ret1 = cal(a, b, op0);
    ret2 = cal(ret1, c, op1);
    ret3 = cal(ret2, d, op2);
    return ret3;
}
float calc_model2(float a, float b, float c, float d, u8 op0, u8 op1, u8 op2)//(a # (b # c)) # d
{
    float ret1, ret2, ret3;
    ret1 = cal(b, c, op1);
    ret2 = cal(a, ret1, op0);
    ret3 = cal(ret2, d, op2);
    return ret3;
}

float calc_model3(float a, float b, float c, float d, u8 op0, u8 op1, u8 op2)//a # ((b # c) # d)
{
    float ret1, ret2, ret3;
    ret1 = cal(b, c, op1);
    ret2 = cal(ret1, d, op2);
    ret3 = cal(a, ret2, op0);
    return ret3;
}


float calc_model4(float a, float b, float c, float d, u8 op0, u8 op1, u8 op2)//a # (b # (c # d))
{
    float ret1, ret2, ret3;
    ret1 = cal(c, d, op2);
    ret2 = cal(b, ret1, op1);
    ret3 = cal(a, ret2, op0);
    return ret3;
}

float calc_model5(float a, float b, float c, float d, u8 op0, u8 op1, u8 op2)//(a # b) # (c # d)
{
    float ret1, ret2, ret3;
    ret1 = cal(a, b, op0);
    ret2 = cal(c, d, op2);
    ret3 = cal(ret1, ret2, op1);
    return ret3;
}

bool cal_to_24(u32 a, u32 b, u32 c, u32 d)
{
    bool ret = FALSE;
    char op[5] = {'+', '-', '*', '/', '%'};
    u8 op0, op1, op2;
    
    for (op0 = 0; op0 < 4; op0++) {//0:+  1:-  2:*  3:/  4:%
        for (op1 = 0; op1 < 4; op1++) {
            for (op2 = 0; op2 < 4; op2++) {
                if (calc_model1(a, b, c, d, op0, op1, op2) == 24) {
                    DBGPRINTF("((%d%c%d)%c%d)%c%d==24\n", a, op[op0], b, op[op1], c, op[op2], d);
                    ret = TRUE;
                }
                if (calc_model2(a, b, c, d, op0, op1, op2) == 24) {
                    DBGPRINTF("(%d%c(%d%c%d))%c%d==24\n", a, op[op0], b, op[op1], c, op[op2], d);
                    ret = TRUE;
                }
                if (calc_model3(a, b, c, d, op0, op1, op2) == 24) {
                    DBGPRINTF("%d%c((%d%c%d)%c%d)==24\n", a, op[op0], b, op[op1], c, op[op2], d);
                    ret = TRUE;
                }
                if (calc_model4(a, b, c, d, op0, op1, op2) == 24) {
                    DBGPRINTF("%d%c(%d%c(%d%c%d))==24\n", a, op[op0], b, op[op1], c, op[op2], d);
                    ret = TRUE;
                }
                if (calc_model5(a, b, c, d, op0, op1, op2) == 24) {
                    DBGPRINTF("(%d%c%d)%c(%d%c%d)==24\n", a, op[op0], b, op[op1], c, op[op2], d);
                    ret = TRUE;
                }
            }
        }
    }

    return ret;
}
void calc_expression_to_24()
{
    u32 a, b, c, d;
    DBGPRINTF("input four intergers(1-10) please\n");
input:
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if (a<1 || a>10 || b<1 || b>10 || c<1 || c>10 || d<1 || d>10) {
        DBGPRINTF("input illege, input again please\n");
        goto input;
    }
    if (cal_to_24(a, b, c, d));
    else
        DBGPRINTF("sorry, the four interger cannot be calculated to 24\n");
        
    
}
void stamp_issue()
{
    u32 idx;
    u32 stamp1, stamp2, stamp3, stamp4;
    u32 num1, num2, num3, num4;
    static u32 s[1000] = {0};//邮资
    DBGPRINTF("input four stamp value:\n");
    scanf("%d %d %d %d", &stamp1, &stamp2, &stamp3, &stamp4);
    for (num1 = 0; num1 <= 5; num1++) {
        for (num2 = 0; num1+num2 <= 5; num2++) {
            for (num3 = 0; num1+num2+num3 <= 5; num3++) {
                for (num4 = 0; num1+num2+num3+num4 <= 5; num4++) {
                    if (stamp1*num1 + stamp2*num2 + stamp3*num3 + stamp4*num4) {
                        s[stamp1*num1 + stamp2*num2 + stamp3*num3 + stamp4*num4]++;
                    }
                }
            }
        }
    }
    u32 max_idx;
    for (idx = 0; idx < sizeof(s) / sizeof(s[0]); idx++) {
        if (s[idx]) {
            max_idx = idx;
        }
    }
    DBGPRINTF("num1=%d num2=%d\n", num1, num2);
    DBGPRINTF("the max value is %d sizeof(a=b+1)=%d\n", max_idx, sizeof(num1 = num2+1));
    DBGPRINTF("num1=%d num2=%d\n", num1, num2);
}
void print_compile_info()
{
    DBGPRINTF("compile time: date(%s) time(%s)\n", __DATE__, __TIME__);
}

void calc_n_numbers_sum()
{
    s32 sum = 0;
    s32 num;
    do {
        DBGPRINTF("\nEnter a interger > ");
        scanf("%d", &num);
        if (num > 0)
            sum += num;
    } while (num > 0);
    DBGPRINTF("\nThe sum is %d\n", sum);
}

typedef struct _money_worth {
    u32 dollars;
    u32 pennies;
    u32 nickles;
    u32 dimes;
    u32 quarters;
} money_worth;
void calc_how_many_your_collection_worth()
{
    u32 pennies;
    u32 nickles;
    u32 dimes;
    u32 quarters;
    u32 left;//临时变量，将会用于各种计算
    DBGPRINTF("\nEnter the number of quarters, dimes, nickles, and pennies: ");
    scanf("%d %d %d %d", &quarters, &dimes, &nickles, &pennies);

    left = 25 * quarters + 10 * dimes + 5 * nickles + pennies;
    money_worth my_money;
    my_money.dollars = left / 100;
    my_money.quarters = left % 100 /25;
    my_money.dimes = left % 100 % 25 / 10;
    my_money.nickles = left % 100 % 25 % 10 /5;
    my_money.pennies = left % 100 % 25 % 10 % 5;
    DBGPRINTF("\nMy collection is worth %d dollars, %d quarter, %d dimes, %d nickels, and %d pennies\n",
        my_money.dollars, my_money.quarters, my_money.dimes, my_money.nickles, my_money.pennies);
}

void exchange(u32 *a, u32 *b)
{
    u32 temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void array_sort(u32 *array, u32 size)
{
    u32 i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = i+1; j < size; j++) {  //for (j = i; j < size; j++) {
            //DBGPRINTF("array[%d](%d) array[%d](%d)\n", i, j, array[i], array[j]);
            if (array[i] > array[j]) {
                exchange(&array[i], &array[j]);
            }
        }
    }
}
void auto_deal_procedure()
{
    // 1-d 黑桃   11-1d 红桃  21-2d 梅花 31-3d 方块 
    u32 card[54] = {0};
    u32 shuffled_card[54] = {0};
    u32 a[17];
    u32 b[17];
    u32 c[17];
    u32 d[3];//底牌3张
    u8 card_cnt = 54;
    //新牌
    u8 idx = 0;
    u8 type;
    for (idx = 0; idx < card_cnt; idx++) {
        type = idx / 13;
        //DBGPRINTF("type.%d\n", type);
        switch(type) {
            case 0: 
                card[idx] = idx % 13 + 1;
                break;
            case 1:
                card[idx] = idx % 13 + 1 + 0x10;
                break;
            case 2:
                card[idx] = idx % 13 + 1 + 0x20;
                break;
            case 3:
                card[idx] = idx % 13 + 1 + 0x30;
                break;
            case 4:
                if (idx == 52)
                    card[idx] = 0xFE;
                else if (idx == 53)
                    card[idx] = 0xFF;
                else
                    ASSERT(FALSE);
                break;
            default:
                ASSERT(FALSE);
                break;
        }
    }
    //查牌
#if 0
    for (idx = 0; idx < card_cnt; idx++) {
        DBGPRINTF("card[%d] = 0x%x\n", idx, card[idx]);
    }
#endif
    //洗牌
    u8 remain_card_cnt;
    u8 fetch_idx;
    u8 idx1;
    u8 idx2;
    for (idx = 0; idx < card_cnt; idx++) {
        remain_card_cnt = card_cnt - idx;
        //设置种子
        srand((unsigned)time(NULL));
        //生成随机数
        fetch_idx = rand() % remain_card_cnt;
        DBGPRINTF("fetch_idx.%d\n", fetch_idx);
        shuffled_card[idx] = card[fetch_idx];
        for (idx1 = fetch_idx; idx1 < remain_card_cnt; idx1++) {
            if (fetch_idx < remain_card_cnt - 1)
                card[idx1] = card[idx1 + 1];
            else
                card[idx1] = 0;
        }
        for (idx2 = 0; idx2 < card_cnt; idx2++) {
            //DBGPRINTF("card[%d] = 0x%x\n", idx2, card[idx2]);
        }
    }
    //洗牌后查牌
#if 0
    for (idx = 0; idx < card_cnt; idx++) {
        DBGPRINTF("shuffled_card[%d] = 0x%x\n", idx, shuffled_card[idx]);
    }
#endif
    //发牌
    u8 idx_a = 0;
    u8 idx_b = 0;
    u8 idx_c = 0;
    for (idx = 0; idx < card_cnt - 3; idx++) {
        if (idx % 3 == 0) {
            a[idx_a] = shuffled_card[idx];
            idx_a++;
        }
        else if (idx % 3 == 1) {
            b[idx_b] = shuffled_card[idx];
            idx_b++;
        }
        else if (idx % 3 == 2) {
            c[idx_c] = shuffled_card[idx];
            idx_c++;
        }
    }
    for (idx = 0; idx < 3; idx++) {
        d[idx] = shuffled_card[card_cnt - (3 - idx)];
    }
    //拿牌
#if 1
    DBGPRINTF("\na:\n");
    for (idx = 0; idx < 17; idx++) {
        DBGPRINTF(" %2X ", a[idx]);
    }
    DBGPRINTF("\nb:\n");
    for (idx = 0; idx < 17; idx++) {
        DBGPRINTF(" %2X ", b[idx]);
    }
    DBGPRINTF("\nc:\n");
    for (idx = 0; idx < 17; idx++) {
        DBGPRINTF(" %2X ", c[idx]);
    }
    DBGPRINTF("\n底牌:\n");
    for (idx = 0; idx < 3; idx++) {
        DBGPRINTF(" %2X ", d[idx]);
    }
    DBGPRINTF("\n");
#endif
    //齐牌
    array_sort(a, sizeof(a)/sizeof(u32));
    array_sort(b, sizeof(b)/sizeof(u32));
    array_sort(c, sizeof(c)/sizeof(u32));
    array_sort(d, sizeof(d)/sizeof(u32));
    
    //看牌
    DBGPRINTF("\na:\n");
    for (idx = 0; idx < 17; idx++) {
        DBGPRINTF(" %2X ", a[idx]);
    }
    DBGPRINTF("\nb:\n");
    for (idx = 0; idx < 17; idx++) {
        DBGPRINTF(" %2X ", b[idx]);
    }
    DBGPRINTF("\nc:\n");
    for (idx = 0; idx < 17; idx++) {
        DBGPRINTF(" %2X ", c[idx]);
    }
    DBGPRINTF("\n底牌:\n");
    for (idx = 0; idx < 3; idx++) {
        DBGPRINTF(" %2X ", d[idx]);
    }
    DBGPRINTF("\n");
    
}

void dr_riddle_issue()
{
    u8 A, B, C;
    for (A = 0; A <= 1; A++) {
        for (B = 0; B <= 1; B++) {
            for (C = 0; C <= 1; C++) {
                if (((A && (A+B+C == 2)) || (!A && (A+B+C != 2))) &&
                    ((B && (A+B+C == 1)) || (!B && (A+B+C != 1))) &&
                    ((C && (A+B+C == 1)) || (!C && (A+B+C != 1)))) {
                    DBGPRINTF("第一个人来自%s\n", A ? "诚实族" : "说谎族");
                    DBGPRINTF("第二个人来自%s\n", B ? "诚实族" : "说谎族");
                    DBGPRINTF("第三个人来自%s\n", C ? "诚实族" : "说谎族");
                }
            }
        }
    }
}

void dr_riddle_issue1()
{
    u8 L, M, R;//左中右 分别表示来自诚实族
    u8 LL, MM, RR;//分别表示来自两面族
    for (L = 0; L <= 1; L++) {
        for (M = 0; M <= 1; M++) {
            for (R = 0; R <= 1; R++) {
                for (LL = 0; LL <= 1; LL++) {
                    for (MM = 0; MM <= 1; MM++) {
                        for (RR = 0; RR <= 1; RR++) {
                            if (((L && !LL && M && !MM) || (!L && !M)) &&
                              ((!M && MM) || (!M && !MM)) &&
                              ((R && !M && !MM) || (!R && !RR && ((M && !MM) || (!M && MM))) || (!R && RR)) &&
                              (L + M + R == 1) &&
                              (LL+ MM + RR == 1) &&
                              (L+LL!=2 && M+MM!=2 && R+RR!=2)) {
                                DBGPRINTF("左边的人来自%s\n", L ? "诚实族" : (LL ? "两面族" : "说谎族"));
                                DBGPRINTF("中间的人来自%s\n", M ? "诚实族" : (MM ? "两面族" : "说谎族"));
                                DBGPRINTF("右边的人来自%s\n", R ? "诚实族" : (RR ? "两面族" : "说谎族"));
                            }
                        }
                    }
                }
            }
        }
    }
}
u32 get_right_loc_num(u32 num1, u32 num2)
{
    u32 right_loc_num = 0;
    u32 i;
    for (i = 0; i < 4; i++) {
        if ((num1 / (u32)pow(10, i)) % 10 == (num2 / (u32)pow(10, i)) % 10) {
            right_loc_num++;
        }    
    }
    return right_loc_num;
}

u32 get_right_num(u32 num1, u32 num2)
{
    u32 right_num = 0;
    u32 i, j;
    u32 num3, num4;
    u32 loc[4] = {0};
    bool flag = 0;
    num3 = num1;
    for (i = 1; i < 5; i++) {
        num4 = num2;
        flag = 1;
        for (j = 1; j < 5; j++) {
            if (num3 % 10 == num4 % 10) {
                if (flag && j != loc[0] && j != loc[1] && j != loc[2] && j != loc[3]) {
                    right_num++;
                    flag = 0;
                    loc[right_num-1] = j; 
                }
            }
            num4 /= 10;
        }
        num3 /= 10;
    }
    return right_num;
}

void guess_the_number_game()
{
    u32 num;
    u32 guess_num;
    u32 right_loc_num, right_num;//位置正确的数字个数和数字正确的个数
    u32 guess_times = 0;//总共猜了多少次
    srand((unsigned)time(NULL));
    num = rand() % 9000 + 1000;//1000 ~ 9999
    //DBGPRINTF("num = %d\n", num);
    do {
        DBGPRINTF("Enter a four digit number please: ");
        scanf("%d", &guess_num);
        guess_times++;
        if (guess_num != num) {
            right_loc_num = get_right_loc_num(num, guess_num);
            right_num = get_right_num(num, guess_num);
            DBGPRINTF("%d right loc, %d right num, go on please!\n", right_loc_num, right_num);
        }
        else {
            DBGPRINTF("congratulations, you are right, the num is %d!!!\n", num);
        }
    } while (guess_num != num);
    DBGPRINTF("you guessed %d times at all\n", guess_times);
}

bool num_is_prime(u32 num)
{
    u32 i;
#if 0
    for (i = 2; i <= num/2; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
#else
    for (i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0;
        }
    }
#endif
    return 1;
}
void verify_goldbach_conjecture()
{
    u32 i = 0;
    u32 j = 0;
    bool flag = TRUE;
    for (i = 4; i <= 2000; i+=2) {
        for (j = 2; j < i; j++) {
            if (num_is_prime(j) && num_is_prime(i-j)) {
                DBGPRINTF("num(%d) = i(%d) + j(%d)\n", i, j, i-j);
                break;
            }
        }
        if (j == i) {
            flag = TRUE;
        }
    }
    if (!flag)
        DBGPRINTF("goldbach's conjecture is wrong!\n");
    else 
        DBGPRINTF("goldbach's conjecture is right!\n");
}

void calc_exact_value_of_fraction()
{
    u32 i, j;//分子、分母
    u32 integer;     //整数部分
    u32 decimals[100] = {0};//小数部分
    u32 remainder[10000] = {0};//存放
    u32 temp;//存放余数
    u32 idx, idx1;
    
    DBGPRINTF("Input numerator and denominator(0-100): ");//输入被除数和除数
    scanf("%d %d", &i, &j);
    integer = i/j;
    DBGPRINTF("\n%d/%d's accuracy value is %d.", i, j, integer);
    idx = 1;
    temp = i%j*10;//余数扩大10倍
    while (idx < 100) {
        if (temp == 0) {
            for (idx1 = 1; idx1 <= idx; idx1++) {
                DBGPRINTF("%d", decimals[idx1]);
            }
            break;
        }

        if (remainder[temp] != 0) {
            for (idx1 = 1; idx1 < idx; idx1++) {
                DBGPRINTF("%d", decimals[idx1]);
            }
            DBGPRINTF("无限循环小数, 循环从idx%d 到 idx%d\n", remainder[temp], idx-1);
            break;
        }
        remainder[temp] = idx;
        decimals[idx] = temp/j;
        temp = temp%j*10;
        idx++;// TODO:
    }
}
/*
void thread_calc_array_sum()
{
    float arr[300];
    float sum1;
    u32 idx;
    for (idx = 0; idx < sizeof(arr)/sizeof(float); idx++) {
        arr[idx] = 1;
    }
    sum(arr, sizeof(arr)/sizeof(float), &sum1);
    DBGPRINTF("sum = %f\n", sum1);
    
}*/
u32 get_gcd(u32 a, u32 b)//求最大公约数,greatest common divisor
{
    u32 temp = 0;
    if (a < b) {
        temp = a;
        a = b;
        b = temp;
    }

    temp = a % b;
    while (temp) {
        a = b;
        b = temp;
        temp = a % b;
    }

    return b;
}

void compare_two_fraction()
{
    u32 a = 128;
    u32 b = 36;
    u32 gcd = get_gcd(a, b);
    DBGPRINTF("%d and %d gcd is %d\n", a, b, gcd);
}
u32 retry_table_a[3][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
};
u32 retry_table_b[3][4] = {
    {12, 11, 10, 9},
    {8, 7, 6, 5},
    {4, 3, 2, 1},
};
#if 0
void print_2d_array(u32 (*array)[4], u32 row)
{
    u32 i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < 4; j++) {
            DBGPRINTF("%d ", array[i][j]);
        }
        DBGPRINTF("\n");
    }
}
#else
void print_2d_array(u32 array[][4], u32 row)
{
    u32 i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < 4; j++) {
            DBGPRINTF("%d ", array[i][j]);
        }
        DBGPRINTF("\n");
    }
}
#endif
void two_dimensional_array_test()
{
    u32 (*array)[4];
    u32 flag;
    scanf("%d", &flag);
    DBGPRINTF("array_table_a\n");
    print_2d_array(retry_table_a, 3);
    DBGPRINTF("retry_table_b\n");
    print_2d_array(retry_table_b, 3);
    if (!flag) {
        array = retry_table_a;
        memcpy(retry_table_b, retry_table_a, sizeof(retry_table_b));
    }
    else {
        array = retry_table_b;
        memcpy(retry_table_a, retry_table_b, sizeof(retry_table_a));
    }
    DBGPRINTF("sizeof(retry_table_a) = %d\n", sizeof(retry_table_a));
    DBGPRINTF("sizeof(retry_table_a[0]) = %d\n", sizeof(retry_table_a[0]));
    DBGPRINTF(">>>>>>>>>>>>>>>>>>>>>>>>\n");
    DBGPRINTF("array\n");
    print_2d_array(array, 3);
    DBGPRINTF("array_table_a\n");
    print_2d_array(retry_table_a, 3);
    DBGPRINTF("retry_table_b\n");
    print_2d_array(retry_table_b, 3);
    
}
void swap(u32*a, u32*b)
{
    u32 temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
//插入排序
void insert_sort(u32 s[], u32 n)
{
    u32 i,j, temp;
    for(i=1; i<=n-1; i++)    //数组下标从2开始，s[0]做监视哨，s[1]一个数据无可比性
    {
        temp = s[i];    //给监视哨陚值
        j=i-1;    //确定要比较元素的最右边位黄
        while(temp<s[j])
        {
            s[j+1]=s[j];    //数据右移
            j--;    //产移向左边一个未比较的数
        }
        s[j+1]=temp;    //在确定的位置插入s[i]
    }
    return;
}

//冒泡排序
void bubble_sort(u32 s[], u32 n)
{
    u32 i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-1 - i; j++) {
            if (s[j] > s[j+1]) {
                swap(&s[j], &s[j+1]);
            }
        }
    }
}

//选择排序
void select_sort(u32 s[], u32 n)
{
    u32 i, j;
    for (i = 0; i < n-1; i++) {
        for (j = i+1; j <= n-1; j++) {
            if (s[i] > s[j])
                swap(&s[i], &s[j]);
        }
    }
}

//快速排序
#if 0
void quick_sort(u32 s[], u32 start, u32 end)
{
    u32 i, j, temp;
    i = start;
    j = end;
    temp = s[start];
    while (i < j) {
        while (i < j && temp < s[j]) {
            j--;
        }

        if (i < j) {
            s[i] = s[j];
            i++;
        }

        while (i < j && temp > s[i]) {
            i++;
        }

        if (i < j) {
            s[j] = s[i];
            j--;
        }
    }
    
    s[j] = temp;

    if (start < i)
        quick_sort(s, start, j-1);
    if  (i < end)
        quick_sort(s, j+1, end);
        
}
#else
void quick_sort(int *a, int left, int right)
{
    if(left >= right)/*如果左边索引大于或者等于右边的索引就代表已经整理完成一个组了*/
    {
        return ;
    }
    int i = left;
    int j = right;
    int key = a[left];
     
    while(i < j)                               /*控制在当组内寻找一遍*/
    {
        while(i < j && key <= a[j])
        /*而寻找结束的条件就是，1，找到一个小于或者大于key的数（大于或小于取决于你想升
        序还是降序）2，没有符合条件1的，并且i与j的大小没有反转*/ 
        {
            j--;/*向前寻找*/
        }
         
        swap(&a[i], &a[j]);
                /*交换a[i]和a[j]的数值*/
        /*找到一个这样的数后就把它赋给前面的被拿走的i的值（如果第一次循环且key是
        a[left]，那么就是给key）*/
         
        while(i < j && key >= a[i])
        /*这是i在当组内向前寻找，同上，不过注意与key的大小关系停止循环和上面相反，
        因为排序思想是把数往两边扔，所以左右两边的数大小与key的关系相反*/
        {
            i++;
        }
         
        swap(&a[i], &a[j]);
    }
     
    a[i] = key;/*当在当组内找完一遍以后就把中间数key回归*/
    quick_sort(a, left, i - 1);/*最后用同样的方式对分出来的左边的小组进行同上的做法*/
    quick_sort(a, i + 1, right);/*用同样的方式对分出来的右边的小组进行同上的做法*/
                       /*当然最后可能会出现很多分左右，直到每一组的i = j 为止*/
}
#endif
//归并排序
void Merge(int sourceArr[],int tempArr[], int startIndex, int midIndex, int endIndex)
{
    int i = startIndex, j=midIndex+1, k = startIndex;
    while(i!=midIndex+1 && j!=endIndex+1)
    {
        if(sourceArr[i] > sourceArr[j])
            tempArr[k++] = sourceArr[j++];
        else
            tempArr[k++] = sourceArr[i++];
    }
    while(i != midIndex+1)
        tempArr[k++] = sourceArr[i++];
    while(j != endIndex+1)
        tempArr[k++] = sourceArr[j++];
    for(i=startIndex; i<=endIndex; i++)
        sourceArr[i] = tempArr[i];
}
 
//内部使用递归
void Merge_Sort(int sourceArr[], int tempArr[], int startIndex, int endIndex)
{
    int midIndex;
    if(startIndex < endIndex)
    {
        midIndex = startIndex + (endIndex-startIndex) / 2;//避免溢出int
        Merge_Sort(sourceArr, tempArr, startIndex, midIndex);
        Merge_Sort(sourceArr, tempArr, midIndex+1, endIndex);
        Merge(sourceArr, tempArr, startIndex, midIndex, endIndex);
    }
}
 

//希尔排序
//根据当前增量进行插入排序
void shellInsert(int array[],int n,int dk)
{
    int i,j,temp;
    for(i=dk;i<n;i++)//分别向每组的有序区域插入
    {
        temp=array[i];
        for(j=i-dk;(j>=i%dk)&&array[j]>temp;j-=dk)//比较与记录后移同时进行
            array[j+dk]=array[j];
        if(j!=i-dk)
            array[j+dk]=temp;//插入
    }
}
 
//计算Hibbard增量
int dkHibbard(int t,int k)
{
    return (int)(pow(2,t-k+1)-1);
}
 
//希尔排序
void shellSort(int array[],int n,int t)//t为排序趟数，排序趟数应为log2(n+1)的整数部分，可取(int)(log(n+1)/log(2))，n为数组长度
{
    //void shellInsert(int array[],int n,int dk);
    int i;
    for(i=1;i<=t;i++)
        shellInsert(array,n,dkHibbard(t,i));
}
 

void sort_method_test()
{

}

void test_rand_func()
{
    s32 a;
    srand((u32)time(NULL));
    a = rand();
    DBGPRINTF("a = %d\n", a);
}

void open_file_test()
{
    FILE *fp;
    char ch;

    if ((fp == fopen("./testFile", "w+t")) == NULL) {
        DBGPRINTF("===========================\n");
        puts("Fail to open file!");
        DBGPRINTF("===========================\n");
    }

    DBGPRINTF("Input a string\n");
    while ((ch=getchar()) != '\n') {
        fputc(ch, fp);
    }

    fclose(fp);
    return;
}

//c语言入门编程练习
void test1()
{
    print_compile_info();
    //ASSERT(FALSE);
    //assert(0);
    //how_many_days_in_a_month_of_a_year();//某一年的某一月有多少天?
    //count_number_letters_space_and_others();//输入一个字符串，统计英文字母、空格、数字和其它字符个数
    //calc_compose_1yuan_with_125cent();//用1.2.5分组成1元的方式有多少种?
    //print_nine_nine_multiplication_table();//用4种方法输出99乘法表
    //print_rhombus(10);//输出行数为n+1的菱形
    //print_rhombus1();//输出行数为n的菱形
    //hundred_yuan_buy_hundred_chickens();//百钱买百鸡,公鸡5元一只,母鸡3元一只,小鸡1元3只,100元买一百只鸡有多少种情况?
    //calc_PI_value();//求π的近似值
    //calc_PI_value1();//求π的近似值
    //aliTest();//ali笔试题
    //array0_test();//数组长度为0的使用
    //judge_number_is_prime();//判断一个数是不是素数
    //perfect_number_in_range();//求1-n范围内的完数
    //close_number_in_range();//求1-n范围内的亲密数
    //divide_fish_issue();//分鱼问题
    //how_old_is_n_person();//求第n个人的年龄
    //delete_asterisk_in_the_string();//删除*号
    //get_the_last_number_lose_game();//常胜将军
    //horse_travel_chessboard();//马踏棋盘
    //matrix_transpose();//矩阵转置
    //magic_square();//魔方阵
    //shake_elbows_game();//掷骰子
    //calc_expression_to_24();//24点问题
    //stamp_issue();//邮票组合问题
    //calc_n_numbers_sum();//输入n个整数求和
    //calc_how_many_your_collection_worth();//计算我收藏了多少钱
    //auto_deal_procedure();//自动洗牌系统
    //dr_riddle_issue();//谜语博士问题
    //dr_riddle_issue1();//谜语博士问题1
    //guess_the_number_game();//猜数游戏
    //verify_goldbach_conjecture();//验证哥德巴赫猜想
    //thread_calc_array_sum();//线程求数组元素的和
    //calc_exact_value_of_fraction();//计算小数精确值
    //compare_two_fraction();//比较两个分数的大小(通过公分母进行)
    //two_dimensional_array_test();//二维数组的大小、声明和使用
    //test_rand_func();//测试随机数生成
    open_file_test();//测试文件打开、关闭、操作
}


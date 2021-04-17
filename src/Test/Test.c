#include "Test.h"
#include <math.h>

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
//c语言入门编程练习
void test1()
{
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
    divide_fish_issue();//分鱼问题
    
}


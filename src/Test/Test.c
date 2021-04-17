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
        if (ch == '\r') {//�س���������
            printf("\n");
            break;
        }

        if (ch == '\b' && i > 0) {//����ɾ����
            i--;
            printf("\b \b");
        } else if (isprint(ch)) {//����ɴ�ӡ�ַ�
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
    char *string = /*/**/"*/"/*"/**/;//����һ�ּ���Ƿ�֧��Ƕ��ע�͵ķ�����/*/*/0*/**/1,���֧������Ϊ1�������֧����Ϊ0*1,���Ϊ0
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
    DBGPRINTF("nested comments is %s\n", result);//���������Ƕ��ע�ͣ����Ϊ*/,���������/*
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
            u32 nMant : 23;     //β��
            u32 nExp  : 8;       //ָ��
            u32 nSign : 1;      //����λ
        } ui;
    } float_type;
    float_type ft;
    ft.f = 128.101;//19.22233333;
    DBGPRINTF("float.%f, nSign.%#x, nExp.%#x, nMant.%#x\n", ft.f, ft.ui.nSign, ft.ui.nExp, ft.ui.nMant);
#endif
#if WIDE_NARROW_CHAR
    wchar_t web_url[] = L"http://c.biancheng.net";
    //wchar_t web_name[] = L"C����������";
    wchar_t web_name[] = L"DDDDDDDDD";
    //setlocale(LC_ALL, "zh_CN");//�����ػ������óɼ�������
    wprintf(L"web_url: %ls \nweb_name: %ls \n", web_url, web_name);
    DBGPRINTF("web_url: %ls \nweb_name: %ls \n", web_url, web_name);
    DBGPRINTF("web_name: C����������\n");

    
    wchar_t a = L'A';  //Ӣ���ַ������������ַ���
    wchar_t b = L'9';  //Ӣ�����֣����������֣�
    wchar_t c = L'��';  //���ĺ���
    wchar_t d = L'��';  //���ĺ���
    wchar_t e = L'��';  //���ı��
    wchar_t f = L'��';  //����Ƭ����
    wchar_t g = L'?';  //�������
    wchar_t h = L'?';  //����
   
    //�����ػ�������Ϊ��������
    setlocale(LC_ALL, "zh-CN");
    //ʹ��ר�ŵ� putwchar ������ַ�
    putwchar(a);  putwchar(b);  putwchar(c);  putwchar(d);
    putwchar(e);  putwchar(f);  putwchar(g);  putwchar(h);
    putwchar(L'\n');  //ֻ��ʹ�ÿ��ַ�
   
    //ʹ��ͨ�õ� wprintf ������ַ�
    wprintf(
        L"Wide chars: %lc %lc %lc %lc %lc %lc %lc %lc\n",  //����ʹ�ÿ��ַ���
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
    printf("C����������");
    fflush(stdout);//�������������������ջ�����
    sleep(5);
    printf("http://c.biancheng.net\n");

    int a = 1, b = 2;
    char c;
    scanf("a=%d", &a);
    while((c = getchar()) != '\n' && c != EOF);//���´ζ�ȡǰ��ջ�����
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
    //�����Ǵ�ӡ
    DBGPRINTF("�����Ǵ�ӡ\n");
    for (i = 1; i <= 9; i++) {
        for (j = 1; j <= i; j++) {
            DBGPRINTF("%d*%d=%2d ", i, j, i*j);
        }
        DBGPRINTF("\n");
    }
    //�����Ǵ�ӡ
    DBGPRINTF("�����Ǵ�ӡ\n");
    for (i = 1; i <= 9; i++) {
        for (n = 1; n <= 9-i; n++) {
            DBGPRINTF("       ");
        }
        for (j = 1; j <= i; j++) {
            DBGPRINTF("%d*%d=%2d ", i, j, i*j);
        }
        DBGPRINTF("\n");
    }
    //�������Ǵ�ӡ
    DBGPRINTF("�������Ǵ�ӡ\n");
    for (i = 1; i <= 9; i++) {
        for (j = i; j <= 9; j++) {
            DBGPRINTF("%d*%d=%2d ", i, j, i*j);
        }
        DBGPRINTF("\n");
    }
    //�������Ǵ�ӡ
    DBGPRINTF("�������Ǵ�ӡ\n");
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
        if (i % 2 == 1) {//�����в���ӡ
            DBGPRINTF("\n");
        } else {//ż���д�ӡ*
            if (i <= row_col) {//*��������
                for (j = 0; j <= row_col; j++) {
                    if (j >= (row_col - i) / 2 && j <= (row_col + i) / 2)
                        DBGPRINTF("*");
                    else
                        DBGPRINTF(" ");
                }  
            } else {//*�����ݼ�
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
    int line;  // ����������
    int column;  // ����������
    int i;  // ��ǰ��
    int j;  // ��ǰ��
    DBGPRINTF("���������ε�����(����)��");
    scanf("%d", &line);
    if(line%2==0){  // �ж��Ƿ�������
        DBGPRINTF("��������������\n");
        exit(1);
    }
    column = line;  // ����������������ͬ
    for(i=1; i<=line; i++){  // ����������
        if(i<(line+1)/2+1){  // �ϰ벿�֣������м�һ�У�
            for(j=1; j<=column; j++){  // �����ϰ벿�ֵ�������
                if( (column+1)/2-(i-1)<=j && j<=(column+1)/2+(i-1) ){
                    DBGPRINTF("*");
                }else{
                    DBGPRINTF(" ");
                }
            }
        }else{  // �°벿��
            for(j=1; j<=column; j++){  // �����°벿�ֵ�������
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
    u32 i, j, k;//������ĸ����С��
    u32 count = 0;
    u32 cal_times = 0;
    for (i = 0; i < 100/5; i++) {
        for (j = 0; j < 100/3; j++) {
            for (k = 0; k < 100; k+=3) {
                if ((i+j+k) == 100 && (5*i+3*j+k/3) == 100) {
                    count++;
                    DBGPRINTF("count%d: %dֻ����, %dֻĸ��, %dֻС��\n", count, i, j, k);
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
    int numer, denomin;//���Ӻͷ�ĸ:numerator and denominator
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
                //DBGPRINTF("��= %lf\n", 4 * PI);
                //assert(0);
        //}
        //if (i < 1000) {
        //    DBGPRINTF("i.%d: %lf(numer.%d, denomin.%d)\n", i, (double)numer / denomin, numer, denomin);
        //}
    }
    PI = 4*PI;
    DBGPRINTF("��= %lf\n", PI);
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
        // ������Ƶĺ����ÿ�������Ŷ���һ�� 
        s=-s; 
        i=s/n;
    }
    pi=4*pi;
    printf("pi��ֵΪ��%.6f\n",pi);
    
    return 0;
}

typedef unsigned int uint32_t;
uint32_t ArrayMerge(uint32_t Asize, uint32_t *A, uint32_t Bsize, uint32_t *B, uint32_t *C) {
//��д������
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
    DBGPRINTF("������һ����(����1):\n");
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

    DBGPRINTF("��������һ����(����2):\n");
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
    DBGPRINTF("����һ����:(��1�������Χ�ڵ�����)\n");
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
    DBGPRINTF("����һ����:(��1�������Χ�ڵ�������)\n");
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
//c�������ű����ϰ
void test1()
{
    //how_many_days_in_a_month_of_a_year();//ĳһ���ĳһ���ж�����?
    //count_number_letters_space_and_others();//����һ���ַ�����ͳ��Ӣ����ĸ���ո����ֺ������ַ�����
    //calc_compose_1yuan_with_125cent();//��1.2.5�����1Ԫ�ķ�ʽ�ж�����?
    //print_nine_nine_multiplication_table();//��4�ַ������99�˷���
    //print_rhombus(10);//�������Ϊn+1������
    //print_rhombus1();//�������Ϊn������
    //hundred_yuan_buy_hundred_chickens();//��Ǯ��ټ�,����5Ԫһֻ,ĸ��3Ԫһֻ,С��1Ԫ3ֻ,100Ԫ��һ��ֻ���ж��������?
    //calc_PI_value();//��еĽ���ֵ
    //calc_PI_value1();//��еĽ���ֵ
    //aliTest();//ali������
    //array0_test();//���鳤��Ϊ0��ʹ��
    //judge_number_is_prime();//�ж�һ�����ǲ�������
    //perfect_number_in_range();//��1-n��Χ�ڵ�����
    //close_number_in_range();//��1-n��Χ�ڵ�������
    divide_fish_issue();//��������
    
}


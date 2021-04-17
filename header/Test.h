#pragma once
#include "Type.h"
#include "Utils.h"
#include <wchar.h>
#include <locale.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
//#include <conio.h>

#define      TEMP_TEST                              0//临时借用

#define      PTRDIFFWITHARRAY                       0//指针和数组不等测试
#define      BINARY_OCTONARY_DECIMAL                0//二进制、八进制、十进制表示及输出
#define      CHAR_DIFF_WITH_STRING                  0//字符和字符串的区别
#define      IS_SUPPORT_NESTED_COMMENTS             0//检测是否支持嵌套注释
#define      VAR_TYPE_FLOAT_DOUBLE_INT              0//变量类型:float、double存储方式
#define      WIDE_NARROW_CHAR                       0//宽字符和窄字符
#define      SCANF_FUNCTION                         0//scanf函数的使用
#define      PRINTF_FUNCTION                        0//printf输出及缓存相关
#define      SET_PASSWORD                           0//set password
#define      IF_ELSE_SWITCH                         0//判断语句
#define      MYSTERY_FUNCTION                       0//神秘函数
#define      DAYS_IN_A_MONTH_OF_A_YEAR             1//某一年的某一月有多少天

#define      PWDLEN                                 20

extern u32 a[5];
extern u32 *b;

extern void test();
extern void test1();




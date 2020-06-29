/*********************************************************
Date:2018.9.5
Author:tonghaitao
Function:relate with sales
*********************************************************/
#include "Typedef.h"
#define PRODUCT_NAME_SIZE 20

typedef float Price;
typedef struct{
    char product[PRODUCT_NAME_SIZE];
    int quantity;
    float unitPrice;
    float totalAmount;
}Transaction;
typedef struct{
    short area;
    short exchange;
    short station;
}PHONE_NUMBER;
typedef struct{
    short month;
    short day;
    short year;
    int time;
    PHONE_NUMBER called;
    PHONE_NUMBER calling;
    PHONE_NUMBER billed;
}LONG_DISTANCE_BILL;

extern void DoShopping();
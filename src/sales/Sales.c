#include "Sales.h"
void ComputeTotalAmount(Transaction *tempTrans)
{
    //scanf("input product name: %s\n", tempTrans->product);
    //scanf("input unitPrice: %f\n", &tempTrans->unitPrice);
    //scanf("input quantity: %d\n", &tempTrans->quantity);
    scanf("%s[^/n]", tempTrans->product);
    scanf("%f", &tempTrans->unitPrice);
    scanf("%d", &tempTrans->quantity);
    tempTrans->totalAmount = tempTrans->unitPrice * tempTrans->quantity;
}

void PrintReceipt(Transaction tempTrans)
{
    printf("%s\n", tempTrans.product);
    printf("%d @ %.2f total %.2f\n", tempTrans.quantity, tempTrans.unitPrice,
        tempTrans.totalAmount);
}

void DoShopping()
{
    Transaction trans;
    ComputeTotalAmount(&trans);
    PrintReceipt(trans);
}

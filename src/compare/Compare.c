#include "Compare.h"
#include "Typedef.h"
COMPARE_RESLUT CompareInt(void const *a, void const *b)
{
    COMPARE_RESLUT result;
    register int const *pa = a;
    register int const *pb = b;
    result = *pa > *pb ? CP_TRUE : *pa < *pb ? CP_FALSE : CP_EQUAL;
    return result;
}

void QSort(uint32 *array, uint32 lengthOfValue)
{
    uint32 iterator_i;
    uint32 iterator_j;
    uint32 temp;
    for (iterator_i = 0; iterator_i < lengthOfValue - 1; iterator_i++)
    {
        for (iterator_j = iterator_i + 1; iterator_j < lengthOfValue; iterator_j++)
        {
            if (array[iterator_i] > array[iterator_j])
            {
                temp = array[iterator_i];
                array[iterator_i] = array[iterator_j];
                array[iterator_j] = temp;
            }
        }
    }
}
uint32 ArraySort()
{
    uint32 *array;
    uint32 nValue;
    uint32 iterator;
    printf("Input the number of integers:\n");
    if (scanf("%d", &nValue) != 1 || nValue <= 0)
    {
        printf("Illegal number of integers.\n");
        return FALSE;
    }
    //alloc memory
    array = malloc(nValue * sizeof(uint32));
    if (NULL == array)
    {
        printf("Out of memory\n");
        return FALSE;
    }
    //input the integers
    for (iterator = 0; iterator < nValue; iterator++)
    {
        if (scanf("%d", array+iterator) != 1)
        {
            printf("Error reading value #%d\n", iterator);
            free(array);
            return FALSE;
        }
    }
    //sort
    QSort(array, nValue);
    //print the value after sort
    for(iterator = 0; iterator < nValue; iterator++)
    {
        printf("%d", array[iterator]);
    }

    free(array);
    return TRUE;
    
}

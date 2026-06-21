#include <stdlib.h>
#include <stdio.h>
#include "dynamicArray.h"

void initDynamicArray(DynamicArray *arrPtr, int maxSize)
{
    arrPtr->data = malloc(maxSize * sizeof(int));
    arrPtr->size = 0;
    arrPtr->maxSize = maxSize;
}

void pushToDynamicArray(DynamicArray *arrPtr, int value)
{
    if (arrPtr->size >= arrPtr->maxSize)
    {
        int newMaxSize = arrPtr->maxSize * 2;
        int *newData = realloc(arrPtr->data, newMaxSize * sizeof(int));
        if (!newData) {
            printf("realloc failed\n");
            return;
        }
        arrPtr->data = newData;
        arrPtr->maxSize = newMaxSize;
    }
    arrPtr->data[arrPtr->size] = value;
    arrPtr->size++;
}

int popFromDynamicArray(DynamicArray *arrPtr)
{
    if (arrPtr->size == 0)
    {
        printf("pop from empty array\n");
        return -1;
    }
    arrPtr->size--;
    return arrPtr->data[arrPtr->size];
}

void freeDynamicArray(DynamicArray *arrPtr)
{
    free(arrPtr->data);
    arrPtr->data = NULL;
    arrPtr->size = 0;
    arrPtr->maxSize = 0;
}

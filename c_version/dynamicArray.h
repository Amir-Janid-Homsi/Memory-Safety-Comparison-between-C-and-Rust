#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

typedef struct
{
    int *data;
    int size;
    int maxSize;
} DynamicArray;

void initDynamicArray(DynamicArray *arrPtr, int maxSize);
void pushToDynamicArray(DynamicArray *arrPtr, int value);
int popFromDynamicArray(DynamicArray *arrPtr);
void freeDynamicArray(DynamicArray *arrPtr);

#endif

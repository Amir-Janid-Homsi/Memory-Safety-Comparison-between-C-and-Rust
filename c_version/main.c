#include <stdio.h>
#include "dynamicArray.h"

void main()
{
    int choice;
    while (1)
    {
        DynamicArray arr;
        printf("\nMemory Safety Bug Runner\n\n");
        printf("1. Use-After-Free\n");
        printf("2. Double Free\n");
        printf("3. Buffer Overflow\n");
        printf("4. Exit\n");
        printf("Choice: \n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                initDynamicArray(&arr, 2);
                pushToDynamicArray(&arr, 10);
                pushToDynamicArray(&arr, 20);
                freeDynamicArray(&arr);

                printf("%d\n", arr.data[0]);
            case 2:
                initDynamicArray(&arr, 2);
                pushToDynamicArray(&arr, 10);
                freeDynamicArray(&arr);

                freeDynamicArray(&arr);
            case 3:
                initDynamicArray(&arr, 2);

                arr.data[2] = 999;
                freeDynamicArray(&arr);
            case 4:
                printf("Goodbye.\n");
                return;
            default:
                printf("Invalid choice.\n");
        }
    }
}

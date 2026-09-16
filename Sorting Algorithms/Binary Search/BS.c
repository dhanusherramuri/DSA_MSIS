#include "Binary.h"

void search(int a[], int low, int high, int key)
{
    if (low > high)
    {
        printf("NOT FOUND\n");
        return;
    }

    int mid = low + (high - low) / 2;

    if (key == a[mid])
    {
        printf("\nKEY FOUND\n");
        return;
    }

    if (key > a[mid])
        search(a, mid + 1, high, key);
    else
        search(a, low, mid - 1, key);
}

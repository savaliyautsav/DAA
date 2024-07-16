#include <stdio.h>

void merge(int a[], int lb, int mid, int ub, int b[])
{
    int i = lb, j = mid + 1, k = lb;

    while (i <= mid && j <= ub)
    {
        if (a[i] <= a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }
    if(i<=mid)
    {
    while (i <= mid)
    {
        b[k] = a[i];
        i++;
        k++;
    }
    }
    else{
    while (j <= ub)
    {
        b[k] = a[j];
        j++;
        k++;
    }
    }
 for (i = lb; i <= ub; i++)
{
      a[i] = b[i];
    }
}

void mergeSort(int a[], int lb, int ub, int b[])
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;
        mergeSort(a, lb, mid, b);
        mergeSort(a, mid + 1, ub, b);
        merge(a, lb, mid, ub, b);
    }
}

void main()
{
    int n, a[100], b[100];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }

    mergeSort(a, 0, n - 1, b);

    // Display the sorted array using b
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", b[i]);
    }
    printf("\n");
}

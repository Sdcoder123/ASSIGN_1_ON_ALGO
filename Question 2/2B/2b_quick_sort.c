#include <stdio.h>
#include <stdbool.h> //for true keyword
#include <stdlib.h>  //for rand() and srand()
#include <time.h>
#include <math.h>

void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

int partition(int *arr, int initial, int final)
{
    int pivot_value = arr[initial];

    int left_iterator = initial;
    int right_iterator = final;

    while (true)
    {
        while (arr[left_iterator] < pivot_value)
            left_iterator++;

        while (pivot_value < arr[right_iterator])
            right_iterator--;

        if (arr[left_iterator] == arr[right_iterator])
        {
            if (left_iterator == right_iterator)
                return left_iterator;
            else
                right_iterator--;
        }
        else if (left_iterator < right_iterator)
            swap(&arr[left_iterator], &arr[right_iterator]);
        else
            return left_iterator;
    }
}

//sorts array using quick_sort algorithm, give initial as 0, and final as sizeofarray -1
void quick_sort(int *arr, int initial, int final)
{
    if (initial < final)
    {
        int pos_of_pivot = partition(arr, initial, final);
        quick_sort(arr, initial, pos_of_pivot);
        quick_sort(arr, pos_of_pivot + 1, final);
    }
}

//assuming 1 is true, 0 is false
int is_array_sorted(int *arr, int length)
{
    for (int i = 0; i < length - 1; i++)
        if (arr[i] > arr[i + 1])
            return 0;

    return 1;
}

void main()
{

    srand(time(0));

    for (int i = 0; i < 5000; i++)
    {
        int n = floor(pow(2, 4));
        int a[n];
        for (int i = 0; i < n; i++)
            a[i] = rand() % 100;

        for (int i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");

        float start_time = clock();
        quick_sort(a, 0, n - 1);
        float end_time = clock();

        for (int i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n\n");

        if (is_array_sorted(a, sizeof(a) / sizeof(int)) == 1)
            printf("Run %d: %0.4fms\n", i + 1, (end_time - start_time) * 1000 / CLOCKS_PER_SEC);
        else
        {
            printf("Array Not Sorted\n");
            break;
        }
    }
}
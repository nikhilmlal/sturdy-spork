#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int p, pivot;

//using Fisher-Yates algorithm
void random_array(int A[], int size)
{
    int temp, j;
    srand(time(0));
    for (int i = size-1 ; i > 0 ; --i) 
    {
        j = rand() % (i+1);
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
}

int partition(int A[], int low, int high)
{
    int i = low - 1;
    int j, temp;
    pivot = A[high];

    for (j = low ; j < high ; ++j)
    {
        if (A[j] < pivot)
        {
            ++i;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    temp = A[i+1];
    A[i+1] = A[high];
    A[high] = temp;
    return i+1;
}

void quicksort(int A[], int low, int high)
{
    if (low < high)
    {
        p = partition(A, low, high);
        quicksort(A, low, p-1);
        quicksort(A, p+1, high);
    }
}

void print_array(int A[], int size)
{
    for (int i = 0 ; i < size ; ++i)
        printf("%d ", A[i]);
    printf("\n");
}

int main()
{
    int size, test_index;
    clock_t start, stop, total;
    printf("Enter the size of the array : ");
    scanf(" %d", &size);
    printf("Performing tests on an array of size %d\n", size);
    test_index = size/2;
    int arr[size];

    for (int i = 0 ; i < size ; ++i)
        arr[i] = i;
    
    printf("\nShuffling the array with Fisher-Yates...\n");
    start = clock();
    random_array(arr, size);
    stop = clock();
    total = (stop - start);
    printf("Fisher-Yates shuffle took %lu microseconds\n", total);
    //print_array(arr, size);
    printf("\n%dth element is %d\n", test_index, arr[test_index-1]);

    printf("\nStarting quicksort...\n");
    start = clock();
    quicksort(arr, 0, size-1);
    stop = clock();
    total = (double)(stop - start);
    printf("QuickSort took %lu microseconds\n", total);
    //print_array(arr, size);
    printf("\n%dth element is %d\n\n", test_index, arr[test_index-1]);
    printf("\n%dth element is %d\n\n", test_index+1, arr[test_index]);
    printf("\n%dth element is %d\n\n", test_index+2, arr[test_index+1]);
    return 0;
}

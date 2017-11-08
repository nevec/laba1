#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void heap_sort(int arr[], int n);
void selection_sort(int arr[], int n);
void radix_sort(int a[], int n);

void benchmark(int a[], int n);

int Comparisons, Swaps;


#define SIZE1 1000
#define SIZE2 10000
#define SIZE3 100000


int main()
{
    int a[SIZE1], b[SIZE2], c[SIZE3];

    benchmark(a, SIZE1);
    benchmark(b, SIZE2);
    benchmark(c, SIZE3);


    return 0;
}

void fill_sorted(int a[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        a[i] = i;
}

void fill_reversed(int a[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        a[i] = n-i-1;
}

void fill_random(int a[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        a[i] = rand();

}

void get_stats(int a[], int n)
{
    Swaps = Comparisons = 0;
    heap_sort(a, n);
    printf("%d : %d %d\n", n, Swaps, Comparisons);
}

void get_stats_advanced(int a[], int n, int times)
{
    int i;
    int sum1 = 0, sum2 = 0;
    for (i = 0; i < times; ++i) {
        Swaps = Comparisons = 0;
        heap_sort(a, n);
        sum1 += Swaps;
        sum2 += Comparisons;
    }

    printf("%d : %d %d\n", n, sum1/times, sum2/times);
}

void benchmark(int a[], int n)
{
    fill_sorted(a, n);
    printf("Ordered: ");
    get_stats(a, n);


    fill_random(a, n);
    printf("Random: ");
    get_stats_advanced(a, n, 500);


    fill_reversed(a, n);
    printf("Reversed: ");
    get_stats(a, n);
}

void selection_sort(int a[], int n)
{
    int i, j, imax, t;

    for (i = 0; i < n-1; ++i) {
        imax = 0;
        for (j = 1; j < n-i; ++j) {
            Comparisons++;
            if (a[j] > a[imax])
                imax = j;
        }

        Swaps++;
        t = a[imax];
        a[imax] = a[n-i-1];
        a[n-i-1] = t;
    }
}


void countsort_by_byte(int a[], int n, int byte)
{
    int b[100000], i, count[256];
    int mask;

    memset(count, 0, 256*sizeof(int));

    for (i = 0; i < n; ++i)
        count[ (a[i]>>(8*byte)) & 0xFF ]++;

    Comparisons += n;

    for (i = 1; i < 256; ++i)
        count[i] += count[i-1];

    for (i = n-1; i >= 0; --i) {
        mask = (a[i]>>(8*byte)) & 0xFF;

        b[count[mask]-1] = a[i];
        count[mask]--;
    }
    Swaps += 2*n;
    memcpy(a, b, sizeof(int)*n);
}

void radix_sort(int a[], int n)
{
    int i;
    for (i = 0; i < 4; ++i) {
        countsort_by_byte(a, n, i);
    }
}



int* heap;
int n;

int right(int i) { return 2*i + 2;}
int left(int i) { return 2*i + 1;}
int parent(int i) { return (i-1) / 2;}

void show_heap()
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%d ", heap[i]);
    printf("\n");

}

void swap_heap(int i, int j)
{
    int t = heap[i];
    heap[i] = heap[j];
    heap[j] = t;
    Swaps++;
}

void sift_down(int i)
{
    int leftv, rightv, maxv, max_ind;

    if (left(i) >= n)
        return;
    if (left(i) == n-1) {
        Comparisons++;
        if (heap[left(i)] > heap[i])
            swap_heap(i, left(i));
        return;
    }

    leftv = heap[left(i)];
    rightv = heap[right(i)];
    maxv = (leftv > rightv)?leftv:rightv;
    max_ind = (leftv > rightv)?left(i):right(i);

    Comparisons += 2;

    if (maxv > heap[i]) {
        swap_heap(max_ind, i);
        sift_down(max_ind);
    }
}

void build_heap(int arr[], int size)
{
    int i;

    n = size;
    heap = arr;
    for (i=parent(n-1); i >= 0; --i) {
        sift_down(i);
    }

}

void heap_sort(int arr[], int size)
{
    build_heap(arr, size);

    while (n > 1) {
        swap_heap(0, n-1);
        --n;
        sift_down(0);
    }
}

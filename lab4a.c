#include <stdio.h>

const int Nmax = 100;

int main(void) {
    int a[Nmax], b[Nmax], c[2*Nmax];
    int n, m, i, a_ind, b_ind;

    printf("Enter a and b sizes (less than %d)\n", Nmax);
    scanf("%d%d", &n, &m);

    printf("Enter a: ");
    for (i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    printf("Enter b: ");
    for (i = 0; i < m; ++i) {
        scanf("%d", &b[i]);
    }

    a_ind = b_ind = 0;

    for (i = 0; i < n+m; ++i) {
        if (a_ind == n) 
            c[i] = b[b_ind++];
        else if (b_ind == m)
            c[i] = a[a_ind++];
        else if (a[a_ind] < b[b_ind])
            c[i] = a[a_ind++];
        else
            c[i] = b[b_ind++];
    }

    printf("Merged array:\n");
    for (i = 0; i < n+m; ++i)
        printf("%d ", c[i]);
    printf("\n");
    return 0;
}

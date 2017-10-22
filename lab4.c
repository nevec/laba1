#include <stdio.h>

const int MAX = 100;

int main(void) 
{
    int A[MAX][MAX] = {};
    int i, j, y, x, n = 0, m = 0, result;
    
    printf("Enter n [1, %d], m [1, %d]: ", MAX, MAX);
    scanf("%d%d", &n, &m);
    
    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            printf("Enter a[%d][%d] ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    for (i = 0; i < n; ++i) 
        for (j = 0; j < m; ++j) 
            for (y = 0; y < n; ++y) 
                for (x = 0; x < m; ++x) 
                    if (y != i && x != j && A[i][j] == A[y][x]) {
                        printf("%d\n%d %d\t %d %d\n", A[i][j], i, j, y, x);
                        return 0;
                    }
    printf("No equal elements found\n");

    return 0;
    
}


#include <stdio.h>

int main() {
    int i, j, m, n, k, l;

    printf("Enter number of rows and columns of matrix A: ");
    scanf("%d %d", &m, &n);
    int a[m][n];
    printf("Enter matrix A:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter number of rows and columns of matrix B: ");
    scanf("%d %d", &k, &l);
    int b[k][l];
    printf("Enter matrix B:\n");
    for (i = 0; i < k; i++) {
        for (j = 0; j < l; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    if (m == k && n == l) {
        int c[m][n], d[m][n];
        printf("Sum of A and B:\n");
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                c[i][j] = a[i][j] + b[i][j];
                printf("%d\t", c[i][j]);
            }
            printf("\n");
        }

        printf("Difference of A and B:\n");
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                d[i][j] = a[i][j] - b[i][j];
                printf("%d\t", d[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Addition/Subtraction not possible (dimension mismatch).\n");
    }

    if (n == k) {
        int e[m][l];
        printf("Multiplication of A and B:\n");
        for (i = 0; i < m; i++) {
            for (j = 0; j < l; j++) {
                e[i][j] = 0;
                for (int p = 0; p < n; p++) {
                    e[i][j] += a[i][p] * b[p][j];
                }
                printf("%d\t", e[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Multiplication not possible (columns of A != rows of B).\n");
    }

    int transposeA[n][m];
    printf("Transpose of A:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            transposeA[j][i] = a[i][j];
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d\t", transposeA[i][j]);
        }
        printf("\n");
    }

    int transposeB[l][k];
    printf("Transpose of B:\n");
    for (i = 0; i < k; i++) {
        for (j = 0; j < l; j++) {
            transposeB[j][i] = b[i][j];
        }
    }
    for (i = 0; i < l; i++) {
        for (j = 0; j < k; j++) {
            printf("%d\t", transposeB[i][j]);
        }
        printf("\n");
    }

    return 0;
}



#include <stdio.h>

/*
2 4 3
1 2 3
4 5 6
1 2 3 4
5 6 7 8
9 10 11 12
*/

void matmul(int a[100][100], int b[100][100], int n, int m, int c) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int s = 0;
            for (int k = 0; k < c; k++) {
                s += (a[i][k] * b[k][j]);
            }
            printf("%d ", s);
        }
        printf("\n");
    }
}
/*
void invmat(float a[100][100], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int k = i + 1; k < n; k++) {
            for (int j = i; j < m; j++) {
                a[k][j] -= a[i][j]
            }
        }
    }
}
*/
int main()
{

    int a[100][100], b[100][100], n, m, c;
    scanf("%d %d %d", &n, &m, &c);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &a[i][j]);
    for (int i = 0; i < c; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &b[i][j]);
    matmul(a, b, n, m, c);

    return 0;
}

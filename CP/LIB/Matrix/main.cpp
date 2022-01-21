#include <bits/stdc++.h>

using namespace std;

const int ms = 101;

bool invmat(double a[ms][ms], double ans[ms][ms], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i == j)
                ans[i][j] = 1.0;
            else
                ans[i][j] = 0.0;
    for (int i = 0; i < n; i++) {
        if (fabs(a[i][i]) < 1e-5)
            return false;
        if (fabs(a[i][i] - 1.0) > 1e-5) {
            double x = a[i][i];
            for (int j = 0; j < n; j++) {
                a[i][j] /= x;
                ans[i][j] /= x;
            }
        }
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;
            double x = a[j][i] / a[i][i];
            for (int k = 0; k < n; k++) {
                a[j][k] -= (a[i][k] * x);
                ans[j][k] -= (ans[i][k] * x);
            }
        }
    }
    return true;
}

void matmul(int a[ms][ms], int b[ms][ms], int ans[ms][ms], int n, int m, int t) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans[i][j] = 0;
            for (int k = 0; k < t; k++)
                ans[i][j] += (a[i][k] * b[k][j]);
        }
    }
}

void copyMat(int a[ms][ms], int b[ms][ms], int n, int m) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            b[i][j] = a[i][j];
}

void binaryExponentiation(int x[ms][ms], int ans[ms][ms], int n, int mas){
    int tmp[ms][ms];
    memset(ans, 0, (mas + 1) * sizeof *ans[0]);
    for (int i = 0; i < mas; i++)
        ans[i][i] = 1;
    while(n > 0) {
        if(n % 2 == 1) {
            copyMat(ans, tmp, mas, mas);
            matmul(x, tmp, ans, mas, mas, mas);
        }
        matmul(x, x, tmp, mas, mas, mas);
        copyMat(tmp, x, mas, mas);
        n = n / 2;
    }
}

int main()
{
    int n, m, t;
    /*
    //Test matrix expo
    int a[ms][ms], ans[ms][ms];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    binaryExponentiation(a, ans, m, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", ans[i][j]);
        printf("\n");
    }
    */
    /*
    //Test matmul
    int a[ms][ms], b[ms][ms], ans[ms][ms];
    scanf("%d %d %d", &n, &m, &t);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < t; j++)
            scanf("%d", &a[i][j]);
    for (int i = 0; i < t; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &b[i][j]);
    matmul(a, b, ans, n, m, t);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%d ", ans[i][j]);
        printf("\n");
    }
    */
    /*
    //Test mat invert
    double ivmat[ms][ms], mat[ms][ms];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%lf", &mat[i][j]);
    if(!invmat(mat, ivmat, n)) {
        printf("Matrix can't invert");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%lf ", ivmat[i][j]);
        printf("\n");
    }
    */

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int add(int i, int j) {
    i += j;
    if (i >= MOD) i -= MOD;
    return i;
}
int mul(int i, int j) {
    return int((long long) i * j % MOD);
}

struct Matrix{
    int m[50][50];
};

Matrix MatrixMultiplication(Matrix a, Matrix b) {
    Matrix res;
    memset(res.m, 0, sizeof(res.m));

    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            for (int k = 0; k < 50; k++) { 
                res.m[i][j] = add(res.m[i][j], mul(a.m[i][k], b.m[k][j]));
            }
        }
    }

    return res;
}

Matrix MatrixPower(Matrix a, long long k) {
    Matrix res;
    memset(res.m, 0, sizeof(res.m));
    for (int i = 0; i < 50; i++) res.m[i][i] = 1;

    while (k > 0) {
        if (k & 1) res = MatrixMultiplication(res, a);
        a = MatrixMultiplication(a, a);
        k >>= 1;
    }

    return res;
}

int main() {

    long long k, n;
    cin >> n >> k;
    Matrix ans, trans;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> trans.m[i][j];
    for (int i = 0; i < n; i++)
        ans.m[0][i] = 1;
    ans = MatrixMultiplication(ans, MatrixPower(trans, k));
    int res = 0;
    for (int i = 0; i < n; i++)
        res = (res + ans.m[0][i]) % MOD;
    cout << res << endl;

    return 0;
}

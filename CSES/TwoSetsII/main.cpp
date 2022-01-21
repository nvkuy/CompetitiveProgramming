#include <bits/stdc++.h>

using namespace std;

long long d,x,y;
void extendedEuclid(long long A, long long B) {
    if(B == 0) {
        d = A;
        x = 1;
        y = 0;
    } else {
        extendedEuclid(B, A%B);
        long long temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}
long long modInverse(long long A, long long M) {
    extendedEuclid(A,M);
    return (x%M+M)%M;
}

int main()
{
    long long n, s, m = 1e9 + 7;
    cin >> n;
    s = ((n + 1) * n) / 2;
    if (s % 2) {
        cout << '0';
        return 0;
    }
    s /= 2;
    vector<vector<long long>> f(s + 1, vector<long long>(n + 1, 0LL));
    for (int i = 0; i <= n; i++)
        f[0][i] = 1;
    for (int i = 1; i <= s; i++) {
        for (int j = 1; j <= n; j++) {
            f[i][j] = f[i][j - 1];
            if (i >= j)
                f[i][j] = (f[i][j] + f[i - j][j - 1]) % m;
        }
    }
    cout << (f[s][n] * modInverse(2, m)) % m;

    return 0;
}

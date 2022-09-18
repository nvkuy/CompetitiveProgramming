#include <bits/stdc++.h>

using namespace std;

const long mod = 1e9 + 7;
long n, m, x[100000], y[100000];

long long sub2() {

    long long ans = 0;
    long long ngang = x[1] - x[0];
    long long doc = 0;
    for (int i = 0; i < (m - 1); i++) {
        for (int j = i + 1; j < m; j++) {
            doc = y[j] - y[i];
            ans = (ans + ((doc * ngang) % mod)) % mod;
        }
    }

    return ans;
}

long long sub1() {

    long long ans = 0;
    long long ngang = 0;
    long long doc = 0;
    for (int i = 0; i < (n - 1); i++) {
        for (int j = i + 1; j < n; j++) {
            ngang = x[j] - x[i];
            for (int k = 0; k < (m - 1); k++) {
                for (int l = k + 1; l < m; l++) {
                    doc = y[l] - y[k];
                    ans = (ans + ((doc * ngang) % mod)) % mod;
                }
            }
        }
    }

    return ans;
}

int main()
{

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    for (int i = 0; i < m; i++)
        cin >> y[i];

    if (n == 2) {
        cout << sub2();
        return 0;
    }
    if ((n <= 50) && (m <= 50)) {
        cout << sub1();
        return 0;
    }

    return 0;
}

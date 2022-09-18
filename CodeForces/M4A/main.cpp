#include <bits/stdc++.h>

using namespace std;

int minPrime[1000001];
int f[1000001];

void snt (int n) {

    for (int i = 2; i * i <= n; ++i) {
        if (minPrime[i] == 0) {
            for (int j = i * i; j <= n; j += i) {
                if (minPrime[j] == 0) {
                    minPrime[j] = i;
                }
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        if (minPrime[i] == 0) {
            minPrime[i] = i;
        }
    }
}

int cal(int n) {
    int ans = n - (n / minPrime[n]);
    int cur = minPrime[n];
    while (n != 1) {
        if (minPrime[n] != cur) {
            ans = ans - (ans / minPrime[n]);
            cur = minPrime[n];
        }
        n /= minPrime[n];
    }
    return ans;
}

int main()
{

    snt(1000001);
    f[0] = 0; f[1] = 1;
    for (int i = 2; i < 1000001; i++) {
        if (minPrime[i] == i)
            f[i] = i - 1;
        else
            f[i] = cal(i);
    }

    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        printf("%d\n", f[n]);
    }

    return 0;
}

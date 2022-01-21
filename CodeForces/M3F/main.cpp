#include <bits/stdc++.h>

using namespace std;

int minPrime[10000001];
long long f[10000001];

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

    snt(10000001);
    //cout << cal(4) << endl;
    f[0] = 0; f[1] = 1;
    for (int i = 2; i <= 10000001; i++) {
        if (minPrime[i] == i)
            f[i] = f[i - 1] + i - 1;
        else
            f[i] = f[i - 1] + cal(i);
    }
    //for (int i = 0; i <= 100; i++)
    //    cout << f[i] << " ";
    //cout << endl;

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << f[n] << "\n";
    }

    return 0;
}

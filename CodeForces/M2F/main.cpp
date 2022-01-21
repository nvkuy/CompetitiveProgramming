#include <bits/stdc++.h>

using namespace std;

int maxn = 1000002;
int minPrime[1000002];
long long f[1000002];

int cal(int n) {
    int ans = 1;
    int cur = minPrime[n], cc = 0;
    while (n != 1) {
        if (minPrime[n] == cur) {
            cc++;
            if (n == minPrime[n]) {
                ans *= (cc + 1);
                //cc = 0;
                //cur = minPrime[n];
            }
        } else {
            ans *= (cc + 1);
            cur = minPrime[n];
            cc = 1;
            if (n == minPrime[n])
                ans *= (cc + 1);
        }
        n /= minPrime[n];
    }

    return ans;
}

void snt() {
    for (int i = 2; i * i <= maxn; ++i) {
        if (minPrime[i] == 0) {
            for (int j = i * i; j <= maxn; j += i) {
                if (minPrime[j] == 0) {
                    minPrime[j] = i;
                }
            }
        }
    }
    for (int i = 2; i <= maxn; ++i) {
        if (minPrime[i] == 0) {
            minPrime[i] = i;
        }
    }
}

int main()
{
    snt();
    //cout << cal(15) << endl;
    f[1] = maxn; f[0] = maxn;
    for (int i = 2; i <= maxn; i++)
        f[i] = max(f[i - 1], ((long long)(cal(i) * i) + (maxn - i)));
    int n, t;
    cin >> t;
    while (t > 0) {
        t--;
        cin >> n;
        cout << ((long long)(f[n] - maxn + n)) << "\n";
    }

    return 0;
}

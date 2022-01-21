#include <bits/stdc++.h>

using namespace std;

long long mod = 1000003;
long long minPrime[1000004], f[1000004];

long long cal(int curP, int curB) {
    return (((long long)((pow(curP, curB + 1) - 1) / (curP - 1))) % mod);
}

long long factorize(int n) {

    long long ans = 1;
    long long cur = minPrime[n], cc = 0;
    while (n != 1) {
        if (minPrime[n] == cur) {
            cc++;
            if (n == minPrime[n]) {
                ans = ((long long) (ans * cal(minPrime[n], cc)) % mod);
            }
        } else {
            ans = ((long long) (ans * cal(minPrime[n], cc)) % mod);
            cur = minPrime[n];
            cc = 1;
            if (n == minPrime[n])
                ans = ((long long) (ans * cal(minPrime[n], cc)) % mod);
        }
        n /= minPrime[n];
    }

    return (ans - 1);
}

void snt() {
    for (int i = 2; i * i <= 1000004; ++i) {
        if (minPrime[i] == 0) {
            for (int j = i * i; j <= 1000004; j += i) {
                if (minPrime[j] == 0) {
                    minPrime[j] = i;
                }
            }
        }
    }
    for (int i = 2; i <= 1000004; ++i) {
        if (minPrime[i] == 0) {
            minPrime[i] = i;
        }
    }
}

int main()
{
    snt();
    //cout << factorize(84) << endl;
    int t, n, q;
    long long t1, t2, t3, curA, f[2001];
    cin >> t;
    while (t > 0) {
        t--;
        memset(f, 0, sizeof(f));
        cin >> n >> q;
        for (int i = 0; i < n; i++) {
            cin >> f[i];
            f[i] = factorize(f[i]);
        }
        for (int i = 0; i < q; i++) {
            cin >> t1;
            if (t1 == 2) {
                cin >> t2;
                f[t2] = factorize(f[t2 - 1]);
            } else {
                curA = 0;
                cin >> t2 >> t3;
                for (int j = (t2 - 1); j <= (t3 - 1); j++)
                    curA = max(f[j], curA);
                cout << curA << "\n";
            }
        }
    }

    return 0;
}

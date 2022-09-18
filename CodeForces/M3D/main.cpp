#include <bits/stdc++.h>

using namespace std;

int minPrime[10000001], f[10000001];

int calcs(int n) {
    int s = 0;
    while (n > 0) {
        s += (n % 10);
        n = n / 10;
    }
    return s;
}

bool check(int n) {
    int t = n, s1 = 0, s2 = 0;
    while (t != 1) {
        s1 += calcs(minPrime[t]);
        t /= minPrime[t];
    }
    s2 = calcs(n);
    return (s1 == s2);
}

void snt() {
    memset(minPrime, 0, sizeof(minPrime));
    memset(f, 0, sizeof(f));
    for (int i = 2; i * i <= 10000001; ++i) {
        if (minPrime[i] == 0) {
            for (int j = i * i; j <= 10000001; j += i) {
                if (minPrime[j] == 0) {
                    minPrime[j] = i;
                }
            }
        }
    }
    for (int i = 2; i <= 10000001; ++i) {
        if (minPrime[i] == 0) {
            minPrime[i] = i;
            f[i] = f[i - 1] + 1;
        } else
            f[i] = f[i - 1] + check(i);
    }
    //cout << check(4937775) << endl;
}

int main()
{
    snt();

    int t, l, r;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        scanf("%d %d", &l, &r);
        printf("%d\n", f[r] - f[l - 1]);
    }

    return 0;
}

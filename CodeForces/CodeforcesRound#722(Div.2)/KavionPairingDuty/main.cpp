#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<int> minPrime;

void facSieve(int n) {
    minPrime.assign(n + 1, 0);
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

int numDiv(int n) {
    int ans = 1;
    map<int, int> cnt;
    map<int, int>::iterator it;
    while (n != 1) {
        cnt[minPrime[n]]++;
        n /= minPrime[n];
    }
    for (it = cnt.begin(); it != cnt.end(); it++)
        ans *= ((*it).second + 1);
    return ans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long n, mod = 998244353;
    long long f = 1, psf = 1;

    cin >> n;
    facSieve(n + 1);

    for (int i = 2; i <= n; i++) {
        f = (psf + numDiv(i)) % mod;
        psf = (psf + f) % mod;
    }
    cout << f;

    return 0;
}

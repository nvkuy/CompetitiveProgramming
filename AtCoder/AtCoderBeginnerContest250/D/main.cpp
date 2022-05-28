#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

void sieve(int n, vector<bool> &isPrime) {
    isPrime.assign(n + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 2; i * i <= n; ++i) {
         if(isPrime[i] == true) {
             for(int j = i * i; j <= n; j += i)
                 isPrime[j] = false;
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long ans = 0, n, maxQ = 1e6;
    vector<long long> ps(maxQ + 1);

    vector<bool> isPrime;
    sieve(maxQ, isPrime);

    ps[0] = 0;
    for (int i = 1; i <= maxQ; i++)
        ps[i] = ps[i - 1] + isPrime[i];

    cin >> n;
    for (long long q = 0; q <= maxQ; q++) {
        if (isPrime[q]) {
            long long maxP = min(n / (q * q * q), q - 1);
            ans += ps[maxP];
        }
    }
    cout << ans;

    return 0;
}

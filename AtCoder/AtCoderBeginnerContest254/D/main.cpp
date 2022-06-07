#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

void facSieve(int n, vector<int> &minPrime) {
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

long long smallestNotSqr(int n, vector<int> &minPrime) {
    map<int, int> cnt;
    map<int, int>::iterator it;
    while (n != 1) {
        cnt[minPrime[n]]++;
        n /= minPrime[n];
    }
    long long ans = 1;
    for (it = cnt.begin(); it != cnt.end(); it++) {
        if ((*it).second % 2)
            ans *= (*it).first;
    }
    return ans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<int> minPrime;
    facSieve(1e6, minPrime);

    long long ans = 0, n;
    cin >> n;
    vector<long long> sqn;
    for (long long i = 1; i <= n; i++)
        sqn.push_back(i * i);
    for (long long i = 1; i <= n; i++) {
        long long smallest = smallestNotSqr(i, minPrime);
        int l = 0, r = n - 1, m;
        while (l < r) {
            if (r - l == 1) {
                if (sqn[r] * smallest <= n)
                    l = r;
                break;
            }
            m = (l + r) / 2;
            if (sqn[m] * smallest <= n)
                l = m;
            else
                r = m - 1;
        }
        ans += (l + 1);
    }
    cout << ans;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int maxVal = 38, maxSntSize = 12;
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

set<int> factorize(int n) {
    set<int> res;
    while (n != 1) {
        res.insert(minPrime[n]);
        n /= minPrime[n];
    }
    return res;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<int> p2(18, 1);
    for (int i = 1; i < 18; i++)
        p2[i] = p2[i - 1] * 2;

    int n;
    cin >> n;
    vector<int> a(n), snt;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    facSieve(maxVal);
    for (int i = 1; i < maxVal; i++)
        if (minPrime[i] == i)
            snt.push_back(i);
    vector<int> cf(p2[maxSntSize], 0), pf(p2[maxSntSize], 0);
    for (int i = 0; i < n; i++) {
        pf = cf;
        fill(cf.begin(), cf.end(), 1e9);
        for (int state = 0; state < p2[maxSntSize]; state++) {
            bitset<17> bs(state);
            map<int, int> remain;
            for (int j = 0; j < snt.size(); j++) {
                if (bs[j] == 1)
                    continue;
                remain.insert({snt[j], j});
            }
            for (int j = 1; j < maxVal; j++) {
                bitset<17> bsf = bs;
                set<int> facs = factorize(j);
                bool iok = true;
                for (int k : facs) {
                    if (remain.find(k) == remain.end()) {
                        iok = false;
                        break;
                    }
                    bsf[remain[k]] = 1;
                }
                if (!iok)
                    continue;
                int opt_state = 0;
                for (int k = 0; k < maxSntSize; k++)
                    if (bsf[k] == 1) opt_state += p2[k];
                cf[opt_state] = min(cf[opt_state], pf[state] + abs(j - a[i]));
            }
        }
    }
    int ans = 1e9;
    for (int i = 0; i < p2[maxSntSize]; i++)
        ans = min(ans, cf[i]);
    cout << ans;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int maxVal = 58, maxSntSize = 16;

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

    vector<int> p2(maxSntSize + 1, 1);
    for (int i = 1; i <= maxSntSize; i++)
        p2[i] = p2[i - 1] * 2;

    int n;
    cin >> n;
    vector<int> a(n), snt, numMask(maxVal + 1);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    facSieve(maxVal);
    for (int i = 1; i <= maxVal; i++)
        if (minPrime[i] == i)
            snt.push_back(i);
    map<int, int> rp;
    for (int i = 0; i < snt.size(); i++)
        rp[snt[i]] = i;
    for (int i = 1; i <= maxVal; i++) {
        set<int> tmp = factorize(i);
        bitset<maxSntSize> mask(0);
        for (int k : tmp)
            mask[rp[k]] = 1;
        numMask[i] = mask.to_ullong();
    }
    vector<int> cf(p2[maxSntSize], 1e9), pf(p2[maxSntSize], 1e9);
    pf[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int mask = 0; mask < p2[maxSntSize]; mask++) {
            for (int num = 1; num <= maxVal; num++) {
                if ((numMask[num] & mask) != numMask[num])
                    continue;
                int opt_mask = (numMask[num] ^ mask);
                cf[mask] = min(cf[mask], pf[opt_mask] + abs(a[i] - num));
            }
        }
        pf = cf;
        fill(cf.begin(), cf.end(), 1e9);
    }
    int ans = 1e9;
    for (int i = 0; i < p2[maxSntSize]; i++)
        ans = min(ans, pf[i]);
    cout << ans;

    return 0;
}

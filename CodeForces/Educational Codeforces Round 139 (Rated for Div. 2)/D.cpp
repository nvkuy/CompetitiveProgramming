#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

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

set<int> factorize(int n, vector<int> &minPrime) {
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

    vector<int> minPrime;
    facSieve(1e7, minPrime);

    int t, x, y;
    cin >> t;
    while (t--) {
        cin >> x >> y;
        if (x + 1 == y) {
            cout << -1 << endl;
            continue;
        }
        if (gcd(x, y) > 1) {
            cout << 0 << endl;
            continue;
        }
        int tmp = y - x;
        int ans = 1e9;
        set<int> tt = factorize(tmp, minPrime);
        for (int pi : tt) {
            int ttt = x % pi;
            ans = min(ans, pi - ttt);
        }
        cout << ans << endl;
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

inline void debugLocal() {
    if (!fopen("input.txt", "r"))
        return;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
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

vector<int> factorize(int n, vector<int> &minPrime) {
    vector<int> res;
    while (n != 1) {
        res.push_back(minPrime[n]);
        n /= minPrime[n];
    }
    return res;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int n, ans = 1, nn;
    cin >> n;
    nn = n;
    vector<int> minPrime, facs;
    facSieve(1e6, minPrime);
    for (int i = 2; i * i <= nn * 8; i++) {
        facs = factorize(i, minPrime);
        for (int j : facs) {
            if (n % j == 0)
                n /= j;
        }
        if (n == 1) {
            ans = i;
            break;
        }
    }
    if (n > 1)
        ans = n;
    cout << ans << endl;

    return 0;
}

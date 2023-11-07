#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
#define bit_cnt(x) __builtin_popcountll(x)
#define low_bit(x) __builtin_ctzll(x)

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MAXN = 1e6;

int minPrime[MAXN + 1];
long long psPhi[MAXN + 1];

void facSieve() {
    for (int i = 2; i * i <= MAXN; ++i) {
        if (minPrime[i] == 0) {
            for (int j = i * i; j <= MAXN; j += i) {
                if (minPrime[j] == 0) {
                    minPrime[j] = i;
                }
            }
        }
    }
    for (int i = 2; i <= MAXN; ++i) {
        if (minPrime[i] == 0) {
            minPrime[i] = i;
        }
    }
}

int eulerPhi(int n) {
    int ans = n;
    while (true) {
        if (n <= 1) break;
        int p = minPrime[n];
        ans -= ans / p;
        while (n % p == 0) n /= p;
    }
    if (n > 1) ans -= ans / n;
    return ans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    facSieve();
    for (int i = 2; i <= MAXN; i++) {
        psPhi[i] += psPhi[i - 1];
        psPhi[i] += eulerPhi(i);
    }

    int t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;
        vector<long long> cnt_gcd(n + 1, 0);
        for (long long i = 2; i <= n; i++) {
            long long divide_i = n / i;
            cnt_gcd[i] = psPhi[divide_i];
        }
        long long cost = 0;
        for (long long i = n; i >= 2; i--) {
            long long have = cnt_gcd[i] / (i - 1);
            long long can_take = m / (i - 1);
            long long take = min(can_take, have);
            m -= take * (i - 1);
            cost += take * i;
        }
        if (m > 0) {
            cout << -1 << endl;
            continue;
        }
        cout << cost << endl;
    }

    return 0;
}

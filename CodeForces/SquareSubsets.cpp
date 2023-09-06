#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
#define bit_cnt(x) __builtin_popcountll(x)

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const long long mod = 1e9 + 7, MAXN = 1e5, NPRIME = 19;
long long per[MAXN + 1];
int prime[NPRIME] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67 };

long long power(long long num, long long pow) {
    if (pow == 0) return 1;
    if (pow % 2) return (num * power(num, pow - 1)) % mod;
    return power((num * num) % mod, pow / 2);
}

long long ckn(int n, int k) {
    return (per[n] * power((per[n - k] * per[k]) % mod, mod - 2)) % mod;
}

int num_to_bit(int num) {
    int res = 0;
    for (int i = 0; i < NPRIME; i++) {
        int cnt = 0;
        while (num % prime[i] == 0) {
            cnt++;
            num /= prime[i];
        }
        res |= ((cnt % 2) << i);
    }
    return res;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    per[0] = 1;
    for (int i = 1; i <= MAXN; i++)
        per[i] = (per[i - 1] * i) % mod;

    int n;
    cin >> n;
    map<int, int> cnt;
    while (n--) {
        int ai;
        cin >> ai;
        cnt[num_to_bit(ai)]++;
    }
    vector<pair<int, int>> num_cnt(cnt.begin(), cnt.end());
    
    vector<long long> pf(1 << NPRIME, 0), f = pf;
    pf[0] = 1;

    for (auto p : num_cnt) {
        fill(f.begin(), f.end(), 0);
        long long way_odd = 0, way_even = 0;
        for (int i = 0; i <= p.second; i++) {
            if (i % 2) way_odd += ckn(p.second, i);
            else way_even += ckn(p.second, i);
        }
        way_even %= mod;
        way_odd %= mod;
        for (int i = 0; i < (1 << NPRIME); i++) {
            f[i] = (f[i] + pf[i] * way_even) % mod;
            f[i ^ p.first] = (f[i ^ p.first] + pf[i] * way_odd) % mod; 
        }
        pf = f;
    }

    cout << (f[0] + mod - 1) % mod << endl;

    return 0;
}

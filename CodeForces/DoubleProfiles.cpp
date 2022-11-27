#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int base = 311, maxN = 1e6 + 5;
const long long m1 = 1e9 + 7, m2 = 1e9 + 9;
long long pow_base1[maxN], pow_base2[maxN];

void buildPow(int n) {
    pow_base1[0] = 1;
    for (int i = 1; i <= n; i++) {
        pow_base1[i] = (pow_base1[i - 1] * base);
        // pow_base2[i] = (pow_base2[i - 1] * base) % m2;
    }
}

void buildHash(const string &s, vector<long long> &pf_hash1, vector<long long> &pf_hash2) {
    pf_hash1.resize(s.length() + 1);
    // pf_hash2.resize(s.length() + 1);
    pf_hash1[0] = 0;
    for (int i = 1; i <= s.length(); i++) {
        pf_hash1[i] = (pf_hash1[i - 1] * base + s[i - 1]);
        // pf_hash2[i] = (pf_hash2[i - 1] * base + s[i - 1]) % m2;
    }
}

//index from 1
long long getHash(int l, int r, vector<long long> &pf_hash1, vector<long long> &pf_hash2) {
    // pair<long long, long long> ans;
    // ans.first = (pf_hash1[r] - pf_hash1[l - 1] * pow_base1[r - l + 1] + m1 * m1) % m1;
    // ans.second = (pf_hash2[r] - pf_hash2[l - 1] * pow_base2[r - l + 1] + m2 * m2) % m2;
    // return ans;
    // return (pf_hash1[r] - pf_hash1[l - 1] * pow_base1[r - l + 1] + m1 * m1) % m1;
    return (pf_hash1[r] - pf_hash1[l - 1] * pow_base1[r - l + 1]);
}

hash<string> hasher;

long long getHashh(string &s) {
    long long res = 0;
    for (int i = 1; i <= s.length(); i++) {
        res = (res * base + s[i - 1]);
        // pf_hash2[i] = (pf_hash2[i - 1] * base + s[i - 1]) % m2;
    }
    return res;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "w", stdout);
    // int x = 1000, y = x * (x - 1) / 2;
    // cout << x * x << ' ' << y << endl;
    // for (int i = 1; i <= x; i++)
    //     for (int j = i + 1; j <= x; j++)
    //         cout << x * x - i << ' ' << x * x - j << endl;
    // return 0;

    int n, m, u, v;
    cin >> n >> m;

    // buildPow(n + 1);

    vector<vector<int>> c(n + 1);
    while (m--) {
        cin >> u >> v;
        c[u].push_back(v);
        c[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        sort(c[i].begin(), c[i].end());
    unordered_map<long long, long long> cnt;
    cnt.reserve(n + m + 1);
    // cout << "OK" << endl;
    // return 0;
    for (int i = 1; i <= n; i++) {
        string hash = ".";
        for (int u : c[i])
            hash += (to_string(u) + ".");
        // vector<long long> t1, t2;
        // buildHash(hash, t1, t2);
        // // cout << "OK" << endl;
        // cnt[getHash(1, hash.length(), t1, t2)]++;
        cnt[getHashh(hash)]++;
    }
    // cout << "OK" << endl;
    // return 0;
    for (int i = 1; i <= n; i++)
        c[i].push_back(i);
    for (int i = 1; i <= n; i++)
        sort(c[i].begin(), c[i].end());
    for (int i = 1; i <= n; i++) {
        string hash = ".";
        for (int u : c[i])
            hash += (to_string(u) + ".");
        // vector<long long> t1, t2;
        // buildHash(hash, t1, t2);
        // cnt[getHash(1, hash.length(), t1, t2)]++;
        cnt[getHashh(hash)]++;
    }
    long long ans = 0;
    for (auto p : cnt) {
        // cout << p.first.first << ' ' << p.first.second << ' ' << p.second << endl;
        ans += (p.second * (p.second - 1LL)) / 2LL;
    }
    // cout << cnt.size() << endl;
    cout << ans << endl;

    return 0;
}

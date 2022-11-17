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

const int base = 311, maxN = 1e6 + 5;
const long long m1 = 1e9 + 7, m2 = 1e9 + 9;
long long pow_base1[maxN], pow_base2[maxN];

void buildPow(int n) {
    pow_base1[0] = pow_base2[0] = 1;
    for (int i = 1; i <= n; i++) {
        pow_base1[i] = (pow_base1[i - 1] * base) % m1;
        pow_base2[i] = (pow_base2[i - 1] * base) % m2;
    }
}

void buildHash(const string &s, vector<long long> &pf_hash1, vector<long long> &pf_hash2) {
    pf_hash1[0] = pf_hash2[0] = 0;
    for (int i = 1; i <= s.length(); i++) {
        pf_hash1[i] = (pf_hash1[i - 1] * base + s[i - 1]) % m1;
        pf_hash2[i] = (pf_hash2[i - 1] * base + s[i - 1]) % m2;
    }
}

//index from 1
pair<long long, long long> getHash(int l, int r, vector<long long> &pf_hash1, vector<long long> &pf_hash2) {
    pair<long long, long long> ans;
    ans.first = (pf_hash1[r] - pf_hash1[l - 1] * pow_base1[r - l + 1] + m1 * m1) % m1;
    ans.second = (pf_hash2[r] - pf_hash2[l - 1] * pow_base2[r - l + 1] + m2 * m2) % m2;
    return ans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    string s1, s2;
    cin >> s1;
    cin >> s2;
    buildPow(max(s1.length(), s2.length()) + 1);
    vector<long long> pf_hashs11(s1.length() + 1), pf_hashs12(s1.length() + 1), pf_hashs21(s2.length() + 1), pf_hashs22(s2.length() + 1);
    buildHash(s1, pf_hashs11, pf_hashs12);
    buildHash(s2, pf_hashs21, pf_hashs22);
    for (int i = 1; i <= s1.length(); i++) {
        int j = i + s2.length() - 1;
        if (j > s1.length())
                break;
        pair<long long, long long> p1 = getHash(i, j, pf_hashs11, pf_hashs12), p2 = getHash(1, s2.length(), pf_hashs21, pf_hashs22);
        //cout << p1.first << '|' << p1.second << ' ' << p2.first << '|' << p2.second << endl;
        if (p1 == p2)
            cout << i << ' ';
    }
    cout << endl;

    return 0;
}

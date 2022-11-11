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

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // debugLocal();

    long long mod = 1e9 + 7;
    string l, r;
    cin >> l;
    cin >> r;
    reverse(r.begin(), r.end());
    while (r.back() == '0')
        r.pop_back();
    reverse(r.begin(), r.end());
    reverse(l.begin(), l.end());
    while (l.back() == '0')
        l.pop_back();
    reverse(l.begin(), l.end());
    if (r.length() == 0) {
        cout << 0 << endl;
        return 0;
    }
    vector<long long> ans;
    if (l.length() < r.length()) {
        int p = -1;
        for (int i = 0; i < r.length(); i++) {
            if (r[i] != '0') {
                p = i;
                break;
            }
        }
        if (p >= 0) {
            // cout << p << endl;
            // cout << r.length() << endl;
            if (r[p] != '1')
                ans.push_back(r[p] - '0' - 1);
            for (int i = p + 1; i < r.length(); i++)
                ans.push_back(9);
        }
    } else {
        for (int i = 0; i < r.length(); i++) {
            if (r[i] == l[i] || r[i] == '1') {
                ans.push_back(r[i] - '0');
                continue;
            }
            if (r[i] > l[i]) {
                ans.push_back(r[i] - '0' - 1);
                for (int j = i + 1; j < r.length(); j++)
                    ans.push_back(9);
                break;
            } else {
                if (r[i] == '0') {
                    ans.push_back(0);
                    break;
                }
                ans.push_back(r[i] - '0' - 1);
                for (int j = i + 1; j < r.length(); j++)
                    ans.push_back(9);
                break;
            }
        }
    }
    long long ra = 1;
    for (int i = 0; i < ans.size(); i++) {
        ra = (ra * ans[i]) % mod;
        // cout << ans[i] << endl;
    }
    cout << ra << endl;

    return 0;
}

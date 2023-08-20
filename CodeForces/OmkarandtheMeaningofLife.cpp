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

int query(vector<int> a) {
    cout << "? ";
    for (int num : a) cout << num << ' ';
    cout << endl;
    cout.flush();
    int rp;
    cin >> rp;
    return rp;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    map<int, int> q1, q2;

    for (int i = 1; i <= n; i++) {
        vector<int> tmp(n, 1);
        for (int j = 0; j + 1 < n; j++) tmp[j] = i;
        int pos = query(tmp);
        pos--;
        if (pos >= 0) q1[pos] = i;
    }

    for (int i = 1; i <= n; i++) {
        vector<int> tmp(n, 1);
        tmp[n - 1] = i;
        int pos = query(tmp);
        pos--;
        if (pos >= 0) q2[pos] = i;
    }

    vector<int> ans(n);
    ans[n - 1] = q1.size() + 1;

    for (auto p : q1) ans[p.first] = ans[n - 1] + 1 - p.second;
    for (auto p : q2) ans[p.first] = ans[n - 1] + p.second - 1;

    cout << "! ";
    for (int num : ans) cout << num << ' ';
    cout << endl;
    cout.flush();

    return 0;
}

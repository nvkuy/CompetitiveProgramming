#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

inline void debugMode() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

bool build1(int n, int d1, int d2, int d3, int left, int mid, int right, vector<pair<int, int>> &c) {
    if (d2 != d1 + d3)
        return false;
    c.clear();
    vector<int> tmp;
    tmp.push_back(left);
    int rm = 4;
    while (d1 > 1) {
        tmp.push_back(rm);
        rm++;
        d1--;
    }
    tmp.push_back(mid);
    while (d3 > 1) {
        tmp.push_back(rm);
        rm++;
        d3--;
    }
    tmp.push_back(right);
    while (rm <= n) {
        tmp.push_back(rm);
        rm++;
    }
    for (int i = 1; i < n; i++)
        c.push_back({tmp[i - 1], tmp[i]});
    return true;
}

bool build2(int n, int d1, int d2, int d3, int left, int mid, int right, vector<pair<int, int>> &c) {
    if ((d1 + d3 - d2) % 2 == 1)
        return false;
    int t2 = (d1 + d3 - d2) / 2;
    int t1 = d1 - t2, t3 = d3 - t2;
    if (t1 + t2 + t3 + 1 > n || min(t1, min(t2, t3)) <= 0)
        return false;
    c.clear();
    int rm = 5;
    vector<int> v1(1, 4), v2(1, 4), v3(1, 4);
    while (t1 > 1) {
        v1.push_back(rm);
        rm++;
        t1--;
    }
    v1.push_back(left);
    while (t2 > 1) {
        v2.push_back(rm);
        rm++;
        t2--;
    }
    v2.push_back(mid);
    while (t3 > 1) {
        v3.push_back(rm);
        rm++;
        t3--;
    }
    v3.push_back(right);
    while (rm <= n) {
        v3.push_back(rm);
        rm++;
    }
    for (int i = 1; i < v1.size(); i++)
        c.push_back({v1[i - 1], v1[i]});
    for (int i = 1; i < v2.size(); i++)
        c.push_back({v2[i - 1], v2[i]});
    for (int i = 1; i < v3.size(); i++)
        c.push_back({v3[i - 1], v3[i]});
    return true;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugMode();

    int t, n, d1, d2, d3;
    cin >> t;
    while (t--) {
        cin >> n >> d1 >> d2 >> d3;
        vector<pair<int, int>> c;
        bool iok = false;
        if (!iok)
            iok = build1(n, d1, d2, d3, 2, 1, 3, c);
        if (!iok)
            iok = build1(n, d2, d1, d3, 2, 3, 1, c);
        if (!iok)
            iok = build1(n, d1, d3, d2, 1, 2, 3, c);
        if (!iok)
            iok = build2(n, d1, d2, d3, 2, 1, 3, c);
        if (!iok)
            iok = build2(n, d2, d1, d3, 2, 3, 1, c);
        if (!iok)
            iok = build2(n, d1, d3, d2, 1, 2, 3, c);
        if (!iok) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        for (auto p : c)
            cout << p.first << ' ' << p.second << endl;
    }

    return 0;
}

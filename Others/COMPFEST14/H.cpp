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

bool check(vector<int> &a, vector<int> &ans, int z) {
    vector<int> has(3, 0);
    for (int i = 0; i < a.size(); i++)
        has[a[i] % 3]++;
    vector<vector<int>> c(3, vector<int>(3, 0));
    for (int i = 0; i < 3; i++) {
        if (has[i] == 0)
            continue;
        for (int j = 0; j < 3; j++) {
            if (has[j] == 0 || (i == j && has[j] == 1))
                continue;
            if ((((i + j) * (i + j) + i * j) % 3) == z)
                c[i][j] = 1;
            // cout << i << '|' << j << '|' << (((i + j) * (i + j) + i * j) % 3) << '|' << z << endl;
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (i == 2 && c[0][0] == 1)
                    continue;
                if (j == 2 && c[1][1] == 1)
                    continue;
                if (k == 2 && c[2][2] == 1)
                    continue;
                if ((i != j || i == 2 || j == 2) && c[0][1] == 1)
                    continue;
                if ((i != k || i == 2 || k == 2) && c[0][2] == 1)
                    continue;
                if ((j != k || j == 2 || k == 2) && c[1][2] == 1)
                    continue;
                int c0 = 0, c1 = 0;
                c0 += ((i == 0) * has[0]);
                c0 += ((j == 0) * has[1]);
                c0 += ((k == 0) * has[2]);
                c1 += ((i == 1) * has[0]);
                c1 += ((j == 1) * has[1]);
                c1 += ((k == 1) * has[2]);
                if (c0 * 2 > a.size() || c1 * 2 > a.size())
                    continue;
                int n0 = (a.size() / 2) - c0;
                ans.clear();
                for (int ai : a) {
                    if (ai % 3 == 0) {
                        if (i == 2) {
                            if (n0 == 0)
                                ans.push_back(1);
                            else {
                                ans.push_back(0);
                                n0--;
                            }
                        } else
                            ans.push_back(i);
                    }
                    if (ai % 3 == 1) {
                        if (j == 2) {
                            if (n0 == 0)
                                ans.push_back(1);
                            else {
                                ans.push_back(0);
                                n0--;
                            }
                        } else
                            ans.push_back(j);
                    }
                    if (ai % 3 == 2) {
                        if (k == 2) {
                            if (n0 == 0)
                                ans.push_back(1);
                            else {
                                ans.push_back(0);
                                n0--;
                            }
                        } else
                            ans.push_back(k);
                    }
                }
                return true;
            }
        }
    }
    return false;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int n;
    cin >> n;
    vector<int > a(n), ans(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < 3; i++) {
        if (check(a, ans, i)) {
            cout << i << endl;
            for (int cl : ans)
                cout << cl;
            cout << endl;
            return 0;
        }
    }
    cout << -1 << endl;
	
    return 0;
}

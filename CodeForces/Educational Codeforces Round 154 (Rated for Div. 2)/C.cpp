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

const int unknown = 0, inc = 1, not_inc = -1;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.length(), iok = 1, cur = 0;
        vector<int> f(n + 2, unknown);
        f[0] = inc;
        for (auto c : s) {
            if (c == '+' || c == '-') {
                if (c == '+') {
                    cur++;
                    if (cur < 2)
                        f[cur] = inc;
                    else {
                        if (f[cur - 1] == inc)
                            f[cur] = unknown;
                        else
                            f[cur] = f[cur - 1];
                    }
                } else {
                    f[cur] = unknown;
                    cur--;
                }
            } else {
                if (c == '1') {
                    if (f[cur] == not_inc)
                        iok = 0;
                    int tmp = cur;
                    while (f[tmp] == unknown) {
                        f[tmp] = inc;
                        tmp--;
                    }
                } else {
                    if (f[cur] == inc)
                        iok = 0;
                    f[cur] = not_inc;
                }
            }
        }
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}

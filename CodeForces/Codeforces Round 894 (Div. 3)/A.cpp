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

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        set<int> v_pos, i_pos, k_pos, a_pos;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++) {
                if (s[j] == 'v')
                    v_pos.insert(j);
                if (s[j] == 'i')
                    i_pos.insert(j);
                if (s[j] == 'k')
                    k_pos.insert(j);
                if (s[j] == 'a')
                    a_pos.insert(j);
            }
        }
        bool iok = false;
        for (int p1 : i_pos) {
            for (int p2 : k_pos) {
                if (p1 >= p2) continue;
                if (v_pos.size() > 0 && *v_pos.begin() < p1 && a_pos.size() > 0 && *a_pos.rbegin() > p2)
                    iok = true;
            }
        }
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}

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
        set<long long> ss;
        vector<long long> c_val(n);
        for (int i = 0; i < n; i++) {
            long long tmp = 0;
            for (int j = 0; j < m; j++) {
                long long cij;
                cin >> cij;
                tmp += cij * j;
            }
            ss.insert(tmp);
            c_val[i] = tmp;
        }
        assert(ss.size() == 2);
        int special = 0;
        for (int i = 0; i < n; i++)
            if (c_val[i] == *ss.rbegin())
                special = i;
        cout << special + 1 << ' ' << *ss.rbegin() - *ss.begin() << endl;
    }

    return 0;
}

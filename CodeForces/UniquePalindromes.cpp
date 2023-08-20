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
        int n, k;
        cin >> n >> k;
        vector<int> x(k + 1), c(k + 1);
        x[0] = 3; c[0] = 3;
        for (int i = 1; i <= k; i++) cin >> x[i];
        for (int i = 1; i <= k; i++) cin >> c[i];
        bool iok = true;
        for (int i = 1; i <= k; i++) {
            if (x[i] - x[i - 1] < c[i] - c[i - 1]) 
                iok = false;
        }
        if (!iok) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        cout << "abc";
        char tmp = 'a';
        for (int i = 1; i <= k; i++) {
            int not_need = (x[i] - x[i - 1]) - (c[i] - c[i - 1]), need = (x[i] - x[i - 1]) - not_need;
            for (int j = 0; j < need; j++) cout << char('c' + i);
            for (int j = 0; j < not_need; j++) {
                cout << tmp;
                tmp = (((tmp - 'a') + 1) % 3) + 'a';
            }
        }
        cout << endl;
    }

    return 0;
}

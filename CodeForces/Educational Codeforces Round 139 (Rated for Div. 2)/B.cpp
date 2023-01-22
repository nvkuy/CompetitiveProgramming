#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n;
    string s;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> s;
        bool iok = false;
        set<string> dd;
        for (int i = 2; i < n; i++) {
            string tmp;
            tmp.push_back(s[i - 1]);
            tmp.push_back(s[i]);
            if (dd.find(tmp) != dd.end()) {
                iok = true;
                break;
            }
            tmp.clear();
            tmp.push_back(s[i - 2]);
            tmp.push_back(s[i - 1]);
            dd.insert(tmp);
        }
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}

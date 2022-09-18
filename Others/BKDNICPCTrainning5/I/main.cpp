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

    int n;
    string s;
    cin >> n;
    vector<int> rp;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s == "LIE")
            rp.push_back(0);
        else
            rp.push_back(1);
    }
    for (int i = n - 1; i > 0; i--) {
        if (rp[i] == 0)
            rp[i - 1] = 1 - rp[i - 1];
    }
    cout << (rp[0] ? "TRUTH" : "LIE");

    return 0;
}

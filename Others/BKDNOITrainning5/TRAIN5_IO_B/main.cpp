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
    char a, b;
    map<char, char> c;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        c[a] = b;
    }
    cin >> n;
    string ans;
    while (n--) {
        cin >> a;
        if (c.find(a) == c.end())
            ans.push_back(a);
        else
            ans.push_back(c[a]);
    }
    cout << ans;

    return 0;
}

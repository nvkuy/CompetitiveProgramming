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

    string s;
    int n, c;
    map<string, long long> cnt;
    cin >> n;
    while (n--) {
        cin >> s >> c;
        cnt[s] += c;
    }
    for (int i = 1; i <= 5; i++) {
        for (auto p : cnt) {
            if (p.first.length() != i)
                continue;
            cout << p.first << ' ' << p.second << endl;
        }
    }

    return 0;
}

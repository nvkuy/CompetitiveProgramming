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

    long long t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        vector<pair<int, long long>> ra;
        for (auto rit = cnt.rbegin(); rit != cnt.rend(); rit++)
            ra.push_back(*rit);
        long long ans = 0, addEdge = 0, curNode = 0;
        for (int i = 0; i < ra.size(); i++) {
            addEdge += (ra[i].second / 2);
            curNode += ra[i].second;
            long long tans = 0;
            long long rmNode = n - curNode;
            tans = max(rmNode * curNode, addEdge);
            ans = max(ans, tans);
        }
        cout << ans << endl;
    }

    return 0;
}

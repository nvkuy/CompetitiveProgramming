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

        int n;
        cin >> n;
        vector<int> a(n), sa;
        for (int i = 0; i < n; i++) cin >> a[i];

        sa = a;
        sort(sa.begin(), sa.end());
        multiset<int> diff, arr(sa.begin(), sa.end());
        for (int i = 0; i < n; i++) {
            if (i - 1 >= 0) 
                diff.insert(sa[i] - sa[i - 1]);
        }

        int q;
        cin >> q;
        while (q--) {

            int x, v;
            cin >> x >> v;
            x--;

            int pre = -1, next = -1;
            auto it = arr.lower_bound(a[x]);
            if (it != arr.begin()) {
                it--;
                pre = *it;
                it++;
            }
            it++;
            if (it != arr.end()) next = *it;
            it--;
            if (pre > 0) diff.erase(diff.lower_bound(a[x] - pre));
            if (next > 0) diff.erase(diff.lower_bound(next - a[x]));
            if (pre > 0 && next > 0) diff.insert(next - pre);
            arr.erase(it);
            a[x] = v;

            pre = -1, next = -1;
            it = arr.lower_bound(v);
            if (it != arr.end()) next = *it;
            if (it != arr.begin()) {
                it--;
                pre = *it;
            }
            if (pre > 0 && next > 0) diff.erase(diff.lower_bound(next - pre));
            if (pre > 0) diff.insert(v - pre);
            if (next > 0) diff.insert(next - v);
            arr.insert(v);

            int t1 = 0, t2 = 0;
            if (diff.size() > 0) t1 = *diff.rbegin();
            if (arr.size() > 0) t2 = *arr.rbegin();
            cout << t1 + t2 << ' ';
            
        }
        cout << endl;
    }

    return 0;
}

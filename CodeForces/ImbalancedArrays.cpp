#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

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
        vector<int> a(n);
        map<int, int> cnt, f;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        int cur = n, greater = 0, too_small = 0;
        bool iok = true;
        auto it1 = cnt.begin();
        for (auto it2 = cnt.rbegin(); it2 != cnt.rend(); it2++) {
            if (greater >= it1->first) {
                if (greater > it1->first) {
                    iok = false;
                    break;
                }
                f[it1->first] = -cur;
                cur--;
                too_small += it1->second;
                it1++;
            }
            if (it1 == cnt.end() || it1->first > it2->first) break;
            greater += it2->second;
            if (n - too_small != it2->first) {
                iok = false;
                break;
            }
            f[it2->first] = cur;
            cur--;
            if (it1->first == it2->first) break;
        }
        if (!iok) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        for (auto num : a)
            cout << f[num] << ' ';
        cout << endl;
    }

    return 0;
}

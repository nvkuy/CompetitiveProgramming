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

    int n, d, ans = 0;
    cin >> n >> d;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    while (a.size() > 0 && a.back() > d) {
        ans++;
        a.pop_back();
    }
    deque<int> rm;
    for (int i = 0; i < a.size(); i++)
        rm.push_back(a[i]);
    while (true) {
        if (rm.size() == 0)
            break;
        int mn = rm.back();
        rm.pop_back();
        int curS = mn;
        while (true) {
            if (curS > d) {
                ans++;
                break;
            }
            if (rm.size() == 0)
                break;
            curS += mn;
            rm.pop_front();
        }
    }
    cout << ans << endl;

    return 0;
}

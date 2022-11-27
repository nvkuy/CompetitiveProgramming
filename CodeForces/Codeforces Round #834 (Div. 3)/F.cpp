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

    int t, n, p;
    cin >> t;
    while (t--) {
        cin >> n >> p;
        set<int> s;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s.insert(a[i]);
        }
        int endPoint = (a[n - 1] - 1 + p) % p;
        while (s.find(endPoint) != s.end() && endPoint != a[n - 1])
            endPoint = (endPoint - 1 + p) % p;
        if (endPoint == a[n - 1]) {
            cout << 0 << endl;
            continue;
        }
        if (endPoint > a[n - 1]) {
            cout << endPoint - a[n - 1] << endl;
            continue;
        }
        int ans = p - a[n - 1], last = a[n - 1]; 
        a[n - 1] = p - 1;
        for (int i = n - 1; i >= 0; i--) {
            a[i]++;
            a[i] %= p;
            if (a[i] != 0)
                break;
        }
        if (a[0] == 0)
            a.insert(a.begin(), 1);
        for (int ai : a)
            s.insert(ai);
        endPoint = last - 1;
        while (s.find(endPoint) != s.end() && endPoint > 0)
            endPoint = (endPoint - 1 + p) % p;
        ans += endPoint;
        cout << ans << endl;
    }

    return 0;
}

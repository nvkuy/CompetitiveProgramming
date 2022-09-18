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
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n), b;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        b = a;
        int final_pos = 0, curMax = 0;
        set<int> s;
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (s.find(a[i]) != s.end())
                a[i] = 0;
            if (a[i] < curMax) {
                final_pos = i;
                while (q.size() > 0) {
                    s.insert(q.front());
                    q.pop();
                }
            }
            curMax = a[i];
            q.push(b[i]);
        }
        s.clear();
        for (int i = 0; i < final_pos; i++)
            s.insert(b[i]);
        cout << s.size() << endl;
    }

    return 0;
}

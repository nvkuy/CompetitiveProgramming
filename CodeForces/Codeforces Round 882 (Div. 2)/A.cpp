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
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b;
        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 1; i < n; i++)
            b.push_back(abs(a[i] - a[i - 1]));
        sort(b.begin(), b.end());
        while (k > 1 && b.size() > 0) {
            k--;
            b.pop_back();
        }

        cout << accumulate(b.begin(), b.end(), 0) << endl;

    }

    return 0;
}

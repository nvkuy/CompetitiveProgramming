#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

bool cmp(pair<int, int> p1, pair<int, int> p2) {
    int r1 = p1.first + p1.second, r2 = p2.first + p2.second;
    if (p1.first == p2.first)
        return r1 < r2;
    return p1.first < p2.first;
}

int rand_range(int l, int r) {
    return l + rand() % (r - l + 1);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    srand(842003);

    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i].first >> arr[i].second;
        }
        if (arr[0].first >= k) {
            cout << "YES" << endl;
            continue;
        }
        if (n == 1 || arr[0].first + arr[0].second < k) {
            cout << "NO" << endl;
            continue;
        }
        sort(arr.begin() + 1, arr.end(), cmp);
        int p = arr[1].first;
        for (int i = 2; i < n; i++) {
            if (p >= arr[i].first)
                p = max(p, arr[i].first + arr[i].second);
            else
                p = max(arr[i].first, p + arr[i].second);
        }
        cout << (p >= arr[0].first ? "YES" : "NO") << endl;
    }

    return 0;
}

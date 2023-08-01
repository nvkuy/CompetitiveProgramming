#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

long long cal(long long a, long long b) {

    if (a == 0) return 0;
    if (b == 0) return 1;
    if (a < b) return 1 + cal(b, b - a);
    long long num = a / (2LL * b);
    if (num == 0)
        return 1 + cal(b, a - b);
    return num * 3LL + cal(a % (2LL * b), b);

}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // cout << cal(4, 4) << ' ' << cal(0, 0) << ' ' << cal(2, 2) << endl;
    // cout << cal(2, 1) << ' ' << cal(1, 2) << ' ' << cal(7, 2) << ' ' << cal(9, 2) << ' ' << cal(8, 3) << ' ' << cal(8, 2) << endl;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        set<int> tmp;
        for (int i = 0; i < n; i++) {
            if (max(a[i], b[i]) == 0) continue;
            tmp.insert(cal(a[i], b[i]) % 3LL);
        }
        cout << (tmp.size() <= 1 ? "YES" : "NO") << endl;
    }

    return 0;
}

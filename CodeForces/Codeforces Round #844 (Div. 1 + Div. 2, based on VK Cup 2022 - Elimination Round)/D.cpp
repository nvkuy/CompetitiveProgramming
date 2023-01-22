#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

bool check(long long num) {
    long long tmp = sqrt(num);
    return tmp * tmp == num;
}

int cal(int n, long long x, vector<int> &a) {
    int res = 0;
    for (int i = 0; i < n; i++) res += check(x + a[i]);
    return res;
}

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
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        int ans = max(cal(n, 0, a), 1);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int diff = a[j] - a[i];
                for (int k = 1; k * k <= diff; k++) {
                    if (diff % k > 0) continue;
                    int c1 = k, c2 = diff / k;
                    if ((c1 + c2) % 2 > 0) continue;
                    long long b1 = (c1 + c2) / 2;
                    long long aa = b1 * b1 - a[j];
                    if (aa <= 0) continue;
                    ans = max(ans, cal(n, aa, a));
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}

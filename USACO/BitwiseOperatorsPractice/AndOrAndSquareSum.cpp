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


    int n;
    cin >> n;
    vector<int> a(n), cnt(22, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < 22; j++)
            if ((a[i] >> j) & 1) cnt[j]++;
    }
    long long ans = 0;
    while (true) {
        if (accumulate(cnt.begin(), cnt.end(), 0) == 0) break;
        long long num = 0;
        for (int i = 0; i < 22; i++) {
            if (cnt[i] > 0) {
                num += (1 << i);
                cnt[i]--;
            }
        }
        ans += (num * num);
    }
    cout << ans << endl;

    return 0;
}

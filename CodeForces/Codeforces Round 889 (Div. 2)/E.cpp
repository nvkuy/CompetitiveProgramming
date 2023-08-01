#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MaxN = 2e5 + 1;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<long long> a(MaxN, 0), ps(MaxN, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ps[i] = a[i];
    }
    for (int i = 1; i < MaxN; i++)
        ps[i] += ps[i - 1];

    bitset<MaxN> canUnlock(0);
    canUnlock[0] = 1;
    // for (int i = 0; i < n; i++)
    //     canUnlock = (canUnlock | (((canUnlock >> i) << i) << a[i]));
    for (int i = 0; i < n; i++)
        canUnlock |= ((canUnlock >> i) << (i + a[i]));
    
    long long ans = 0;
    for (int i = 0; i < MaxN; i++) {
        if (canUnlock[i])
            ans = max(ans, ps[i] - i);
    }

    cout << ans << endl;

    return 0;
}

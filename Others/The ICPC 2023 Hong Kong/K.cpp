#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
#define bit_cnt(x) __builtin_popcountll(x)

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<long long> cnt(k + 1, 0), cntRep(1e5 + 1, 0);
    for (int i = 0; i < n; i++) {
        int ai;
        cin >> ai;
        cntRep[ai + 1]++;
    }
    for (int i = 1; i <= 1e5; i++) {
        for (int j = 0; j * i <= k; j++) {
            cnt[j * i] += cntRep[i];
        }
    }
    for (int i = 1; i <= k; i++) cout << cnt[i] << ' ';
    cout << endl;

    return 0;
}

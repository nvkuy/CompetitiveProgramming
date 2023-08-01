#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

long long cal(int n, vector<int> a) {
    int start = 0, end = (start + 1) % n;
    long long curSum = a[start];
    while (start != end) {
        while (curSum < 0) {
            start = (start + n - 1) % n;
            curSum += a[start];
        }
        curSum += a[end];
        end = (end + 1) % n;
        if (curSum >= 0) continue;
        while (curSum < 0) {
            start = (start + n - 1) % n;
            curSum += a[start];
        }
    }
    // cout << start << endl;
    long long res = 0, curCarry = 0;
    int pos = start;
    while (true) {
        curCarry += a[pos];
        // cout << curCarry << ' ';
        res += curCarry;
        pos = (pos + 1) % n;
        if (pos == start) break;
    }
    // cout << endl;
    return res;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    long long fullSum = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        fullSum += a[i];
    }
    for (int i = 0; i < n; i++)
        a[i] = a[i] - (fullSum / n);

    // for (int i = 0; i < n; i++)
    //     cout << a[i] << ' ';
    // cout << endl;

    long long ans = cal(n, a);
    reverse(a.begin(), a.end());
    ans = min(ans, cal(n, a));
    cout << ans << endl;

    return 0;
}

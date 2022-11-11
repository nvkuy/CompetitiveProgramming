#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

inline void debugLocal() {
    if (!fopen("input.txt", "r"))
        return;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<long long> a(n), b;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        b.push_back(a[0]);
        for (int i = 0; i + 1 < n; i++)
            b.push_back(lcm(a[i], a[i + 1]));
        b.push_back(a.back());
        bool iok = true;
        for (int i = 0; i < n; i++) {
            if (gcd(b[i], b[i + 1]) != a[i]) {
                iok = false;
                break;
            }
        }
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}
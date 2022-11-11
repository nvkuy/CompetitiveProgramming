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

double er = 1e-8;

bool cmpLess(double a, double b) {
    return (a + er <= b);
}

bool cmpGreater(double a, double b) {
    return (a >= b + er);
}

void check(double a, double d, double p, int &ans1, int &ans2) {
    if (cmpGreater(a / d, p))
        ans1++;
    if (cmpLess(a / d, -p))
        ans2++;
    return;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int n, ans1 = 0, ans2 = 0;
    double p;
    cin >> n >> p;
    vector<int> c(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int len = 3; len <= n; len++) {
        int tmp = 0;
        double a, d;
        for (int i = 1; i < len; i++)
            tmp += (c[i] - c[i - 1]);
        a = 1.0 * tmp / n;
        
        for (int i = 1; i < n; i++) {
            if (i + len - 1 >= n)
                break;
            
        }
    }

    return 0;
}

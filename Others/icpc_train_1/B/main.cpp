#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

struct line {
    int a, b, c;
};

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

bool isParallel(line l1, line l2) {
    int g1 = gcd(l1.a, l1.b);
    if (g1 != 0) {
        l1.a /= g1;
        l1.b /= g1;
    }
    if (l1.a < 0) {
        l1.a *= -1;
        l1.b *= -1;
    }
    int g2 = gcd(l2.a, l2.b);
    if (g2 != 0) {
        l2.a /= g2;
        l2.b /= g2;
    }
    if (l2.a < 0) {
        l2.a *= -1;
        l2.b *= -1;
    }
    return (l1.a == l2.a && l1.b == l2.b);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<line> lines(n);
    for (int i = 0; i < n; i++)
        cin >> lines[i].a >> lines[i].b >> lines[i].c;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (isParallel(lines[i], lines[j]))
                continue;
            for (int k = j + 1; k < n; k++) {
                if (isParallel(lines[i], lines[k]) || isParallel(lines[j], lines[k]))
                    continue;
                ans++;
            }
        }
    }
    cout << ans;

    return 0;
}


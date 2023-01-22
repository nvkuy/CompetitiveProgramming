#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        if (n == 2) {
            cout << "YES" << endl;
            cout << "1 -1" << endl;
            continue;
        }
        if (n == 3) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        int a = n / 2, b = a;
        if (n % 2)
            a++;
        a--, b--;
        int tmp = lcm(a, b);
        a = tmp / a, b = -1 * (tmp / b);
        if (abs(a) > abs(b))
            swap(a, b);
        if (n % 2)
            cout << a << ' ';
        for (int i = 0; i < n / 2; i++)
            cout << b << ' ' << a << ' ';
        cout << endl;
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, a, b;
    cin >> n >> m >> a >> b;
    int t1 = a % m, t2 = b % m;
    if (t1 == 0) t1 += m;
    if (t2 == 0) t2 += m;
    if (((a - 1) / m == (b - 1) / m) || (t1 == 1 && t2 == m) || (t1 == 1 && b == n)) {
        cout << "1";
        return 0;
    }
    if (t1 == 1 || t2 == m || abs(t1 - t2) == 1 || b == n || a == 1) {
        cout << "2";
        return 0;
    }
    cout << "3";

    return 0;
}

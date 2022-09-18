#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    long long n, k;
    cin >> t;
    while (t--) {
        cin >> n;
        k = n;
        while (k % 2 == 0)
            k /= 2;
        if (k == 1) {
            cout << "-1\n";
            continue;
        }
        if ((k > 1e9 + 1e3) || ((k + 1LL) * k) > (2LL * n))
            k = ((2LL * n) / k);
        cout << k << endl;
    }

    return 0;
}

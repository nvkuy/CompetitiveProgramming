#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, c1, c2;
    cin >> t;
    while (t--) {
        cin >> n;
        c1 = c2 = n / 3;
        if (n % 3 == 1)
            c1++;
        if (n % 3 == 2)
            c2++;
        cout << c1 << ' ' << c2 << endl;
    }

    return 0;
}

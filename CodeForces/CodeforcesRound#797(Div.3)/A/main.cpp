#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int h1 = 3, h2 = 2, h3 = 1;
        n -= 6;
        int tmp = n / 3;
        h1 += tmp, h2 += tmp, h3 += tmp;
        tmp = n % 3;
        if (tmp >= 1)
            h1++;
        if (tmp >= 2)
            h2++;
        cout << h2 << ' ' << h1 << ' ' << h3 << endl;
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        pair<int, int> r1, r2;
        cin >> r1.first >> r1.second >> r2.first >> r2.second;
        if (r1.second > r2.second)
            swap(r1, r2);
        if (r1.second >= r2.first && r1.second <= r2.second)
            cout << max(r2.first, r1.first) << endl;
        else
            cout << r1.first + r2.first << endl;
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        if (a == 0) {
            cout << "1\n";
            continue;
        }
        cout << b * 2 + a + 1 << endl;
    }

    return 0;
}

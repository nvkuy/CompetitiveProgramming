#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, m, ai;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        int energy_need = 0;
        for (int i = 0; i < n; i++) {
            cin >> ai;
            energy_need += ai;
        }
        cout << max(0, energy_need - m) << endl;
    }

    return 0;
}

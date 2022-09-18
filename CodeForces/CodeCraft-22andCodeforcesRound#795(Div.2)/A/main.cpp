#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, ai;
    cin >> t;
    while (t--) {
        cin >> n;
        int oc = 0, ec = 0;
        for (int i = 0; i < n; i++) {
            cin >> ai;
            if (ai % 2)
                oc++;
            else
                ec++;
        }
        cout << min(oc, ec) << endl;
    }

    return 0;
}

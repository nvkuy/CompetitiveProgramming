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
        int ec = 0, ai;
        for (int i = 0; i < n; i++) {
            cin >> ai;
            if (ai % 2 == 0)
                ec++;
        }
        cout << ((ec % 2) ? "errorgorn" : "maomao90") << endl;
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<long long> c(n);
        for (int i = 0; i < n; i++)
            cin >> c[i];
        long long minOddPos = 1, minEvenPos = 0, rmOdd = n, rmEven = n;
        long long ans = c[minOddPos] * rmOdd + c[minEvenPos] * rmEven, ps = c[minEvenPos] + c[minOddPos];
        for (int i = 2; i < n; i++) {
            //cout << ans << endl;
            if (i % 2) {
                if (c[i] < c[minOddPos])
                    minOddPos = i;
                rmOdd--;
            } else {
                if (c[i] < c[minEvenPos])
                    minEvenPos = i;
                rmEven--;
            }
            ps += c[i];
            long long tans = c[minOddPos] * rmOdd + c[minEvenPos] * rmEven + (ps - c[minEvenPos] - c[minOddPos]);
            ans = min(ans, tans);
        }
        cout << ans << endl;
    }

    return 0;
}

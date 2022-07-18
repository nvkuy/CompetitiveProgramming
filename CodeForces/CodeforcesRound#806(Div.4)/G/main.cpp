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
        cin >> n >> k;
        vector<int> a(n + 1, 0);
        vector<long long> ps(n + 1, 0);
        long long ans = -1e18, tans;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            ps[i] = ps[i - 1] + a[i];
        }
        for (long long numKey = 0; numKey <= n; numKey++) {
            vector<int> b = a;
            for (long long numBadKey = 0; numBadKey <= 30; numBadKey++) {
                if (numKey < numBadKey)
                    break;
                long long numGoodKey = numKey - numBadKey;
                long long tans = ps[numGoodKey] - numGoodKey * k;
                for (long long i = numGoodKey + 1; i <= numKey; i++) {
                    b[i] /= 2;
                    tans += b[i];
                }
                ans = max(ans, tans);
                //cout << numKey << '|' << numBadKey << '|' << tans << endl;
            }
        }
        cout << ans << endl;
    }

    return 0;
}

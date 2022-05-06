#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    long long n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        long long ans = a[0] * n + a[1] * n, movedDis = a[0] + a[1], iMinOdd = 1, iMinEven = 0;
        for (long long i = 2; i < n; i++) {
            long long movedDisEachDirect = i / 2, remainDisVer, remainDisHor;
            remainDisHor = remainDisVer = n - movedDisEachDirect;
            if (i % 2) {
                ans = min(ans, a[i] * remainDisHor + a[iMinEven] * remainDisVer + movedDis - a[iMinEven]);
                if (a[iMinOdd] > a[i])
                    iMinOdd = i;
            } else {
                remainDisHor++;
                long long minCostSeg = min(a[i], a[iMinOdd]);
                ans = min(ans, minCostSeg * remainDisHor)
            }
        }
    }

    return 0;
}

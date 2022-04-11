#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long n, k, ans = 0, decSum = 0, sum = 0;
    cin >> n >> k;
    vector<long long> a(n);
    vector<long long> close(n, 0);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (long long i = n - 1; i >= 0; i--) {
        a[i] -= sum;
        long long t2 = min(i + 1, k);
        long long t1 = (max(a[i], 0LL) / t2) + (a[i] % t2 > 0);
        ans += t1;
        close[i - t2 + 1] += t1;
        decSum += t1;
        sum += (t1 * t2);
        sum -= decSum;
        decSum -= close[i];
        //cout << sum << '|' << decSum << '|' << ans << endl;
    }
    cout << ans << endl;

    return 0;
}

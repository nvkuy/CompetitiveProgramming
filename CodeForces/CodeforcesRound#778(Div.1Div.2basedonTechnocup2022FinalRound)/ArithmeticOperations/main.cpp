#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

long long n;
vector<long long> arr;

long long cal(long long dtx, long long dty) {
    map<string, long long> co;
    long long tmp, tans = 0;
    string b;
    for (long long i = 1; i <= n; i++) {
        tmp = i * dtx - arr[i] * dty;
        b = to_string(tmp) + "/" + to_string(dtx);
        co[b]++;
        tans = max(tans, co[b]);
    }
    return n - tans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long ans;
    cin >> n;
    arr.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    ans = n;
    for (long long dty = -n; dty <= n; dty++) {
        for (long long dtx = -1e5; dtx <= 1e5; dtx++) {
            ans = min(ans, cal(dtx, dty));
        }
    }
    cout << ans << endl;

    return 0;
}

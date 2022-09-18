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
        vector<long long> a(n), dd(n, 0);
        vector<pair<long long, int>> tmp;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            tmp.push_back({a[i] - (n - i - 1), i});
        }
        sort(tmp.begin(), tmp.end());
        reverse(tmp.begin(), tmp.end());
        for (int i = 0; i < k; i++)
            dd[tmp[i].second] = 1;
        long long cost = 0, jc = 0;
        for (int i = 0; i < n; i++) {
            if (dd[i] == 1) {
                jc++;
                continue;
            }
            cost += (a[i] + jc);
        }
        cout << cost << endl;
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<long long> a(n);
        set<long long> dd;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        bool iok = false;
        for (int i = 0; i < n; i++) {
            if (dd.find(a[i] - k) != dd.end()) {
                iok = true;
                break;
            }
            dd.insert(a[i]);
        }
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}

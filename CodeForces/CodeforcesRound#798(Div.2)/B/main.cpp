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
        vector<int> a(n), dd(n + 1, 1), ans;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        if (n == 1) {
            cout << "-1" << endl;
            continue;
        }
        for (int i = 0; i < n; i++) {
            int minVal = a[i];
            for (int j = 1; j <= n; j++) {
                if (j == a[i])
                    continue;
                if (dd[j] == 1) {
                    minVal = j;
                    dd[j] = 0;
                    break;
                }
            }
            ans.push_back(minVal);
        }
        if (ans.back() == a[n - 1])
            swap(ans[n - 2], ans[n - 1]);
        for (int i = 0; i < n; i++)
            cout << ans[i] << ' ';
        cout << endl;
    }

    return 0;
}

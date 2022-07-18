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
        vector<int> a(n);
        long long cost = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cost += a[i];
        }
        cost -= a[n - 1];
        int j = n - 1;
        for (int i = 0; i < n; i++) {
            if (a[i] > 0) {
                j = i;
                break;
            }
        }
        for (int i = j + 1; i < n - 1; i++) {
            if (a[i] == 0) {
                while (a[j] == 0)
                    j++;
                a[j]--;
                a[i]++;
                cost++;
            }
        }
        cout << cost << endl;

    }

    return 0;
}

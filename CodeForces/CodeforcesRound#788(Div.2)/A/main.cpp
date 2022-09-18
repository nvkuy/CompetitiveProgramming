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
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int i = 0, j = n - 1;
        while (i < j) {
            if (a[i] < 0) {
                i++;
                continue;
            }
            if (a[j] > 0) {
                j--;
                continue;
            }
            a[i] = -a[i];
            a[j] = -a[j];
            i++, j--;
        }
        bool iok = true;
        for (int i = 1; i < n; i++) {
            if (a[i] < a[i - 1]) {
                iok = false;
                break;
            }
        }
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}

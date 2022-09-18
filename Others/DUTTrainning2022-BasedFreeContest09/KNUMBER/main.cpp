#include <bits/stdc++.h>

using namespace std;

int main()
{

    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int k = 1; k <= n; k++) {
            vector<int> dd(n + 1, 0);
            for (int i = 0; i < k; i++) {
                dd[a[i]]++;
            }
            int ans = 1e9;
            for (int i = k; i < n; i++) {

            }
        }
    }

    return 0;
}

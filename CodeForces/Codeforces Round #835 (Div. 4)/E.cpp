#include <bits/stdc++.h>
using namespace std;

int main() {

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 0)
                cnt0++;
            else
                cnt1++;
        }
        long long ans = 0, tcnt0 = cnt0, tcnt1 = cnt1;
        for (int i = 0; i < n; i++) {
            if (a[i] == 0)
                tcnt0--;
            else {
                ans += tcnt0;
                tcnt1--;
            }
        }
        // cout << "TEST " << ans << endl;
        tcnt0 = cnt0, tcnt1 = cnt1;
        long long max_dt = 0;
        for (int i = 0; i < n; i++) {
            long long dt = 0;
            if (a[i] == 0) {
                tcnt0--;
                dt -= (cnt1 - tcnt1);
                dt += tcnt0;
            } else {
                dt += (cnt1 - tcnt1);
                dt -= tcnt0;
                tcnt1--;
            }
            max_dt = max(max_dt, dt);
            // cout << i << '|' << dt << ' ';
        }
        // cout << endl;
        cout << ans + max_dt << endl;
    }

    return 0;
}
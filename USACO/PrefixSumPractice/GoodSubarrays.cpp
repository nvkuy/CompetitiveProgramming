#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        map<int, int> cnt;
        cnt[0]++;
        long long ans = 0;
        int cur = 0;
        for (int i = 1; i <= n; i++) {
            cur += (s[i - 1] - '0');
            ans += cnt[cur - i];
            cnt[cur - i]++;
        }
        cout << ans << endl;
    }

    return 0;
}
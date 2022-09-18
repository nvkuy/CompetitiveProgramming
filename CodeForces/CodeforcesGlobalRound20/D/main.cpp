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
        vector<int> a(n), b(n), cnt(n + 1, 0);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        bool iok = true;
        int j = 0, i = 0;
        while (i < n && j < n) {
            if (b[i] == a[j]) {
                i++, j++;
                continue;
            }
            if (i > 0 && b[i] == b[i - 1] && cnt[b[i]] > 0) {
                cnt[b[i]]--;
                i++;
                continue;
            }
            cnt[a[j]]++;
            j++;
        }
        while (i < n) {
            if (i > 0 && b[i] == b[i - 1] && cnt[b[i]] > 0) {
                cnt[b[i]]--;
                i++;
            } else {
                iok = false;
                break;
            }
        }
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, ai;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> cnt(10, 0);
        for (int i = 0; i < n; i++) {
            cin >> ai;
            cnt[ai % 10]++;
        }
        bool ans = false;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 10; k++) {
                    if (((i + j + k) % 10) != 3)
                        continue;
                    bool iok = true;
                    if (cnt[i] <= 0)
                        iok = false;
                    cnt[i]--;
                    if (cnt[j] <= 0)
                        iok = false;
                    cnt[j]--;
                    if (cnt[k] <= 0)
                        iok = false;
                    cnt[k]--;
                    cnt[i]++, cnt[j]++, cnt[k]++;
                    if (iok)
                        ans = true;
                }
            }
        }
        cout << (ans ? "YES" : "NO") << endl;
    }

    return 0;
}

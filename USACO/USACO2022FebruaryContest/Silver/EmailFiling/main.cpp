#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t, n, m, k;
    cin >> t;
    while (t--) {
        cin >> m >> n >> k;
        vector<int> f(n), behind, used(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> f[i];
            f[i]--;
        }
        int l = 0, r = min(l + k - 1, m - 1);
        int topOfWindow = 0, botOfWindow = 0, curItemWindow = 0;
        map<int, int> cnt;
        while (true) {
            if (botOfWindow == f.size()) {
                if (behind.size() > 0) {
                    while (behind.size() > 0) {
                        f.push_back(behind.back());
                        behind.pop_back();
                    }
                    continue;
                }
                while (r + 1 < m) {
                    l++, r++;
                    if (cnt[r] != 0) {
                        curItemWindow -= cnt[r];
                        cnt.erase(cnt.find(r));
                    }
                }
                break;
            }
            if (curItemWindow == k) {
                while (used[topOfWindow] == 1)
                    topOfWindow++;
                cnt[f[topOfWindow]]--;
                curItemWindow--;
                behind.push_back(topOfWindow);
                if (r + 1 < m)
                    l++, r++;
                if (cnt[r] != 0) {
                    curItemWindow -= cnt[r];
                    cnt.erase(cnt.find(r));
                }
                continue;
            }
            while (botOfWindow < f.size() && f[botOfWindow] >= l && f[botOfWindow] <= r) {
                used[botOfWindow] = 1;
                botOfWindow++;
            }
            if (botOfWindow == f.size())
                continue;
            curItemWindow++;
            cnt[f[botOfWindow]]++;
            botOfWindow++;
        }
        cout << (curItemWindow == 0 ? "YES" : "NO") << endl;
    }

    return 0;
}

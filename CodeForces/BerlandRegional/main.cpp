#include <bits/stdc++.h>

using namespace std;

int u[200002], um[200002], dd[200002];
vector<vector<long long>> br;

int main()
{
    int t, n, mask, m, si;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> u[i];
            um[i] = u[i];
        }
        sort(um, um + n);
        memset(dd, 0, (n + 1) * sizeof *dd);
        dd[um[0]] = 1;
        for (int i = 1; i < n; i++) {
            if (um[i] != um[i - 1])
                dd[um[i]] = dd[um[i - 1]] + 1;
        }
        m = dd[um[n - 1]];
        br.clear();
        br.resize(m + 1);
        for (int i = 0; i < n; i++) {
            cin >> si;
            br[dd[u[i]]].push_back(si);
        }
        for (int i = 1; i <= m; i++) {
            sort(br[i].begin(), br[i].end());
            for (int j = 1; j < br[i].size(); j++)
                br[i][j] += br[i][j - 1];
        }

        bool ic = true;
        for (int i = 1; i <= n; i++) {
            if (!ic) {
                cout << "0 ";
                continue;
            }
            long long ans = 0LL;
            for (int j = m; j >= 1; j--) {
                if (br[j].size() < i) {
                    br.erase(br.begin() + j);
                    m--;
                    continue;
                }
                ans += br[j][br[j].size() - 1];
                if (br[j].size() % i > 0)
                    ans -= br[j][(br[j].size() % i) - 1];
            }
            cout << ans << ' ';
            if (ans == 0)
                ic = false;
        }
        cout << endl;
    }

    return 0;
}

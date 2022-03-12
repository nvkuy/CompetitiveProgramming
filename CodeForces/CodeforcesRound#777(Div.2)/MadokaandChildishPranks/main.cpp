#include <bits/stdc++.h>

using namespace std;

struct box {
    int ubx, uby, dbx, dby;
    box(int ubi, int ubj, int dbi, int dbj) {
        ubx = ubi;
        uby = ubj;
        dbx = dbi;
        dby = dbj;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, m;
    string s;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        cin.ignore();
        vector<vector<bool>> c(n);
        vector<box> ans;
        for (int i = 0; i < n; i++) {
            getline(cin, s);
            for (int j = 0; j < m; j++)
                c[i].push_back(s[j] == '1');
        }
        if (c[0][0]) {
            cout << "-1\n";
            continue;
        }
        for (int i = 0; i < n; i++) {
            int j = 0;
            while (j < m) {
                if (!c[i][j])
                    j++;
                else {
                    int k = j;
                    while (c[i][k]) {
                        k++;
                        if (k >= m)
                            break;
                    }
                    for (int l = k - 1; l >= max(j, 1); l--)
                        ans.push_back(box(i + 1, l, i + 1, l + 1));
                    j = k;
                }
            }
        }
        int i = 0;
        while (i < n) {
            if (!c[i][0])
                i++;
            else {
                int j = i;
                while (c[j][0]) {
                    j++;
                    if (j >= n)
                        break;
                }
                for (int k = j - 1; k >= i; k--)
                    ans.push_back(box(k, 1, k + 1, 1));
                i = j;
            }
        }
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i].ubx << ' ' << ans[i].uby << ' ' << ans[i].dbx << ' ' << ans[i].dby << endl;
    }

    return 0;
}

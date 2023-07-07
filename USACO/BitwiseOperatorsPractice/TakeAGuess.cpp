#include <bits/stdc++.h>
using namespace std;

int query(const string &qc, int i, int j) {
    cout << qc << ' ' << i << ' ' << j << endl;
    cout.flush();
    int rp;
    cin >> rp;
    return rp;
}

int main() {

    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1, 0);
    map<pair<int, int>, int> or_qr, and_qr;
    for (int i = 1; i <= 3; i++) {
        for (int j = i + 1; j <= 3; j++) {
            int to = query("or", i, j);
            or_qr.insert({{i, j}, to});
            or_qr.insert({{j, i}, to});
            int ta = query("and", i, j);
            and_qr.insert({{i, j}, ta});
            and_qr.insert({{j, i}, ta});
        }
    }

    for (int i = 4; i <= n; i++) {
        int j = 1;
        int to = query("or", i, j);
        or_qr.insert({{i, j}, to});
        or_qr.insert({{j, i}, to});
        int ta = query("and", i, j);
        and_qr.insert({{i, j}, ta});
        and_qr.insert({{j, i}, ta});
    }

    vector<vector<int>> ans(3, vector<int>(33, -1));
    for (int i = 0; i <= 30; i++) {
        while (true) {
            if (min(ans[0][i], min(ans[1][i], ans[2][i])) != -1) break;
            for (int j = 1; j <= 3; j++) {
                for (int k = 1; k <= 3; k++) {
                    if (k == j) continue;
                    if ((and_qr[{k, j}] & (1 << i)) != 0)
                        ans[j - 1][i] = ans[k - 1][i] = 1;
                    if ((or_qr[{k, j}] & (1 << i)) == 0)
                        ans[j - 1][i] = ans[k - 1][i] = 0;
                    if (ans[j - 1][i] == 1 && (and_qr[{k, j}] & (1 << i)) == 0)
                        ans[k - 1][i] = 0;
                    if (ans[j - 1][i] == 0 && (or_qr[{k, j}] & (1 << i)) != 0)
                        ans[k - 1][i] = 1;
                }
            }
        }
    }

    for (int i = 1; i <= 3; i++) {
        for (int j = 0; j <= 30; j++) {
            a[i] |= (ans[i - 1][j] << j);
            // cout << ans[i - 1][j];
        }
        // cout << endl;
        // cout.flush();
    }

    // cout << "@test: " << a[1] << ' ' << a[2] << ' ' << a[3] << ' ';
    for (int i = 4; i <= n; i++) {
        a[i] = (a[1] ^ and_qr[{1, i}] ^ or_qr[{1, i}]);
        // cout << a[i] << ' ';
    }
    // cout << endl;
    // cout.flush();

    sort(a.begin(), a.end());
    cout << "finish " << a[k] << endl;
    cout.flush();

    return 0;
}
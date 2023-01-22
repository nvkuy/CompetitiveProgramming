#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, x, y, tmp = 1;
    map<int, int> compressFunc;
    cin >> n;
    vector<pair<int, int>> cor;
    vector<int> all;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        cor.push_back({x, y});
        all.push_back(x);
        all.push_back(y);
    }
    sort(all.begin(), all.end());
    for (int num : all) {
        if (compressFunc[num] == 0)
            compressFunc[num] = tmp++;
    }
    vector<vector<int>> ps(tmp + 1, vector<int>(tmp + 1, 0));
    for (auto &p : cor) {
        p = {compressFunc[p.first], compressFunc[p.second]};
        ps[p.first][p.second]++;
    }
    for (int i = 1; i <= tmp; i++) {
        for (int j = 1; j <= tmp; j++) {
            ps[i][j] += (ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1]);
        }
    }
    long long ans = n + 1;
    sort(cor.begin(), cor.end());
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int high = max(cor[i].second, cor[j].second);
            int low = min(cor[i].second, cor[j].second);
            long long num1 = ps[cor[j].first][tmp] - ps[cor[i].first - 1][tmp] - ps[cor[j].first][high] + ps[cor[i].first - 1][high];
            long long num2 = ps[cor[j].first][low - 1] - ps[cor[i].first - 1][low - 1] - ps[cor[j].first][0] + ps[cor[i].first - 1][0];
            // cout << i << ' ' << j << ": ";
            // cout << "Up " << num1 << ", Down " << num2 << endl;
            ans += ((num1 + 1LL) * (num2 + 1LL));
        }
    }
    cout << ans << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {

    if (fopen("div7.in", "r")) {
        freopen("div7.in", "r", stdin);
        freopen("div7.out", "w", stdout);
    }

    int n;
    vector<int> pos(7, 1e9);
    cin >> n;
    int cur_s = 0, ans = 0;
    pos[0] = 0;
    for (int i = 1; i <= n; i++) {
        int ai;
        cin >> ai;
        (cur_s += ai) %= 7;
        if (pos[cur_s] == 1e9)
            pos[cur_s] = i;
        else
            ans = max(ans, i - pos[cur_s]);
    }
    cout << ans << endl;

    return 0;
}
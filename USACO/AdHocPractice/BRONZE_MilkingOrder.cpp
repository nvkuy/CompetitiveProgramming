#include <bits/stdc++.h>
using namespace std;

int main() {

    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> pos(n + 1, -1), od(m + 2), oc(n + 1, 0);
    bool hasOne = false;
    for (int i = 1; i <= m; i++) {
        cin >> od[i];
        if (od[i] == 1)
            hasOne = true;
    }
    while (k--) {
        int tmp;
        cin >> tmp;
        cin >> pos[tmp];
        oc[pos[tmp]] = 1;
    }
    if (pos[1] != -1) {
        cout << pos[1] << endl;
        return 0;
    }
    if (!hasOne) {
        int cur_pos = n;
        for (int i = m; i > 0; i--) {
            if (pos[od[i]] != -1) {
                cur_pos = pos[od[i]] - 1;
                continue;
            }
            while (oc[cur_pos])
                cur_pos--;
            oc[cur_pos] = 1;
            cur_pos--;
        }
        for (int i = 1; i <= n; i++) {
            if (!oc[i]) { 
                cout << i << endl;
                break;
            }
        }
        return 0;
    }
    int cur_pos = 1;
    for (int i = 1; i <= m; i++) {
        if (pos[od[i]] != -1) {
            cur_pos = pos[od[i]] + 1;
            continue;
        }
        while (oc[cur_pos])
            cur_pos++;
        oc[cur_pos] = 1;
        pos[od[i]] = cur_pos;
        cur_pos++;
    }
    cout << pos[1] << endl;

    return 0;
}
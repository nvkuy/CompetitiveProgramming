#include <bits/stdc++.h>
using namespace std;

struct ac {
    int a, b, p, m;
};

int main() {

    int n, m;
    cin >> n >> m;
    vector<int> stall_temp(101, 0);
    while (n--) {
        int s, t, c;
        cin >> s >> t >> c;
        for (int i = s; i <= t; i++)
            stall_temp[i] += c;
    }
    vector<ac> acs(m);
    for (int i = 0; i < m; i++)
        cin >> acs[i].a >> acs[i].b >> acs[i].p >> acs[i].m;
    int ans = 2e9;
    for (int mask = 0; mask < (1 << m); mask++) {
        vector<int> real_temp(101, 0);
        int money = 0;
        for (int i = 0; i < m; i++) {
            if (((1 << i) & mask) != 0) {
                money += acs[i].m;
                for (int j = acs[i].a; j <= acs[i].b; j++)
                    real_temp[j] += acs[i].p;
            }
        }
        bool iok = true;
        for (int i = 0; i <= 100; i++)
            iok &= (real_temp[i] >= stall_temp[i]);
        if (iok)
            ans = min(ans, money);
    }
    cout << ans << endl;

    return 0;
}
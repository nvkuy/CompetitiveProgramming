#include <bits/stdc++.h>
using namespace std;

vector<int> f;

int cal(int n, int k, int num) {
    if (num == 0) return 0;
    if (f[num] != -1)
        return f[num];
    int ans = 1 - cal(n, k, num - 1);
    if (num >= k)
        ans = max(ans, 1 - cal(n, k, num - k));
    f[num] = ans;
    return ans;
}

int main()
{

    // cout << "TEST" << endl;
    // f.assign(1e4, -1);
    // cout << cal(6, 2, 12) << endl;
    freopen("dotak.in", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        f.assign(n * k + 1, -1);
        cout << ((cal(n, k, n * k) == 1) ? "Omda" : "Teemo") << endl;
        // cout << cal(n, k, n * k) << endl;
    }
    // set<string> dd;
    // for (int n = 1; n <= 80; n++) {
    //     for (int k = 1; k <= 80; k++) {
    //         f.assign(n * k + 1, -1);
    //         dd.insert((to_string(n % 2) + "|" + to_string(k % 2) + "|" + to_string((n * k) % 2) + "|" + to_string((n * k) % (k + 1)) + "|" + to_string(cal(n, k, n * k))));
    //     }
    // }
    // for (string s : dd)
    //     cout << s << endl;

    return 0;
}

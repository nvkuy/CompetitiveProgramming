#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t, n, m, a, b, c;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<int> dd(n + 1, false);
        while (m--) {
            cin >> a >> b >> c;
            dd[b] = true;
        }
        int root = -1;
        for (int i = 1; i <= n; i++) {
            if (!dd[i]) {
                root = i;
                break;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (i == root)
                continue;
            cout << root << ' ' << i << endl;
        }
    }

    return 0;
}

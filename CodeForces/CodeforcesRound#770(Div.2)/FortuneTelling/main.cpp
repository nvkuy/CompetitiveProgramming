#include <bits/stdc++.h>

using namespace std;

bool a[100001], ans;

void dfs(bool u, int i) {
    if (i < 0) {
        ans = u;
        return;
    }
    if (!a[i])
        dfs(u, i - 1);
    else
        dfs(!u, i - 1);
}

int main()
{

    long long t, x, y, n, ai;
    cin >> t;
    while (t--) {
        cin >> n >> x >> y;
        for (int i = 0; i < n; i++) {
            cin >> ai;
            a[i] = (ai % 2);
        }
        dfs(y % 2, n - 1);
        if (ans == (x % 2))
            cout << "Alice\n";
        else
            cout << "Bob\n";
    }

    return 0;
}

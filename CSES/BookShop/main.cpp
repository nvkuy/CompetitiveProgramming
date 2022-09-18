#include <bits/stdc++.h>

using namespace std;

int h[1001], s[1001], f[100001];

int main()
{

    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    memset(f, 0, (x + 1) * sizeof *f);
    for (int i = 1; i <= n; i++) {
        for (int j = x; j >= h[i]; j--) {
            f[j] = max(f[j], f[j - h[i]] + s[i]);
        }
    }
    cout << f[x];

    return 0;
}

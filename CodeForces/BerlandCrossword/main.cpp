#include <bits/stdc++.h>

using namespace std;

bool try_corn(int corn, int u, int r, int d, int l, int n) {
    bitset<4> bs(corn);
    u -= bs[0]; r -= bs[0];
    r -= bs[1]; d -= bs[1];
    l -= bs[2]; d -= bs[2];
    l -= bs[3]; u -= bs[3];
    if (u < 0 || r < 0 || d < 0 || l < 0)
        return false;
    if (u > n - 2 || r > n - 2 || d > n - 2 || l > n - 2)
        return false;
    return true;
}

int main()
{
    int t, n, u, r, d, l;
    cin >> t;
    while (t--) {
        cin >> n >> u >> r >> d >> l;
        bool iok = false;
        for (int i = 0; i < (1 << 4); i++)
            iok |= try_corn(i, u, r, d, l, n);
        cout << (iok ? "YES" : "NO") << '\n';
    }

    return 0;
}

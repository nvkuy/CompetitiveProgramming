#include <bits/stdc++.h>

using namespace std;

string s;
int ans;

void try_seg(int l, int r, char c, int tans) {
    if (r - l == 1) {
        if (s[l] != c)
            tans++;
        ans = min(ans, tans);
        return;
    }
    int co = 0;
    for (int i = l; i < (l + r) / 2; i++)
        if (s[i] != c)
            co++;
    try_seg((l + r) / 2, r, c + 1, tans + co);
    co = 0;
    for (int i = (l + r) / 2; i < r; i++)
        if (s[i] != c)
            co++;
    try_seg(l, (l + r) / 2, c + 1, tans + co);
}

int main()
{
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cin.ignore();
        getline(cin, s);
        ans = 1e9 + 7;
        try_seg(0, n, 'a', 0);
        cout << ans << endl;
    }

    return 0;
}

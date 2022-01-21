#include <bits/stdc++.h>

using namespace std;

int cal(bitset<100001> a, bitset<100001> b, int y, int x, int n) {
    int ans = 0;
    if (x == y) {
        for (int i = 0; i < n; i++)
            ans += (a[i] != b[i]);
    }
    if (x != y) {
        for (int i = 0; i < n; i++)
            ans += (a[i] == b[i]);
    }
    return ans;
}

int main()
{
    int t, n;
    string s;
    cin >> t;
    while (t--) {
        cin >> n;
        cin.ignore();
        getline(cin, s);
        bitset<100001> a(s), c(s);
        int i;
        for (i = 0; i < n; i++)
            if (c[i])
                break;
        c[i] = ~c[i];
        for (i = 0; i < n; i++)
            c[i] = ~c[i];
        getline(cin, s);
        bitset<100001> b(s);
        int x = b.count(), y = a.count(), z = c.count();
        if (x != y && x != z) {
            cout << "-1\n";
            continue;
        }
        int co1 = cal(a, b, y, x, n);
        int co2 = cal(c, b, z, x, n);
        cout << min(co1, co2) << endl;
    }

    return 0;
}

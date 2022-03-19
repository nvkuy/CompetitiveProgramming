#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

int cal(bitset<100001> a, bitset<100001> b, int n) {
    if (a.count() != b.count())
        return 1e9 + 7;
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += (a[i] != b[i]);
    return ans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n;
    string s;
    cin >> t;
    while (t--) {
        cin >> n;
        cin.ignore();
        getline(cin, s);
        bitset<100001> a(s), c(s);
        getline(cin, s);
        bitset<100001> b(s);
        int p = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i] && a[i] == true) {
                p = i;
                break;
            }
            if (a[i] == true)
                p = i;
        }
        if (p < 0) {
            if (a != b)
                cout << "-1\n";
            else
                cout << "0\n";
            continue;
        }
        c[p] = !c[p];
        for (int i = 0; i < n; i++)
            c[i] = !c[i];
        int ans = min(cal(a, b, n), cal(c, b, n) + 1);
        if (ans == 1e9 + 7)
            ans = -1;
        cout << ans << endl;
    }

    return 0;
}

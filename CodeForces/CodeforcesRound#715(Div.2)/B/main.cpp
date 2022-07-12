#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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
        bool iok = true;
        int tc = 0, mc = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'T')
                tc++;
            else
                mc++;
        }
        if (tc != mc * 2)
            iok = false;
        tc = 0, mc = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'T')
                tc++;
            else
                mc++;
            if (mc > tc)
                iok = false;
        }
        tc = 0, mc = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == 'T')
                tc++;
            else
                mc++;
            if (mc > tc)
                iok = false;
        }
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}

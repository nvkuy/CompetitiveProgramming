#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    string s;
    cin >> t;
    cin.ignore();
    while (t--) {
        getline(cin, s);
        int n = s.length(), cs = 0;
        bool iok = s[n - 1] == 'B';
        for (int i = 0; i < n; i++) {
            if (s[i] == 'A')
                cs++;
            else
                cs--;
            if (cs < 0)
                iok = false;
        }
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}

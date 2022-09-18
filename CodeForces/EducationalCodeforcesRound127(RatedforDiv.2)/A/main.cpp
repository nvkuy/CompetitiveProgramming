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
        char c = s[0];
        int co = 0;
        bool iok = true;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == c)
                co++;
            else {
                if (co == 1)
                    iok = false;
                co = 1;
                c = s[i];
            }
        }
        if (co == 1)
            iok = false;
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}

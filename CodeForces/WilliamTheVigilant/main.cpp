#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q, p, co;
    string s;
    char c;
    cin >> n >> q;
    cin.ignore();
    getline(cin, s);
    co = 0;
    for (int i = 0; i < n - 2; i++) {
        if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c')
            co++;
    }
    while (q--) {
        cin >> p >> c;
        if (s[p - 1] == 'a') {
            if (p + 1 < n && s[p] == 'b' && s[p + 1] == 'c')
                co--;
        } else if (s[p - 1] == 'b') {
            if (p - 2 >= 0 && p < n && s[p - 2] == 'a' && s[p] == 'c')
                co--;
        } else {
            if (p - 3 >= 0 && s[p - 3] == 'a' && s[p - 2] == 'b')
                co--;
        }
        if (c == 'a') {
            if (p + 1 < n && s[p] == 'b' && s[p + 1] == 'c')
                co++;
        } else if (c == 'b') {
            if (p - 2 >= 0 && p < n && s[p - 2] == 'a' && s[p] == 'c')
                co++;
        } else {
            if (p - 3 >= 0 && s[p - 3] == 'a' && s[p - 2] == 'b')
                co++;
        }
        s[p - 1] = c;
        cout << co << endl;
    }

    return 0;
}

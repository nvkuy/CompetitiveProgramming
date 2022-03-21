#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

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
        map<char, int> co;
        int j = 0;
        for (int i = 0; i < s.length(); i++) {
            co[s[i]]++;
            while (co[s[j]] > 1) {
                co[s[j]]--;
                j++;
            }
            //cout << i << '|' << j << endl;
        }
        for (int i = j; i < s.length(); i++)
            cout << s[i];
        cout << endl;
    }

    return 0;
}

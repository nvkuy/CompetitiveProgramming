#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

bool canHoldBack(char c1, char c2) {
    if (c1 == 'a' && c2 == 'c')
        return false;
    if (c1 == 'b' && c2 == 'a')
        return false;
    return true;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int q, n;
    string s, t;
    cin >> q;
    while (q--) {
        cin >> n;
        cin.ignore();
        getline(cin, s);
        getline(cin, t);
        int i = 0, j = 0, curCount = 0;
        char curChar = 'd';
        bool iok = true;
        while (i < s.length() && j < t.length()) {
            if (!iok)
                break;
            if (curChar == s[i]) {
                curCount++;
                i++;
                continue;
            }
            if (!canHoldBack(curChar, s[i])) {
                while (curCount > 0) {
                    if (j >= t.length() || !iok)
                        break;
                    if (t[j] != curChar)
                        iok = false;
                    j++;
                    curCount--;
                }
                if (curCount == 0)
                    curChar = 'd';
                continue;
            }
            if (s[i] == t[j]) {
                i++, j++;
                continue;
            }
            if (curChar == t[j]) {
                curCount--;
                j++;
                if (curCount == 0)
                    curChar = 'd';
                continue;
            }
            if (curChar != 'd' || s[i] == 'c') {
                iok = false;
                continue;
            }
            curChar = s[i], curCount = 1;
            i++;
        }
        if (iok && curCount > 0 && j < t.length()) {
            while (curCount > 0) {
                if (j >= t.length() || !iok)
                    break;
                if (t[j] != curChar)
                    iok = false;
                j++;
                curCount--;
            }
        }
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}

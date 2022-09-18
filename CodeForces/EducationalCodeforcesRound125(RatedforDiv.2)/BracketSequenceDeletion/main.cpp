#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

int n, op, cl;
bool crb;
string s;

bool checkRB() {
    return op == cl;
}

bool checkPL(int l, int r) {
    while (l < r) {
        if (s[l] != s[r])
            return false;
        l++, r--;
    }
    return true;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, ans, st;
    cin >> t;
    while (t--) {
        cin >> n;
        cin.ignore();
        getline(cin, s);
        op = 0, cl = 0, st = 0, ans = 0;
        crb = true;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(')
                op++;
            else
                cl++;
            if (op - cl < 0)
                crb = false;
            if (crb) {
                if (checkRB()) {
                    n -= (i - st + 1);
                    st = i + 1;
                    op = cl = 0;
                    ans++;
                }
            }
            if (i - st > 0) {
                if (checkPL(st, i)) {
                    n -= (i - st + 1);
                    st = i + 1;
                    op = cl = 0;
                    ans++;
                    crb = true;
                }
            }
        }
        cout << ans << ' ' << n << endl;
    }

    return 0;
}

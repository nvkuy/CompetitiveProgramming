#include <bits/stdc++.h>

using namespace std;

bool check(string x, string ans) {
    for (int i = 0; i < x.length(); i++) {
        if ((int)ans[i] > (int)x[i])
            return true;
        if ((int)ans[i] < (int)x[i])
            return false;
    }
    return true;
}

string gene(int s, int d, int l) {
    if (s + d * (l - 1) > 9 || s + d * (l - 1) < 0)
        return "xxx";
    string ans = to_string(s);
    for (int i = 1; i < l; i++) {
        s += d;
        ans += to_string(s);
    }
    return ans;
}

int main()
{
    bool iok = false;
    string x, ans;
    getline(cin, x);
    if (x.length() <= 1) {
        cout << x;
        return 0;
    }
    for (int s = x[0] - '0'; s < 10; s++) {
        for (int d = -9; d < 10; d++) {
            ans.clear();
            ans = gene(s, d, x.length());
            if (ans[0] == 'x')
                continue;
            if (check(x, ans)) {
                iok = true;
                break;
            }
        }
        if (iok)
            break;
    }
    if (ans[0] == 'x') {
        ans.clear();
        ans = "1";
        ans += gene(0, 0, x.length());
    }
    cout << ans;

    return 0;
}

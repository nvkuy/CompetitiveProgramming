#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s, ans;
    getline(cin, s);
    vector<int> ss(s.length() + 1);
    ss[0] = 0;
    for (int i = 0; i < s.length() - 1; i++)
        ss[i + 1] += (ss[i] + (s[i] - '0'));
    int cs = 0;
    for (int i = s.length() - 1; i >= 0; i--) {
        cs += (s[i] - '0' + ss[i]);
        ans.push_back('0' + (cs % 10));
        cs /= 10;
    }
    if (cs > 0)
        ans += to_string(cs);
    for (int i = ans.length() - 1; i >= 0; i++) {
        if (ans[i] == '0')
            ans.pop_back();
        else
            break;
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
    return 0;
}

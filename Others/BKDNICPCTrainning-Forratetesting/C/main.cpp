#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s, ans;
    cin >> s;
    ans.push_back(s[0]);
    int pos = 1;
    while (pos < s.length() && s[pos] == '/')
        pos++;
    while (true) {
        if (pos >= s.length())
            break;
        if (s[pos] != '/') {
            ans.push_back(s[pos]);
            pos++;
            continue;
        }
        ans.push_back('/');
        while (pos < s.length() && s[pos] == '/')
            pos++;
    }
    if (ans.back() == '/' && ans.size() > 1)
        ans.pop_back();
    cout << ans;

    return 0;
}

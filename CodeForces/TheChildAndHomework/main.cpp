#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    vector<pair<int, char>> c;
    getline(cin, s);
    c.push_back(make_pair(s.length() - 2, 'A'));
    getline(cin, s);
    c.push_back(make_pair(s.length() - 2, 'B'));
    getline(cin, s);
    c.push_back(make_pair(s.length() - 2, 'C'));
    getline(cin, s);
    c.push_back(make_pair(s.length() - 2, 'D'));
    sort(c.begin(), c.end());
    vector<char> ans;
    if (c[0].first * 2 <= c[1].first)
        ans.push_back(c[0].second);
    if (c[3].first >= c[2].first * 2)
        ans.push_back(c[3].second);
    if (ans.size() == 1)
        cout << ans[0];
    else
        cout << 'C';

    return 0;
}

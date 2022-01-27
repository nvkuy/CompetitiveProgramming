#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, j;
    map<string, int> ms;
    map<string, int>::iterator it;
    cin >> n >> m;
    vector<bool> ans(n, false);
    string s;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        cin >> s;
        ms.insert(make_pair(s, i));
    }
    for (int i = 0; i < m; i++) {
        cin >> s;
        it = ms.find(s);
        if (it != ms.end())
            ans[it->second] = true;
    }
    for (int i = 0; i < n; i++)
        cout << (ans[i] ? "Yes" : "No") << '\n';

    return 0;
}

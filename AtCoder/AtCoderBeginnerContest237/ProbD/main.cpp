#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string s;
    deque<int> ans;
    cin >> n;
    cin.ignore();
    getline(cin, s);
    ans.push_back(n);
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'R')
            ans.push_front(i);
        else
            ans.push_back(i);
    }
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';

    return 0;
}

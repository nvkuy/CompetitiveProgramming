#include <bits/stdc++.h>

using namespace std;

int cal(string s, char c, int n) {
    vector<int> a(n + 1);
    a[0] = -1;
    int ans = -1;
    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1];
        if (s[i - 1] == c)
            a[i]++;
        else
            a[i]--;
        ans = max(ans, i + a[i]);
    }
    return ans;
}

int main()
{
    int n, ans = 0;
    string s;
    cin >> n;
    cin.ignore();
    getline(cin, s);
    ans = max(ans, cal(s, 'a', n));
    ans = max(ans, cal(s, 'b', n));
    ans = max(ans, cal(s, 'c', n));
    cout << ans;

    return 0;
}

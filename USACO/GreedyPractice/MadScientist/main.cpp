#include <bits/stdc++.h>

using namespace std;

int main()
{

    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);

    int n, ans = 0;
    cin >> n;
    string s1, s2;
    cin >> s1;
    cin >> s2;
    vector<int> needOp(n + 2, 0);
    for (int i = 1; i <= n; i++) needOp[i] = (s1[i - 1] != s2[i - 1]);
    for (int i = 1; i <= n; i++) {
        if (!needOp[i - 1] && needOp[i])
            ans++;
    }
    cout << ans << endl;

    return 0;
}

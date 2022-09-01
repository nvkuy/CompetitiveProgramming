#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> mask;
    for (int i = 0; i < n; i += 2) {
        if (s[i] == s[i + 1])
            continue;
        mask.push_back(s[i] == 'G');
    }
    int ans = mask.back();
    for (int i = 1; i < mask.size(); i++)
        ans += (mask[i] != mask[i - 1]);
    cout << ans;

    return 0;
}

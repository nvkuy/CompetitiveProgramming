#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, x, y;
    cin >> t;
    while (t--) {
        vector<pair<int, int>> cor;
        for (int i = 0; i < 3; i++) {
            cin >> x >> y;
            cor.push_back(make_pair(y, x));
        }
        sort(cor.begin(), cor.end());
        int ans = 0;
        if (cor[2].first == cor[1].first)
            ans = abs(cor[2].second - cor[1].second);
        cout << ans << endl;
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<pair<int, int>> p(3);
    for (int i = 0; i < 3; i++)
        cin >> p[i].first >> p[i].second;
    sort(p.begin(), p.end());
    vector<pair<pair<int, int>, pair<int, int>>> ans;
    if (p[0].first == p[2].first) {
        int tx = p[0].first, ty1 = max(p[0].second, max(p[1].second, p[2].second)), ty2 = min(p[0].second, min(p[1].second, p[2].second));
        ans.push_back({{tx, ty1}, {tx, ty2}});
    } else {
        if (p[0].first != p[1].first)
            ans.push_back({{p[0].first, p[0].second}, {p[1].first, p[0].second}});
        if (p[1].first == p[2].first) {
            int tx = p[1].first, ty1 = max(p[0].second, max(p[1].second, p[2].second)), ty2 = min(p[0].second, min(p[1].second, p[2].second));
            ans.push_back({{tx, ty1}, {tx, ty2}});
        } else {
            if (p[0].second != p[1].second)
                ans.push_back({{p[1].first, p[0].second}, {p[1].first, p[1].second}});
            pair<pair<int, int>, pair<int, int>> tmp = ans.back();
            int l = min(tmp.first.second, tmp.second.second), r = max(tmp.first.second, tmp.second.second);
            if (p[2].second >= l && p[2].second <= r)
                ans.push_back({{p[1].first, p[2].second}, {p[2].first, p[2].second}});
            else {
                if (p[2].second < l) {
                    ans.push_back({{p[1].first, l}, {p[2].first, l}});
                    ans.push_back({{p[2].first, l}, {p[2].first, p[2].second}});
                } else {
                    ans.push_back({{p[1].first, r}, {p[2].first, r}});
                    ans.push_back({{p[2].first, r}, {p[2].first, p[2].second}});
                }
            }
            /*
            ans.push_back({{p[1].first, p[1].second}, {p[2].first, p[1].second}});
            if (p[1].second != p[2].second)
                ans.push_back({{p[2].first, p[1].second}, {p[2].first, p[2].second}});
            */
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].first.first << ' ' << ans[i].first.second << ' ' << ans[i].second.first << ' ' << ans[i].second.second << endl;

    return 0;
}

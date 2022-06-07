#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    string s;
    cin >> n;
    cin.ignore();
    getline(cin, s);
    vector<int> good;
    int normal = 0, ans = 0, still_good = 0;
    for (int i = 2; i < s.length(); i++) {
        if (s[i - 2] != 'A' || s[i - 1] != 'R' || s[i] != 'C')
            continue;
        int l = i - 3, r = i + 1, good_cnt = 1;
        while (l >= 0 && r < n) {
            if (s[l] != 'A' || s[r] != 'C')
                break;
            good_cnt++;
            l--, r++;
        }
        if (good_cnt == 1)
            normal++;
        else
            good.push_back(good_cnt);
    }
    sort(good.begin(), good.end(), greater<int>());
    while (!good.empty()) {
        int good_cnt = good.back(); good.pop_back();
        while ((good_cnt > 1) && (normal > 0 || still_good > 0)) {
            ans += 2;
            good_cnt--;
            if (normal > 0)
                normal--;
            else
                still_good--;
        }
        if (good_cnt > 1)
            still_good++;
        else
            normal++;
    }
    ans += normal;
    ans += (2 * still_good);
    cout << ans;

    return 0;
}

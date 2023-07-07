#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

inline void debugLocal() {
    if (!fopen("input.txt", "r"))
        return;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    //debugLocal();

    int n, k;
    cin >> n >> k;
    string s1, s2;
    cin >> s1 >> s2;
    vector<long long> a(n + 1), f(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f[i] = f[i - 1] + a[i];
    }

    if (k == 0) {
        cout << 0 << endl; // two string must be equal, problem say always have ans
        return 0;
    }

    map<char, int> cnt1, cnt2;
    vector<pair<int, int>> seg;
    bool isPreEqual = true;
    for (int i = 0; i < n; i++) {
        // if (s1[i] != s2[i]) {
        //     if (i == 0 || s1[i - 1] == s2[i - 1])
        //         seg.push_back({i + 1, i + 1});
        //     seg.back().second = i + 1;
        // }
        cnt1[s1[i]]++;
        cnt2[s2[i]]++;
        bool isNowEqual = true;
        for (char j = 'a'; j <= 'z'; j++) {
            if (cnt1[j] != cnt2[j]) {
                isNowEqual = false;
                break;
            }
        }
        if (!isNowEqual) {
            //cout << i + 1 << ' ';
            if (isPreEqual)
                seg.push_back({i + 1, i + 1});
            seg.back().second = i + 1;
        }
        if (isNowEqual && !isPreEqual)
            seg.back().second = i + 1;
        isPreEqual = isNowEqual;
    }
    //cout << endl;
    sort(seg.begin(), seg.end());

    long long ans = 0;
    for (auto sg : seg) {
        ans += (f[sg.second] - f[sg.first - 1]);
        //cout << sg.first << ' ' << sg.second << endl;
    }
    vector<long long> opt_seg;
    for (int i = 1; i < seg.size(); i++) opt_seg.push_back(f[seg[i].first - 1] - f[seg[i - 1].second]);
    sort(opt_seg.begin(), opt_seg.end(), greater<long long>());
    while (true) {
        if (opt_seg.size() + 1 <= k) break;
        ans += opt_seg.back();
        opt_seg.pop_back();
    }

    cout << ans << endl;

    return 0;
}

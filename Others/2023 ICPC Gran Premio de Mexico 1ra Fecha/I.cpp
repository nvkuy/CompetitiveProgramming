#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
#define bit_cnt(x) __builtin_popcountll(x)

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<int> cnt;
int k, n;

bool iok() {
    for (int i = 0; i < 26; i++) if (cnt[i] > k) return false;
    return true;
}

int len(int l, int r) {
    return r - l + 1;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    string s;
    cin >> s;
    bool all_same = true;
    for (int i = 0; i + 1 < n; i++)
        if (s[i] != s[i + 1]) all_same = false;
    if (all_same) {
        cout << -1 << endl;
        return 0;
    }
    string tmp = "";
    while (s.back() == s[0]) {
        tmp.push_back(s.back());
        s.pop_back();
    }
    s = tmp + s;
    s = s + s + s;
    // cout << "@s: " << s << endl;

    int ans = 0, ans_i = -1, ans_j = -1;
    cnt.assign(26, 0);
    int j = -1;
    for (int i = 0; i < n; i++) {
        while (j < i) {
            j++;
            cnt[s[j] - 'a']++;
        }
        if (iok() && (i == 0 || s[i] != s[i - 1])) {
            while (len(i, j) <= n && iok()) {
                j++;
                cnt[s[j] - 'a']++;
                // cout << i << ' ' << j << ' ' << cnt['b' - 'a'] << endl;
            }
            // cout << i << ' ' << j << ' ' << s.substr(i, j - i) << endl;
            if (len(i, j - 1) > ans && s[j - 1] != s[j]) {
                ans = len(i, j - 1);
                ans_i = i, ans_j = j - 1;
            }
        }
        cnt[s[i] - 'a']--;
    }

    cout << ans << endl;
    for (int i = ans_i; i <= ans_j; i++) cout << s[i];
    cout << endl;

    return 0;
}

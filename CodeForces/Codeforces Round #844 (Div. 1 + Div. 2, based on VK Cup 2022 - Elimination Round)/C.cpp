#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s, s_ans;
        cin >> n;
        cin >> s;
        map<char, int> cnt;
        for (int i = 0; i < n; i++)
            cnt[s[i]]++;
        vector<pair<int, char>> tcnt;
        for (auto p : cnt) tcnt.push_back({p.second, p.first});
        int ans = n;
        for (int num_char = 1; num_char <= 26; num_char++) {
            if ((n % num_char) > 0)
                continue;
            string ts_ans = s;
            int num = n / num_char;
            int tans = 0;
            set<char> has;
            vector<int> ttcnt(303, 0);
            vector<pair<int, char>> tmp = tcnt;
            while (num_char < tmp.size()) {
                sort(tmp.begin(), tmp.end());
                tmp.erase(tmp.begin());
            }
            while (num_char > tmp.size()) {
                for (int i = 0; i < 26; i++) {
                    bool ttt = false;
                    for (int j = 0; j < tmp.size(); j++)
                        if (tmp[j].second == 'a' + i)
                            ttt = true;
                    if (ttt == false) {
                        tmp.push_back({0, 'a' + i});
                        break;
                    }
                }
            }
            for (auto p : tmp) has.insert(p.second);
            for (auto p : cnt) {
                if (has.find(p.first) != has.end())
                    ttcnt[p.first] += p.second;
            }
            for (int i = 0; i < n; i++) {
                if (has.find(s[i]) == has.end() || ttcnt[s[i]] > num) {
                    for (char x : has) {
                        // cout << x << ' ' << ttcnt[x] << ' ' << num << endl;
                        if (ttcnt[x] < num) {
                            ttcnt[x]++;
                            tans++;
                            ts_ans[i] = x;
                            ttcnt[s[i]]--;
                            // cout << "Change " << s[i] << " to " << x << endl;
                            break;
                        }
                    }
                }
            }
            if (tans < ans) {
                ans = tans;
                s_ans = ts_ans;
                // cout << tans << ' ' << num << ' ' << num_char << endl;
            }
        }
        cout << ans << endl;
        cout << s_ans << endl;
    }

    return 0;
}

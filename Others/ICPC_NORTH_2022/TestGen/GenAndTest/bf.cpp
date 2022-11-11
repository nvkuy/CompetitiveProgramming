#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int q;
    long long mod = 1e9 + 7;
    string s;
    cin >> q;
    while (q--) {
        cin >> s;
        int n = s.length();
        map<string, pair<long long, long long>> cnt;
        // set<string> used;
        for (int i = 0; i < n; i++) {
            // for (int j = i; j < n; j++) {
            //     string tmp = s.substr(i, j - i + 1);
            //     // cout << i << '|' << j << '|' << tmp << endl;
            //     cnt[tmp]++;
            // }
            string cur;
            int tc = 0;
            for (int j = i; j < n; j++) {
                cur.push_back(s[j]);
                tc += (s[j] - 'a' + 1);
                pair<long long, long long> ttt = {tc, 0};
                if (cnt.find(cur) != cnt.end())
                    ttt = cnt[cur];
                ttt.second++;
                cnt[cur] = ttt;
            }

        }
        long long ans = 0;
        // for (int i = 0; i < n; i++) {
        //     for (int j = i; j < n; j++) {
        //         string tmp = s.substr(i, j - i + 1);
        //         if (used.find(tmp) != used.end())
        //             continue;
        //         long long tt = 0;
        //         for (int k = 0; k < tmp.length(); k++)
        //             tt += (tmp[k] - 'a' + 1);
        //         // cout << i << '|' << j << '|';
        //         // cout << tmp.size() << '|' << cnt[tmp] << '|' << tt << endl;
        //         ans += (tmp.size() * cnt[tmp] * tt);
        //         ans %= mod;
        //         used.insert(tmp);
        //     }
        // }
        for (auto tmp : cnt) {
            ans += (tmp.first.length() * tmp.second.first * tmp.second.second);
            ans %= mod;
        }
        cout << ans << endl;
    }
    

    return 0;
}

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

string s, rp;
vector<int> cnt, fix;
vector<string> rs;
// vector<vector<int>> dd;

void gen(int p, string &ans) {
    if (p == 8) {
        int n1 = stoi(ans.substr(0, 2));
        int n2 = stoi(ans.substr(3, 2));
        int n3 = stoi(ans.substr(6, 2));
        // if (dd[n1][n2] == 1)
        //     return;
        if (n1 + n2 != n3)
            return;
        vector<int> tmp(10, 0);
        for (int i = 0; i < 8; i++) {
            int tt = ans[i] - '0';
            if (tt >= 0 && tt < 10)
                tmp[tt]++;
        }
        for (int i = 0; i < 10; i++) {
            if (fix[i] == 1 && cnt[i] != tmp[i])
                return;
            if (fix[i] == 0 && cnt[i] > tmp[i])
                return;
        }
        rs.push_back(ans);
        // dd[n1][n2] = dd[n2][n1] = 1;
        return;
    }
    if (rp[p] == 'G') {
        ans.push_back(s[p]);
        gen(p + 1, ans);
        ans.pop_back();
        return;
    }
    for (int i = 0; i < 10; i++) {
        if (i + '0' == s[p])
            continue;
        ans += to_string(i);
        gen(p + 1, ans);
        ans.pop_back();
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    getline(cin, s);
    getline(cin, rp);
    cnt.assign(10, 0);
    fix.assign(10, 0);
    // dd.assign(101, vector<int>(101, 0));
    for (int i = 0; i < 8; i++) {
        if (rp[i] == 'B') {
            int tt = s[i] - '0';
            if (tt >= 0 && tt < 10)
                fix[tt] = 1;
            continue;
        }
        int tt = s[i] - '0';
        if (tt >= 0 && tt < 10)
            cnt[tt]++;
    }
    string ans;
    gen(0, ans);
    cout << rs.size() << endl;
    for (string ss : rs)
        cout << ss << endl;

    return 0;
}

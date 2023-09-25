#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
#define bit_cnt(x) __builtin_popcountll(x)
#define low_bit(x) __builtin_ctzll(x)

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

bool cmp(const pair<int, string> &p1, const pair<int, string> &p2) {
    if (p1.first == p2.first)
        return p1.second.size() > p2.second.size();
    return p1.first < p2.first;
}

vector<pair<int, string>> a;
int len, n;

pair<bool, string> tryMake(int id_del) {
    string cur = "";
    for (int k = 0; k < n; k++) {
        if (k == id_del) continue;
        auto p = a[k];
        if (p.first > cur.length()) return {false, ""};
        if (p.first < cur.length()) {
            for (int i = 0; i < p.second.length(); i++) {
                if (p.first + i >= cur.length())
                    break;
                if (p.second[i] != cur[p.first + i])
                    return {false, ""};
            }
        }
        int tlen = cur.length();
        for (int i = 0; i < p.second.length(); i++) {
            if (p.first + i < tlen) continue;
            cur.push_back(p.second[i]);
        }
    }
    if (id_del >= 0) {
        bool isDiff = false;
        for (int i = 0; i < a[id_del].second.length(); i++)
            isDiff |= cur[i + a[id_del].first] != a[id_del].second[i];
        if (!isDiff)
            return {false, ""};
    }
    if (cur.length() == len)
        return {true, cur};
    return {false, ""};
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> len;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        a[i].first--;
    }
    sort(a.begin(), a.end(), cmp);
    int ans_cnt = 0;
    string ans;
    auto tmp = tryMake(-1);
    if (tmp.first) {
        ans_cnt++;
        ans = tmp.second;
    }
    for (int i = 0; i < n; i++) {
        tmp = tryMake(i);
        if (tmp.first) {
            ans_cnt++;
            ans = tmp.second;
        }
    }

    if (ans_cnt == 0) {
        cout << -1 << endl;
        return 0;
    }

    if (ans_cnt == 1) {
        cout << ans << endl;
        return 0;
    }

    cout << -2 << endl;

    return 0;
}

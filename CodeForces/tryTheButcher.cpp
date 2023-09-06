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

vector<pair<long long, long long>> rec;

bool canMake(long long h, long long w, multiset<pair<long long, int>> &s_ver, multiset<pair<long long, int>> &s_hoz) {
    if (h * w == 0) return true;
    if (s_ver.rbegin()->first == h) {
        int rec_id = s_ver.rbegin()->second;
        w -= rec[rec_id].second;
        s_ver.erase(s_ver.lower_bound({rec[rec_id].first, rec_id}));
        s_hoz.erase(s_hoz.lower_bound({rec[rec_id].second, rec_id}));
        return canMake(h, w, s_ver, s_hoz);
    }
    if (s_hoz.rbegin()->first == w) {
        int rec_id = s_hoz.rbegin()->second;
        h -= rec[rec_id].first;
        s_ver.erase(s_ver.lower_bound({rec[rec_id].first, rec_id}));
        s_hoz.erase(s_hoz.lower_bound({rec[rec_id].second, rec_id}));
        return canMake(h, w, s_ver, s_hoz);
    }
    return false;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        rec.resize(n);
        long long area = 0, w, h;
        multiset<pair<long long, int>> s_ver, s_hoz, t1, t2;
        for (int i = 0; i < n; i++) {
            cin >> rec[i].first >> rec[i].second;
            area += rec[i].first * rec[i].second;
            s_ver.insert({rec[i].first, i});
            s_hoz.insert({rec[i].second, i});
        }

        set<pair<long long, long long>> ans;
        t1 = s_ver, t2 = s_hoz;
        h = s_ver.rbegin()->first, w = area / h;
        if (area % h == 0) {
            int rec_id = s_ver.rbegin()->second;
            t1.erase(t1.lower_bound({rec[rec_id].first, rec_id}));
            t2.erase(t2.lower_bound({rec[rec_id].second, rec_id}));
            if (canMake(h, w - rec[rec_id].second, t1, t2)) ans.insert({h, w});
        }
        t1 = s_ver, t2 = s_hoz;
        w = s_hoz.rbegin()->first, h = area / w;
        if (area % w == 0) {
            int rec_id = s_hoz.rbegin()->second;
            t1.erase(t1.lower_bound({rec[rec_id].first, rec_id}));
            t2.erase(t2.lower_bound({rec[rec_id].second, rec_id}));
            if (canMake(h - rec[rec_id].first, w, t1, t2)) ans.insert({h, w});
        }

        cout << ans.size() << endl;
        for (auto p : ans) cout << p.first << ' ' << p.second << endl;

    }

    return 0;
}

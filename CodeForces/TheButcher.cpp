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

bool canMake(long long area, long long pre_side, bool ver_cut, multiset<pair<long long, int>> &s_ver, multiset<pair<long long, int>> &s_hoz) {
    assert(s_hoz.size() == s_ver.size());
    if (area == 0) return true;
    if (ver_cut) {
        long long side = s_ver.rbegin()->first;
        if (area % side > 0) return false;
        if (area / pre_side != side) return false;
        while (true) {
            if (s_ver.size() == 0) break;
            auto it = s_ver.rbegin();
            if (it->first != side) break;
            int rec_id = it->second;
            area -= rec[rec_id].first * rec[rec_id].second;
            s_ver.erase(s_ver.lower_bound({rec[rec_id].first, rec_id}));
            s_hoz.erase(s_hoz.lower_bound({rec[rec_id].second, rec_id}));
        }
        return canMake(area, side, false, s_ver, s_hoz);
    }
    long long side = s_hoz.rbegin()->first;
    if (area % side > 0) return false;
    if (area / pre_side != side) return false;
    while (true) {
        if (s_hoz.size() == 0) break;
        auto it = s_hoz.rbegin();
        if (it->first != side) break;
        int rec_id = it->second;
        area -= rec[rec_id].first * rec[rec_id].second;
        s_ver.erase(s_ver.lower_bound({rec[rec_id].first, rec_id}));
        s_hoz.erase(s_hoz.lower_bound({rec[rec_id].second, rec_id}));
    }
    return canMake(area, side, true, s_ver, s_hoz);
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
        long long area = 0, t3;
        multiset<pair<long long, int>> s_ver, s_hoz, t1, t2;
        for (int i = 0; i < n; i++) {
            cin >> rec[i].first >> rec[i].second;
            area += rec[i].first * rec[i].second;
            s_ver.insert({rec[i].first, i});
            s_hoz.insert({rec[i].second, i});
        }

        set<pair<long long, long long>> ans;
        t1 = s_ver, t2 = s_hoz;
        t3 = s_ver.rbegin()->first;
        if (canMake(area, area / t3, true, t1, t2)) {
            assert(area % t3 == 0);
            ans.insert({t3, area / t3});
        }
        t1 = s_ver, t2 = s_hoz;
        t3 = s_hoz.rbegin()->first;
        if (canMake(area, area / t3, false, t1, t2)) {
            assert(area % t3 == 0);
            ans.insert({area / t3, t3});
        }

        assert(ans.size() > 0);
        cout << ans.size() << endl;
        for (auto p : ans) {
            assert(p.first * p.second == area);
            cout << p.first << ' ' << p.second << endl;
        }
    }

    return 0;
}

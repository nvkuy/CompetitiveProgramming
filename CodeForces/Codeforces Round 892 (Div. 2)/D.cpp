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

/*

DMDDFNDJHKUGHSLKUhfudhfglushdkfghsdsd
f
dfgieo84p8h4guh34p8ythg
gsdfgjsldkfg
sdfgsdjflgikjsdf

DMDMDMDMMDMDMDMD CUOC DOI =((((((
    
*/

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> range;
        vector<int> all_num, query;
        for (int i = 0; i < n; i++) {
            int l, r, a, b;
            cin >> l >> r >> a >> b;
            all_num.push_back(l);
            // all_num.push_back(r);
            // all_num.push_back(a);
            all_num.push_back(b);
            range.push_back({b, l});
        }
        int q;
        cin >> q;
        query.resize(q);
        for (int i = 0; i < q; i++) {
            cin >> query[i];
            all_num.push_back(query[i]);
        }
        sort(all_num.begin(), all_num.end());
        set<int> avai_pos;
        map<int, int> hashf, dehashf;
        int cur_hash = 1;
        for (int num : all_num) {
            if (hashf[num] == 0) {
                hashf[num] = cur_hash;
                dehashf[cur_hash] = num;
                cur_hash++;
            }
        }
        vector<int> f(hashf.size() + 1);
        for (int i = 0; i < f.size(); i++)  f[i] = i;
        avai_pos.insert(f.begin(), f.end());
        sort(range.begin(), range.end(), greater<pair<int, int>>());
        for (auto r : range) {
            auto it = avai_pos.lower_bound(hashf[r.second]);
            while (true) {
                if (it == avai_pos.end() || *it > hashf[r.first]) break;
                f[*it] = max(f[*it], f[hashf[r.first]]);
                it = avai_pos.erase(it);
            }
        }
        for (auto qr : query)
            cout << dehashf[f[hashf[qr]]] << ' ';
        cout << endl;
    }

    return 0;
}

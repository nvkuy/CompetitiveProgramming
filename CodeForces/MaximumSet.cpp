#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

long long rq_size, mod = 998244353;
vector<pair<long long, long long>> all_conf;

long long modExp(long long num, long long pow) {
    if (pow == 0)
        return 1;
    if (pow % 2)
        return (num * modExp(num, pow - 1)) % mod;
    return modExp((num * num) % mod, pow / 2);
}

void bf(int l, int r, int num, vector<int> &conf) {
    long long t3 = l, t4 = 0;
    while (t3 * num <= r) {
        t3 *= num;
        t4++;
    }
    if (conf.size() + t4 < rq_size) return;
    if (l * num > r) {
        if (conf.size() == rq_size) {
            // cout << "Found conf: ";
            // for (auto ttt : conf) cout << ttt << ' ';
            // cout << endl;
            map<int, int> cnt;
            long long t1 = 1, t2 = 1, t5 = 1;
            for (long long i = 0; i < conf.size(); i++) {
                cnt[conf[i]]++;
                t1 = (t1 * (i + 1)) % mod;
                t5 *= conf[i];
            }
            for (auto p : cnt) {
                for (long long i = 1; i <= p.second; i++)
                    t2 = (t2 * i) % mod;
            }
            long long set_conf =  (t1 * modExp(t2, mod - 2)) % mod;
            // cout << "t1_t2: " << t1 << '_' << t2 << endl;
            all_conf.push_back({t5, set_conf});
        }
        return;
    }
    conf.push_back(num);
    bf(l * num, r, num, conf);
    conf.pop_back();
    bf(l, r, num + 1, conf);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        rq_size = 0;
        vector<int> conf;
        all_conf.clear();
        while (l * (1 << (rq_size + 1)) <= r)
            rq_size++;
        bf(l, r, 2, conf);
        long long ans = 0;
        for (auto p : all_conf) {
            long long ll = l, rr = r, mm;
            while (ll < rr) {
                mm = (ll + rr + 1) / 2;
                if (p.first * mm > r)
                    rr = mm - 1;
                else
                    ll = mm;
            }
            ans = (ans + ((p.second * (ll - l + 1)) % mod)) % mod;
        }
        cout << rq_size + 1 << ' ' << ans << endl;
    }

    return 0;
}

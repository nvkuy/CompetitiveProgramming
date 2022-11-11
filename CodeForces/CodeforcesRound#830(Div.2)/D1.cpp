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

    debugLocal();

    long long q, x;
    char c;
    cin >> q;
    set<long long> num;
    map<long long, long long> mex_num;
    while (q--) {
        cin >> c >> x;
        if (c == '+')
            num.insert(x);
        else {
            auto it = mex_num.find(x);
            long long cur_mex = x;
            if (it != mex_num.end())
                cur_mex = it->second;
            while (num.find(cur_mex) != num.end())
                cur_mex += x;
            if (it != mex_num.end())
                mex_num.erase(it);
            mex_num.insert({x, cur_mex});
            cout << cur_mex << endl;
        }
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

long long query(long long num) {
    assert(num <= 1e9);
    cout << "- " << num << endl;
    cout.flush();
    int rp;
    cin >> rp;
    return rp;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        long long cnt, high_bit = 0, mask = 0, ans = 0;
        cin >> cnt;
        for (int i = 0; i < 30; i++) {
            cnt -= __builtin_popcountll(mask);
            if (cnt == 0)
                break;
            long long num = mask ^ (1LL << high_bit);
            long long new_cnt = query(num);
            long long new_high = new_cnt - cnt + 1;
            long long new_high_bit = high_bit + new_high;
            ans ^= (1LL << new_high_bit);
            mask = 0;
            for (int i = high_bit; i < new_high_bit; i++)
                mask ^= (1LL << i);
            high_bit = new_high_bit;
            cnt = new_cnt;
        }
        cout << "! " << ans << endl;
        cout.flush(); 
    }

    return 0;
}

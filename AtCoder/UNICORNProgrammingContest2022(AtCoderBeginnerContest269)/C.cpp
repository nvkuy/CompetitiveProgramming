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

    long long n;
    cin >> n;
    vector<int> pos;
    for (int i = 0; i < 60; i++) {
        if (((1LL << i) & n) != 0)
            pos.push_back(i);
    }
    for (int i = 0; i < (1LL << pos.size()); i++) {
        long long num = 0;
        for (int j = 0; j < pos.size(); j++) {
            if (((1LL << j) & i) != 0)
                num += (1LL << pos[j]);
        }
        cout << num << endl;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

bool query(int num) {
    cout << "? " << num << endl;
    cout.flush();
    char rp;
    cin >> rp;
    return rp == '<';
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int prime[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    int l = 0, r = 24, m;
    while (l < r) {
        m = (l + r + 1) / 2;
        if (query(prime[m]))
            l = m;
        else
            r = m - 1;
        //cout << l << ' ' << r << endl;
    }
    cout << "! " << prime[l];

    return 0;
}
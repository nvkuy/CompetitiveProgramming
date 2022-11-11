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

int n;
string query(int p1, int p2) {
    cout << p1 << ' ' << p2 << endl;
    cout.flush();
    string rp;
    cin >> rp;
    return rp;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // debugLocal();
    cin >> n;
    while (true) {
        for (int j = n; j > 1; j--) {
            if (query(j - 1, j) == "WIN")
                return 0;
        }
        for (int j = 1; j < n; j++) {
            if (query(j, j + 1) == "WIN")
                return 0;
        }
    }

    return 0;
}

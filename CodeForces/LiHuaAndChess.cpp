#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int query(int r, int c) {
    cout << "? " << r << ' ' << c << endl;
    cout.flush();
    int rp;
    cin >> rp;
    return rp;
}

void printAns(int r, int c) {
    cout << "! " << r << ' ' << c << endl;
    cout.flush();
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        int d1 = query(1, 1);
        if (d1 >= n) {
            int d2 = query(1, d1 + 1);
            printAns(d2 + 1, d1 + 1);
            continue;
        }
        if (d1 >= m) {
            int d2 = query(d1 + 1, 1);
            printAns(d1 + 1, d2 + 1);
            continue;
        }
        int d2 = query(d1 + 1, d1 + 1);
        int d3 = query(1, d1 + 1);
        if (d1 == 0) {
            printAns(1, 1);
            continue;
        }
        if (d2 == 0) {
            printAns(d1 + 1, d1 + 1);
            continue;
        }
        if (d3 == 0) {
            printAns(1, d1 + 1);
            continue;
        }
        if (d1 == d2 && d2 == d3) {
            printAns(d1 + 1, 1);
            continue;
        }
        if (d1 == d3) {
            int diff = d1 - d2;
            printAns(d1 + 1, diff + 1);
            continue;
        }
        printAns(d3 + 1, d1 + 1);

    }

    return 0;
}

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

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    /*
    5 3
    5 4 3 2 1
    */
    /*
    q1: 1 5 4
    q2: 2 4 3
    */
    int n = 5, k = 3;
    vector<int> b = { 0, 5, 4, 3, 2, 1 };
    vector<int> a = { 0, 0, 0, 0, 0, 0 };
    vector<int> l1 = { 0, 1, 5, 4 };
    vector<int> l2 = { 0, 2, 4, 3 };

    for (int i = 1; i <= n; i++)
        cout << a[i] << ' ';
    cout << endl;

    for (int i = 1; i <= k; i++)
        a[l1[i]] = l1[(i % k) + 1];

    for (int i = 1; i <= n; i++)
        cout << a[i] << ' ';
    cout << endl;

    for (int i = 1; i <= k; i++)
        a[l2[i]] = l2[(i % k) + 1];

    for (int i = 1; i <= n; i++)
        cout << a[i] << ' ';
    cout << endl;

    return 0;
}

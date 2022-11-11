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

void gen(int size, int i, long long num, vector<long long> &arr) {
    if (i == size) {
        arr.push_back(num);
        return;
    }
    gen(size, i + 1, num * 10LL + 4LL, arr);
    gen(size, i + 1, num * 10LL + 7LL, arr);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    //debugLocal();
    int k;
    cin >> k;
    vector<long long> arr;
    for (int i = 1; i <= 20; i++) {
        if (arr.size() > k)
            break;
        gen(i, 0, 0, arr);
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < k; i++)
        cout << arr[i] << endl;
    // cout << arr[k - 1] << endl;

    return 0;
}

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

long long cnt = 0;

bool check(int k, vector<int> &a) {
    int tc = 0;
    for (int i = 1; i < a.size() - 1; i++)
        if (a[i] > a[i - 1] && a[i] > a[i + 1])
            tc++;
    return tc == k;
}

void gen(int x, int k, int pos, vector<int> &a) {
    if (pos == a.size()) {
        cnt += check(k, a);
        return;
    }
    for (int i = 0; i < x; i++) {
        a[pos] = i;
        gen(x, k, pos + 1, a);
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int n, x, k;
    cin >> n >> x >> k;

    if (pow(x, n) > 2e8) {
        cout << 0;
        return 0;
    }

    vector<int> a(n);
    gen(x, k, 0, a);
    cout << cnt << endl;

    return 0;
}

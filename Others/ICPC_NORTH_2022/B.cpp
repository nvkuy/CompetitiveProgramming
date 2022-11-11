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

long long m;
vector<pair<long long, long long>> arr;
vector<int> dd;

void bfs(int st) {
    dd[st] = 0;
    queue<int> q;
    q.push(st);
    while (!q.empty()) {
        long long u = q.front();
        q.pop();
        for (int i = 0; i < arr.size(); i++) {
            long long v = (u * arr[i].first + arr[i].second) % m;
            if (dd[v] != -1)
                continue;
            dd[v] = dd[u] + 1;
            q.push(v);
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int n, s0;
    cin >> m >> n >> s0;
    arr.resize(n);
    dd.assign(m + 1, -1);
    for (int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;
    bfs(s0);
    cout << dd[0] << endl;

    return 0;
}

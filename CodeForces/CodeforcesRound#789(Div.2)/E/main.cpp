#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<vector<int>> c;
vector<int> cycle, dd;

void dfs(int u) {
    dd[u] = 1;
    cycle.push_back(u);
    for (int i = 0; i < c[u].size(); i++) {
        int v = c[u][i];
        if (dd[v] == 0)
            dfs(v);
    }
}

bool cmpCycle(vector<int> &c1, vector<int> &c2) {
    int rm1 = c1.size() % 2, rm2 = c2.size() % 2;
    if (rm1 == rm2) {
        if (c1.size() == 1 || c2.size() == 1)
            return c1.size() > c2.size();
        return c1.size() < c2.size();
    }
    return rm1 < rm2;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n), b(n);
        deque<int> nums;
        vector<vector<int>> cycles;
        dd.assign(n + 1, 0);
        for (int i = 1; i <= n; i++)
            nums.push_back(i);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        c.clear();
        c.resize(n + 1);
        for (int i = 0; i < n; i++) {
            c[a[i]].push_back(b[i]);
            c[b[i]].push_back(a[i]);
        }
        for (int i = 0; i < n; i++) {
            if (dd[a[i]] == 0) {
                cycle.clear();
                dfs(a[i]);
                cycles.push_back(cycle);
            }
        }
        sort(cycles.begin(), cycles.end(), cmpCycle);
        long long ans = 0;
        for (int i = 0; i < cycles.size(); i++) {
            int pre = nums.front(), first = pre; nums.pop_front();
            //cout << cycles[i].size() << endl;
            for (int j = 1; j < cycles[i].size(); j++) {
                int val;
                if (j % 2) {
                    val = nums.back();
                    nums.pop_back();
                } else {
                    val = nums.front();
                    nums.pop_front();
                }
                ans += abs(val - pre);
                pre = val;
            }
            ans += (pre - first);
        }
        cout << ans << endl;
    }

    return 0;
}

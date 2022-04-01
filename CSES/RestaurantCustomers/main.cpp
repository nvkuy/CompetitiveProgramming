#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, a, b, ans = 0;
    cin >> n;
    vector<pair<int, int>> cuss;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        cuss.push_back(make_pair(a, b));
    }
    sort(cuss.begin(), cuss.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        pq.push(cuss[i].second);
        while (!pq.empty() && pq.top() < cuss[i].first)
            pq.pop();
        ans = max(ans, (int)pq.size());
    }
    cout << ans;

    return 0;
}

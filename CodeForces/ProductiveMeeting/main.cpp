#include <bits/stdc++.h>

using namespace std;

priority_queue<pair<int, int>> pq;
vector<pair<int, int>> ans;

int main()
{
    int t, n, ai;
    scanf("%d", &t);
    while (t--) {
        ans.clear();
        while (!pq.empty())
            pq.pop();
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &ai);
            if (ai > 0)
                pq.push(make_pair(ai, i));
        }
        pair<int, int> p1, p2;
        while (pq.size() > 1) {
            p1 = pq.top();
            pq.pop();
            p2 = pq.top();
            pq.pop();
            ans.push_back(make_pair(p2.second, p1.second));
            p2.first--; p1.first--;
            if (p1.first > 0)
                pq.push(p1);
            if (p2.first > 0)
                pq.push(p2);
        }
        printf("%d\n", ans.size());
        for (int i = 0; i < ans.size(); i++)
            printf("%d %d\n", ans[i].first, ans[i].second);
    }

    return 0;
}

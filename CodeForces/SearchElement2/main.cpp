#include <bits/stdc++.h>

using namespace std;

int searchElement02(vector<vector<int>> a, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < a[0].size(); i++) {
        for (int j = 0; j < a.size(); j++) {
            pq.push(a[i][j]);
        }
    }
    int c = 1, cur = pq.top();
    pq.pop();
    while ((c < k) && (pq.size() > 0)) {
        if (pq.top() != cur) {
            c++;
            cur = pq.top();
        }
        pq.pop();
    }
    if (c < k)
        return -1;
    return cur;
}

int main()
{
    cout << searchElement02({{1,3,8}, {2,4,10}, {2,5,12}}, 4);
    return 0;
}

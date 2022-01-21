#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k, ai;
    priority_queue<int, vector<int>, greater<int>> pq;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> ai;
        pq.push(ai);
    }
    cout << pq.top() << endl;
    for (int i = k; i < n; i++) {
        cin >> ai;
        if (pq.top() < ai) {
            pq.pop();
            pq.push(ai);
        }
        cout << pq.top() << endl;
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int mn = 2002;
long long a[mn];
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    int n, po;
    long long h = 0LL;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++) {
        if (h + a[i] >= 0) {
            pq.push(a[i]);
            h += a[i];
        } else {
            if (pq.empty())
                continue;
            po = pq.top();
            if (po < a[i]) {
                h -= po;
                h += a[i];
                pq.pop();
                pq.push(a[i]);
            }
        }
    }
    cout << pq.size();

    return 0;
}

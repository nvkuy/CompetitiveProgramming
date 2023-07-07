#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int c, n;
    cin >> c >> n;
    vector<int> num, has((1 << c) + 1, 0);
    vector<int> rans((1 << c) + 1, -1);
    queue<int> q;
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        int tnum = 0;
        for (int j = 0; j < c; j++)
            tnum += ((1 << j) * (tmp[j] == 'G'));
        int rnum = ((1 << c) - 1) ^ tnum;
        rans[rnum] = 0;
        q.push(rnum);
        has[tnum] = 1;
        num.push_back(tnum);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < c; i++) {
            int v = (u ^ (1 << i));
            if (rans[v] == -1) {
                rans[v] = rans[u] + 1;
                q.push(v);
            }
        }
    }
    for (int ai : num)
        cout << c - rans[ai] << endl;

    return 0;
}

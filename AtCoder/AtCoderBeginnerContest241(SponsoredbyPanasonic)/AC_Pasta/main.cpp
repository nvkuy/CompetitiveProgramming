#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, ai;
    cin >> n >> m;
    map<int, int> co;
    for (int i = 0; i < n; i++) {
        cin >> ai;
        co[ai]++;
    }
    bool iok = true;
    for (int i = 0; i < m; i++) {
        cin >> ai;
        if (co[ai] > 0)
            co[ai]--;
        else
            iok = false;
    }
    cout << (iok ? "Yes" : "No");

    return 0;
}

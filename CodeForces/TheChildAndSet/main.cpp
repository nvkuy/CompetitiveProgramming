#include <bits/stdc++.h>

using namespace std;

int main()
{
    int s, lim, u;
    cin >> s >> lim;
    vector<int> m;
    for (int i = lim; i >= 0; i--) {
        u = i & ~(i - 1);
        if (s >= u) {
            s -= u;
            m.push_back(i);
        }
        if (s == 0)
            break;
    }
    if (s > 0) {
        cout << "-1";
        return 0;
    }
    cout << m.size() << endl;
    for (int i = 0; i < m.size(); i++)
        cout << m[i] << ' ';

    return 0;
}

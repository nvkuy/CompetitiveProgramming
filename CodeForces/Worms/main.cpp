#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, t, m;
    vector<int> p;
    scanf("%d", &n);
    p.push_back(0);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &t);
        p.push_back(t + p[i - 1]);
    }
    scanf("%d", &m);
    while (m--) {
        scanf("%d", &t);
        printf("%d\n", lower_bound(p.begin(), p.end(), t) - p.begin());
    }

    return 0;
}

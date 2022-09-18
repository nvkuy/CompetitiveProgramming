#include <bits/stdc++.h>

using namespace std;

int main()
{

    int maxi = 0, maxl = -1e9 + 7, n, t;
    scanf("%d", &n);
    scanf("%d", &maxi);
    for (int i = 1; i < n; i++) {
        scanf("%d", &t);
        maxl = max(maxi - t, maxl);
        maxi = max(maxi, t);
    }
    if (maxl <= 0)
        cout << "Lo nang roi!";
    else
        cout << maxl;

    return 0;
}

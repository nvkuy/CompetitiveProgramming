#include <bits/stdc++.h>

using namespace std;

long n, m, t, tmp, low, high;

int main()
{

    cin >> n >> m;

    t = m - ((n * (n + 1)) / 2);
    if (t < 0)
        cout << -1;
    else {
        tmp = ((int) (t / n));
        low = 1 + tmp;
        high = n + tmp;
        if ((t % n) > 0)
            high++;
    }

    cout << low << " " << high;

    return 0;
}

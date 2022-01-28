#include <bits/stdc++.h>

using namespace std;

int n;
long long x;
vector<long long> a;

long long pay(long long mn, int i) {
    if (mn == 0LL)
        return 0LL;
    if (i == 1)
        return mn;
    if (mn < a[i]) {
        //return min(pay(mn, i - 1), pay(a[i] - mn, i - 1) + 1);
        if (2 * mn - a[i] > a[i - 1])
            return pay(a[i] - mn, i - 1) + 1;
        return pay(mn, i - 1);
    } else
        return ((mn / a[i]) + pay(mn % a[i], i));
}

int main()
{

    cin >> n >> x;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cout << pay(x, n);

    return 0;
}

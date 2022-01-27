#include <bits/stdc++.h>

using namespace std;

vector<long long> f(200002);
map<long long, int> ms;
map<long long, int>::iterator it;

int main()
{
    int n, ai;
    long long k, ans = 0LL;
    f[0] = 0LL;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> ai;
        f[i] = f[i - 1] + ai;
    }
    ms.insert(make_pair(0LL, 1));
    for (int i = 1; i <= n; i++) {
        it = ms.find(f[i] - k);
        if (it != ms.end())
            ans += (it->second);
        it = ms.find(f[i]);
        if (it == ms.end())
            ms.insert(make_pair(f[i], 1));
        else
            (it->second)++;
    }
    cout << ans << endl;

    return 0;
}

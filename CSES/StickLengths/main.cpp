#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int n;
vector<int> a;

long long f(int x) {
    long long cost = 0LL;
    for (int i = 0; i < n; i++)
        cost += abs(x - a[i]);
    return cost;
}

long long mincost(int left, int right) {

    int x1 = left + ((right - left) / 3);
    int x2 = right - ((right - left) / 3);

    if (x1 == left && x2 == right) {
        long long ans = 1e18;
        for (int i = x1; i <= x2; i++)
            ans = min(ans, f(i));
        return ans;
    }

    if (f(x1) > f(x2)) left = x1;
    else if (f(x1) < f(x2)) right = x2;
    else right = x2, left = x1;

	return mincost(left, right);

}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    a.resize(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << mincost(0, 1e9);

    return 0;
}

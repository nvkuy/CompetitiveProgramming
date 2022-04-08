#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int n, needProduct;
vector<int> a;

bool isEnough(long long time) {
    long long numProduct = 0LL;
    for (int i = 0; i < n; i++) {
        numProduct += (time / a[i]);
        if (numProduct >= needProduct)
            return true;
    }
    return false;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> needProduct;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    long long l = 0, r = 1e18 + 2003, m;
    while (l < r) {
        m = (l + r) / 2LL;
        if (isEnough(m))
            r = m;
        else
            l = m + 1LL;
    }
    cout << r << endl;

    return 0;
}

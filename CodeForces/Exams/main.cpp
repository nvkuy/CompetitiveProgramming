#include <bits/stdc++.h>

using namespace std;

struct date {
    long long a, b;
    date(long long ai, long long bi) {
        a = ai;
        b = bi;
    }
};

bool cmp(date d1, date d2) {
    if (d1.a == d2.a)
        return d1.b < d2.b;
    return d1.a < d2.a;
}

vector<date> ds;

int main()
{

    long long n, a, b;
    long long ans;
    cin >> n;
    for (long long i = 0; i < n; i++) {
        cin >> a >> b;
        ds.push_back(date(a, b));
    }
    sort(ds.begin(), ds.begin() + n, cmp);
    ans = ds[0].b;
    for (long long i = 0; i < n; i++) {
        if (ans == ds[i].b)
            continue;
        else if (ans > ds[i].b)
            ans = ds[i].a;
        else
            ans = ds[i].b;
    }
    cout << ans;


    return 0;
}

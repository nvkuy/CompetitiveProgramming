#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

long long n;
map<long long, vector<long long>> types;
map<long long, vector<long long>>::iterator it;
vector<long long> a;

long long calType(vector<long long> b) {
    //for (int i = 0; i < b.size(); i++)
    //    cout << b[i] << '|';
    //cout << endl;
    vector<long long> ps;
    ps.push_back(0);
    for (int i = 0; i < b.size(); i++)
        ps.push_back(ps.back() + b[i]);
    long long ans = 0;
    for (long long i = 1; i <= b.size(); i++)
        ans += (b[i - 1] * ((n + 1LL) * (b.size() - i) - ps[b.size()] + ps[i]));
    return ans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        a.resize(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        types.clear();
        for (int i = 1; i <= n; i++)
            types[a[i]].push_back(i);
        long long ans = 0;
        for (it = types.begin(); it != types.end(); it++)
            ans += calType(it->second);
        cout << ans << endl;
    }

    return 0;
}

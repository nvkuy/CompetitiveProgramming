#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<long long, int> &a1, pair<long long, int> &a2) {
    return (abs(a1.first) < abs(a2.first));
}

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}

vector<long long> b;
vector<pair<long long, int>> a;

int main()
{
    long long t, n, t1, t2;
    cin >> t;
    while (t--) {
        cin >> n;
        b.resize(n);
        a.clear();
        for (int i = 0; i < n; i++) {
            cin >> t1;
            a.push_back(make_pair(t1, i));
        }
        sort(a.begin(), a.end(), cmp);
        int i = 0;
        t1, t2;
        if (n % 2) {
            i += 3;
            if (a[0].first + a[1].first == 0)
                swap(a[0], a[2]);
            if (a[0].first + a[1].first == 0)
                swap(a[1], a[2]);
            t1 = a[0].first + a[1].first;
            t2 = lcm(t1, a[2].first);
            b[a[0].second] = b[a[1].second] = (t2 / t1);
            b[a[2].second] = (- t2 / a[2].first);
        }
        while (i < n) {
            t1 = lcm(a[i].first, a[i + 1].first);
            b[a[i].second] = (t1 / a[i].first);
            b[a[i + 1].second] = (- t1 / a[i + 1].first);
            i += 2;
        }
        for (int i = 0; i < n; i++)
            cout << b[i] << ' ';
        cout << endl;
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

long long rand_range(long long l, long long r) {
    return l + rand() % (r - l + 1);
}

vector<int> genNum(long long num, int k) {
    vector<int> rs;
    while (num != 0) {
        rs.push_back(num % 3);
        num /= 3;
    }
    while (rs.size() < k)
        rs.push_back(0);
    reverse(rs.begin(), rs.end());
    return rs;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n = rand_range(100, 200), k = rand_range(10, 20);
    long long maxNum = 1;
    for (int i = 0; i < k; i++)
        maxNum *= 3LL;
    cout << n << ' ' << k << endl;
    set<long long> used;
    for (int i = 0; i < n; i++) {
        long long num = rand_range(0, maxNum - 1);
        while (used.find(num) != used.end())
            num = rand_range(0, maxNum - 1);
        vector<int> ki = genNum(num, k);
        for (int kii : ki)
            cout << kii << ' ';
        cout << endl;
    }

    return 0;
}

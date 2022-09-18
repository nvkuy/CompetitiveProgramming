#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

int main()
{
    long long n, m;
    cin >> n >> m;
    set<long long> s;
    for (long long i = 1; i <= n; i++) {
        for (long long j = 1; j <= m; j++)
            s.insert(pow(i, j));
    }
    cout << s.size();

    return 0;
}

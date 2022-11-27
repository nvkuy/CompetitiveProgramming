#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int rand_range(int l, int r) {
    return l + rand() % (r - l + 1);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    srand(time(0));
    cout << 1 << endl;
    int n = 2e5;
    cout << n << ' ' << rand_range(1, 1e6) << endl;
    for (int i = 0; i < n; i++)
        cout << rand_range(1, 1e8) << ' ';
    cout << endl;

    return 0;
}

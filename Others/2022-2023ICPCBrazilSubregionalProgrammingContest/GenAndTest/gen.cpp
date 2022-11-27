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
    
    int n = rand_range(2, 20);
    int x = max(min((1 << n) - rand_range(0, (1 << n) - 1), (1 << n) - 1), 1);
    int y = max(min((1 << n) - rand_range(0, (1 << n) - 1), (1 << n) - 1), 1);
    cout << n << ' ' << x << ' ' << y << endl;

    return 0;
}

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
    
    int n = 5;
    cout << n << endl;
    for (int i = 0; i < n; i++)
        cout << rand_range(1, 4) << ' ';
    cout << endl;
    cout << 1 << endl;
    cout << 3 << endl;
    cout << "1 2 5" << endl;

    return 0;
}

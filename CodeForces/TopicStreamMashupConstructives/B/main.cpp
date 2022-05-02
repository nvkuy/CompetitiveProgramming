#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    string a, b;
    for (int i = 0; i < 2230; i++) {
        if (i == 2229)
            a.push_back('9');
        else
            a.push_back('8');
        b.push_back('1');
    }
    cout << a << endl << b;

    return 0;
}

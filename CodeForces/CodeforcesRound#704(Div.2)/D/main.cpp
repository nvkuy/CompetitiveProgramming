#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int a, b, k;
    cin >> a >> b >> k;
    string x, y;
    if (k == 0) {
        for (int i = 0; i < b; i++)
            x.push_back('1'), y.push_back('1');
        for (int i = 0; i < a; i++)
            x.push_back('0'), y.push_back('0');
    } else {
        if (a == 0 || b <= 1 || a + b - 2 < k) {
            cout << "No";
            return 0;
        }
        b -= 2, a--;
        x.push_back('1'), y.push_back('1');
        x.push_back('1'), y.push_back('0');
        for (int i = 1; i < k; i++) {
            if (a > 0) {
                x.push_back('0'), y.push_back('0');
                a--;
            } else {
                x.push_back('1'), y.push_back('1');
                b--;
            }
        }
        x.push_back('0'), y.push_back('1');
        for (int i = 0; i < b; i++)
            x.push_back('1'), y.push_back('1');
        for (int i = 0; i < a; i++)
            x.push_back('0'), y.push_back('0');
    }
    cout << "Yes" << endl;
    cout << x << endl << y;

    return 0;
}

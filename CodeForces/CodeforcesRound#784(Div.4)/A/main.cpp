#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, rt;
    cin >> t;
    while (t--) {
        cin >> rt;
        if (rt < 1400)
            cout << "Division 4";
        else {
            if (rt < 1600)
                cout << "Division 3";
            else {
                if (rt < 1900)
                    cout << "Division 2";
                else
                    cout << "Division 1";
            }
        }
        cout << endl;
    }

    return 0;
}

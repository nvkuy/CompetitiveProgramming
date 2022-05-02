#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    getline(cin, s);
    int vp = 0, hp = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '0') {
            cout << "1 " << vp + 1 << endl;
            vp++;
            vp %= 4;
        } else {
            cout << "3 " << hp + 1 << endl;
            hp += 2;
            hp %= 4;
        }
    }

    return 0;
}

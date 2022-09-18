#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    string s;
    map<char, int> pos;
    map<char, int>::iterator it;

    cin >> t;
    cin.ignore();
    while (t--) {
        getline(cin, s);
        pos.clear();
        vector<int> f(s.length() + 1, 0);
        for (int i = 1; i <= s.length(); i++) {
            f[i] = f[i - 1];
            it = pos.find(s[i - 1]);
            if (it != pos.end()) {
                //cout << it->second << ' ' << i << ' ' << f[it->second - 1] << endl;
                f[i] = max(f[i], f[it->second - 1] + 2);
                (*it).second = i;
            } else
                pos.insert(make_pair(s[i - 1], i));
        }
        //for (int i = 1; i < s.length(); i++)
        //    cout << f[i] << ' ';
        //cout << endl;
        cout << s.length() - f[s.length()] << endl;
    }

    return 0;
}

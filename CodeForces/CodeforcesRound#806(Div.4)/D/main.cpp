#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cin.ignore();
        vector<string> as;
        as.resize(n);
        set<string> s;
        for (int i = 0; i < n; i++) {
            getline(cin, as[i]);
            s.insert(as[i]);
        }
        string ans;
        for (int i = 0; i < n; i++) {
            bool iok = false;
            for (int j = 1; j <= as[i].length(); j++) {
                string t1, t2;
                t1 = as[i].substr(0, j);
                t2 = as[i].substr(j);
                if (s.find(t1) != s.end() && s.find(t2) != s.end())
                    iok = true;
            }
            ans.push_back('0' + iok);
        }
        cout << ans << endl;
    }

    return 0;
}

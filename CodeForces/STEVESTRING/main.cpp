#include <bits/stdc++.h>

using namespace std;

char nc(char c1, char c2) {
    return (char)('a' + 'b' + 'c' - c1 - c2);
}

int main()
{
    //cout << nc('a', 'b') << endl;
    int t, pl;
    vector<char> rs;
    string s;
    cin >> t;
    while (t > 0) {
        t--;
        cin >> s;
        rs.clear();
        pl = s.length();
        for (int i = 0; i < pl; i++)
            rs.push_back(s[i]);
        //for (int i = 0; i < rs.size(); i++)
        //    cout << rs[i];
        //cout << endl;
        do {
            if (rs.size() == 1)
                break;
            pl = rs.size();
            for (int i = (pl - 1); i >= 0; i--) {
                if (rs[i] != rs[i - 1]) {
                    //cout << rs[i] << "-" << rs[i - 1] << "\n";
                    rs[i - 1] = nc(rs[i], rs[i - 1]);
                    rs.erase(rs.begin() + i);

                }
            }

        } while (pl != rs.size());
        cout << rs.size() << "\n";
    }

    return 0;
}

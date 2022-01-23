#include <bits/stdc++.h>

using namespace std;

bool cp(string s, int len) {
    for (int i = 0; i < len / 2; i++)
        if (s[i] != s[len - i - 1])
            return false;
    return true;
}

int main()
{
    int t, n;
    string s, tmp;
    cin >> t;
    while (t--) {
        cin >> n;
        set<string> ss;
        set<string>::iterator it;
        vector<string> as;
        cin.ignore();
        bool iok = false;
        for (int i = 0; i < n; i++) {
            getline(cin, s);
            ss.insert(s);
            as.push_back(s);
            if (cp(s, s.length()))
                iok = true;
            tmp = as[i];
            reverse(tmp.begin(), tmp.end());
            if (ss.find(tmp) != ss.end())
                iok = true;
            if (as[i].length() == 3) {
                tmp.clear();
                tmp.push_back(as[i][2]);
                tmp.push_back(as[i][1]);
                if (ss.find(tmp) != ss.end())
                    iok = true;
            }
            if (as[i].length() == 2) {
                tmp.clear();
                tmp.push_back(as[i][1]);
                tmp.push_back(as[i][0]);
                tmp.push_back('0');
                for (char j = 'a'; j <= 'z'; j++) {
                    tmp[2] = j;
                    if (ss.find(tmp) != ss.end())
                        iok = true;
                }
            }
        }
        cout << (iok ? "YES" : "NO") << '\n';
    }

    return 0;
}

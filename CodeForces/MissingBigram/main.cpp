#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n;
    string s, tmp;
    vector<string> sp;
    cin >> t;
    while (t--) {
        cin >> n;
        cin.ignore();
        getline(cin, s);
        sp.clear();
        s.push_back(' ');
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                tmp.clear();
                tmp.push_back(s[i - 2]);
                tmp.push_back(s[i - 1]);
                sp.push_back(tmp);
            }
        }
        int j = 1;
        cout << s[0];
        for (int i = 0; i < (n - 3); i++) {
            cout << sp[i][1];
            j++;
            if (sp[i][1] != sp[i + 1][0]) {
                cout << sp[i + 1][0];
                j++;
            }
        }
        cout << sp[n - 3][1];
        j++;
        if (j < n)
            cout << 'b';
        cout << endl;
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

struct song {
    int rate, pos;
    song(int r, int p) {
        rate = r;
        pos = p;
    }
};

bool cmp(song s1, song s2) {
    return s1.rate < s2.rate;
}

int t, n, a[200002];
vector<song> s1s, s2s;

int main()
{
    string s;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cin.ignore();
        getline(cin, s);
        s1s.clear(); s2s.clear();
        for (int i = 0; i < n; i++) {
            if (s[i] == '1')
                s1s.push_back(song(a[i], i));
            else
                s2s.push_back(song(a[i], i));
        }
        sort(s1s.begin(), s1s.end(), cmp);
        sort(s2s.begin(), s2s.end(), cmp);
        int j = 1;
        for (int i = 0; i < s2s.size(); i++) {
            //cout << s2s[i].rate << "|" << s2s[i].pos << " ";
            a[s2s[i].pos] = j;
            j++;
        }
        //cout << endl;
        for (int i = 0; i < s1s.size(); i++) {
            //cout << s1s[i].rate << "|" << s1s[i].pos << " ";
            a[s1s[i].pos] = j;
            j++;
        }
        //cout << endl;
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }

    return 0;
}

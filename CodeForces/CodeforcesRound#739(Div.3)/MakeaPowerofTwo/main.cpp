#include <bits/stdc++.h>

using namespace std;

int cmo(string s1, string s2) {
    int i = 0, j = 0, c = 0;
    while (true) {
        while (s1[j] != s2[i]) {
            i++;
            c++;
            if (i >= s2.length())
                break;
        }
        if (i >= s2.length())
            break;
        j++;
        i++;
        if (j >= s1.length() || i >= s2.length())
            break;
    }
    if (j >= s1.length() && i < s2.length())
        return c + s2.length() - i;
    return s1.length() - j + c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long t;
    t = 1;
    vector<string> po2;
    while (t <= 1e18) {
        po2.push_back(to_string(t));
        t *= 2;
    }
    cin >> t;
    string n;
    cin.ignore();
    while (t--) {
        getline(cin, n);
        int ans = n.length() + 1;
        for (int i = 0; i < po2.size(); i++)
            ans = min(ans, cmo(po2[i], n));
        cout << ans << endl;
    }

    return 0;
}

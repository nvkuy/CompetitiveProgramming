#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

string make_cor(int a, int b) {
    if (a == 0)
        return "0:1";
    if (b == 0)
        return "1:0";
    int c = gcd(a, b);
    return (to_string(a / c) + ':' + to_string(b / c));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t, n, a, b;
    string s, tmp;
    cin >> t;
    while (t--) {
        map<string, int> cor;
        map<string, int>::iterator it;
        cin >> n;
        cin.ignore();
        getline(cin, s);
        a = b = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'D')
                a++;
            else
                b++;
            tmp = make_cor(a, b);
            //cout << tmp << '|';
            it = cor.find(tmp);
            if (it == cor.end()) {
                cout << "1 ";
                cor.insert(make_pair(tmp, 1));
            } else {
                (it->second)++;
                cout << (it->second) << ' ';
            }
        }
        cout << endl;
    }

    return 0;
}

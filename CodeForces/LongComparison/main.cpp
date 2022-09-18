#include <bits/stdc++.h>

using namespace std;

char cmp(int x1, int x2, int p1, int p2) {
    string s1 = to_string(x1);
    string s2 = to_string(x2);
    if ((s1.length() + p1) == (s2.length() + p2)) {
        if (x1 == x2)
            return '=';
        else {
            while (x1 > x2) {
                p2--;
                if (p1 > p2)
                    return '>';
                x2 *= 10;
            }
            if ((x1 == x2) && (p1 == p2))
                return '=';
            while (x1 < x2) {
                p1--;
                if (p1 < p2)
                    return '<';
                x1 *= 10;
            }
            if ((x1 == x2) && (p1 == p2))
                return '=';
            if (p1 == p2)
                return (x1 > x2 ? '>' : '<');
            return (p1 > p2 ? '>' : '<');
            //s1 = to_string(x1);
            //s2 = to_string(x2);
            //return ((s1.length() + p1) > (s2.length() + p2) ? '>' : '<');
        }
    } else {
        return ((s1.length() + p1) > (s2.length() + p2) ? '>' : '<');
    }
}

int main()
{

    int t, x1, x2, p1, p2;
    cin >> t;
    while (t--) {
        cin >> x1 >> p1;
        cin >> x2 >> p2;
        cout << cmp(x1, x2, p1, p2) << '\n';
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    string s;
    cin >> t;
    cin.ignore();
    while (t--) {
        s.clear();
        getline(cin, s);
        vector<int> mig(2, 0), mag(2, 0);
        int cp = 0;
        for (int i = 0; i < 10; i++) {
            cp++;
            if (s[i] == '1') {
                mig[i % 2]++;
                mag[i % 2]++;
            }
            if (s[i] == '?')
                mag[i % 2]++;
            //cout << "TEST: " << mag[i % 2] << ' ' << mig[1 - (i % 2)] << ' ' << (10 - i) / 2 << endl;
            if (((mag[i % 2] - mig[1 - (i % 2)]) > ((10 - i) / 2)) || ((mag[1 - (i % 2)] - mig[i % 2]) > ((10 - i - 1) / 2))) {
                cout << cp << endl;
                cp = -1;
                break;
            }
        }
        if (cp >= 0)
            cout << cp << endl;
    }

    return 0;
}

    #include <bits/stdc++.h>

    using namespace std;

    bool nt[100001];
    int d[300];

    bool icnt(string s) {

        memset(d, 0, sizeof(d));
        int c = 0;
        for (int i = 0; i < s.length(); i++) {
            if (d[s[i]] == 0)
                if (s[i] >= 'a' && s[i] <= 'z')
                    c++;
            d[s[i]]++;
        }
        //cout << s << "|" << c << endl;
        if (!nt[c])
            return false;

        for (int i = 'a'; i <= 'z'; i++) {
            if (d[i] > 0) {
                //cout << (char)(i) << ":" << d[i] << endl;
                if (!nt[d[i]])
                    return false;
            }
        }

        return true;
    }

    int main()
    {
        //freopen("input.inp", "r", stdin);
        //freopen("output.out", "w", stdout);

        memset(nt, true, sizeof(nt));
        nt[1] = false;
        nt[0] = false;

        for(int i = 2; i * i <= 100001; ++i) {
            if(nt[i] == true) {
                for(int j = i * i; j <= 100001; j += i)
                    nt[j] = false;
            }
        }
        int t;
        string s;
        cin >> t;
        //cin.ignore();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        while (t > 0) {
            t--;
            getline(cin, s);
            //cout << (icnt(s) ? "YES" : "NO") << "\n";
            if (icnt(s))
                cout << "YES";
            else
                cout << "NO";
            cout << '\n';
        }

        return 0;
    }

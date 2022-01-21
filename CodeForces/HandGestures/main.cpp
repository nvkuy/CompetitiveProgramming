#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> s(26);

int main()
{

    //freopen("input.inp", "r", stdin);
    //freopen("output.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, d, t;
    //int c;
    //fscanf(stdin, "%d %d %d", &n, &m, &d);
    cin >> n >> m >> d;
    for (int i = 0; i < n; i++) {
        string st;
        //fscanf(stdin, "%d", &t);
        cin >> t;
        /*for (int j = 0; j < d; j++) {
            fscanf(stdin, "%d", &c);
            //cin >> c;
            st.push_back((char)c);
        }*/
        getline(cin, st);
        s[t].push_back(st);
    }

    for (int i = 0; i < m; i++) {
        //fscanf(stdin, "%d", &t);
        cin >> t;
        string st;
        /*for (int j = 0; j < d; j++) {
            fscanf(stdin, "%d", &c);
            //cin >> c;
            st.push_back((char)c);
        }*/
        getline(cin, st);
        bool fl = true;
        if (!(s[t]).empty()) {
            for (int j = 0; j < (int)((s[t]).size()); j++) {
                if (st == s[t][j]) {
                    fl = false;
                    break;
                }
            }
        }
        //printf("%s\n", st.c_str());
        //fprintf(stdout, "%s\n", (fl ? "GOOD" : "BAD"));
        cout << (fl ? "GOOD" : "BAD") << "\n";
    }

    return 0;
}

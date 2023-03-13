#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

class ttrie {
  public :
    struct node {
        int a[303];
        int value;
        int& operator[] (int i){ return a[i%303]; }
        node() { for (int i=0; i<303; i++) a[i]=0; value=0; }
    };
   
    vector<node> a;
   
    int& operator[] (string &s){
        int pos=0, i, c;
       
        for (i=0; c=s[i]; i++)
        {
            if (a[pos][c]==0) {
                a.push_back(node());
                a[pos][c] = a.size()-1;
            }
            pos=a[pos][c];
        }
        return a[pos].value;
    }
   
    void clear(){ a.clear(); a.push_back(node()); }
    ttrie(){ clear(); }
};

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m));
        ttrie tr;
        for (int i = 0; i < n; i++) {
            string hashSTR;
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];
            hashSTR += to_string(arr[i][0]);
            for (int j = 1; j < m; j++)
                hashSTR += ("|" + arr[i][j]);
            tr[hashSTR] = i + 1;
        }
        for (int i = 0; i < n; i++) {
            int res = 0;
            vector<int> tt(m);
            for (int j = 0; j < m; j++)
                tt[arr[i][j] - 1] = j + 1;
            string hashSTR;
            hashSTR += to_string(tt[0]);
            int tmp = tr[hashSTR];
            if (tmp != 0)
                res = 1;
            for (int j = 1; j < m; j++) {
                hashSTR += "|";
                hashSTR +=  to_string(tt[j]);
                tmp = tr[hashSTR];
                if (tmp != 0) res = j + 1;
                // cout << hashSTR << "->" << tmp << endl;
            }
            // cout << hashSTR << endl;
            cout << res << ' ';
        }
        cout << endl;
    }

    return 0;
}

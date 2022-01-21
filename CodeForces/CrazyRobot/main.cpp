#include <bits/stdc++.h>

using namespace std;

struct cor{
    int x, int y;
    cor(int xi, int yj) {
        x = xi;
        y = yj;
    }
};

vector<cor> lab;
vector<char> li;
vector<vector<char>> fm;

bool check(int x, int y, bool dr) {
    bool cr = cl = true, nb = true;
    if (dr) {
        for (int i = 1; i <= y; i++) {
            if (fm[i][x + 1] != '#')
                cr = false;
            if (fm[i][x - 1] != '#')
                cl = false;
        }
        for (int i = y; i <= m; i++) {
            if (fm[i][x + 1] != '#')
                cr = false;
            if (fm[i][x - 1] != '#')
                cl = false;
        }
    } else {
        for (int i = 1; i <= x; i++) {
            if (fm[y + 1][i] != '#')
                cr = false;
            if (fm[y - 1][i] != '#')
                cl = false;
            for (int i = 1; i <= x; i++) {
            if (fm[y + 1][i] != '#')
                cr = false;
            if (fm[y - 1][i] != '#')
                cl = false;
    }
}

int main()
{

    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i <= n; i++) {
            li.push_back('#');
        }
        fm.push_back(li);
        for (int i = 0; i < n; i++) {
            li.clear(); li.push_back('#');
            for (int j = 0; j < m; j++) {
                scanf("%c", &c);
                if (c == 'L')
                    lab.push_back(cor(j + 1, i + 1));
                li.push_back(c);
            }
            li.push_back('#');
            fm.push_back(li);
        }
        for (int i = 0; i <= n; i++) {
            li.push_back('#');
        }
        fm.push_back(li);
        for (int i = 0; i < lab.size(); i++) {
            for (int )
        }
    }

    return 0;
}

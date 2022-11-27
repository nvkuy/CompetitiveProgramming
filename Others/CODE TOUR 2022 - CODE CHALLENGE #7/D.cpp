#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using uc = unsigned char;

const int SZ = 30000;

uc arr[SZ];
int ptr=0;
string cmd;
stack<int> stk;

int main() {
    char c;
    cmd = "";
    while (cin >> c) {
        for (char v : "+-[]><.") {
            if (c == v) {
                cmd += c;
                break;
            }
        }
    }
    int n = cmd.size();
    int ip = 0;
    while (ip < n) {
        switch (cmd[ip++]) {
            case '+':
                arr[ptr]++; break;
            case '-':
                arr[ptr]--; break;
            case '[':
                stk.push(ip); break;
            case ']':
                if (arr[ptr]) ip = stk.top();
                else stk.pop();
                break;
            case '>':
                ptr++;
                if (ptr == SZ) ptr = 0;
                break;
            case '<':
                ptr--;
                if (ptr < 0) ptr = SZ-1;
                break;
            case '.':
                cout << arr[ptr];
                break;
        }
    }
}
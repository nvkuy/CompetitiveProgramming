#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
#define bit_cnt(x) __builtin_popcountll(x)

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const long long mod = 998244353;
const int max_bit = 30;

long long power(long long num, long long pow)
{
    if (pow == 0)
        return 1;
    if (pow % 2)
        return (num * power(num, pow - 1)) % mod;
    return power((num * num) % mod, pow / 2);
}

struct TrieNode
{
    TrieNode *child[2];
    int cnt;
    TrieNode()
    {
        for (int i = 0; i < 2; i++)
            child[i] = NULL;
        cnt = 0;
    }
};

TrieNode *root;

void trieInsert(const string &s)
{
    int n = s.length();
    TrieNode *p = root;
    for (int i = 0; i < n; ++i)
    {
        int nxt = s[i] - '0';
        if (p->child[nxt] == NULL)
            p->child[nxt] = new TrieNode();
        p = p->child[nxt];
        ++p->cnt;
    }
}

long long trieCount(const string &s)
{
    int n = s.length();
    TrieNode *p = root;
    for (int i = 0; i < n; ++i)
    {
        int nxt = s[i] - '0';
        if (p->child[nxt] == NULL)
            return false;
        p = p->child[nxt];
    }
    return p->cnt;
}

void trieGo(TrieNode *&cur, char c) {
    int id = c - '0';
    cur = cur->child[id];
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        unordered_map<long long, long long> cnt;
        root = new TrieNode();
        vector<long long> a(n);
        long long all_way = (n * n) % mod, sum_val = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            cnt[a[i]]++;
        }
        for (auto p : cnt)
        {
            long long way_equal = (p.second * p.second) % mod;
            sum_val += way_equal * (bit_cnt(p.first) + 1);
            sum_val %= mod;
        }
        // cout << "@equal: " << sum_val << endl;
        for (int num : a)
        {
            string tmp;
            for (long long i = max_bit - 1; i >= 0; i--)
            {
                int j = ((num >> i) & 1);
                tmp.push_back('0' + j);
            }
            trieInsert(tmp);
        }
        for (int k = 0; k < n; k++)
        {
            TrieNode *alice = root, *bob = root;
            long long one_cnt = 0;
            for (long long i = max_bit - 1; i >= 0; i--)
            {
                int j = ((a[k] >> i) & 1);
                long long turn = (((one_cnt + 1) / 2) * 2) + 1, bob_cnt = 0;
                trieGo(alice, '0' + j);
                trieGo(bob, '0' + (1 - j));
                if (j == 1)
                {
                    turn = ((one_cnt / 2) + 1) * 2;
                    one_cnt++;
                }
                if (bob != NULL) bob_cnt = bob->cnt;
                sum_val += (turn * bob_cnt);
                sum_val %= mod;
                bob = alice;
            }
        }
        long long ans = (sum_val * power(all_way, mod - 2)) % mod;
        // cout << "@sum_val: " << sum_val << endl;
        // cout << "@all_way: " << all_way << endl;
        cout << ans << endl;
    }

    return 0;
}
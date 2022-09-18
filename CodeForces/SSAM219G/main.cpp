#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define alphaa "abcdefghijklmnopqrstuvwxyz"
#define ALPHAA "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define faster() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

using namespace std;

typedef double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> II;

const ld pi=2*acos(0);
const ll inf  = LLONG_MAX;
const ll ninf = LLONG_MIN;
const int oo = INT_MAX;
const int noo = INT_MIN;
const int limit = 1e5+5;


int n;
int a[limit];

void init(){
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
}

void process(){
	stack<int> L;
	stack<int> R;
	int leftz[n];
	int right[n];
	L.push(0);
	for(int i=0;i<n;i++){
		while(L.size() && a[L.top()] >= a[i]){
			L.pop();
		}
		if (L.empty()){
			leftz[i] = 0;
		}else leftz[i] = L.top()+1;
		L.push(i);
	}

	R.push(n-1);
	for(int i=n;i>=0;i--){
		while(R.size() && a[R.top()] >= a[i]){
			R.pop();
		}
		if (R.empty()){
			right[i] = n-1;
		}else right[i] = R.top()-1;
		R.push(i);
	}

	ll res = 0;
	for(int i=0;i<n;i++){
		res = max(res , (ll)(1 + right[i] - leftz[i])*a[i]);
	}
	cout << res << endl;

}


int main(){

	faster();
	int T;
	cin >> T;
	while(T--){
		init();
		process();
	}
	return 0;
}

/*
#include <bits/stdc++.h>

using namespace std;

struct col {
    int hi;
    int id;
    col (int h, int cs) {
        hi = h;
        id = cs;
    }
};

stack<col> s;
int l[100001], r[100001], h[100001];

int main()
{

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int t, n;
    long long maxs;
    col coli = col(0, 0);
    //scanf("%d", &t);
    cin >> t;
    while (t--) {
        //scanf("%d", &n);
        cin >> n;
        for (int i = 0; i < n; i++) {
            //scanf("%d", &h[i]);
            cin >> h[i];
            l[i] = i;
            r[i] = i;
        }
        for (int i = 0; i < n; i++) {
            while (!s.empty()) {
                coli = s.top();
                if (coli.hi > h[i]) {
                    r[coli.id] = i - 1;
                    s.pop();
                } else
                    break;
            }
            s.push(col(h[i], i));
        }
        while (!s.empty()) {
            coli = s.top();
            r[coli.id] = n - 1;
            s.pop();
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty()) {
                coli = s.top();
                if (coli.hi > h[i]) {
                    l[coli.id] = i + 1;
                    s.pop();
                } else
                    break;
            }
            s.push(col(h[i], i));
        }
        while (!s.empty()) {
            coli = s.top();
            l[coli.id] = 0;
            s.pop();
        }
        maxs = 0;
        for (int i = 0; i < n; i++) {
            maxs = max(maxs, (long long)(h[i] * (r[i] - l[i] + 1)));
            //cout << r[i] << "|" << l[i] << " ";
        }
        //cout << endl;
        //printf("%ld\n", maxs);
        cout << maxs << "\n";
    }

    return 0;
}
*/

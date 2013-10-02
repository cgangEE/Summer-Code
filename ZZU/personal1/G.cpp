#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cctype>
#include <ctime>

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <stack>
using namespace std;
typedef vector<int> vi;
typedef map<int,int> mii;
typedef long long ll;
template <class T> void checkmax(T &t, T x){if (x > t) t = x;}
template <class T> void checkmin(T &t, T x){if (x < t) t = x;}
template <class T> void _checkmax(T &t, T x){if (t == -1 || x > t) t = x;}
template <class T> void _checkmin(T &t, T x){if (t == -1 || x < t) t = x;}
#define INF (INT_MAX/10)
#define SQR(x) ((x)*(x))
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define iter(v) __typeof((v).begin())
#define foreach(it, v) for (iter(v) it = (v).begin(); it != (v).end(); it++)
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define mid(x, y) ((x+y)/2)
#define vp vector<P>
#define itr iterator
#define N 100

int i,j,k,m,n,l;
string s, t;
map<string, int> mp;
int idx, bg, ed;
vi a[N*2+10];
string pre;

int get(string s){
	int ret=map[s];
	if (ret==0) map[s]=++idx, ret=idx;
	return ret;
}

void solve(){
	bg=mp['sea'], ed=mp['sky'];
	if (bg*ed==0){
		puts("what a pity"); return;
	}

	pre="what a pity";
	repf(i, 2, n-1){
		if (!dfs(bg)){
			cout<<pre<<endl;
			return;
		}
	}

}
int main(){
	while (~scanf("%d", &n) && n){
		idx=0;
		repf(i, 1, n*2) a[i].clear();
		rep(i, n){
		   	cin>>s>>t;
			j=get(s), k=get(t);
			a[j].pb(k), a[k].pb(j);
		}
		solve();
	}
	return 0;
}



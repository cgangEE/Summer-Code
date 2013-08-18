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
template <class T> void checkmax(T &t, T x){ if (x>t) t=x; }
template <class T> void checkmin(T &t, T x){ if (x<t) t=x; }
template <class T> void _checkmax(T &t, T x){ if (t==-1 || x>t) t=x; }
template <class T> void _checkmin(T &t, T x){ if (t==-1 || x<t) t=x; }
#define INF (INT_MAX/10)
#define SQR(x) ((x)*(x))
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define iter(v) __typeof((v).begin())
#define foreach(it, v) for (iter(v) it=(v).begin(); it!=(v).end(); ++it)
#define clr(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define mid(x, y) ((x+y)/2)
#define vp vector<P>
#define itr iterator
#define N 13

int i,j,k,m,n,l;
bool v[(1<<N)+10];
int x[(1<<N)+10];
vi w;

int g(int k){
	int ret=0;
	while (k) ret+=((k&1)?1:0), k>>=1;
	return ret;
}

bool dfs(int i, int d){
	x[d]=i, v[i]=1;
	if (d==(1<<n)){
		return true;
	}
	rep(j, sz(w)){
		if (!v[w[j]^i] && dfs(w[j]^i, d+1)) return true;
	}
	v[i]=0;
	return false;
}

void solve(){
	w.clear();
	rep(i, 1<<n) if (g(i)>=n/2) w.pb(i);
	clr(v, 0);
	if (!dfs(0, 1)) puts("");
	else{
		rep(i, 1<<n){
			rep(j, n) printf("%d", (x[i+1]&(1<<j))?1:0);
			putchar('\n');
		}
	}
}
	
int main(){
	bool first=1;
	while (~scanf("%d", &n) && n){
		if (!first) puts("");
		else first=0;
		solve();
	}
	return 0;
}


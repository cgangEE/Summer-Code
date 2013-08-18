#pragma comment(linker, "/STACK:1024000000,1024000000")
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
#define N 50000
#define C 3

int i,j,k,m,n,l;
vi a[N+10];
int val[N+10], c[N+10];
ll d[2][N+10][C+10];
ll ans;

void dfs(int i, int fa){
	d[c[i]][i][c[i]]=val[i];
	checkmax(ans, (ll)val[i]);

	rep(k, sz(a[i])) if (a[i][k]!=fa){
		int j=a[i][k];
		dfs(j, i);
		rep(r, 2) repf(l, 0, m) if (d[r][i][l]!=-1)
			rep(s, 2) repf(x, 0, m-l) if (d[s][j][x]!=-1)
				if (!(r==0 && s==0 && l+x==m)) 
					checkmax(ans, d[r][i][l]+d[s][j][x]);

		rep(r, 2) repf(l, 0, m-c[i]) if (d[r][j][l]!=-1)
			checkmax(d[r][i][l+c[i]], d[r][j][l]+val[i]);
	}
}

int main(){
	int tests;
	scanf("%d", &tests);
	while (tests--){
		scanf("%d%d", &n, &m);
		rep(i, n) a[i].clear();
		rep(i, n) scanf("%d%d", &val[i], &c[i]);
		rep(i, n-1) scanf("%d%d", &j, &k), a[j].pb(k), a[k].pb(j);
		clr(d, -1), ans=0;
		dfs(0, -1);
		cout<<ans<<endl;
	}
	return 0;
}



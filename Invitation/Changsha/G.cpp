#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <ctime>
using namespace std;
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define pb push_back
#define clr(a, b) memset(a, b, sizeof(a))
#define N 100
#define TT 300

template<class T> T _checkmin(T &a, T b){ if (a==-1 || a>b) a=b; }
template<class T> T _checkmax(T &a, T b){ if (a==-1 || a<b) a=b; }

int i,j,k,m,n,l,t,st,ed;
int s[N+10], c[N+10];
int a[N+10][N+10];
int b[N+10];
int f[N+10][TT+10];

bool cmp(int i, int j){ return s[i]<s[j]; }

int solve(){
	rep(i, n) b[i]=i;
	sort(b, b+n, cmp);
	clr(f, -1);
    rep(i, n) f[i][a[st][i]]=0, f[i][a[st][i]+c[i]]=s[i];
	rep(I, n) rep(J, I) {
		int i=b[I], j=b[J];
		if (s[i]==s[j]) continue;
		repf(k, c[i]+a[j][i], t)
		    if (f[j][k-c[i]-a[j][i]]!=-1)
				_checkmax(f[i][k], f[j][k-c[i]-a[j][i]]+s[i]);
	}
	int ret=0;
	rep(i, n) repf(k, a[i][ed], t)
		if (f[i][k-a[i][ed]]!=-1)
			_checkmax(ret, f[i][k-a[i][ed]]);
	return ret;
}

int main(){
	int tests;
	scanf("%d", &tests);
	repf(test, 1, tests){
		scanf("%d%d%d%d%d", &n, &m, &t, &st, &ed);
		rep(i, n) scanf("%d", &c[i]);
		rep(i, n) scanf("%d", &s[i]);
		clr(a, -1);
		while (m--) 
			scanf("%d%d%d", &i, &j, &k), 
			_checkmin(a[i][j], k), _checkmin(a[j][i], k);
		rep(i, n) a[i][i]=0;
		rep(k, n) rep(i, n) if (a[i][k]!=-1) rep(j, n) if (a[k][j]!=-1)
			_checkmin(a[i][j], a[i][k]+a[k][j]);
		printf("Case #%d:\n%d\n", test, solve());
	}
	return 0;
}

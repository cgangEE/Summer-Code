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

#define N 20000
#define M 100

int i,j,k,m,n,l;
char a[M+10][N+10];
char c[N+10];
int tot, idx;

void dfs(int d){
	if (d==n){
		tot+=n;
		memcpy(a[idx++], c, sizeof(c));
		return;
	}
	if (tot>100000) return;

	repf(i, 'a', 'c'){
		if (d && c[d-1]==i) continue;
		if (d-1 && c[d-2]==i) continue;
	   	c[d]=i;
		dfs(d+1);
	}
}

int main(){
	tot=idx=0;
	scanf("%d", &n);
	dfs(0);
	if (tot>100000) puts("TOO LONG");
	else{
		rep(i, idx) puts(a[i]);
	}
	return 0;
}


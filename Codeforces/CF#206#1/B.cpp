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
#include <deque>
#include <vector>
#include <set>
#include <map>
#include <stack>
using namespace std;
typedef vector<int> vi;
typedef map<int,int> mii;
typedef long long ll;
template <class T> void checkmax(T &t, T x){if (x>t) t=x;}
template <class T> void checkmin(T &t, T x){if (x<t) t=x;}
template <class T> void _checkmax(T &t, T x){if (t==-1 || x>t) t=x;}
template <class T> void _checkmin(T &t, T x){if (t==-1 || x<t) t=x;}
#define INF (INT_MAX/1)
#define SQR(x) ((x)*(x))
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define iter(v) __typeof((v).begin())
#define foreach(it, v) for (iter(v) it = (v).begin(); it!=(v).end(); ++it)
#define clr(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define mid(x, y) ((x+y)/2)
#define vp vector<P>
#define itr iterator 
#define N 20

int i,j,k,m,n,l;
char c[N+10][N+10];

int dfs(int x, int y, bool v, int a, int b){
	a+=c[x][y]=='a'?1:0, b+=(c[x][y]=='b'?1:0);
	if (x==n-1 && y==n-1){
		return a-b+N*N;
	}
	int ret=-1;
	if (x+1<n){
		int k=dfs(x+1, y, !v, a, b);
		if (v) _checkmax(ret, k);
		else _checkmin(ret, k);
	}
	if (y+1<n){
		/*
		if (ret!=-1){
			if (v && ret-N*N>0) return ret;
			if (!v && ret-N*N<0) return ret;
		}
		*/
		int k=dfs(x, y+1, !v, a, b);
		if (v) _checkmax(ret, k);
		else _checkmin(ret, k);
	}
	return ret;
}

int main(){
	while (~scanf("%d", &n)){
		rep(i, n) rep(j, n){
			c[i][j]=getchar();
			while (!isalpha(c[i][j])) c[i][j]=getchar();
		}
		int k=dfs(0, 0, 0, 0, 0)-N*N;
		if (k>0) puts("FIRST");
		else if (k==0) puts("DRAW");
		else puts("SECOND");

	}
	return 0;
}



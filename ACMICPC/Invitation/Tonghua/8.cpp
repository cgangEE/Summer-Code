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
typedef pair<int,int> pii;
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
#define N 20

int i,j,k,m,n,l;
int a[N+10], b[N+10];

pair<int,int> gao(int i, int j, int x, int y, int u, int v, int e){
	if (e==n*2){
		return make_pair(u, v);
	}

	pii ret=make_pair(0,0), g;
	if ((e&1)==0){
		if (i<=j){
			g=gao(i+1, j, x, y, u+a[i], v, e+1);

			if (g.first>ret.first || (g.first==ret.first && g.second<ret.second))
				ret = g;

			g= gao(i, j-1, x, y, u+a[j], v, e+1);

			if (g.first>ret.first || (g.first==ret.first && g.second<ret.second))
				ret = g;

		}
		if (x<=y){
			g = gao(i, j, x+1, y, u+b[x], v, e+1);
			
			if (g.first>ret.first || (g.first==ret.first && g.second<ret.second))
				ret = g;

			g = gao(i, j, x, y-1, u+b[y], v, e+1);

			if (g.first>ret.first || (g.first==ret.first && g.second<ret.second))
				ret = g;
		}
	}
	else{
		if (i<=j){
			g = gao(i+1, j, x, y, u, v+a[i], e+1);

			if (g.second>ret.second || (g.second==ret.second && g.first<ret.second))
				ret = g;

			g = gao(i, j-1, x, y, u, v+a[j], e+1);

			if (g.second>ret.second || (g.second==ret.second && g.first<ret.second))
				ret = g;
		}
		if (x<=y){
			g = gao(i, j, x+1, y, u, v+b[x], e+1);

			if (g.second>ret.second || (g.second==ret.second && g.first<ret.second))
				ret = g;

			g = gao(i, j, x, y-1, u, v+b[y], e+1);

			if (g.second>ret.second || (g.second==ret.second && g.first<ret.second))
				ret = g;

		}
	}
	
	return ret;
}

void solve(){
	pii ret = gao(1, n, 1, n, 0, 0, 0);
	cout<<ret.first<<endl;
}

void init(){
	scanf("%d", &n);
	repf(i, 1, n) scanf("%d", &a[i]);
	repf(i, 1, n) scanf("%d", &b[i]);
}

int main(){
	int ts;
	scanf("%d", &ts);
	while (ts--){
		init();
		solve();
	}	
	return 0;
}



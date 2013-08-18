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
template <class T> void checkmax(T &t, T x){if (x>t) t=x;}
template <class T> void checkmin(T &t, T x){if (x<t) t=x;}
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
#define N 1000


int i,j,k,m,n,l;
int t[4];
bool v[N*N+10];
vi prm;

struct P{
	int x, y;
	bool t[4];
	vi a;
	void gao(){
		clr(t, 1), a.clear();
		scanf("%d%d", &x, y);
		if (v[x]) t[0]=0;
		int n=x;
		rep(i, sz(prm)) if (n%prm[i]==0){
			int k=0, w=1;
			while (n%prm[i]==0) k++, n/=prm[i], w*=prm[i];
			a.pb(k);
			if (v[k+1]) t[1]=0;

		}
		if (n!=1) a.pb(1);
		if (sz(a)!=1) t[1]=t[2]=0;
		
	}
};

P a[N+10];

int main(){
	v[0]=v[1]=1;
	repf(i, 2, N*N) if (!v[i]){
		if (i<=N) prm.pb(i);
		repf(j, i, N/i) v[i*j]=1;
	}

	int tests;
	scanf("%d", &tests);
	while (tests--){
		scanf("%d%d", &n, &m);
		repf(i, 1, n) a[i].gao();
		rep(i, 4) scanf("%d", &t[i]);

	}
	return 0;
}

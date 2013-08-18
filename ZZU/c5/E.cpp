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
#define N 1000

struct P{
	int w, s, i;
	bool in(int ii){
		i=ii;
		bool ret= (scanf("%d%d", &w, &s)==2);

		return ret;
	}
	bool operator <(const P&p)const{
		return w<p.w;
	}
};

int i,j,k,m,n,l;
P a[N+10];
int f[N+10], g[N+10];

void gao(int k){
	if (k==-1) return;
	gao(g[k]);
	printf("%d\n", a[k].i+1);
}

int main(){
	n=0;
	while (a[n].in(n)) n++;

	sort(a, a+n);
	int k=0;
	rep(i, n){
		g[i]=-1, f[i]=1;
		repf(j, 0, i-1) if (a[j].w<a[i].w && a[j].s>a[i].s){
			if (f[j]+1>f[i])
				f[i]=f[j]+1, g[i]=j;
		}
		if (f[i]>f[k]) k=i;
	}
	printf("%d\n", f[k]);
	gao(k);

	return 0;
}



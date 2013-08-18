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
#define N 30
#define M 200
#define C 10

int i,j,k,m,n,l;

struct P{
	int i, t;
	int a[C+10];
	void init(int ii){
		i=ii;
		scanf("%d%d", &a[0], &t);
		repf(j, 1, a[0]) scanf("%d", &a[j]);
	}
	bool operator <(const P&p)const{ return t<p.t; }
};


bool v[M+10];
int t[N+10], now[N+10], ans[N+10];
P a[N+10];

void search(int d){
	if (now[0]+n-d<=ans[0]) return;	
	if (d==n || (t[0] && a[d].t-t[t[0]]>l)){
		if (now[0]>ans[0])
			repf(i, 0, now[0]) ans[i]=now[i];
		return;
	}
	search(d+1);

	int x[C+10]; 
	x[0]=0;
	repf(i, 1, a[d].a[0]) if (!v[a[d].a[i]]) x[++x[0]]=a[d].a[i];
	if (x[0]>2){
		repf(i, 1, x[0]) v[x[i]]=1;
		now[++now[0]]=a[d].i, t[++t[0]]=a[d].t;
		
		search(d+1);

		now[0]--, t[0]--;
		repf(i, 1, x[0]) v[x[i]]=0;
	}
}

int main(){
	int tests;
	scanf("%d", &tests);
	while (tests--){
		scanf("%d%d%d", &n, &m, &l);
		rep(i, n) a[i].init(i+1);
		sort(a, a+n);

		now[0]=ans[0]=t[0]=0;
		clr(v, 0);

		search(0);

		sort(ans+1, ans+1+ans[0]);
		printf("%d\n", ans[0]);
		repf(i, 1, ans[0]){
			printf("%d%c", ans[i], i==ans[0]?'\n':' ');
		}
	}
	return 0;
}



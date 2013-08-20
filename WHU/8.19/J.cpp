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

char s[100];

struct P{
	int i, j, w, t;
	void in(){
		scanf("%d%d%d%s", &i, &j, &w, s);
		if (strcmp("Licensed", s)==0) t=0;
		else if (strcmp("Pirated", s)==0) t=1;
		else if (strcmp("Cracked", s)==0) t=2;
	}
	bool operator <(const P&p)const{ return i<p.i; }
};

int i,j,k,m,n,l;
P a[N+10];
ll f[N+10][2];	//0 licensed	1 pirated

int main(){
	while (~scanf("%d%d", &n, &m)){

		rep(i, m) a[i].in();
		sort(a, a+m);

		clr(f, -1);
		f[1][0]=0;
		rep(i, m) if (a[i].t==0){
			if (f[a[i].i][0]!=-1)
				_checkmin(f[a[i].j][0], f[a[i].i][0]+a[i].w);
		}
		else if (a[i].t==1){
			if (f[a[i].i][0]!=-1)
				_checkmin(f[a[i].j][1], f[a[i].i][0]+a[i].w);
			if (f[a[i].i][1]!=-1)
				_checkmin(f[a[i].j][1], f[a[i].i][1]+a[i].w);
		}
		else if (a[i].t==2){
			if (f[a[i].i][0]!=-1)
				_checkmin(f[a[i].j][0], f[a[i].i][0]+a[i].w);
			if (f[a[i].i][1]!=-1)
				_checkmin(f[a[i].j][1], f[a[i].i][1]+a[i].w);
		}
		ll ans=-1;
		if (f[n][0]!=-1) _checkmin(ans, f[n][0]);
		if (f[n][1]!=-1) _checkmin(ans, f[n][1]);
		if (ans==-1) puts("Offline");
		else{
			puts("Online");
			cout<<ans<<endl;
		}
	}

	return 0;
}



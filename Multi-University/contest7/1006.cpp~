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
#define M 100
#define N 100

int i,j,k,m,n,l;
bool v[N+10];
vi a;

void out(){
	clr(v, 0);
	rep(i, sz(a)) v[a[i]]=1;
	repf(i, 1, n) if (!v[i]) a.pb(i);
	rep(i, sz(a)){
		if (i) putchar(' ');
		printf("%d", a[i]);
	}
	putchar('\n');
}


int x[N+10];

int main(){
	while(~scanf("%d%d", &n, &m)){
		repf(i, 1, n) x[i]=n;

		rep(i, m){
			a.clear();
			k=i%n+1;
			a.pb(k);
			if (x[k]==k){
				x[k]--;
				if (x[k]==0) x[k]=n;
			}
			a.pb(x[k]);

			x[k]--;
			if (x[k]==0) x[k]=n;

			out();
		}
	
	}
	return 0;
}



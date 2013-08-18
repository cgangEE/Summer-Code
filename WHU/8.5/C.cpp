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
#define N 10000

struct P{
	int x, y, i;
	P(){}
	P(int x, int y):x(x), y(y){}
	void init(int ii){
		i=ii; scanf("%d%d", &x, &y); 
	}
	P operator -(const P&p)const{ return P(x-p.x, y-p.y); }
	ll operator *(const P&p)const{ return (ll)x*p.y-(ll)y*p.x; }
	void out(){
		cout<<x<<' '<<y<<endl;
	}
};

int i,j,k,m,n,l;
P a[N+10];
P e;

bool cmp(P a, P b){
	return (a-e)*(b-e)>0; 
}

int main(){
	int tests;
	scanf("%d", &tests);
	while (tests--){
		scanf("%d%d", &n, &m);
	
		repf(i, 1, n){
		   	a[i].init(i);
			if (a[i].y<a[1].y) swap(a[i], a[1]);
		}
		e=a[1];
		sort(a+2, a+1+n, cmp);
		repf(i, 1, m) printf("%d\n", a[i].i);
	}
	return 0;
}



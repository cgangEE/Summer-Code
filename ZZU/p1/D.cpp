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
template <class T>T xabs(T a){ return a<0?-a:a; }
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
#define N 100000

struct P{
	ll x, y;
	P(){}
	P(int x, int y):x(x),y(y){}
	P operator -(const P&p)const{ return P(x-p.x, y-p.y ); }
	ll operator *(const P&p)const{ return x*p.y-y*p.x; }
	void out(){ cout<<x<<' '<<y<<endl; }
};

int i,j,k,m,n,l;
P a[N+10];

int main(){
	while (~scanf("%d", &n)){
		repf(i, 1, n) scanf("%d", &k), a[i]=P(i, k);
		vp b;
		repf(i, 1, n){
			while (sz(b)>1 && (b[sz(b)-1]-b[sz(b)-2])*(a[i]-b[sz(b)-2])>0)
				b.pop_back();
			b.pb(a[i]);
		}
		
		P now(1, 0), ans(1, 2);	
		rep(i, sz(b)-1){
			P p=b[i]-b[i+1];
			p.x=xabs(p.x), p.y=xabs(p.y);

			if (now*p>0){
			   	now=p, ans=P(b[i].x, b[i+1].x);
			}
		}	
		printf("%d %d\n", (int)ans.x, (int)ans.y);
	}
	return 0;
}



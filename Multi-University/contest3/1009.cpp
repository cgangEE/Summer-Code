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
#define N 50

#define eps 1e-7
int sgn(double d){ return d<-eps?-1:d>eps; }

struct P{
	double x, y;
	P(){}
	P(double x, double y):x(x),y(y){}
	void input(){ scanf("%lf%lf", &x, &y); }
	P operator -(const P&p)const{ return P(x-p.x, y-p.y); }
	double operator *(const P&p)const{ return x*p.y-y*p.x; }
};
struct tri{
	P a, b, c;
	vp v;
	void input(){ 
		a.input(), b.input(), c.input();
		v.clear(), v.pb(a), v.pb(b), v.pb(c), v.pb(a);
   	}
};

int i,j,k,m,n,l;
int tests;
tri a[N+10];
int f[N+10];

bool isPointInPolygon(P p, vp &a){
    int w=0;
    rep(i, n){
        int k=sgn((a[i+1]-a[i])*(p-a[i]));
        int d1=sgn(a[i].y-p.y);
        int d2=sgn(a[i+1].y-p.y);
        if (k>0 && d1<=0 && d2>0) w++;
        if (k<0 && d2<=0 && d1>0) w--;
    }
    if (w!=0) return 1;
    return 0;
}

int gao(double x, double y){
	int ret=0;
	rep(i, n) if (isPointInPolygon(P(x, y), a[i].v)) ret++;
	return ret;
}

int main(){
	srand(time(NULL));
	scanf("%d", &tests);
	while (tests--){
		scanf("%d", &n);
		rep(i, n) a[i].input();
		clr(f, 0);
		m=100000;
		rep(i, m){
			double x=(rand()%10001)/100., y=(rand()%10001)/100.;
			f[gao(x,y)]++;
		}
		repf(i, 1, n) printf("%.5lf\n", f[i]*1./m*10000); 
	}
	return 0;
}


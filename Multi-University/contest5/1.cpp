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
	P(double x, double y):x(x), y(y){}
	void in(){ scanf("%lf%lf", &x, &y); }
	void out(){ printf("%lf %lf\n", x, y); }
	P operator +(const P&p)const{ return P(x+p.x, y+p.y); }
	P operator -(const P&p)const{ return P(x-p.x, y-p.y); }
	P operator *(const double k)const{ return P(x*k, y*k); }
	double operator *(const P&p)const{ return x*p.y-y*p.x; }
	double dis()const{ return sqrt(SQR(x)+SQR(y)); }
	P rot()const{ return P(-y, x); }
};

struct L{
	P o, r;
	L(){}
	L (P o, P r):o(o),r(r){}
};

int i,j,k,m,n,l;
P city[N+10], base[N+10];
set<int> st;
double d[N+10];

P GetLineIntersection(P p, P v, P q, P w){
	P u = p-q;
	double t=(w*u)/(v*w);
	return p+v*t;
}

void gao(P p){
	double k=-1;
	repf(i, 1, m) d[i]=(p-base[i]).dis(), _checkmin(k, d[i]);
	repf(i, 1, m) if (sgn(d[i]-k)==0) st.insert(i);
}

void solve(){
	repf(i, 1, n) city[i].in();
	repf(i, 1, m) base[i].in();

	vector<L> v;

	repf(i, 1, m) repf(j, i+1, m) {
		P o=(base[i]+base[j])*0.5;
		P r=(base[j]-base[i]).rot();
		v.pb(L(o, r));
	}

	int qry, i, j;
	scanf("%d", &qry);
	while (qry--){
		scanf("%d%d", &i, &j);
		st.clear();
		gao(city[i]), gao(city[j]);
		rep(k, sz(v)){
			int d1=sgn(v[k].r*(city[i]-v[k].o));
			int d2=sgn(v[k].r*(city[j]-v[k].o));
			if (d1*d2<0){
				gao( GetLineIntersection(v[k].o, v[k].r, city[i], city[j]-city[i]) );
			}
		}
		printf("%d\n", st.size()-1);
	}
}

int main(){
	while (~scanf("%d%d", &n, &m)){
		solve();
	}
	return 0;
}



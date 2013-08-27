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
typedef vector<double> vd;
typedef map<int,int> mii;
typedef long long ll;
template <class T> void checkmax(T &t, T x){ if (x>t) t=x; }
template <class T> void checkmin(T &t, T x){ if (x<t) t=x; }
template <class T> void _checkmax(T &t, T x){ if (t==-1 || x>t) t=x; }
template <class T> void _checkmin(T &t, T x){ if (t==-1 || x<t) t=x; }
#define INF (INT_MAX/10)
#define SQR(x) ((x)*(x))
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (Int i=(a); i>=(b); --i)
#define iter(v) __typeof((v).begin())
#define foreach(it, v) for (iter(v) it=(v).begin(); it!=(v).end(); ++it)
#define clr(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define mid(x, y) ((x+y)/2)
#define vp vector<P> 
#define itr iterator 
#define E 1000
#define N 50

#define eps 1e-10
int sgn(double d){ return d<-eps?-1:d>eps; }

struct P{
	double x, y;
	P(){}
	P(double x, double y):x(x), y(y){}
	P operator +(const P &p)const{ 
		return P(x+p.x, y+p.y); 
	}
	P operator -(const P &p)const{ 
		return P(x-p.x, y-p.y); 
	}
	P operator *(double d)const{ 
		return P(x*d, y*d); 
	}
	P operator /(double d)const{ 
		return P(x/d, y/d); 
	}
	double operator ^(const P&p)const{
		return x*p.x + y*p.y; 
	}
	double operator *(const P&p)const{
		return x*p.y - y*p.x;
	}
	bool operator <(const P&p)const{
		if (sgn(x-p.x)!=0) return x<p.x;
		return y<p.y;
	}
	double distTo(const P&p)const{
		double dx = x - p.x, dy = y - p.y;
		return hypot(dx, dy);
	}
	void in(){
		scanf("%lf%lf", &x, &y);
	}
	void out(){
		printf("%.4lf   %.4lf\n", x, y);
	}
};


struct Tri{
	P p[3];				//three point of triangle...
	double l, r;
	void in(){
		rep(i, 3){ 
			p[i].in(); 
			if (!i || p[i].x<l) l=p[i].x;
			if (!i || p[i].x>r) r=p[i].x;
		}
	}
	bool zero(){
		return sgn((p[1]-p[0])*(p[2]-p[0]))==0;
	}
};

struct Line{
	double x, y;
	int type;
	Line(){}
	Line(P p, int type):x(p.x),y(p.y),type(type){}
	bool operator <(const Line& l)const{
		if (sgn(x-l.x)!=0) return x<l.x;
		if (sgn(y-l.y)!=0) return y<l.y;
		return type>l.type;
	}
};

int i,j,k,m,n,l;
Tri tri[N+10];
double ans[N+10];
int cnt;
vd x;

void init(){
	m=0;
	scanf("%d", &n);

	rep(i, n){
		tri[m].in();
		if (!(tri[m].zero())) m++;
	}
	n=m;
}

bool interSection(P p1, P p2, P p3, P p4){
	double d1=(p2-p1)*(p3-p1), d2=(p2-p1)*(p4-p1);
	double d3=(p4-p3)*(p1-p3), d4=(p4-p3)*(p2-p3);
	int s1=sgn(d1), s2=sgn(d2), s3=sgn(d3), s4=sgn(d4);
	return s1*s2<0 && s3*s4<0;
}

P getInterSection(P p1, P p2, P p3, P p4){
	double d1=(p2-p1)*(p3-p1), d2=(p2-p1)*(p4-p1);
	double d3=(p4-p3)*(p1-p3), d4=(p4-p3)*(p2-p3);
	return (p3*d2-p4*d1)/(d2-d1);
}

void getScanLine(){
	vd tx;
	P c;
	rep(i, n){
		rep(j, 3) tx.pb(tri[i].p[j].x), tx.pb(tri[i].p[j].y);
		repf(j, i+1, n-1)
			rep(k, 3) rep(l, 3)
				if (interSection(tri[i].p[k], tri[i].p[(k+1)%3], 
							tri[j].p[l], tri[j].p[(l+1)%3])){

					tx.pb(getInterSection(tri[i].p[k], tri[i].p[(k+1)%3], 
							tri[j].p[l], tri[j].p[(l+1)%3]).x);

				}
	}
	sort(all(tx));

	x.clear();
	rep(i, sz(tx))
		if (x.empty() || sgn(tx[i]-x.back())!=0)
			x.pb(tx[i]);
}

bool in2(double l, double r, double x, double y){
	return sgn(l-x)>=0 && sgn(y-r)>=0;
}

vector<Line> getArea(double l, double r){
	vector<Line> ret;
	rep(i, n) if (in2(l, r, tri[i].l, tri[i].r)){

		P l1(l, -E), l2(l, E), r1(r, -E), r2(r, E), c1, c2;

		vp x;
		rep(j, 3){
			P a=tri[i].p[j], b=tri[i].p[(j+1)%3];
			if (b<a) swap(a, b);
			if (in2(l, r, a.x, b.x)){
				c1=getInterSection(a, b, l1, l2);
				c2=getInterSection(a, b, r1, r2);
				x.pb(P(c1.y, c2.y));
			}
		}
		sort(all(x));
		rep(i, sz(x)) ret.pb(Line(x[i], i==0?1:-1));
	}
	sort(all(ret));
	return ret;
}

void addToAns(vector<Line> &v, double d){
	int cnt=0;
	rep(i, sz(v)){
		if (cnt) ans[cnt]+=(v[i].x-v[i-1].x+v[i].y-v[i-1].y)*d/2;
		cnt+=v[i].type;
	}
}

void solve(){
	clr(ans, 0);

	rep(i, sz(x)-1){
		vector<Line> v=getArea(x[i], x[i+1]);
		addToAns(v, x[i+1]-x[i]);
	}
	repf(i, 1, n) printf("%.8lf\n", ans[i]);
}


int main(){
	int ts;
	scanf("%d", &ts);
	while(ts--){
		init();
		getScanLine();
		solve();
	}
	return 0;
}


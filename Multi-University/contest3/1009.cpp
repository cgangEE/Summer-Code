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
	void in(){
		rep(i, 3) p[i].in();
	}
};

void getScanLine(){
	vd x;
	P c;
	rep(i, n){
		rep(j, 3) x.pb(tri[i].p[j].x);
		repf(j, i+1, n-1)
			rep(k, 3) rep(l, 3)
				if (interSection(tri[i].p[k], tri[i].p[(k+1)%3], 
							tri[j].p[l], tri[i].p[(l+1)%3], c)){

				}
	}
}

int main(){
	int ts;
	scanf("%d", &ts);
	while(ts--){
		scanf("%d", &n);
		rep(i, n) tri[i].in();
		getScanLine();
	}
	return 0;
}


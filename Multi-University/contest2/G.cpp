#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <set>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <ctime>
#include <cctype>

using namespace std;

#define rep(i, a) for (int i=0; i<(a); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define clr(a, b) memset(a, b, sizeof(a))
#define sz(a) ((int)(a).size())
#define pb push_back

#define N 30

#define eps 1e-9
int sgn(double d){ return d<-eps?-1:d>eps; }

struct P3{
	double x, y, z;
	P3(){}
	P3(double x, double y, double z):x(x),y(y),z(z){}
	void in(){ scanf("%lf%lf%lf", &x, &y, &z); }

	P3 operator +(const P3&p)const{ return P3(x+p.x, y+p.y, z+p.z); }
	P3 operator -(const P3&p)const{ return P3(x-p.x, y-p.y, z-p.z); }
	P3 operator *(const P3&p)const{ return P3(y*p.z-z*p.y, z*p.x-x*p.z, x*p.y-y*p.x); }
	double operator ^(const P3&p)const{ return x*p.x+y*p.y+z*p.z; }
	double len()const{ return sqrt(x*x+y*y+z*z); }
};

struct C{
	P3 o, p, a, b; 
	double r;
	void in(){ 
		o.in(), a.in(), b.in(); 
		p=(a-o)*(b-o);
		r=sqrt((a-o)^(a-o));
	}
};

double linetoline(P3 u1, P3 u2, P3 v1, P3 v2){
	P3 n = u2 * v2;
	if (sgn(n^n)==0) return ((v1-u1)*u2).len()/u2.len();
	return fabs( ((u1-v1)^n) / n.len());
}

int i,j,k,m,n,l;
C a[N+10];

int main(){
	int ts;
	scanf("%d", &ts);
	while (ts--){
		scanf("%d", &n);
		rep(i, n) a[i].in();
		double ans;
		rep(i, n) repf(j, i+1, n-1){
			double d=linetoline(a[i].o, a[i].p, a[j].o, a[j].p);
			double r=a[i].r+a[j].r;
			if ((i==0 && j==1) || d-r<ans) ans=d-r;
		}
		if (sgn(ans)<=0) puts("Lucky");
		else printf("%.2lf\n", ans);
	}
	return 0;
}


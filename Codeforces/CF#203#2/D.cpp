#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cctype>

#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define clr(a, b) memset(a, b, sizeof(a))
#define sz(a) ((int)(a).size())
#define pb push_back

#define N 300000
#define M 1500

int i,j,k,m,n,l;

struct P{
	double x, y;
	P(){}
	P(double x, double y):x(x),y(y){}

	P operator +(const P&p)const{ return P(x+p.x, y+p.y); }
	P operator -(const P&p)const{ return P(x-p.x, y-p.y); }
	double operator ^(const P&p)const{ return x*p.x+y*p.y; }
	double operator *(const P&p)const{ return x*p.y-y*p.x; }
	
	void in(){ scanf("%lf%lf", &x, &y); }
};

struct L{
	P u, v;
	L(){}
	L(P u, P v):u(u),v(v){}
	void in(){ 
		u.in(), v.in(); 
		if (P(1,0)*(v-u)<0) swap(u, v);
	}
};

struct C{
	P o;
	double r;
	void in(){ o.in() scanf("%lf", &r); }
};

L line[N+10];
C circle[M+10];

ll solve(){
	rep(i, m) repf(j, i+1, m-1){
		
	}
}

int main(){
	while (~scanf("%d%d", &n, &m)){
		rep(i, n) line[i].in();
		rep(i, m) circle[i].in();
		cout<<solve()<<endl;
	}
	return 0;
}

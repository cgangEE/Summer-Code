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
#define fill(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define mid(x, y) ((x+y)/2)
#define vp vector<P>
#define itr iterator
#define N 200

double eps =1e-9;
int sgn(double d){ return d<-eps?-1:d>eps; }

struct P{
	int x, y;
	P(){}
	P(int x, int y):x(x),y(y){}
	void input(){ scanf("%d%d", &x, &y); }
	P operator -(const P &p)const{ return P(x-p.x, y-p.y); }
	bool operator ==(const P &p)const { return x==p.x && y==p.y; }
	double operator ^(const P &p)const{ return x*p.x+y*p.y; }
	double operator *(const P &p)const{ return x*p.y-y*p.x; }
	double len(){return sqrt(SQR(x)+SQR(y)); }
};

struct Line{
	P p1, p2;
	void input(){
		p1.input(), p2.input();
	}
};

double point2line(Line l, P p){
	P a=l.p1, b=l.p2;
	return fabs((p-a)*(a-b))/(a-b).len();
}

int i,j,k,m,n,l;
double f[N+10][N+10], d[2][N+10];
int g[N+10][N+10];
Line l1, l2;
int c, ans[N+10];

void gao(int i, int j){
	if (i==0) return;
	if (g[i][j]==1) ans[i]=1, gao(i-1, j-1);
	else ans[i]=2, gao(i-1, j);
}

int main(){
	while (~scanf("%d%d", &n, &c)){
		l1.input(), l2.input();
		clr(g, 0), g[0][0]=1;
		f[0][0]=0;
		repf(i, 1, n){
			P p; p.input();
			scanf("%d", &k);
			d[0][i]=point2line(l1, p)*k, d[1][i]=point2line(l2, p)*k;
			repf(j, 0, i){
				if (j && g[i-1][j-1] && (!g[i][j] || f[i-1][j-1]+d[0][i]<f[i][j]))
					g[i][j]=1, f[i][j]=f[i-1][j-1]+d[0][i];
				if (g[i-1][j] && (!g[i][j] || f[i-1][j]+d[1][i]<f[i][j]))
					g[i][j]=2, f[i][j]=f[i-1][j]+d[1][i];
			}
	   	}
		k=0;
		repf(i, 0, n) if (abs(n-2*i)<=c && g[n][i] && (abs(n-2*k)>c || !g[n][k] || f[n][i]<f[n][k])) k=i;
		gao(n, k);
		repf(i, 1, n) printf("%d%c", ans[i], i==n?'\n':' ');
		puts("");
	}	
	return 0;
}


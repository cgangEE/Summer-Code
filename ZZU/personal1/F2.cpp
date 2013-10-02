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

#define eps 1e-9
int sgn(double d){
	return d<-eps?-1:d>eps;
}

struct P{
	int x, y;
	double k;
	P(){}
	P(int x, int y):x(x),y(y){
		k=x*1./y;
	}
	P operator +(const P&p)const{
		return P(x+p.x, y+p.y);
	}
	int gcd(int a, int b){
		return b==0?a:gcd(b, a%b); 
	}
	int gcd(){ return gcd(x, y); }
	bool operator <(const P&p)const{
		if (x*p.y!=y*p.x) 
		return x*p.y<y*p.x;
		return x<p.x;
	}
	void out(){
		printf("%d/%d ", x, y);
	}
};

int i,j,k,m,n,l,p;


int main(){
	return 0;
}


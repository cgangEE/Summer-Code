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
#define N 200
#define M 100

int i,j,k,m,n,l,r;

struct Mat{
	double a[N+10];
	Mat(){ clr(a, 0); }

	Mat operator *(const Mat & m)const{
		Mat ret;
		rep(i, n){
			rep(j, n) ret.a[i]+=a[(j+n)%n] * m.a[(j+n-i)%n];
		}
		return ret;
	}
	void out(){
		rep(i, n) cout<<a[i]<<' ';
		cout<<endl;
		cout<<endl;
	}
};

Mat gao(int i, int k){
	Mat ret; ret.a[0]=1;
	Mat a;
	rep(j, n){
		if ((j+i)%n==0) a.a[j]+=0.5;
		if ((j-i+n)%n==0) a.a[j]+=0.5;
	}

	while (k){
		if (k&1) ret=ret*a;
		a=a*a;
		k>>=1;
	}
	return ret;
}

int a[M+10];

int main(){
	while (~scanf("%d%d%d%d", &n, &m, &l, &r) && n+m+l+r){
		clr(a, 0);
		while (m--) scanf("%d", &k), a[k]++;
		
		Mat ret; ret.a[0]=1;
		repf(i, 1, 100) if (a[i]){
			ret=ret*gao(i, a[i]);
		}
		double ans=0;
		repf(i, l-1, r-1) ans+=ret.a[i];
		printf("%.4lf\n", ans);
	}
	return 0;
}



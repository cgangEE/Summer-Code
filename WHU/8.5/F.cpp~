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

double eps = 1e-7;
int sgn(double d){ return d<-eps?-1:d>eps; }

int i,j,k,m,n,l;
double d[N+10];
int a[N+10], mul[N+10];

void gao_qry(){
	int k;
	double ret=1;
	
	clr(a, 0);
	clr(mul, 0);

	scanf("%d", &k);
	repf(i, 1, k){
		scanf("%d", &j);
		ret *= d[j];
		mul[i]++;
		a[j]++;
	}
	repf(i, 1, n) repf(j, 1, a[i]) mul[j]--;
	repf(i, 1, n){
		repf(j, 1, mul[i]) ret*=i;
		repd(j, -1, mul[i]) ret/=i;
	}
	k=0;
	while (sgn(ret-1)<0) k++, ret*=10;
	printf("%.5lf x 10^-%d\n", ret, k);
}

int main(){
	int ts;
	scanf("%d", &ts);
	repf(te, 1, ts){
		scanf("%d", &n);
		repf(i, 1, n) scanf("%lf", &d[i]);
		scanf("%d", &m);
		
		printf("Test Case #%d:\n", te);
		while (m--)
			gao_qry();
	}
	return 0;
}



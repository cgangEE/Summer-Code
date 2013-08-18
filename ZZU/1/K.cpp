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
#define N 3000


int i,j,k,m,n,l;
double a[N+10], c[N+10];

double gao(){
	repf(i, 1, n){
		a[i+1]=(2*a[i]+c[i])-a[i-1];
	}
	return a[n+1];
}

int main(){
	while (~scanf("%d", &n)){
		double ends;
		scanf("%lf%lf", &a[0], &ends);
		repf(i, 1, n) scanf("%lf", &c[i]);
		a[1]=0;
		double ans=0, now=fabs(ends-gao());
		for (a[1]=-1000; a[1]<=1000; a[1]+=0.01){
			double k=fabs(gao()-ends);
			if (k<now) now=k, ans=a[1];
		}
		cout<<now<<endl;
		a[1]=ans;
		cout<<gao()<<endl;
		printf("%.2lf\n", ans);
	}
	return 0;
}



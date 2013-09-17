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
#define N 12

#define eps 1e-7
int sgn(double d){
	return d<-eps?-1:d>eps;
}
int i,j,k,m,n,l;

int main(){
	int ts;
	scanf("%d", &ts);
	while (ts--){
		double k;
		int tot=0;
		rep(i, N){
		   	scanf("%lf", &k); 
			j=(int)(k*100);

			if (sgn(j-k*100)==0) tot+=j;
			else if (sgn(j+1-k*100)==0) tot+=j+1;	
			else if (sgn(j-1-k*100)==0) tot+=j-1;
		}

		tot=round(tot/12.);
		putchar('$');
		if (tot%100==0) printf("%d\n", tot/100);
		else if (tot%10==0) printf("%.1lf\n", (double)tot/100);
		else printf("%.2lf\n", (double)tot/100.);
		cout.flush();
	}
	return 0;
}



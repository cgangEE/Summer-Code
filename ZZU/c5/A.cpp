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
#define N 1000

int i,j,k,m,n,l;
bool f[N+1000];
int a[N+10];
int h[50+10];

int main(){
while (~scanf("%d", &n) && n){
	clr(h, 0);

	repf(i, 1, n) scanf("%d", &a[i]), h[a[i]]=i;
	scanf("%d", &m);

	int ans=m;
	
	repf(i, 1, 50) if (h[i]){
		clr(f, 0), f[m]=1;
		repf(j, 1, n) if (j!=h[i]){
			repf(k, 5, m-a[j]) if (f[k+a[j]])
				f[k]=1;
		}
		repf(k, 5, m) if (f[k]) checkmin(ans, k-i);

	}
	printf("%d\n", ans);
}
	return 0;
}



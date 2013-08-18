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
#define N 100000
#define M 10000

int i,j,k,m,n,l;
int s[N+10], a[N+10], f[M+10];


int main(){
	while (~scanf("%d%d", &n, &m)){
		l=0;
		clr(f, -1);
		repf(i, 1, n){
			scanf("%d", &a[i]);
			a[i]=(a[i]%m+m)%m;
			s[i]=(s[i-1]+a[i])%m;
		}
		int ans=0;
		repf(i, 0, n){
			if (f[s[i]]!=-1) checkmax(ans, i-f[s[i]]);
			if (f[s[i]]==-1) f[s[i]]=i;
		}
		printf("%d\n", ans);
	}
	return 0;
}



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
#define E 1000000007
#define N 1000000

int i,j,k,m,n,l;
int a[N+10];
ll f[N+10], g[N+10];

int main(){
	int ts;
	scanf("%d", &ts);
	while (ts--){
		scanf("%d", &n);
		repf(i, 1, n) scanf("%d", &a[i]), a[i]%=E;
		sort(a+1, a+1+n);

		f[0]=1;
		repf(i, 1, n) f[i]=(f[i-1]*a[i])%E;
		g[n+1]=1;
		repd(i, n, 1) g[i]=(g[i+1]*a[i])%E;

		ll ret=(f[n]*n)%E;

		int k=n;
		repf(i, 2, n){
			if (k<=i){
				if (k==i) ret=((ret-f[k-1]*g[k+1]%E)+E)%E;
				break;
			}
			ret=((ret-f[k-1]*g[k+1]%E*2)%E+E)%E;
			k--;
		}
		cout<<ret<<endl;
	}
	return 0;
}



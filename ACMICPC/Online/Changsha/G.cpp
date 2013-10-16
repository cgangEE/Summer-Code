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

#define N 80000
#define e 1000000007

int i,j,k,m,n,l;
bool v[N+10];
int a[N+10][2];
int b[N+10][2];
int c[N+10];	// first *+, second +*
int ans[N+10];
vi prm;

void init(){
	v[0]=v[1]=1;
	repf(i, 2, N) if (!v[i]){
		prm.pb(i);
		repf(j, 2, N/i) v[i*j]=1;
		repf(j, i, N){
			if (j-i<=i && !v[j-i]) a[j][0]=(a[j][0]+1)%e;
			a[j][1]=(a[j][1]+a[j-i][0])%e;
			
			if (j%i==0){
				if (j/i<=i && !v[j/i]){
				   	b[j][0]=(b[j][0]+1)%e;
				}
				b[j][1]=(b[j][1]+b[j/i][0])%e;
			}
		}
	}
	rep(i, sz(prm)){
		repf(j, prm[i], N) ans[j]=(ans[j]+b[j-prm[i]][0])%e;
	}

}

void gao(){
	repf(i, 2, N){
		ans[i]=(ans[i]+((!v[i])?1:0))%e;
		rep(j, 2){
			ans[i]=(ans[i]+a[i][j])%e;
			ans[i]=(ans[i]+b[i][j])%e;
		}
	}
	while (~scanf("%d", &n)){
		printf("%d\n", ans[n]);
	}
}

int main(){
	init();	
	gao();
	return 0;
}




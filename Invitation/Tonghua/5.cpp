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
#define N (1<<16)
#define M 31

int i,j,k,m,n,l;
bool v[N+10];
vi prm, vec;
int f[M+10], x[10];

void dfs(int n, int d, int Min, int Max){
	
//	cout<<Min<<' '<<Max<<endl;
	if (d==3){
		if (Min==0 && Max==n){
//			rep(i, 3) cout<<x[i]<<' ';
//			cout<<endl;
		   	f[n]++;
		}
		
		return;
	}
	repf(i, 0, n) x[d]=i, dfs(n, d+1, min(Min, i), max(Max, i));
}

void init(){
	repf(i, 1, M){
//		cout<<"============================="<<endl;
		dfs(i, 0, i, 0);
//		cout<<"============================="<<endl;
//		cout<<i<<' '<<f[i]<<endl;
	}

	repf(i, 2, N) if (!v[i]){
		prm.pb(i);
		repf(j, 2, N/i) v[i*j]=1;
	}
}

void gao(int m, int n){
	rep(i, sz(prm)) if (m%prm[i]==0){
		k=0;
		while (m%prm[i]==0) m/=prm[i], k++;
		while (n%prm[i]==0) n/=prm[i], k--;
		if (k) vec.pb(k);
	}
	if (m!=1 && n==1) vec.pb(1);
}

void solve(){
	if (m%n!=0){
		puts("0"); return;
	}
	vec.clear();
	gao(m, n);
	int ans=1;
	rep(i, sz(vec)) ans*=f[vec[i]];
	printf("%d\n", ans);
}

int main(){
	init();
	int ts;
	scanf("%d", &ts);
	while (ts--){
		scanf("%d%d", &n, &m);
		solve();
	}
	return 0;
}



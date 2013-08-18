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
#define N 2000

int i,j,k,m,n,l;
int a[N+10];
vi v[N+10];
int b[N+10];
vi s1, s2;

bool dfs(int i){
	if (i>n){
		repf(j, 1, n) printf("%d", b[j]);
		putchar('\n');
	   	return true;
	}

	int k=a[i];
	if (v[k][0]==i || v[k][sz(v[k])-1]==i){
		bool ret;
		if (v[k][0]==i){
			if (sz(s1)<sz(s2) && k!=s2[sz(s1)]) return false;
			b[i]=0, s1.pb(k);
			ret=dfs(i+1);
			s1.pop_back();
			return ret;
		}
		else{
			if (sz(s2)<sz(s1) && k!=s1[sz(s2)]) return false;
			b[i]=1, s2.pb(k);
			ret=dfs(i+1);
			s2.pop_back();
			return ret;
		}
	}

	if (!( sz(s1)<sz(s2) && k!=s2[sz(s1)])){
		b[i]=0, s1.pb(k);
		if (dfs(i+1)) return true;
		s1.pop_back();
	}
	if (!( sz(s2)<sz(s1) && k!=s1[sz(s2)])){
		b[i]=1, s2.pb(k);
		if (dfs(i+1)) return true;
		s2.pop_back();
	}
	return false;
}

int main(){
	int ts;
	scanf("%d", &ts);
	while (ts--){
		scanf("%d", &n);
		repf(i, 1, n) v[i].clear();
		repf(i, 1, n) scanf("%d", &a[i]), v[a[i]].pb(i);

		s1.clear(), s2.clear();
		dfs(1);
	}
	return 0;
}



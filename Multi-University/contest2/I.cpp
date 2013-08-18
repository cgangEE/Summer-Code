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
#define N 102
#define M 102*102

int i,j,k,m,n,l;

vi e[M+10];
int f[M+10], v[M+10];

bool find(int i){
	rep(j, sz(e[i])){
		int k=e[i][j];
		if (!v[k]){
			v[k]=1;
			if (f[k]==-1 || find(f[k])){
				f[k]=i;
				return true;
			}
		}
	}
	return false;
}


int main(){
	while (~scanf("%d%d", &n, &m) && n+m){
		repf(i, 0, 102*102) e[i].clear();
		while (n--){
			scanf("%d%d", &i, &j);
			k=i*102+j, l=(i+1)*102+j;
			if ((i+j)&1) e[k].pb(l);
			else e[l].pb(k);
		}
		while (m--){
			scanf("%d%d", &i, &j);
			k=i*102+j, l=i*102+j+1;
			if ((i+j)&1) e[k].pb(l);
			else e[l].pb(k);
		}
		int ans=0;
		clr(f, -1);
		repf(i, 0, 101) repf(j, 0, 101) if ((i+j)&1){
			clr(v, 0);
			if (find(i*102+j)) ans++;
		}
		printf("%d\n", ans);
	}
    return 0;
}

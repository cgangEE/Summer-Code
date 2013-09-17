#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cctype>
#include <ctime>

using namespace std;
typedef vector<int> vi;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define clr(a, b) memset(a, b, sizeof(a))
#define sz(a) ((int)(a).size())
#define pb push_back

#define N 100

int i,j,k,m,n,l;
vi a[N+10];
int v[N+10], idx;

bool dfs(int i, int dep){
	v[i]=dep;
	rep(k, sz(a[i])){
		int j=a[i][k];
		if (!v[j] && !dfs(j, dep+1)) return false;
		else if ((v[i]-v[j])%2==0) return false;
	}
	return true;
}

bool gao(){
	clr(v, 0);
	repf(i, 1, idx) if (!v[i])
		if (!dfs(i, 1)) return false;
	return true;
}

int main(){
	freopen("A-small-2-attempt0.in", "r", stdin);
	freopen("A.out", "w", stdout);

	int ts;
	scanf("%d", &ts);
	repf(te, 1, ts){
		scanf("%d", &n);
		map<string, int> mp;
		string s, t;
		idx=0;
		repf(i, 1, 2*n) a[i].clear();
		rep(i, n){
		   	cin>>s>>t;
			if (mp[s]==0) mp[s]=++idx;
			if (mp[t]==0) mp[t]=++idx;
			a[mp[s]].pb(mp[t]);
			a[mp[t]].pb(mp[s]);
		}
		printf("Case #%d: %s\n", te, gao()?"Yes":"No");
	}
	return 0;
}


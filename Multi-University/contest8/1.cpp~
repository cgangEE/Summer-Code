#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <map>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <ctime>
#include <cctype>

using namespace std;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define clr(a, b) memset(a, b, sizeof(a))
#define fill(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define mid(x, y) ((x+y)/2)
#define sz(a) ((int)(a).size())

//typedef unsigned __int64 ll;
typedef unsigned long long ll;
typedef vector<int> vi;
template<class T> void _checkmin(T &a, T b){ if (a==-1 || b<a) a=b; }

#define N 400000

struct node{
	int name;
	node *next;
};

int i,j,k,m,n,l;
ll f[N+10], p[N+10], r[N+10];
node pool[N*3+10], *a[N+10];
int idx;

void add(int j, int k){
	node *p = &pool[idx++];
	p->name=k;
	p->next=a[j];
	a[j]=p;
}

template <class T>
struct bigNum{
	static const int L=100;
	int it[L+10];
	void clear(){
		fill(it, 0), it[0]=1;
	}
	bigNum(){
		fill(it, 0), it[0]=1;
	}
	bigNum(T n){
		fill(it, 0);
		while (n){
			it[++it[0]]=n%10;
			n/=10;
		}
		if (!it[0]) it[0]=1;
	}
	bigNum operator +(const bigNum & b)const{
		bigNum ret;
		ret.it[0]=max(it[0], b.it[0])+1;
		repf(i, 1, ret.it[0]){
			ret.it[i]+=it[i]+b.it[i];
			ret.it[i+1]+=ret.it[i]/10;
			ret.it[i]%=10;
		}
		while (ret.it[0]>1 && ret.it[ret.it[0]]==0) ret.it[0]--;
		return ret;
	}
	void add(T k){
		int i=0;
		while (k){
			it[++i]+=k%10;
			k/=10;
		}
		it[0]=max(it[0], i)+2;
		repf(i, 1, it[0]) it[i+1]+=it[i]/10, it[i]%=10;
		while (it[0]>1 && it[it[0]]==0) it[0]--;
	}
	void out(){
		repd(i, it[0], 1) printf("%d", it[i]);
		putchar('\n');
	}
};

bigNum<ll> ans;
ll dp[N+10];
int s[N+10], tot;

struct P{
	ll x, y;
	P(){}
	P(int i){x=s[i], y=dp[i]; }
	P(ll x, ll y):x(x),y(y){}
	P operator -(const P&p)const{ return P(x-p.x, y-p.y); }
	ll operator *(const P&p)const{ return x*p.y-y*p.x; }
};

int find(ll k){
	int x=0, y=tot-1;
	if (x>y) return 0;
	while (x!=y){
		int z=mid(1+x, y);
		if (z==0){
			x=z; continue;
		}
		if (dp[s[z]]-dp[s[z-1]] <=  (f[s[z]]-f[s[z-1]])*k) x=z;
		else y=z-1;
	}
	return x;
}

void dfs(int i, int fa){
	j=find(p[i]);
	dp[i]=dp[j]+(f[i]-f[j])*p[i]+r[i];
	if (i!=1){
		ans.add(dp[i]);
	}

	vi v;
	while (tot>1 && (  P(s[tot-1])-P(s[tot-2])) *(P(i)-P(s[tot-2]))<=0)
		v.pb(p[tot-1]), tot--;
	s[tot++]=i;

	for (node *p=a[i]; p; p=p->next) if (p->name!=fa){
		f[p->name]+=f[i];
		dfs(p->name, i);
	}
	tot--;
	repd(j, sz(v)-1, 0) s[tot++]=v[j];
}

int main(){
	int ts, te=0;
	scanf("%d", &ts);
	while (ts--){
		scanf("%d", &n);
		idx=0;
		repf(i, 1, n) a[i]=NULL;
		repf(i, 1, n) scanf("%I64u%I64u%I64u", &f[i], &p[i], &r[i]);
		rep(i, n-1) scanf("%d%d", &j, &k), add(j, k), add(k, j);
		ans.clear();
		tot=1, s[0]=0;
		dfs(1, -1);
		printf("Case #%d: ", ++te);
		ans.out();
	}
	return 0;
}


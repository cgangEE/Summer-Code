#pragma comment(linker, "/STACK:16777216")
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

struct node{
	int name;
	node *next;
};

int i,j,k,m,n,l;
node pool[N*2+100], *a[N+100];
int idx;
int cnt[N+100];
ll ans, now;

void add(int j, int k){
	node *p = &pool[idx++];
	p->name=k, p->next=a[j];
	a[j]=p;
}

void dfs(int i, int fa){
	now=0;
	for (node *p=a[i]; p; p=p->next) if (p->name!=fa){
		dfs(p->name, i);
		ans+=(ll)cnt[i]*cnt[p->name]*(n-1-cnt[p->name]-cnt[i]);
		cnt[i]+=cnt[p->name];
	}
	cnt[i]++;
}

int main(){
	while (~scanf("%d", &n)){
		idx=0;
		repf(i, 1, n) a[i]=NULL;
		rep(i, n-1){
			scanf("%d%d", &j, &k);
			add(j, k), add(k, j);
		}
		clr(cnt, 0);
		ans=0;
		dfs(1, -1);
		cout<<ans<<endl;
	}
	return 0;
}




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

#define M 4000000
#define N 1000
#define L 1000000

struct P{
	int x, y, z;
	P(){}
	P(int x, int y, int z):x(x),y(y),z(z){}
	bool operator <(const P&p)const{
		return y>p.y;
	}
};

int i,j,k,m,n,l,x,y;
int cnt[1<<4], scr[1<<4], b[4];
int vis[L+10];
bool v[M+10];
int u[1<<4];
P a[1<<4];


int solve(){
	rep(i, 1<<4) a[i]=P(cnt[i], scr[i], i);
	sort(a, a+(1<<4));

	int ret=INT_MIN;

	rep(i, 1<<16){

		int now=0, l=0, m=::m;

		rep(j, 1<<4) if ((1<<j)&i){
			if (a[j].x==0) m=-1;
			l|=a[j].z;
			m--;
			now+=a[j].y;
		}

		if (m<0) continue;

		rep(j, 1<<4) if ((1<<j)&i){
			if (a[j].x==0) continue;
			k=min(a[j].x-1, m);
			m-=k, now+=k*a[j].y;
		}
		if (m!=0) continue;

		rep(j, 4) if (!((1<<j)&l)) now+=b[j];
		checkmax(ret, now);
	}
	return ret;
}

void init(){
	v[0]=v[1]=1;
	repf(i, 2, M) if (!v[i])
		repf(j, 2, M/i) v[i*j]=1;
	rep(i, 1<<4){
		int j=i;
		while (j) scr[i]+=j&1, j>>=1;
	}
}

bool issquare(ll pro){
	ll k=(ll)sqrt(pro+0.);
	return SQR(k)==pro || SQR(k-1)==pro || SQR(k+1)==pro;
}

int gao(int n){
//	if (vis[n]!=-1) return vis[n];
	int cnt=0, sum=0;
	ll pro=1;
	for (int i=1; i*i<=n; ++i) if (n%i==0){
		cnt++, sum+=i, pro*=i;
		if (i*i!=n) cnt++, sum+=n/i, pro*=n/i;
		if (pro==(ll)n*n) pro=1;
	}

	int ret=0;
	if (!v[n]) ret+=1;
	if (!v[cnt]) ret+=1<<1;
	if (!v[sum]) ret+=1<<2;
	if (issquare(pro)) ret+=1<<3;
	return vis[n]=ret;
}

int main(){
	init();
	int ts;
	scanf("%d", &ts);
	while (ts--){
		scanf("%d%d", &n, &m);
		clr(cnt, 0);
	//	clr(vis, -1);
		rep(i, n){
			scanf("%d%d", &x, &y);
			int type=gao(x);
			cnt[type]+=y;
			printf("%d", scr[type]);
			putchar(i==n-1?'\n':' ');
		}
		rep(i, 4) scanf("%d", &b[i]);
		printf("%d\n", solve());
	}
	return 0;
}



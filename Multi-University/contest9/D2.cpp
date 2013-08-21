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
#define N 20

struct P{
	int x, y, z;
	P(){}
	P(int x, int y, int z):x(x),y(y),z(z){}	//floor  value   front
};

int i,j,k,m,n,l,des;
char s[N+10];
ll f[(1<<N)+10][20];
ll ans;
bool v[(1<<N)+10][20];

void gao(){

	queue<P> q; clr(v, 0);
	q.push(P(0,0,0)); f[0][0]=1, v[0][0]=1;
	while (q.size()){
		P p=q.front(); q.pop(), v[p.y][p.z]=0;

		if (s[p.x]=='-'){
			if (p.z) f[p.z>>1]
			P u(p.x+1, p.z>>1, p.z+(p.y^1));
		}
	}
}

void gao(vp &a, int g[(1<<N)+10], int e){
	queue<P> q;  clr(v, 0);
	q.push(P(0,0)), g[0]=1, v[0]=1;
	while (q.size()){
		P p=q.front(); q.pop(), v[p.y]=0;

		if (p.x==sz(a)){
			if (e) ans+=(ll)g[p.y]*f[des^p.y];
			continue;
		}

		repf(j, a[p.x].x, a[p.x].y) if (!(p.y&(1<<j))){
			k=p.y|(1<<j);
			g[k]+=g[p.y];
			if (!v[k]) v[k]=1, q.push(P(p.x+1, k));
		}
	}
}

int main(){
	while (~scanf("%s", s)){
		n=strlen(s);

		if (s[0]=='-' || s[n-1]=='+'){
			puts("0"); continue;
		}

		gao();
		printf("%I64d\n", ans);
	}
	return 0;
}



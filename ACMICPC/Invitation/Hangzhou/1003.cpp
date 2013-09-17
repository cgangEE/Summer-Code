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
#define e 10007

int i,j,k,m,n,l;
int op, x, y, c;
int a[N*4+10][3];
bool g[N*4+10];
int mul[N*4+10], add[N*4+10];

void clear(){
	clr(a, 0), clr(g, 0);
}

#define lson i*2, x, z
#define rson i*2+1, z+1, y

void update(int i, int x, int y, int mul, int add){
		rep(u, 3) rep(v, u+1) a[i][u]=a[i][u]*mul%e;

		int c=add;
		int c2=c*c%e;
		int c3=c2*c%e;
		int det=(y-x+1);

		a[i][2]=(a[i][2]+c3*det+3*c2*a[i][0]+3*c*a[i][1])%e;
		a[i][1]=(a[i][1]+c2*det+2*c*a[i][0])%e;
		a[i][0]=(a[i][0]+c*det)%e;
		
		if (!g[i])
			g[i]=1, ::mul[i]=1, ::add[i]=0;
		
		::mul[i]=::mul[i]*mul%e, ::add[i]=(::add[i]*mul+add)%e;
}

void push_down(int i, int x, int y, int z){
	if (x==y) return;
	if (g[i]){
	   	update(i*2, x, z, mul[i], add[i]);
	   	update(i*2+1, z+1, y, mul[i], add[i]);
		g[i]=0;
	}
}

void ins(int i, int x, int y, int l, int r, int mul, int add){
	if (l==x && y==r){
		update(i, x, y, mul, add);
		return; 
	}
	int z=mid(x, y);
	push_down(i, x, y, z);

	if (r<=z) ins(lson, l, r, mul, add);
	else if (l>z) ins(rson, l, r, mul, add);
	else ins(lson, l, z, mul, add), ins(rson, z+1, r, mul, add);

	rep(u, 3) a[i][u]=(a[i*2][u]+a[i*2+1][u])%e;
}

int qry(int i, int x, int y, int l, int r, int p){
	if (x==l && y==r) return a[i][p];

	int z=mid(x, y);

	push_down(i, x, y, z);
	if (r<=z) return qry(lson, l, r, p);
	else if (l>z) return qry(rson, l, r, p);
	else return ( qry(lson, l, z, p) + qry(rson, z+1, r, p) ) % e;
}

int main(){
	while (~scanf("%d%d", &n, &m) && n+m){
		clear();
		while (m--){
			scanf("%d%d%d%d", &op, &x, &y, &c);
			if (op==1) ins(1, 1, n, x, y, 1, c);	//mul, add
			else if (op==2) ins(1, 1, n, x, y, c, 0);
			else if (op==3) ins(1, 1, n, x, y, 0, c);
			else printf("%d\n", qry(1, 1, n, x, y, c-1));
		}
	}
	return 0;
}



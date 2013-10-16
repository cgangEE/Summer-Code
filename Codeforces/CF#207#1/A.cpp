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

#define N 300000

#define lson i*2, x, z
#define rson i*2+1, z+1, y

int ret[N+10];

template <int SZ>
class SegTree{
	int a[SZ*4+10];
public:
	void clear(){ clr(a, 0); }
	void ins(int i, int x, int y, int l, int r, int k){
		if (a[i]) return;
		if (x==l && y==r){
			a[i]=k;
			return;
		}
		int z=mid(x, y);
		if (r<=z) ins(lson, l, r, k);
		else if (l>z) ins(rson, l, r, k);
		else ins(lson, l, z, k), ins(rson, z+1, r, k);
	}
	void gao(int i, int x, int y, int k){
		if (a[i]!=0) k=a[i];
		if (x==y){
			ret[x]=k;
			return;
		}
		int z=mid(x, y);
		gao(lson, k);
		gao(rson, k);
	}
};

int i,j,k,m,n,l;
SegTree<N> st;

int main(){
	while (~scanf("%d%d", &n, &m)){
		st.clear();
		while (m--){
			scanf("%d%d%d", &i, &j, &k);
			if (k!=i) st.ins(1, 1, n, i, k-1, k);
			if (k!=j) st.ins(1, 1, n, k+1, j, k);
		}
		st.gao(1, 1, n, 0);
		repf(i, 1, n){
			if (i-1) putchar(' ');
			printf("%d", ret[i]);
		}
		putchar('\n');
	}
	return 0;
}


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
template <class T> void checkmax(T &t, T x){ if (x>t) t=x; }
template <class T> void checkmin(T &t, T x){ if (x<t) t=x; }
template <class T> void _checkmax(T &t, T x){ if (t==-1 || x>t) t=x; }
template <class T> void _checkmin(T &t, T x){ if (t==-1 || x<t) t=x; }
#define INF (INT_MAX/10)
#define SQR(x) ((x)*(x))
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define iter(v) __typeof((v).begin())
#define foreach(it, v) for (iter(v) it=(v).begin(); it!=(v).end(); ++it)
#define clr(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define sz(a) ((int)(a).size())
#define mid(x, y) ((x+y)/2)
#define vp vector<P>
#define itr iterator
#define N 30000

#define lson i*2, x, z
#define rson i*2+1, z+1, y

template<int SZ>
class SegTree{
	int a[SZ*4+10];
	ll s[SZ*4+10];
	void update(int i, int x, int y, int z){
		a[i*2]=a[i*2+1]=a[i];
		s[i*2]=(z-x+1ll)*a[i], s[i*2+1]=(y-z+0ll)*a[i];
		a[i]=0;
	}
public:
	void clear(){ clr(a, 0), clr(s, 0); }
	void build(int i, int x, int y){
		if (x==y){
			scanf("%d", &a[i]), s[i]=a[i];
			return;
		}
		int z=mid(x, y);
		build(lson), build(rson);
		s[i]=s[i*2]+s[i*2+1];
	}
	void out(int i, int x, int y){
		if (x==y){
			if (x-1) putchar(' ');
			printf("%d", a[i]);
			return;
		}
		int z=mid(x, y);
		if (a[i]) update(i, x, y, z);
		out(lson), out(rson);
		s[i]=s[i*2]+s[i*2+1];
	}
	void ins(int i, int x, int y, int l, int r, int k){
		if (x==l && y==r){
			a[i]=k, s[i]=(y-x+1ll)*k;
			return;
		}
		int z=mid(x, y);
		if (a[i]) update(i, x, y, z);

		if (r<=z) ins(lson, l, r, k);
		else if (l>z) ins(rson, l, r, k);
		else ins(lson, l, z, k), ins(rson, z+1, r, k);
		s[i]=s[i*2]+s[i*2+1];
	}
	ll qry(int i, int x, int y, int l, int r){
		if (x==l && y==r) return s[i];

		int z=mid(x, y);
		if (a[i]) update(i, x, y, z);

		ll ret;
		if (r<=z) ret=qry(lson, l, r);
		else if (l>z) ret=qry(rson, l, r);
		else ret=qry(lson, l, z)+ qry(rson, z+1, r);
		s[i]=s[i*2]+s[i*2+1];
		return ret;
	}
};

int i,j,k,m,n,l;
SegTree<N> st;

int main(){
	while (~scanf("%d%d", &n, &m)){
		st.clear();
		st.build(1, 1, n);
		ll sum=st.qry(1, 1, n, 1, n);
		while (m--){
			scanf("%d%d", &i, &j);
			ll k=st.qry(1, 1, n, i, j);
			if (st.qry(1, 1, n, 1, n)<=sum) 
				k=(k>=0?(k+j-i)/(j-i+1):k/(j-i+1));
			else k=(k>=0?k/(j-i+1):(k-(j-i))/(j-i+1));
			st.ins(1, 1, n, i, j, k);
		}
		st.out(1, 1, n);	
		printf("\n\n");
	}
	return 0;
}

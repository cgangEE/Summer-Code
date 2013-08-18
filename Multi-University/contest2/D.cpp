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
#define all(a) a.begin(), a.end()
#define mid(x, y) ((x+y)/2)
#define vp vector<P>
#define N 50001

#define lson i*2, x, z
#define rson i*2+1, z+1, y

template<int SZ>
class SegTree{
	int a[SZ*4+10], b[SZ*4+10];
	void update(int i, int x, int y, int z){
		a[i*2]=(z-x+1)*b[i], a[i*2+1]=(y-z)*b[i];
		b[i*2]=b[i*2+1]=b[i];
		b[i]=-1;
	}
public:
	void clear(){
		clr(a, 0), clr(b, -1);
	}
	void ins(int i, int x, int y, int l, int r, int c){
		if (x==l && y==r){
			a[i]=(y-x+1)*c, b[i]=c; 
			return;
		}
		int z=mid(x, y);

		if (b[i]!=-1) update(i, x, y, z);

		if (r<=z) ins(lson, l, r, c);
		else if (l>z) ins(rson, l, r, c);
		else ins(lson, l, z, c), ins(rson, z+1, r, c);
		a[i]=a[i*2]+a[i*2+1];
	}
	int find(int i, int x, int y, int l, int r){
		if (x==l && y==r) return (y-x+1-a[i]);
		int z=mid(x, y);
		
		if (b[i]!=-1) update(i, x, y, z);

		if (r<=z) return find(lson, l, r);
		else if (l>z) return find(rson, l, r);
		else return find(lson, l, z) + find(rson, z+1, r);
	}
	int gao(int i, int x, int y, int l, int k){
		if (x==y) return x;
		int z=mid(x, y);
		if (b[i]!=-1) update(i, x, y, z);
		if (l<=z){
			int lk=find(lson, l, z);
			if (lk>=k) return gao(lson, l, k);
			else return gao(rson, z+1, k-lk);
		}
		else return gao(rson, l, k); 
	}
};

int i,j,k,m,n,l,x,y;
SegTree<N> st;

int main(){
	int tests;
	scanf("%d", &tests);
	while (tests--){
		scanf("%d%d", &n, &m);
		st.clear();
		while (m--){
			scanf("%d%d%d", &i, &j, &k), j++;
			if (i==1){
				int w=st.find(1, 1, n, j, n);
				if (w==0)
					puts("Can not put any one.");
				else{
					x=st.gao(1, 1, n, j, 1);
					y=st.gao(1, 1, n, j, min(w, k));

					printf("%d %d\n", x-1, y-1);
					st.ins(1, 1, n, x, y, 1);
				}
			}
			else{
				k++;
				printf("%d\n", k-j+1-st.find(1, 1, n, j, k));
				st.ins(1, 1, n, j, k, 0);
			}
		}
		puts("");
	}
	return 0;
}

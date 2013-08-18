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

int i,j,k,m,n,l;

struct Q{
	int i, x, y, ret;
	void init(int ii){
		i=ii;
		scanf("%d%d", &x, &y);
	}
	bool operator <(const Q&p)const{
		return y<p.y;
	}
};

template <int SZ>
struct BIT{
	int a[SZ+10];
	void clear(){ clr(a, 0); }
	void ins(int x, int k){
	//	cout<<" FT "<<x<<' '<<k<<endl;
		while (x<=n){
			a[x]+=k;
			x+=x&-x;
		}
	}
	int qry(int x){
		int ret=0;
		while (x>0){
			ret+=a[x];
			x-=x&-x;
		}
		return ret;
	}
};

int a[N+10], b[N+10];
Q q[N+10];
int f[N+10];
BIT<N> bit;

bool cmp(Q a, Q b){
	return a.i<b.i;
}

int find(int i){
	if (f[i]==i) return i;
	return f[i]=find(f[i]);
}


void gao(int k, int pre, int l){
	if (l<1 || l>n || b[l]>pre) return;
	bit.ins(n+1-b[l], -1);
	f[l]=k;
}

int main(){
	int tests;
	scanf("%d", &tests);
	while (tests--){
		scanf("%d%d", &n, &m);
		repf(i, 1, n) scanf("%d", &a[i]), b[a[i]]=i;
		repf(i, 1, m) q[i].init(i);
		sort(q+1, q+1+m);
		
		bit.clear();
		int pre=1;
		repf(i, 1, n) f[i]=i;
		repf(i, 1, m){
			for (; pre<=q[i].y; ++pre){
				k=a[pre];
				gao(k, pre, k-1);
				gao(k, pre, k+1);
				bit.ins(n+1-pre, 1);
			}
			q[i].ret=bit.qry(n+1-q[i].x);
		}
		
		sort(q+1, q+1+m, cmp);
		repf(i, 1, m) printf("%d\n", q[i].ret);
	}
	return 0;
}



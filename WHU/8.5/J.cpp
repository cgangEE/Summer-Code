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
#define N 100

int i,j,k,m,n,l;
char s[100], t[100];
int a[24*60+100];

#define lson i*2, x, z
#define rson i*2+1, z+1, y

template<int SZ>
struct SegTree{
	int a[SZ*4+10], b[SZ*4+10];
	void clear(){ clr(a, 0), clr(b, 0); }
	void update(int i){
		a[i*2]+=b[i], b[i*2]+=b[i];
		a[i*2+1]+=b[i], b[i*2+1]+=b[i];
		b[i]=0;
	}
	void ins(int i, int x, int y, int l, int r){
		if (x==l && y==r){
			a[i]+=1, b[i]+=1;
			return;
		}
		if (b[i]) update(i);
		int z=mid(x, y);
		if (r<=z) ins(lson, l, r);
		else if (l>z) ins(rson, l, r);
		else ins(lson, l, z), ins(rson, z+1, r);
	}
	void gao(int i, int x, int y){
		if (x==y){
			::a[x]=a[i];
			return;
		}
		if (b[i]) update(i);
		int z=mid(x, y);
		gao(lson), gao(rson);
	}
};

SegTree<24*60> st;

void out2(int k){
	if (k<10) putchar('0');
	printf("%d", k);
}

void out(int k){
	out2(k/60), putchar(':'), out2(k%60);
}

int gao2(char *s){
	return (s[0]-'0')*10+s[1]-'0';
}

int gao(char *s){
	return gao2(s)*60+gao2(s+3);
}

int main(){
	int tests;
	scanf("%d", &tests);
	while (tests--){
		scanf("%d", &n);
		st.clear();
		rep(i, n){
			scanf("%s%s", s, t);
			j=gao(s), k=gao(t);
			st.ins(1, 0, 24*60, j, k);
		}
		st.gao(1, 0, 24*60);
		int k=0, bg=0, ed=0;
		rep(i, 24*60){
			if (a[i]>a[k]) k=i, bg=ed=i;
			else if (a[i]==a[k] && i==ed+1) ed++;
		}
		out(bg), putchar(' '), out(ed);
		putchar('\n');
	}
	return 0;
}


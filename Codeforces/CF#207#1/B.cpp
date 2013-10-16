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
#define N 1000000
#define M 26

int gcd(int a, int b){ return b==0?a:gcd(b, a%b); }

int i,j,k,m,n,l,x,y;
char p1[N+10], p2[N+10], *s, *t;


struct node{
	int val;
	node * lc, *rc;
};

node *st[M][N];

#define lson p->lc, x, z
#define rson p->rc, z+1, y

void ins(node * &p, int x, int y, int k){
	if (p==NULL){
		p=(node*)malloc(sizeof(node));
		p->val=0, p->lc=p->rc=NULL;
	}
	p->val++;
	if (x==y) return;
	int z=mid(x, y);
	if (k<=z) ins(lson, k);
	else ins(rson, k);
};

int qry(node *p, int x, int y, int l, int r){
	if (p==NULL) return 0;
	if (x==l && y==r){
	   	return p->val;
	}
	int z=mid(x, y);
	if (r<=z) return qry(lson, l, r);
	else if (l>z) return qry(rson, l, r);
	else return qry(lson, l, z)+qry(rson, z+1, r);
}


void gao(){
	int g=gcd(x, y);
	int L=y*2/g;

	rep(i, M) rep(j, g) st[i][j]=NULL;
	rep(i, y*2) {
		ins(st[t[i%y]-'a'][i%g], 0, L, i/g);
	}

	ll ret=0;
	rep(i, x){
		ret+=qry(st[s[i]-'a'][i%g], 0, L, i/g, i/g+y/g-1);
	}
	cout<<(ll)n*x-ret*n*g/y<<endl;
}

int main(){
	s=p1, t=p2;
	while (~scanf("%d%d", &n, &m)){
		scanf("%s%s", s, t);
		x=strlen(s), y=strlen(t);
		if (x>y){
			char *c=s;
			c=s, s=t, t=c;
			swap(x, y), swap(n, m);
		}
		gao();
	}
	return 0;
}


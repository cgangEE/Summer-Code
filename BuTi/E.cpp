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
#define N 1000
#define M 1000

struct P{
	int x, y, k, w;
	bool f[4];
	void in(){ 
		scanf("%d%d", &x, &y); 
		clr(f, 1), k=0;
	}
	bool operator <(const P&p)const{ return k>p.k; }
};

int i,j,k,m,n,l;
P a[N+10];
int b[4], f[N+10];
bool v[M+10];
vi prm;

int gao2(){
	int ret=INT_MIN;
	sort(a, a+n);
	rep(i, 1<<16){
		k=0, l=0;
		rep(j, 16) if (i&(1<<j)) k++, l|=j;
		if (k>m) continue;

		int r=m-k;

		int now=0;
		rep(j, 4) if (!(l&(1<<j))) now+=b[i];
		rep(j, 16) if (i&(1<<j)){
			rep(k, n)
			if (a[k].w==j){
				a[k].y--;
				now+=a[k].k;
				break;
			}
		}


		rep(k, n){
			bool flag=false;
			rep(J, 4){
				int j=1<<J;
				if ((j&a[k].w) && !(j&l)){
				   	flag=true;
					break;
				}
			}
			if (r==0) break;
			if (flag) continue;

			int u=min(r, a[k].y);
			now+=a[k].k*u;
			r-=u;
		}
		rep(j, 16) if (i&(1<<j)){
			rep(k, n)
			if (a[k].w==j){
				a[k].y++;
				break;
			}
		}
		checkmax(ret, now);
	}
	return ret;
}

void gao(){
	rep(I, n){
		int i=a[I].x;
		int num=0, g=1;

		if (v[i]) a[I].f[0]=0;

		rep(J, sz(prm)){
			int j=prm[J];
			if (i%j==0){
				int k=0, l=1;
				while (i%j==0) i/=j, k++, l*=j;
				if (v[k+1]) a[I].f[1]=0;
				if (v[(l*j-1)/(j-1)]) a[I].f[2]=0;

				f[num++]=k, g*=k;
			}
		}
		if (i!=1){
			f[num++]=1;
			if (v[m+1]) a[I].f[2]=0;
		}
		if (num>1 || num==0)
			a[I].f[1]=a[I].f[2]=0;

		rep(j, num) if ((g/f[j])%2==1 && (f[j]*(f[j]+1)/2%2==1)){
			a[I].f[3]=0; break;
		}


		rep(j, 4) if (a[I].f[j]) a[I].k++;

		a[I].w=0;
		repd(j, 3, 0) a[I].w=a[I].w*2+(a[I].f[j]?1:0);

		printf("%d%c", a[I].k, I==n-1?'\n':' ');
	}
	printf("%d\n", gao2());
}

void init(){
	v[0]=v[1]=1;
	repf(i, 2, M) if (!v[i]){
		prm.pb(i);
		repf(j, 2, M/i) v[i*j]=1;
	}
}

void getIn(){
	scanf("%d%d", &n, &m);
	rep(i, n) a[i].in();
	rep(i, 4) scanf("%d", &b[i]);
}

int main(){
	init();
	int ts;
	scanf("%d", &ts);
	while (ts--){
		getIn();
		gao();
	}
	return 0;
}



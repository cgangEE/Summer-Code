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
#define N 18 

int i,j,k,m,n,l;
char s[N+10];
vi v[N+10];
int pre[1<<N][N+10];

void extgcd(int a, int b, int &x, int &y){
	if (!b){ x=1, y=0; }
	else {extgcd(b, a%b, y, x), y-=x*(a/b); }
}

string ans;
int u, w;

void gao(int i, int j){
	if (i==0) return;
	int k=pre[i][j];

	int x=i-(1<<k), y=((j-s[k])%17+17)%17;
	y=y*u%17;


	gao(x, y);
	ans+=s[k]+'0';
}

int main(){
	extgcd(10, 17, u, w);
	u=(u+17)%17;

	while (~scanf("%s", s)){
		n=strlen(s);
		rep(i, n) s[i]-='0';

		repf(i, 0, n) v[i].clear();
		rep(i, 1<<n){
			j=i, k=0;
			while (j) k+=(j&1), j>>=1;
			v[k].pb(i);
		}

		clr(pre, -1);
		pre[0][0]=0;
		repf(I, 1, n) rep(ii, sz(v[I])){
			int i=v[I][ii];
			rep(j, n) if ((1<<j)&i) rep(k, 17) if (pre[i-(1<<j)][k]!=-1){
				if ((i-(1<<j)==0) && s[j]==0) continue;
				int l=(k*10+s[j])%17;
				pre[i][l]=j;
			}
		}
		if (pre[(1<<n)-1][0]==-1) puts("-1");
		else {
			ans="";
			gao((1<<n)-1, 0);
			cout<<ans<<endl;
		}
	}
	return 0;
}



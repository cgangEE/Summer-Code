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
#define N 36

int i,j,k,m,n,l,x;
char a[N+10];
char e[N+10][16][43];
int f[16][43];
char s[1000];

bool gao(int l){
	rep(x, 16) rep(y, 43) if (e[l][x][y]=='*' && f[x][y]==1) return true;
	return false;
}

int main(){
	while (~scanf("%d%d", &n, &m)){
		mii mp;
		rep(i, n){
			a[i]=getchar();
			while (!isalpha(a[i]) && !isdigit(a[i])) a[i]=getchar();
			mp[a[i]]=i;
		}
		rep(i, n){
			rep(j, 16) rep(k, 43){
				e[i][j][k]=getchar();
				while (strchr("*.", e[i][j][k])==NULL)
					e[i][j][k]=getchar();
			}
			rep(k, 43){ 
				char ch=getchar();
				while (strchr("*.", ch)==NULL) ch=getchar();
			}
		}
		rep(i, m){
			scanf("%s", s);
			k=strlen(s);	
			clr(f, 0);
			rep(j, k){
				l=mp[s[j]];
				rep(x, 16) rep(y, 43) if (e[l][x][y]=='*')
					f[x][y]++;
			}
			string ans;
			rep(j, k){
				l=mp[s[j]];
				ans+=(gao(l)?'Y':'N');
			}
			cout<<"Query "<<i+1<<": "<<ans<<endl;
		}
	}
	return 0;
}


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
#define N 16

int i,j,k,m,n,l;
int tests;
char s[N+10];
int f[1<<N+1], w[N+10];
bool vv[1<<N+1];

bool ok(){
	int i=1, j=w[0];
	while (i<j){
		if (s[w[i]]!=s[w[j]]) return false;
		i++, j--;
	}
	return true;
}

int main(){
	scanf("%d", &tests);
	while (tests--){
		scanf("%s", s);
		n=strlen(s);
		clr(vv, 0);
		rep(i, 1<<n){
			w[0]=0;
			rep(j, n) if (i&(1<<j)) w[++w[0]]=j;
			if (ok())vv[i]=1;
		}
		clr(f, -1);
		f[0]=0;
		rep(i, 1<<n) if (vv[i])
			rep(j, 1<<n) if (f[j]!=-1 && (i&j)==0){
				k=i|j;
				if (f[k]==-1 || f[k]>f[j]+1) 
					f[k]=f[j]+1;
			}
		printf("%d\n", f[(1<<n)-1]);
	}
	return 0;
}

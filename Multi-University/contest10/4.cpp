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
#define N 3000000

int i,j,k,m,n,l;
int f[N+10], s[N+10], t[N+10], ans[N+10];

void gao(){
	clr(f, 0);
	clr(s, 0), clr(t, 0);
	clr(ans, 0);

	rep(i, n){
	char ch=getchar();
	while (strchr("IDLRQ", ch)==NULL) ch=getchar();

	switch (ch){
		case 'I':
			scanf("%d", &k);
			s[++s[0]]=k;
			f[s[0]]=f[s[0]-1]+k;
			ans[s[0]]=max(f[s[0]], s[0]==1?f[s[0]]:ans[s[0]-1]);
			break;
		case 'D':
			if (s[0]) --s[0];
			break;
		case 'L':
			if (s[0]){
				k=s[s[0]--];
				t[++t[0]]=k;
			}
			break;
		case 'R':
			if (t[0]){
				k=t[t[0]--];
				s[++s[0]]=k;
				f[s[0]]=f[s[0]-1]+k;
				ans[s[0]]=max(f[s[0]], s[0]==1?f[s[0]]:ans[s[0]-1]);
			}
			break;
		case 'Q':
			scanf("%d", &k);
			printf("%d\n", ans[k]);
	}
	}
}

int main(){
	while (~scanf("%d", &n)){
		gao();
	}
	return 0;
}



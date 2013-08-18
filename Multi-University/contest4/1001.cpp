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

int i,j,k,m,n,l;
int f[N+10][N+10];
char s[N+10];

int main(){
	int tests;
	scanf("%d", &tests);
	repf(test, 1, tests){
		scanf("%s", s);
		n=strlen(s);
		clr(f, 0);
		repf(i, 1, n) f[i][i]=1;
		repf(k, 2, n) repf(i, 1, n-k+1){
			j=i+k-1;
			f[i][j]=(f[i+1][j]+f[i][j-1]-f[i+1][j-1]+10007)%10007;
			if (s[i-1]==s[j-1])
					f[i][j]=(f[i][j]+1+f[i+1][j-1])%10007;
		}
		printf("Case %d: %d\n", test, f[1][n]);
	}
	return 0;
}



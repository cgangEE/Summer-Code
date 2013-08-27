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
char a[N+10][N+10];
char b[N+10][N+10];

int main(){
	int test=0;
	while (~scanf("%d%d", &n, &m) && n+m){
		clr(a, 0), clr(b, 0);
		repf(i, 1, n) repf(j, 1, m) {
			a[i][j]=getchar();
			while (a[i][j]!='*' && a[i][j]!='.') a[i][j]=getchar();
		}
		repf(i, 1, n) repf(j, 1, m){
			if (a[i][j]=='*') b[i][j]='*';
			else{
				b[i][j]='0';
				repf(x, -1, 1) repf(y, -1, 1) if (a[i+x][j+y]=='*')
					b[i][j]++;
			}
		}
		if (test) puts("");
		printf("Field #%d:\n", ++test);
		repf(i, 1, n){
			repf(j, 1, m) putchar(b[i][j]);
			puts("");
		}

	}
	return 0;
}



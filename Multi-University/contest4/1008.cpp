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
#define N 10086

int i,j,k,m,n,l;
char s[N+10];
int f[N+10];

bool ok(int i){
	if (s[i]=='h' && s[i+1]=='e' && s[i+2]=='h' && s[i+3]=='e') return true;
	return false;
}

int main(){
	int tests;
	scanf("%d", &tests);
	repf(test, 1, tests){
		scanf("%s", s);
		n=strlen(s);
		clr(f, 0);
		repf(i, 0, 3) f[i]=1;
		repf(i, 4, n){
			if (ok(i-4)) f[i]=(f[i-1]+f[i-4])%10007;
			else f[i]=f[i-1];
		}
		printf("Case %d: %d\n", test, f[n]);

	}
	return 0;
}



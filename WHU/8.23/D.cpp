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

int i,j,k,m,n,l;
char s[100], t[100];
int a[10];

char ss[3][30]={"Emperor Penguin", "Macaroni Penguin", "Little Penguin"};

int main(){
	while (~scanf("%d\n", &n)){
		clr(a, 0);
		rep(i, n){
		   	scanf("%s%s", s, t);
			if (strcmp(s, "Emperor")==0) a[0]++;
			else if (strcmp(s, "Macaroni")==0) a[1]++;
			else if (strcmp(s, "Little")==0) a[2]++;
		}
		k=0;
		rep(i, 3) checkmax(k, a[i]);
		rep(i, 3) if (k==a[i]){
			puts(ss[i]);
			break;
		}
	}
	return 0;
}



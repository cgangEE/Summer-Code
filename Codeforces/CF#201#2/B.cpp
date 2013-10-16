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
template <class T> void checkmax(T &t, T x){ if (x > t) t = x; }
template <class T> void checkmin(T &t, T x){ if (x < t) t = x; }
template <class T> void _checkmax(T &t, T x){ if (t == -1 || x > t) t = x; }
template <class T> void _checkmin(T &t, T x){ if (t == -1 || x < t) t = x; }
#define INF (INT_MAX/10)
#define SQR(x) ((x)*(x))
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define iter(v) __typedef((v).begin())
#define foreach(it, v) for (iter(v) it = (v).begin(); it!=(v).end(); ++it)
#define clr(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define mid(x, y) ((x+y)/2)
#define vp vector<P>
#define itr iterator
#define N 100000

int i,j,k,m,n,l;
int a[N+10], f[N+10], v[N+10];

int main(){
	while (~scanf("%d", &n)){
		rep(i, n) scanf("%d", &a[i]);
		clr(v, 0);
		clr(f, 0);
		rep(i, n) if (!v[i]){
			k=0, j=i;
			while (!v[j])
				v[j]=1, k++, j=a[j];
			f[k]++;
		}
		if (f[1]!=n){
			if (f[2]) f[1]+=2;
			else f[1]++;
		}
		printf("%d\n", f[1]);
	}
	return 0;
}


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
#define N 1000000

int i,j,k,m,n,l;
bool v[N+10];
int f[N+10];

int main(){
	while (~scanf("%d", &n)){
		clr(v, 0), clr(f, 0);
		m=0;
		f[1]=2;
		repf(i, 1, n){
			scanf("%d", &k);
			l=k;
			for (int j=1; j*j<=k; ++j) if (k%j==0){
				while (j!=1 && l%j==0) l/=j;
				f[j]++;
				if (k/j!=j) f[k/j]++;
			}
			checkmax(m, k);
		}
		repd(i, m, 1) if (f[i]>1){
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}



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

#define N 500000

int i,j,k,m,n,l;
int a[N+10];

bool ok(int z){
	int k=0, ret=0;
	repf(i, 1, n){
		if (a[i]-k>z){
			if (a[i-1]-k>z) return false;
			ret++, k=a[i-1];
			if (ret>m) return false;
		}
	}
	if (a[n]-k>z) return false;
	else ret++;
	if (ret>m) return false;

	return true;
}

int main(){
	while (~scanf("%d%d%d", &l, &n, &m)){
		repf(i, 1, n) scanf("%d", &a[i]);
		a[++n]=l;
		sort(a+1, a+1+n);
		int x=1, y=a[n];
		while (x!=y){
			int z=mid(x, y);
			if (ok(z)) y=z;
			else x=z+1;
		}
		printf("%d\n", x);
	}
	return 0;
}


